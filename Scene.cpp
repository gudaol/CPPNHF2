//
// Created by qz9n1f on 2015.05.14..
//

#include "Scene.h"

Scene::Scene() {
    init();
}

void Scene::addObject(std::unique_ptr<Object> o) {
    objects.push_back(std::move(o));
}

void Scene::addLight(std::unique_ptr<Lightsource> l) {
    lights.push_back(std::move(l));
}

bool Scene::intersectAll(const Ray &_ray, Hit &_hit) {
    float tmax = Settings::distance;
    Hit realhit;
    for (auto &o : objects) {
        if (o->intersect(_ray, _hit)) {
            if (_hit.t > 0 && _hit.t < tmax) {
                tmax = _hit.t;
                realhit = _hit;
            }
        }
    }
    if (tmax < Settings::distance) {
        _hit = realhit;
        return true;
    }
    return false;
}

Color Scene::traceDirect(const Ray &_ray, Hit &_hit) {
    Color color;
    color = _hit.object->material.Ka * La;
    Vector x = _hit.point;
    Vector N = _hit.normal;
    for (auto &l : lights) {
        Ray shadowRay{x - Settings::epsilon * _ray.v, (l->pos - (x - Settings::epsilon * _ray.v)).Normalized()};
        Hit shadowHit;
        intersectAll(shadowRay, shadowHit);
        Vector y = shadowHit.point;
        float ld = (x - l->pos).Length();
        float sd = (x - y).Length();
        if (shadowHit.t < 0 || sd > ld) {
            Vector V = -((_ray).v.Normalized());
            Vector Ll = shadowRay.v.Normalized();
            Vector Hl = (V + Ll).Normalized();
            float lln = Ll * N;
            if (lln < 0.0f)
                lln = 0.0f;
            float hln = Hl * N;
            if (hln < 0.0f)
                hln = 0.0f;
            if (_hit.object->material.isBlinn()) {
                Color diffuse = _hit.object->material.Kd(x.x, x.y, _hit.object->proc()) * (lln);
                Color spek = _hit.object->material.ks * powf((hln), 100.0f);
                Color corr_intensity = l->color * (1.0f / ld / ld);
                color = color + (diffuse + spek) * corr_intensity;
            }
        }
    };
    return color;
}

Color Scene::rTrace(const Ray &_ray, int rec) {
    Color color;
    if (rec > Settings::samples)
        return La;

    Hit hit;
    intersectAll(_ray, hit);
    if (hit.t < 0)
        return La;
    color = traceDirect(_ray, hit);

    if (hit.object->material.isReflective()) {
        Ray rRay(hit.point - Settings::epsilon * _ray.v, hit.object->material.ReflectionDir(_ray.v, hit.normal));
        color = color + hit.object->material.Fresnel(_ray.v, hit.normal) * rTrace(rRay, rec + 1);
    }
    Ray refRay(hit.point + Settings::epsilon * _ray.v, Vector(0, 0, 0));
    if (hit.object->material.isRefractive() &&
        hit.object->material.RefractionDir(_ray.v, hit.normal, refRay.v)) {
        color = color +
                (Color(1, 1, 1) - hit.object->material.Fresnel(_ray.v, hit.normal)) * rTrace(refRay, rec + 1);
    }
    return color;
}

void Scene::init() {
    La = Color{0 / 255.0f, 100 / 255.0f, 250 / 255.0f};
    Vector eye = Vector{5,5,5};
    Vector lookat = Vector{0, 0, 0};
    Vector right = -((lookat - eye).gimmeOrtogonal() * ((eye - lookat).Length()));
    Vector up = -(((lookat - eye) % right).Normalized() * ((eye - lookat).Length()));
    camera = Camera{eye, lookat, up, right};
}

void Scene::renderInterval(Screen const &screen, int from, int to) {
    for (int Y = from; Y < to; Y++) {
        for (int X = 0; X < Screen::Width; X++) {
            Ray ray = camera.getRay(X, Y);
            Color color = rTrace(ray);
            float colormax = Color::max(color);
            Color tmcolor;
            if (colormax > 1)
                tmcolor = color / colormax;
            else tmcolor = color;
            screen.Image[Y * Screen::Width + X] = tmcolor;
        }
    }
}

void Scene::render(Screen const &screen, int threads) {
    std::vector<std::thread> workers;
    for (int i = 0; i < threads; ++i)
        workers.push_back(std::thread{
                [&screen, i, threads, this]() {
                    renderInterval(screen, i * (Screen::Height / threads), (i + 1) * (Screen::Height / threads));
                }
        });

    for (auto &worker : workers)
        worker.join();

}


void Scene::placeAndRotate(std::unique_ptr<Object>  p, std::unique_ptr<Object>  o,
                           Vector t, Vector tn, float a, float b, float c) {
    t = t * p->transformation.m;
    tn = (tn * p->transformation.im.T()).Normalized();
    Vector tnf = (((tn * Transformation::rotateX(10).m) * Transformation::rotateY(10).m) *
                  Transformation::rotateZ(10).m);
    Vector tnx = ((tnf.Normalized()) % tn).Normalized();
    Vector tny = (tnx % tn).Normalized();
    o->transform(Transformation::trans(t.x, t.y, t.z));
    o->transform(Transformation::basisR(tnx, tny, tn));
    o->transform(Transformation::scale(a, b, c));
    addObject(std::move(o));
}
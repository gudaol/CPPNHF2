//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_SCENE_H
#define CPPNHF2_SCENE_H


#include <memory>
#include <vector>
#include <thread>
#include "Settings.h"
#include "Object.h"
#include "Camera.h"
#include "Lightsource.h"

struct Scene {
private:
    void renderInterval(Screen const &, int, int);

public:
    std::vector<std::unique_ptr<Object>> objects;
    std::vector<std::unique_ptr<Lightsource>> lights;
    Camera camera;
    Color La;

    Scene();

    /**
     * Add object to scene.
     */
    void addObject(std::unique_ptr<Object> o);

    /**
     * Add a lightsource to the scene. Ambient light is ALWAYS present.
     */
    void addLight(std::unique_ptr<Lightsource> l);

    /**
     * Intersect all object in scene.
     */
    bool intersectAll(const Ray &_ray, Hit &_hit);

    /**
    * Trace only till first intersection.
    */
    Color traceDirect(const Ray &_ray, Hit &_hit);

    /**
     * Trace ray recursively with reflections, refraction, etc.
     */
    Color rTrace(const Ray &_ray, int rec = 0);

    /**
     * Initialize scene with failsafe values.
     * Eye in 5,5,5; Lookat is 0,0,0; Sky is blue
     */
    void init();

    /**
     * Render full image. Multithreading possible with tampering parameter @threads;
     */
    void render(Screen const &, int threads = 1);

    /**
     * Place o object on p object with properties:
     * @t: point of placement on p
     * @tn: direction on the surface
     * @a, @b, @c: scales on x,y,z axises respectively.
     */
    void placeAndRotate(std::unique_ptr<Object> p, std::unique_ptr<Object> o,
                        Vector t, Vector tn, float a, float b, float c);


};


#endif //CPPNHF2_SCENE_H

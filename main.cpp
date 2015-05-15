#include <GL/gl.h>
#include <GL/glut.h>
#include <random>
#include <map>
#include "Scene.h"
#include "Sphere.h"
#include "RealParaboloid.h"
#include "RealCylinder.h"


Screen screen;
Scene scene;


void onInitialization() {
    glViewport(0, 0, Screen::Width, Screen::Height);
    std::map<int, std::unique_ptr<Object>> object_types;
    object_types.insert(std::pair<int, std::unique_ptr<Object>>{0, make_unique<Sphere>()});
    object_types.insert(std::pair<int, std::unique_ptr<Object>>{1, make_unique<RealParaboloid>()});
    object_types.insert(std::pair<int, std::unique_ptr<Object>>{2, make_unique<RealCylinder>()});
    std::map<int, Material> materials;
    materials.insert(std::pair<int, Material>{0, Settings::material.gold()});
    materials.insert(std::pair<int, Material>{1, Settings::material.gold()});
    materials.insert(std::pair<int, Material>{2, Settings::material.gold()});
    materials.insert(std::pair<int, Material>{3, Settings::material.gold()});
    std::random_device rand;
    std::uniform_real_distribution<float> dist{0, 5};
    std::uniform_real_distribution<float> scale{0, 1};
    std::uniform_int_distribution<int> material{0, 3};
    std::uniform_int_distribution<int> object{0, 2};
    for (int i = 0; i < 20; ++i) {
        int mat = material(rand);
        int objt = object(rand);
        float x = dist(rand), y = dist(rand), z = dist(rand), size = scale(rand);
        std::unique_ptr<Object> add = object_types[objt]->create();
        add->material = materials[mat];
        add->transform(Transformation::scale(size, size, size));

        add->transform(Transformation::trans(x, y, z));
        scene.addObject(std::move(add));

    }
    scene.addLight(make_unique<Lightsource>());
    scene.render(screen, 8);
    glutPostRedisplay();
}

void onDisplay() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(Screen::Width, Screen::Height, GL_RGB, GL_FLOAT, screen.Image);
    glutSwapBuffers();
}

void onKeyboard(unsigned char, int, int) { }

void onKeyboardUp(unsigned char, int, int) { }

void onMouse(int, int, int, int) { }

void onMouseMotion(int, int) { }

void onIdle() {
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Grafika hazi feladat");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    onInitialization();
    glutDisplayFunc(onDisplay);
    glutMouseFunc(onMouse);
    glutIdleFunc(onIdle);
    glutKeyboardFunc(onKeyboard);
    glutKeyboardUpFunc(onKeyboardUp);
    glutMotionFunc(onMouseMotion);
    glutMainLoop();
    return 0;
}

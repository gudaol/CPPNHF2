cmake_minimum_required(VERSION 3.2)
project(CPPNHF2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -pedantic -Wall")

set(SOURCE_FILES main.cpp)
add_executable(CPPNHF2 ${SOURCE_FILES} Ray.h Ray.cpp Object.cpp Object.h Hit.cpp Hit.h Material.cpp Material.h Transformation.cpp Transformation.h Vector.cpp Vector.h Matrix.cpp Matrix.h Color.cpp Color.h Screen.h Sphere.cpp Sphere.h Desk.cpp Desk.h Circle.cpp Circle.h Paraboloid.cpp Paraboloid.h RealParaboloid.cpp RealParaboloid.h Cylinder.cpp Cylinder.h RealCylinder.cpp RealCylinder.h Camera.cpp Camera.h Scene.cpp Scene.h Settings.h Lightsource.cpp Lightsource.h Materials.cpp Materials.h Screen.cpp)
target_link_libraries(CPPNHF2 GL)
target_link_libraries(CPPNHF2 GLU)
target_link_libraries(CPPNHF2 glut)
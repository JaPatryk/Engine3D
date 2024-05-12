#ifndef Sphere_HPP
#define Sphere_HPP

#include "Primitives.hpp"

class Sphere : public Primitives {
public:
    Sphere(float r,float x, float y, float z);
  
    void draw();

private:
    float r;
    float slices=36;
    float stacks=18;
};

#endif // Sphere_HPP
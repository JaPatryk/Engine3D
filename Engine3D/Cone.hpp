#ifndef Cone_HPP
#define Cone_HPP

#include "Primitives.hpp"

class Cone : public Primitives {
public:
    Cone(float r,float h, float x, float y, float z);
    void draw();

private:
    float r;
	float h;
    float slices = 36;
    float stacks = 18;
};

#endif // Cone_HPP
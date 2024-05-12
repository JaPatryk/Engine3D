#ifndef CUBE_HPP
#define CUBE_HPP

#include "Primitives.hpp"

class Cube : public Primitives {
public:
    Cube(float size, float x, float y, float z);
    void draw();

private:
    float m_size;
};

#endif // CUBE_HPP
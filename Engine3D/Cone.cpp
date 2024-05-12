#include "Cone.hpp"
#include <GL/freeglut.h>

Cone::Cone(float r,float h, float x, float y, float z) : Primitives(x, y, z, r, g, b), r(r), h(h) {}

void Cone::draw() {
    glPushMatrix();
    glTranslatef(m_x, m_y, m_z);

    glColor3f(r, g, b);
    if (outline) {
        glutWireCone(1.0, 2.0, slices, stacks);
    }
    else {
        glutSolidCone(1.0, 2.0, slices, stacks);
    }
    glPopMatrix();
}

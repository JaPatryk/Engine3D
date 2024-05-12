#include "Sphere.hpp"
#include <GL/freeglut.h>

Sphere::Sphere(float r, float x, float y, float z) : Primitives(x, y, z, r, g, b), r(r) {}

void Sphere::draw() {
    glPushMatrix();
    glTranslatef(m_x, m_y, m_z);

    glColor3f(r, g, b);
    if (outline) {
        glutWireSphere(r,slices,stacks);
    }
    else {
        glutSolidSphere(r,slices,stacks);
    }
    glPopMatrix();
}

#include "Sphere.hpp"
#include <GL/freeglut.h>

Sphere::Sphere(float r, float x, float y, float z) : Primitives(x, y, z, r, g, b,rotate,rotateX,rotateY,rotateZ), r(r) {}

void Sphere::draw() {
    glPushMatrix();
    glTranslatef(m_x, m_y, m_z);


    if (rotateX != 0.0f) {
        glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    }
    if (rotateY != 0.0f) {
        glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    }
    if (rotateZ != 0.0f) {
        glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    }

    glColor3f(r, g, b);
    if (outline) {
        glutWireSphere(r,slices,stacks);
    }
    else {
        glutSolidSphere(r,slices,stacks);
    }
    glPopMatrix();
}

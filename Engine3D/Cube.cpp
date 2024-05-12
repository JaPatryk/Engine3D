#include "Cube.hpp"
#include <GL/freeglut.h>

Cube::Cube(float size, float x, float y, float z) : Primitives(x, y, z, r, g, b), m_size(size) {}

void Cube::draw(){
    glPushMatrix();
    glTranslatef(m_x, m_y, m_z);
    
    glColor3f(r, g, b);
	if (outline) {
		glutWireCube(m_size);
    }
    else {
        glutSolidCube(m_size);
    }
    glPopMatrix();
}

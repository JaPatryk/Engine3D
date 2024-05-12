#include "Primitives.hpp"

void Primitives::setX(float x) {
    this->m_x = x;
}

void Primitives::setY(float y) {
    this->m_y = y;
}

void Primitives::setZ(float z) {
    this->m_z = z;
}

void Primitives::setR(float r) {
    this->r = r;
}

void Primitives::setG(float g) {
    this->g = g;
}

void Primitives::setB(float b) {
    this->b = b;
}
void Primitives::changeOutline(bool outline) {
	this->outline = outline;
}

// Implementacje funkcji get
float Primitives::getX() const {
    return m_x;
}

float Primitives::getY() const {
    return m_y;
}

float Primitives::getZ() const {
    return m_z;
}

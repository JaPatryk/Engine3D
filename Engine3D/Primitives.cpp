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
void Primitives::setRotateX(float rotateX) {
	this->rotateX = rotateX;
}
void Primitives::setRotateY(float rotateY) {
	this->rotateY = rotateY;
}
void Primitives::setRotateZ(float rotateZ) {
	this->rotateZ = rotateZ;
}
void Primitives::setRotate(float rotate) {
	this->rotate = rotate;
}

float Primitives::getX() const {
    return m_x;
}

float Primitives::getY() const {
    return m_y;
}

float Primitives::getZ() const {
    return m_z;
}
float Primitives::getR() const {
	return r;
}
float Primitives::getG() const {
	return g;
}
float Primitives::getB() const {
	return b;
}
float Primitives::getRotateX() const {
	return rotateX;
}
float Primitives::getRotateY() const {
	return rotateY;
}
float Primitives::getRotateZ() const {
	return rotateZ;
}
float Primitives::getRotate() const {
	return rotate;
}


void Primitives::autoRotate() {
		
	if(this->getRotateX() > 0.0)
		this->rotateX += this->rotate;
	if (this->getRotateY() > 0.0)
		this->rotateY += this->rotate;
	if (this->getRotateZ() > 0.0)
		this->rotateZ += this->rotate;
	
		if (this->getRotateX() > 360.0f) {
			this->setRotateX(0.1f);
		}
		if (this->getRotateY() > 360.0f) {
			this->setRotateY(0.1f);
		}
		if (this->getRotateZ() > 360.0f) {
			this->setRotateZ(0.1f);
		}
	

};
void Primitives::sideToSide() 
{	

	if (this->movingRight) {
		this->m_x += 0.1f;
		if (this->m_x >= 10.0f) {
			this->movingRight = false;
		}
	}
	else {
		this->m_x -= 0.1f;
		if (this->m_x <= -10.0f) {
			this->movingRight = true;
		}
	}

};

#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

class Primitives {
public:
    Primitives(float x = 0.0f, float y = 0.0f, float z = 0.0f, float r = 0.0f, float g = 0.0f, float b = 0.0f, float rotateX = 0.0f, float rotateY= 0.0f, float rotateZ = 0.0f, float rotate = 0.0f) : m_x(x), m_y(y), m_z(z), r(r), g(g), b(b), rotate(rotate),rotateX(rotateX),rotateY(rotateY),rotateZ(rotateZ) {}

    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setR(float r);
    void setG(float g);
    void setB(float b);
	void setRotateX(float rotateX);
	void setRotateY(float rotateY);
	void setRotateZ(float rotateZ);
	void setRotate(float rotate);


    void changeOutline(bool outline);
    // Funkcje get
    float getX() const;
    float getY() const;
    float getZ() const;
	float getR() const;
	float getG() const;
	float getB() const;
	float getRotateX() const;
	float getRotateY() const;
	float getRotateZ() const;
	float getRotate() const;

	void autoRotate();

    float rotateX;
    float rotateY;
    float rotateZ;
    bool outline = false;
    float rotate;
protected:
    float m_x;
    float m_y;
    float m_z;
    float r;
    float g;
	float b;

    
};

#endif // PRIMITIVES_HPP

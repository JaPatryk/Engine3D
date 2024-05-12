#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

class Primitives {
public:
    Primitives(float x = 0.0f, float y = 0.0f, float z = 0.0f, float r = 0.0f, float g = 0.0f, float b = 0.0f) : m_x(x), m_y(y), m_z(z), r(r), g(g), b(b) {}

    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setR(float r);
    void setG(float g);
    void setB(float b);

    void changeOutline(bool outline);
    // Funkcje get
    float getX() const;
    float getY() const;
    float getZ() const;

protected:
    float m_x;
    float m_y;
    float m_z;
    float r;
    float g;
	float b;
    bool outline = false;
};

#endif // PRIMITIVES_HPP

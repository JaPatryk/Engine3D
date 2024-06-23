#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP
/**
 * @brief Klasa bazowa reprezentujaca prymitywy w trojwymiarowej przestrzeni.
 *
 * Klasa ta zawiera podstawowe wlasciwosci i metody wspolne dla wszystkich prymitywow.
 */
class Primitives {
public:
    /**
    * @brief Konstruktor klasy Primitives.
    *
    * @param x Wspolrzedna X polozenia prymitywu.
    * @param y Wspolrzedna Y polozenia prymitywu.
    * @param z Wspolrzedna Z polozenia prymitywu.
    * @param r Skladowa czerwona koloru prymitywu.
    * @param g Skladowa zielona koloru prymitywu.
    * @param b Skladowa niebieska koloru prymitywu.
    * @param rotateX Obrot prymitywu wokol osi X.
    * @param rotateY Obrot prymitywu wokol osi Y.
    * @param rotateZ Obrot prymitywu wokol osi Z.
    * @param rotate Kat ogolny obrotu prymitywu.
    */
    Primitives(float x = 0.0f, float y = 0.0f, float z = 0.0f, float r = 0.0f, float g = 0.0f, float b = 0.0f, float rotateX = 0.0f, float rotateY = 0.0f, float rotateZ = 0.0f, float rotate = 0.0f) : m_x(x), m_y(y), m_z(z), r(r), g(g), b(b), rotate(rotate), rotateX(rotateX), rotateY(rotateY), rotateZ(rotateZ) {};

    void setX(float x); ///< Ustawia wspolrzedna X.
    void setY(float y); ///< Ustawia wspolrzedna Y.
    void setZ(float z); ///< Ustawia wspolrzedna Z.
    void setR(float r); ///< Ustawia skladowa czerwona koloru.
    void setG(float g); ///< Ustawia skladowa zielona koloru.
    void setB(float b); ///< Ustawia skladowa niebieska koloru.
    void setRotateX(float rotateX); ///< Ustawia obrot wokol osi X.
    void setRotateY(float rotateY); ///< Ustawia obrot wokol osi Y.
    void setRotateZ(float rotateZ); ///< Ustawia obrot wokol osi Z.
    void setRotate(float rotate);   ///< Ustawia ogolny kat obrotu.

    void changeOutline(bool outline); ///< Zmienia tryb obrysu.

    float getX() const; ///< Zwraca wspolrzedna X.
    float getY() const; ///< Zwraca wspolrzedna Y.
    float getZ() const; ///< Zwraca wspolrzedna Z.
    float getR() const; ///< Zwraca skladowa czerwona koloru.
    float getG() const; ///< Zwraca skladowa zielona koloru.
    float getB() const; ///< Zwraca skladowa niebieska koloru.
    float getRotateX() const; ///< Zwraca obrot wokol osi X.
    float getRotateY() const; ///< Zwraca obrot wokol osi Y.
    float getRotateZ() const; ///< Zwraca obrot wokol osi Z.
    float getRotate() const;   ///< Zwraca ogolny kat obrotu.

    void autoRotate(); ///< Automatyczny obrot prymitywu.
    void sideToSide(); ///< Ruch prymitywu w lewo i prawo.

    bool movingRight = true; ///< Flaga okreslajaca kierunek ruchu.
    float rotateX; ///< Obrot wokol osi X.
    float rotateY; ///< Obrot wokol osi Y.
    float rotateZ; ///< Obrot wokol osi Z.
    bool outline = false; ///< Flaga okreslajaca tryb obrysu.
    float rotate; ///< Ogolny kat obrotu.

    const char* texturePath; ///< sciezka do tekstury.

protected:
    float m_x; ///< Wspolrzedna X.
    float m_y; ///< Wspolrzedna Y.
    float m_z; ///< Wspolrzedna Z.
    float r;   ///< Skladowa czerwona koloru.
    float g;   ///< Skladowa zielona koloru.
    float b;   ///< Skladowa niebieska koloru.
};

#endif // PRIMITIVES_HPP
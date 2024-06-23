#ifndef CUBE_HPP
#define CUBE_HPP

#include "Primitives.hpp"
#include <GL/glut.h>

/**
 * @brief Klasa reprezentujaca szescian, dziedziczaca po klasie Primitives.
 *
 * Ta klasa definiuje szescian w przestrzeni trojwymiarowej.
 */
class Cube : public Primitives {
public:
    /**
     * @brief Konstruktor klasy Cube.
     *
     * @param size Dlugosc boku szescianu.
     * @param x Wspolrzedna X polozenia szescianu.
     * @param y Wspolrzedna Y polozenia szescianu.
     * @param z Wspolrzedna Z polozenia szescianu.
     */
    Cube(float size, float x, float y, float z);

    /**
     * @brief Metoda do rysowania szescianu.
     *
     * Ta metoda jest odpowiedzialna za rysowanie szescianu.
     */
    void draw();

private:
    float m_size; ///< Dlugosc boku szescianu.
};

#endif // CUBE_HPP

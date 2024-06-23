#ifndef CONE_HPP
#define CONE_HPP

#include "Primitives.hpp"

/**
 * @brief Klasa reprezentujaca stozek dziedziczaca po klasie Primitives.
 *
 * Klasa ta definiuje stozek w trojwymiarowej przestrzeni.
 */
class Cone : public Primitives {
public:
    /**
     * @brief Konstruktor klasy Cone.
     *
     * @param r Promien podstawy stozka.
     * @param h Wysokosc stozka.
     * @param x Wspolrzêdna X polozenia stozka.
     * @param y Wspolrzêdna Y polozenia stozka.
     * @param z Wspolrzêdna Z polozenia stozka.
     */
    Cone(float r, float h, float x, float y, float z);

    /**
     * @brief Metoda do rysowania stozka.
     *
     * Metoda odpowiedzialna za rysowanie stozka z okreslona liczba segmentow (slices i stacks).
     */
    void draw();

private:
    float r; ///< Promien podstawy stozka.
    float h; ///< Wysokosc stozka.
    float slices = 36; ///< Liczba podzialow wokol podstawy stozka.
    float stacks = 18; ///< Liczba segmentow wysokosci stozka.
};

#endif // CONE_HPP

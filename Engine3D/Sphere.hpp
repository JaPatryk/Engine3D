#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Primitives.hpp"

/**
 * @brief Klasa reprezentujaca sfere dziedziczaca po klasie Primitives.
 *
 * Klasa ta definiuje sfere o okreslonym promieniu i polozeniu, oraz zawiera metody do rysowania.
 */
class Sphere : public Primitives {
public:
    /**
     * @brief Konstruktor klasy Sphere.
     *
     * @param r Promien sfery.
     * @param x Wspolrzedna X polozenia sfery.
     * @param y Wspolrzedna Y polozenia sfery.
     * @param z Wspolrzedna Z polozenia sfery.
     */
    Sphere(float r, float x, float y, float z);

    /**
     * @brief Metoda do rysowania sfery.
     */
    void draw();

private:
    float r; ///< Promien sfery.
    float slices = 36; ///< Liczba podzialow na dlugosc (poziome przekroje).
    float stacks = 18; ///< Liczba podzialow na wysokosc (pionowe przekroje).
};

#endif // SPHERE_HPP

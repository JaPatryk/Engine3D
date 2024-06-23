#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <GL/freeglut.h>
#include <cmath>

/**
 * @brief Klasa obslugujaca interakcje z uzytkownikiem za pomoca klawiatury i myszy.
 *
 * Klasa zawiera statyczne metody do obslugi ruchu kamery, obrotu kamery oraz przelaczania opcji oswietlenia i cieni.
 */
class InputHandler {
public:
    /**
     * @brief Metoda do przesuwania kamery w okreslonym kierunku.
     *
     * @param key Kod klawisza kierunkowego.
     * @param cameraPosX Referencja do pozycji X kamery.
     * @param cameraPosZ Referencja do pozycji Z kamery.
     * @param cameraAngleY Referencja do kata obrotu kamery wzdluz osi Y.
     */
    static void moveInDirection(int key, float& cameraPosX, float& cameraPosZ, float& cameraAngleY);

    /**
     * @brief Metoda do obracania kamery za pomoca klawiszy.
     *
     * @param key Kod klawisza obracajacego.
     * @param cameraAngleX Referencja do kata obrotu kamery wzdluz osi X.
     * @param cameraAngleY Referencja do kata obrotu kamery wzdluz osi Y.
     */
    static void rotateCamera(int key, float& cameraAngleX, float& cameraAngleY);

    /**
     * @brief Metoda do obracania kamery za pomoca myszy.
     *
     * @param x Aktualna pozycja X kursora myszy.
     * @param y Aktualna pozycja Y kursora myszy.
     * @param windowWidth Szerokosc okna.
     * @param windowHeight Wysokosc okna.
     * @param cameraAngleX Referencja do kata obrotu kamery wzdluz osi X.
     * @param cameraAngleY Referencja do kata obrotu kamery wzdluz osi Y.
     */
    static void rotateCameraByMouse(int x, int y, int windowWidth, int windowHeight, float& cameraAngleX, float& cameraAngleY);

    /**
     * @brief Metoda do przesuwania kamery za pomoca klawiszy.
     *
     * @param key Kod klawisza.
     * @param cameraPosX Referencja do pozycji X kamery.
     * @param cameraPosZ Referencja do pozycji Z kamery.
     * @param cameraAngleY Kat obrotu kamery wzdluz osi Y.
     */
    static void moveCamera(unsigned char key, float& cameraPosX, float& cameraPosZ, float cameraAngleY);

    /**
     * @brief Metoda do przelaczania stanu oswietlenia.
     *
     * @param key Kod klawisza.
     * @param isLightingEnabled Referencja do flagi okreslajacej stan oswietlenia.
     */
    static void toggleLighting(int key, bool& isLightingEnabled);

    /**
     * @brief Metoda do przelaczania stanu cieni.
     *
     * @param key Kod klawisza.
     * @param isShadowEnabled Referencja do flagi okreslajacej stan cieni.
     */
    static void toggleShadow(int key, bool& isShadowEnabled);
};

#endif // INPUT_HANDLER_HPP

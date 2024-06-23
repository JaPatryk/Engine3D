#ifndef ENGINE3D_HPP
#define ENGINE3D_HPP

#include <GL/freeglut.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * @brief Klasa reprezentujaca silnik 3D obslugujacy interakcje z uzytkownikiem.
 *
 * Silnik ten uzywa biblioteki OpenGL i GLM do renderowania grafiki 3D.
 */
class Engine3D {
public:
    /**
     * @brief Konstruktor klasy Engine3D.
     *
     * @param windowTitle Tytul okna aplikacji 3D.
     * @param windowWidth Szerokosc okna aplikacji.
     * @param windowHeight Wysokosc okna aplikacji.
     */
    Engine3D(const std::string& windowTitle, int windowWidth, int windowHeight);

    /**
     * @brief Metoda uruchamiajaca petle glowna silnika 3D.
     */
    void run();

    float cameraAngleX = 0.0f; ///< Kat obrotu kamery wzduz osi X.
    float cameraAngleY = 0.0f; ///< Kat obrotu kamery wzduz osi Y.

    float cameraPosX = 0.0f; ///< Pozycja kamery na osi X.
    float cameraPosY = 0.0f; ///< Pozycja kamery na osi Y.
    float cameraPosZ = 5.0f; ///< Pozycja kamery na osi Z.

    float fps = 60; ///< Liczba klatek na sekunde.

    int initialMouseX = 0; ///< Poczatkowa pozycja X kursora myszy.
    int initialMouseY = 0; ///< Poczatkowa pozycja Y kursora myszy.
    bool isMouseDragging = false; ///< Flaga okreslajaca, czy przeciaganie myszy jest w trakcie.
    bool isLightingEnabled = true; ///< Flaga okreslajaca, czy oswietlenie jest wlaczone.
    bool isShadowEnabled = false; ///< Flaga okreslajaca, czy cienie sa wlaczone.

    /**
     * @brief Metoda statyczna do rysowania podlogi w scenie 3D.
     */
    static void drawFloor();

private:
    std::string m_windowTitle; ///< Tytul okna aplikacji.
    int m_windowWidth; ///< Szerokosc okna aplikacji.
    int m_windowHeight; ///< Wysokosc okna aplikacji.

    static Engine3D* instance; ///< Wskaznik do instancji silnika (singleton).

    /**
     * @brief Obsluga klawiszy specjalnych klawiatury.
     *
     * @param key Kod klawisza specjalnego.
     * @param x Pozycja X kursora myszy.
     * @param y Pozycja Y kursora myszy.
     */
    static void specialKeyboardKeysHandler(int key, int x, int y);

    /**
     * @brief Metoda do renderowania sceny 3D.
     */
    static void display();

    /**
     * @brief Metoda do zmiany rozmiaru okna.
     *
     * @param w Nowa szerokosc okna.
     * @param h Nowa wysokosc okna.
     */
    static void reshape(int w, int h);

    /**
     * @brief Obsluga standardowych klawiszy klawiatury.
     *
     * @param key Kod standardowego klawisza.
     * @param x Pozycja X kursora myszy.
     * @param y Pozycja Y kursora myszy.
     */
    static void keyboardKeysHandler(unsigned char key, int x, int y);

    /**
     * @brief Obsluga zdarzen myszy (przyciski myszy).
     *
     * @param button Numer przycisku myszy.
     * @param state Stan przycisku (nacisniety lub zwolniony).
     * @param x Pozycja X kursora myszy.
     * @param y Pozycja Y kursora myszy.
     */
    static void mouseHandler(int button, int state, int x, int y);

    /**
     * @brief Obsluga ruchu myszy.
     *
     * @param x Aktualna pozycja X kursora myszy.
     * @param y Aktualna pozycja Y kursora myszy.
     */
    static void mouseMotionHandler(int x, int y);

    /**
     * @brief Metoda obslugujaca zegar (timer).
     *
     * @param value Dodatkowa wartosc przekazywana do funkcji timer.
     */
    static void timer(int value);

    /**
     * @brief Inicjalizacja biblioteki GLUT i ustawienia poczatkowe.
     */
    void initGLUT();
};

#endif // ENGINE3D_HPP

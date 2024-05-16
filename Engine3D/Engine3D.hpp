#ifndef ENGINE3D_HPP
#define ENGINE3D_HPP

#include <GL/freeglut.h>
#include <string>



class Engine3D {
public:
    Engine3D(const std::string& windowTitle, int windowWidth, int windowHeight);
    void run();
    ;
    float cameraAngleX = 0.0f;
    float cameraAngleY = 0.0f;

    float cameraPosX = 0.0f;
    float cameraPosY = 0.0f;
    float cameraPosZ = 5.0f;

private:
    std::string m_windowTitle;
    int m_windowWidth;
    int m_windowHeight;

    static Engine3D* instance; // Statyczny wskaünik do instancji

    static void specialKeyboardKeysHandler(int key, int x, int y);
    static void display();
    static void reshape(int w, int h);
    static void keyboardKeysHandler(unsigned char key, int x, int y);
    static void mouseHandler(int button, int state, int x, int y);
    void initGLUT();
};

#endif // ENGINE3D_HPP

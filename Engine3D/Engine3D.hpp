#ifndef ENGINE3D_HPP
#define ENGINE3D_HPP

#include <GL/freeglut.h>
#include <string>

class Engine3D {
public:
    Engine3D(const std::string& windowTitle, int windowWidth, int windowHeight);
    void run();

private:
    std::string m_windowTitle;
    int m_windowWidth;
    int m_windowHeight;

    static void specialKeys(int key, int x, int y);
    static void display();
    static void reshape(int w, int h);
    static void keyboard(unsigned char key, int x, int y);

    void initGLUT();
};

#endif // ENGINE3D_HPP

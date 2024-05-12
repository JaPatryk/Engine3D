#include "Engine3D.hpp"

#include "Cube.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"

float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 5.0f;

// Globalne zmienne przechowujące pozycję kamery
float cameraPosX = 0.0f;
float cameraPosY = 0.0f;
float cameraPosZ = 5.0f;

// Kąty obrotu kamery
float cameraAngleX = 0.0f;
float cameraAngleY = 0.0f;

Engine3D::Engine3D(const std::string& windowTitle, int windowWidth, int windowHeight)
    : m_windowTitle(windowTitle), m_windowWidth(windowWidth), m_windowHeight(windowHeight) {
    initGLUT();
}

void Engine3D::run() {
    // Inicjalizacja GLUT i konfiguracja okna
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(m_windowWidth, m_windowHeight);
    glutCreateWindow(m_windowTitle.c_str());
    // Ustawienie funkcji callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
   //glutSolidCube(100.0f);
    //glutReshapeFunc(reshapeCallback);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Ustawienie koloru tła na czarny
    glEnable(GL_DEPTH_TEST);
    //Rozpoczęcie głównej pętli GLUT
    glutMainLoop();
}

void Engine3D::initGLUT() {
    int argc = 0;
    char** argv = nullptr;
    glutInit(&argc, argv);
}



void Engine3D::reshape(int w, int h){
   glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(0x1700);
}

void Engine3D::display() {
        
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Cube cube(1.0f, -1, -2, 0);
    Sphere sphere(0.5f,2, 2, 0);
	Cone cone(0.5f, 1.0f, 1, 0, 0);
    cube.setR(1.0f);
    cone.setG(1.0f);
    sphere.changeOutline(true);
	sphere.setB(1.0f);
    sphere.setR(0);
    // Przesunięcie kamery w tył o 5 jednostek od sześcianu
    //gluLookAt(cameraX, cameraY, cameraZ,   // Pozycja kamery
      //  0.0, 0.0, 0.0,   
        //0.0, 1.0, 0.0);
    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,  // Pozycja kamery
        cameraPosX + sin(cameraAngleY), cameraPosY + sin(cameraAngleX), cameraPosZ - cos(cameraAngleY),  // Punkt patrzenia kamery
        0.0f, 1.0f, 0.0f); // Wektor wskazujący górę

	cube.draw();
    sphere.draw();
    cone.draw();
    glutSwapBuffers();

}

//test

void Engine3D::specialKeys(int key, int x, int y) {
   // void specialKeys(int key, int x, int y) {
        switch (key) {
        case GLUT_KEY_UP:
            // Obróć kamerę w górę
            cameraAngleX += 0.1f;
            break;
        case GLUT_KEY_DOWN:
            // Obróć kamerę w dół
            cameraAngleX -= 0.1f;
            break;
        case GLUT_KEY_LEFT:
            // Obróć kamerę w lewo
            cameraAngleY -= 0.1f;
            break;
        case GLUT_KEY_RIGHT:
            // Obróć kamerę w prawo
            cameraAngleY += 0.1f;
            break;
        }
        glutPostRedisplay();
    }

void Engine3D::keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        // Przesuń kamerę w kierunku patrzenia
        cameraPosX += 0.1f * sin(cameraAngleY);
        cameraPosZ -= 0.1f * cos(cameraAngleY);
        break;
    }
    glutPostRedisplay();
}
#include "Engine3D.hpp"
#include "Cube.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "InputHandler.hpp"

Engine3D* Engine3D::instance = nullptr;

Cube cube(1.0f, -1, -2, 0);
Sphere sphere(0.5f, 2, 2, 0);
Cone cone(0.5f, 1.0f, 1, 0, 0);

Engine3D::Engine3D(const std::string& windowTitle, int windowWidth, int windowHeight)
    : m_windowTitle(windowTitle), m_windowWidth(windowWidth), m_windowHeight(windowHeight) {
    instance = this; // Ustaw wskaźnik na tę instancję
    initGLUT();
}


void Engine3D::run() {
    // Inicjalizacja GLUT i konfiguracja okna
    sphere.setRotateX(1.0);
    sphere.setRotate(0.5);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(m_windowWidth, m_windowHeight);
    glutCreateWindow(m_windowTitle.c_str());
    // Ustawienie funkcji callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeyboardKeysHandler);
    glutKeyboardFunc(keyboardKeysHandler);
	glutMouseFunc(mouseHandler);
    glutIdleFunc(timer);
    glutTimerFunc(1000 / instance->fps, OnTimer, 0);
   // glutTimerFunc(1000 /60, timer, 0);
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

    cube.setR(1.0f);
    cone.setG(1.0f);
    sphere.changeOutline(true);
	sphere.setB(1.0f);
    sphere.setR(0);

	
    gluLookAt(instance->cameraPosX, instance->cameraPosY, instance->cameraPosZ,  // Pozycja kamery
        instance->cameraPosX + sin(instance->cameraAngleY), instance->cameraPosY + sin(instance->cameraAngleX), instance->cameraPosZ - cos(instance->cameraAngleY),
        0.0f, 1.0f, 0.0f); // Wektor wskazujący górę


	cube.draw();
    sphere.draw();
    cone.draw();
    glutSwapBuffers();

}



void Engine3D::specialKeyboardKeysHandler(int key, int x, int y) {

    if (instance) {
        InputHandler::rotateCamera(key, instance->cameraAngleX, instance->cameraAngleY);
    }
 
    }

void Engine3D::keyboardKeysHandler(unsigned char key, int x, int y) {
    
       // InputHandler::moveInDirection(key, instance->cameraPosX, instance->cameraPosZ, instance->cameraAngleY);
   }


void Engine3D::mouseHandler(int button, int state, int x, int y) {
	
    InputHandler::moveInDirection(button, instance->cameraPosX, instance->cameraPosZ, instance->cameraAngleY);
}


void Engine3D::timer() {
	glutPostRedisplay(); static int last_time;
    int now_time = glutGet(GLUT_ELAPSED_TIME);
    if (last_time > 0) {
        float times = (now_time - last_time) / 1000.0f;
		sphere.autoRotate();
    }
    last_time = now_time;
    glutPostRedisplay();

}


void Engine3D::OnTimer(int val) {

    glutPostRedisplay();
    glutTimerFunc(1000 / instance->fps, OnTimer, 0);
}
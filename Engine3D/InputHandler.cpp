#include "inputHandler.hpp"
#include <iostream>
void InputHandler::moveInDirection(int button, float& cameraPosX, float& cameraPosZ, float& cameraAngleY) {
	if (button == GLUT_LEFT_BUTTON) {
		// Przesuñ kamerê do przodu
		cameraPosX += 0.1f * sin(cameraAngleY);
		cameraPosZ -= 0.1f * cos(cameraAngleY);
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		// Przesuñ kamerê do ty³u
		cameraPosX -= 0.1f * sin(cameraAngleY);
		cameraPosZ += 0.1f * cos(cameraAngleY);
	}
    glutPostRedisplay();
}
void InputHandler::rotateCamera(int key,float& cameraAngleX, float& cameraAngleY) {
    // void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        // Obróæ kamerê w górê
        cameraAngleX += 0.1f;

        break;
    case GLUT_KEY_DOWN:
        // Obróæ kamerê w dó³
        cameraAngleX -= 0.1f;
        break;
    case GLUT_KEY_LEFT:
        // Obróæ kamerê w lewo
        cameraAngleY -= 0.1f;
        break;
    case GLUT_KEY_RIGHT:
        // Obróæ kamerê w prawo
        cameraAngleY += 0.1f;
        break;
    }
    glutPostRedisplay();
}

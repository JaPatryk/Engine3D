#include "inputHandler.hpp"
#include <iostream>
void InputHandler::moveInDirection(int button, float& cameraPosX, float& cameraPosZ, float& cameraAngleY) {
	if (button == GLUT_LEFT_BUTTON) {
		// Przesu� kamer� do przodu
		cameraPosX += 0.1f * sin(cameraAngleY);
		cameraPosZ -= 0.1f * cos(cameraAngleY);
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		// Przesu� kamer� do ty�u
		cameraPosX -= 0.1f * sin(cameraAngleY);
		cameraPosZ += 0.1f * cos(cameraAngleY);
	}
    glutPostRedisplay();
}
void InputHandler::rotateCamera(int key,float& cameraAngleX, float& cameraAngleY) {
    // void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        // Obr�� kamer� w g�r�
        cameraAngleX += 0.1f;

        break;
    case GLUT_KEY_DOWN:
        // Obr�� kamer� w d�
        cameraAngleX -= 0.1f;
        break;
    case GLUT_KEY_LEFT:
        // Obr�� kamer� w lewo
        cameraAngleY -= 0.1f;
        break;
    case GLUT_KEY_RIGHT:
        // Obr�� kamer� w prawo
        cameraAngleY += 0.1f;
        break;
    }
    glutPostRedisplay();
}

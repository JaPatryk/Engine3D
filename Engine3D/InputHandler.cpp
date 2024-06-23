#include "inputHandler.hpp"
#include <iostream>

#define PI 3.14159265358979323846

void InputHandler::moveInDirection(int button, float& cameraPosX, float& cameraPosZ, float& cameraAngleY) {
	if (button == GLUT_LEFT_BUTTON) {
	
		cameraPosX += 0.1f * sin(cameraAngleY);
		cameraPosZ -= 0.1f * cos(cameraAngleY);
	}
	else if (button == GLUT_RIGHT_BUTTON) {
	
		cameraPosX -= 0.1f * sin(cameraAngleY);
		cameraPosZ += 0.1f * cos(cameraAngleY);
	}
    glutPostRedisplay();
}

void InputHandler::moveCamera(unsigned char key, float& cameraPosX, float& cameraPosZ, float cameraAngleY) {
    float moveStep = 0.1f * 1;

    switch (key) {
    case 'w': 
        cameraPosX += 0.1f * sin(cameraAngleY);
        cameraPosZ -= 0.1f * cos(cameraAngleY);
        break;
    case 's': 
        cameraPosX -= 0.1f * sin(cameraAngleY);
        cameraPosZ += 0.1f * cos(cameraAngleY);
        break;
    case 'a': 
        cameraPosX -= 0.1f * cos(cameraAngleY);
        cameraPosZ -= 0.1f * sin(cameraAngleY);
        break;
    case 'd': 
        cameraPosX += 0.1f * cos(cameraAngleY);
        cameraPosZ += 0.1f * sin(cameraAngleY);
        break;
    }
};
void InputHandler::rotateCamera(int key,float& cameraAngleX, float& cameraAngleY) {
  
    switch (key) {
    case GLUT_KEY_UP:
       
        cameraAngleX += 0.1f;

        break;
    case GLUT_KEY_DOWN:
    
        cameraAngleX -= 0.1f;
        break;
    case GLUT_KEY_LEFT:
     
        cameraAngleY -= 0.1f;
        break;
    case GLUT_KEY_RIGHT:
      
        cameraAngleY += 0.1f;
        break;
    }
    glutPostRedisplay();
}


void InputHandler::rotateCameraByMouse(int x, int y, int windowWidth, int windowHeight, float& cameraAngleX, float& cameraAngleY) {

   
    float xoffset = x - windowWidth / 2;
    float yoffset = windowHeight / 2 - y; 

    const float sensitivity = 0.01f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    cameraAngleY += xoffset;
    cameraAngleX += yoffset;


    if (cameraAngleX > 89.0f)
        cameraAngleX = 89.0f;
    if (cameraAngleX < -89.0f)
        cameraAngleX = -89.0f;

    glutWarpPointer(windowWidth / 2, windowHeight / 2);
  
}
void InputHandler::toggleLighting(int key,bool& isLightingEnabled) {
    if (key == 'l' || key == 'L') {
        isLightingEnabled = !isLightingEnabled;
    }

}

void InputHandler::toggleShadow(int key, bool& isShadowEnabled) {
    if (key == 'o' || key == 'O') {
        isShadowEnabled = !isShadowEnabled;
    }

}
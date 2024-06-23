#include "Engine3D.hpp"
#include "Cube.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "InputHandler.hpp"
#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
Engine3D* Engine3D::instance = nullptr;

Cube cube(1.0f, 0, 1, 0);
Sphere sphere(0.5f, 2, 2, -2);
Cone cone(5.0f, 1.0f, 3, 0, -5);

Sphere sun(2.2f, 5.0f, 11.0f, 0.1f);

Engine3D::Engine3D(const std::string& windowTitle, int windowWidth, int windowHeight)
    : m_windowTitle(windowTitle), m_windowWidth(windowWidth), m_windowHeight(windowHeight) {
    instance = this; 
    initGLUT();

}

void Engine3D::run() {
 
  
    sphere.setRotateX(1.0);
    sphere.setRotate(0.5);
    
	cone.setRotateZ(0.5);
    cone.setRotate(0.5);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(m_windowWidth, m_windowHeight);

    glutCreateWindow(m_windowTitle.c_str());
    glutWarpPointer(instance->m_windowWidth / 2, instance->m_windowHeight / 2);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeyboardKeysHandler);
    glutKeyboardFunc(keyboardKeysHandler);
	glutMouseFunc(mouseHandler);
    glutPassiveMotionFunc(mouseMotionHandler);
    glutTimerFunc(1000 / instance->fps, timer, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
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
    cube.setB(1.0f);
    cube.setG(1.0f);
    cube.texturePath = "C:/Users/Dell/OneDrive/Pulpit/Engine3D/Engine3D/tekstura2.jpg";
    sphere.changeOutline(true);
    
	sun.setR(1.0f); 
    sun.setG(0.8f);
	
    gluLookAt(instance->cameraPosX, instance->cameraPosY, instance->cameraPosZ,  
        instance->cameraPosX + sin(instance->cameraAngleY), instance->cameraPosY + sin(instance->cameraAngleX), instance->cameraPosZ - cos(instance->cameraAngleY),
        0.0f, 1.0f, 0.0f); 



	
   

    if (instance->isLightingEnabled) {      
        glEnable(GL_LIGHTING);
 
        GLfloat lightPosition1[] = { 5.0f, 5.0f, 10.0f, 1.0f };
        GLfloat lightDiffuse1[] = { 0.0f, 0.0f, 0.0f, 0.0f }; 

        GLfloat lightPosition2[] = { -5.0f, 3.0f, 8.0f, 1.0f };
        GLfloat lightDiffuse2[] = { 0.0f, 0.0f, 0.0f, 0.0f }; 

       
        GLfloat lightPosition3[] = { 0.0f, 8.0f, -5.0f, 1.0f };
        GLfloat lightDiffuse3[] = { 0.0f, 0.0f, 0.0f, 0.0f }; 

        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition1);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse1);
        glEnable(GL_LIGHT0);

        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse2);
        glEnable(GL_LIGHT1);

        glLightfv(GL_LIGHT2, GL_POSITION, lightPosition3);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuse3);
        glEnable(GL_LIGHT2);
    }
    else {
        if (instance->isShadowEnabled) {
            glDisable(GL_LIGHTING);
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
        }
        else {
            glEnable(GL_LIGHTING);
            glEnable(GL_NORMALIZE);

            GLfloat lightAmb1[] = { 0.2f, 0.2f, 0.2f, 1.0f };
            GLfloat lightSpc1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            GLfloat lightPosition1[] = { 5.0f, 5.0f, 6.0f, 1.0f };
            GLfloat lightDiffuse1[] = { 0.9f, 0.85f, 0.8f, 1.0f };


            GLfloat lightAmb2[] = { 0.2f, 0.2f, 0.2f, 1.0f };
            GLfloat lightSpc2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            GLfloat lightPosition2[] = { 5.0f, 5.0f, 6.0f, 1.0f };
            GLfloat lightDiffuse2[] = { 0.8f, 0.85f, 0.9f, 1.0f };


            GLfloat lightAmb3[] = { 0.2f, 0.2f, 0.2f, 1.0f };
            GLfloat lightSpc3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            GLfloat lightPosition3[] = { 5.0f, 5.0f, 6.0f, 1.0f };
            GLfloat lightDiffuse3[] = { 0.6f, 0.6f, 0.7f, 1.0f };

            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb1);
            glLightfv(GL_LIGHT0, GL_POSITION, lightPosition1);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse1);
            glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc1);
            glEnable(GL_LIGHT0);

            glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse2);
            glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc2);
            glEnable(GL_LIGHT1);

            glLightfv(GL_LIGHT2, GL_POSITION, lightPosition3);
            glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuse3);
            glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc3);
            glEnable(GL_LIGHT2);
        }
        
    }

    

    cone.draw();
	cube.draw();
    sphere.draw();
    sun.draw();
    instance->drawFloor();

    glutSwapBuffers();

}



void Engine3D::specialKeyboardKeysHandler(int key, int x, int y) {

    if (instance) {
        InputHandler::rotateCamera(key, instance->cameraAngleX, instance->cameraAngleY);
    }
 
    }

void Engine3D::keyboardKeysHandler(unsigned char key, int x, int y) {
    
       InputHandler::moveCamera(key, instance->cameraPosX, instance->cameraPosZ, instance->cameraAngleY);
       InputHandler::toggleLighting(key, instance->isLightingEnabled);
       InputHandler::toggleShadow(key, instance->isShadowEnabled);
   }


void Engine3D::mouseHandler(int button, int state, int x, int y) {
	
    InputHandler::moveInDirection(button, instance->cameraPosX, instance->cameraPosZ, instance->cameraAngleY);




    if (instance) {
        if (button == GLUT_LEFT_BUTTON) {
            if (state == GLUT_DOWN) {
                instance->isMouseDragging = true;
                instance->initialMouseX = x;
                instance->initialMouseY = y;
            }
            else if (state == GLUT_UP) {
                instance->isMouseDragging = false;
            }
        }
    }
}

void Engine3D::mouseMotionHandler(int x, int y) {

    InputHandler::rotateCameraByMouse(x,y, instance->m_windowWidth,instance->m_windowHeight, instance->cameraAngleX, instance->cameraAngleY);
}

void Engine3D::drawFloor() {
    static bool textureLoaded = false;
    static GLuint textureID;

    if (!textureLoaded) {
        int width, height, channels;
        unsigned char* image = stbi_load("C:/Users/Dell/OneDrive/Pulpit/Engine3D/Engine3D/tekstura.jpg", &width, &height, &channels, STBI_rgb);

        if (!image) {
            std::cerr << "Failed to load texture" << std::endl;
            exit(-1); 
        }

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

        stbi_image_free(image);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        textureLoaded = true;
    }
    GLfloat matAmbient[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    GLfloat matDiffuse[] = { 0.0f, 0.5f, 0.0f, 1.0f };
    GLfloat matSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat matShininess[] = { 0.0f };
	

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
    GLfloat floorColor[] = { 0.0f, 0.5f, 0.0f, 1.0f }; 
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, floorColor);
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -1.0f, -10.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, -1.0f, -10.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, -1.0f, 10.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f, -1.0f, 10.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}


void Engine3D::timer(int) {
    glutPostRedisplay();
    sphere.autoRotate();
    cone.autoRotate();
    cube.sideToSide();
    glutTimerFunc(1000 / instance->fps, timer, 0);
};





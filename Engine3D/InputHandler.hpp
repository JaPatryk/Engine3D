#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <GL/freeglut.h>

class InputHandler {
public:

    static void moveInDirection(int key, float& cameraPosX, float& cameraPosZ, float& cameraAngleY);

    static void rotateCamera(int key, float& cameraAngleX, float& cameraAngleY);
};

#endif // INPUT_HANDLER_HPP

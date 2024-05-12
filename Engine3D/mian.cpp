#include "Engine3D.hpp"
#include <GL/freeglut.h>

int main(int argc, char** argv) {
    Engine3D engine("Moja aplikacja 3D", 800, 600);
    engine.run();

    return 0;
}
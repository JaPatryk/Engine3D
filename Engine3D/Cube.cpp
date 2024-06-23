#include "Cube.hpp"
#include <GL/freeglut.h>
#include "stb_image.h"
#include <iostream>
Cube::Cube(float size, float x, float y, float z) : Primitives(x, y, z, r, g, b), m_size(size) {}


void Cube::draw() {

    glPushMatrix();
    glTranslatef(m_x, m_y, m_z);

    if (rotateX != 0.0f) {
        glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    }
    if (rotateY != 0.0f) {
        glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    }
    if (rotateZ != 0.0f) {
        glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    }

    GLfloat matAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat matSpecular[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    GLfloat matShininess[] = { 10.0f };
    GLfloat matDiffuse[] = { r, g, b, 1.0f };

    glColor3f(r, g, b);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
    if (outline) {
        glutWireCube(m_size);
    }
    else {
        if (this->texturePath) {
            static bool textureLoaded = false;
            static GLuint textureID;

            if (!textureLoaded) {
                int width, height, channels;
                unsigned char* image = stbi_load(this->texturePath, &width, &height, &channels, STBI_rgb);

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
           
            
            GLfloat vertices[] = {
                // Front
                -0.5 * this->m_size + this->m_x, -0.5 * this->m_size + this->m_y,  0.5 * this->m_size + this->m_z,
                 0.5 * this->m_size + this->m_x, -0.5 * this->m_size + this->m_y,  0.5 * this->m_size + this->m_z,
                 0.5 * this->m_size + this->m_x,  0.5 * this->m_size + this->m_y,  0.5 * this->m_size + this->m_z,
                -0.5 * this->m_size + this->m_x,  0.5 * this->m_size + this->m_y,  0.5 * this->m_size + this->m_z,
                // Back
                -0.5 * this->m_size + this->m_x, -0.5 * this->m_size + this->m_y, -0.5 * this->m_size + this->m_z,
                 0.5 * this->m_size + this->m_x, -0.5 * this->m_size + this->m_y, -0.5 * this->m_size + this->m_z,
                 0.5 * this->m_size + this->m_x,  0.5 * this->m_size + this->m_y, -0.5 * this->m_size + this->m_z,
                -0.5 * this->m_size + this->m_x,  0.5 * this->m_size + this->m_y, -0.5 * this->m_size + this->m_z
            };

            GLfloat texCoords[] = {
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,

                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,
                0.0, 0.0
            };

            GLuint indices[] = {
                // Front
                0, 1, 2,
                2, 3, 0,
                // Back
                4, 5, 6,
                6, 7, 4,
                // Left
                4, 0, 3,
                3, 7, 4,
                // Right
                1, 5, 6,
                6, 2, 1,
                // Top
                3, 2, 6,
                6, 7, 3,
                // Bottom
                4, 5, 1,
                1, 0, 4
            };


            
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, textureID);
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		else {
			glutSolidCube(m_size);
		}
        }
    glPopMatrix();
}



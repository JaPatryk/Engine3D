#include "Cone.hpp"
#include <GL/freeglut.h>
#include "stb_image.h"
#include <iostream>
#include <cmath>
#include <vector>

Cone::Cone(float r,float h, float x, float y, float z) : Primitives(x, y, z, r, g, b), r(r), h(h) {}

void Cone::draw() {
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
        glutWireCone(1.0, 2.0, slices, stacks);
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
            const float PI = 3.14159265358979f;
            std::vector<GLfloat> vertices((this->slices + 1) * 3 + 3);
            std::vector<GLfloat> texCoords((this->slices + 1) * 2 + 2); 

           
            for (int i = 0; i <= this->slices; ++i) {
                float angle = 2 * PI * i / this->slices;
                vertices[i * 3] = this->r * cos(angle) + this->m_x;
                vertices[i * 3 + 1] = this->m_y;
                vertices[i * 3 + 2] = this->r * sin(angle) + this->m_z;

                texCoords[i * 2] = cos(angle) * 0.5f + 0.5f;
                texCoords[i * 2 + 1] = sin(angle) * 0.5f + 0.5f;
            }

           
            vertices[(this->slices + 1) * 3] = this->m_x;
            vertices[(this->slices + 1) * 3 + 1] = this->m_y + this->h;
            vertices[(this->slices + 1) * 3 + 2] = this->m_z;

            texCoords[(this->slices + 1) * 2] = 0.5f;
            texCoords[(this->slices + 1) * 2 + 1] = 0.5f;

           
            std::vector<GLuint> indices(this->slices * 6); 
            for (int i = 0; i < this->slices; ++i) {
                indices[i * 6] = i;
                indices[i * 6 + 1] = (i + 1) % (int)this->slices;
                indices[i * 6 + 2] = this->slices; 
                indices[i * 6 + 3] = i;
                indices[i * 6 + 4] = this->slices; 
                indices[i * 6 + 5] = (i + 1) % (int)this->slices;
            }

            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glVertexPointer(3, GL_FLOAT, 0, vertices.data());
            glTexCoordPointer(2, GL_FLOAT, 0, texCoords.data());

            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());

            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }else {
            glutSolidCone(1.0, 2.0, slices, stacks);
        }
    }
    glPopMatrix();
}

#include "Sphere.hpp"
#include <GL/freeglut.h>
#include "stb_image.h"
#include <iostream>
#include <cmath>
#include <vector>
Sphere::Sphere(float r, float x, float y, float z) : Primitives(x, y, z, r, g, b,rotate,rotateX,rotateY,rotateZ), r(r) {}

void Sphere::draw() {
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
        glutWireSphere(r,slices,stacks);
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
                    exit(-1); // Mo¿esz obs³u¿yæ b³¹d wczytywania tekstury tutaj
                }

                glGenTextures(1, &textureID);
                glBindTexture(GL_TEXTURE_2D, textureID);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

                stbi_image_free(image);

                // Ustawienie parametrów tekstury
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                textureLoaded = true;
            }
            // Generowanie wierzcho³ków, wspó³rzêdnych tekstur i indeksów trójk¹tów dla sfery
            std::vector<GLfloat> vertices;
            std::vector<GLfloat> texCoords;
            std::vector<GLuint> indices;

            const float PI = 3.14159265358979f;
            const float twoPI = 2.0f * PI;

            // Generowanie wierzcho³ków i wspó³rzêdnych tekstur dla sfery
            for (int i = 0; i <= stacks; ++i) {
                float phi = PI * static_cast<float>(i) / static_cast<float>(stacks);
                float sinPhi = sin(phi);
                float cosPhi = cos(phi);

                for (int j = 0; j <= slices; ++j) {
                    float theta = twoPI * static_cast<float>(j) / static_cast<float>(slices);
                    float sinTheta = sin(theta);
                    float cosTheta = cos(theta);

                    float x = cosTheta * sinPhi;
                    float y = cosPhi;
                    float z = sinTheta * sinPhi;

                    vertices.push_back(this->r * x + this->m_x);
                    vertices.push_back(this->r * y + this->m_y);
                    vertices.push_back(this->r * z + this->m_z);

                    texCoords.push_back(static_cast<float>(j) / static_cast<float>(slices));
                    texCoords.push_back(static_cast<float>(i) / static_cast<float>(stacks));
                }
            }

            // Generowanie indeksów trójk¹tów dla sfery
            for (int i = 0; i < stacks; ++i) {
                for (int j = 0; j < slices; ++j) {
                    int first = (i * (slices + 1)) + j;
                    int second = first + slices + 1;

                    indices.push_back(first);
                    indices.push_back(second);
                    indices.push_back(first + 1);

                    indices.push_back(second);
                    indices.push_back(second + 1);
                    indices.push_back(first + 1);
                }
            }

            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glVertexPointer(3, GL_FLOAT, 0, vertices.data());
            glTexCoordPointer(2, GL_FLOAT, 0, texCoords.data());

            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());

            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }
        else {
            glutSolidSphere(r, slices, stacks);
        }
    }
    glPopMatrix();
}

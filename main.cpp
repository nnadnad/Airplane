#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include "2.1.0_1/include/GL/glew.h"
#include <GLUT/glut.h>

#else
#include "2.1.0_1/include/GL/glew.h"
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "Camera.h"
#include "glm/glm/glm.hpp"
#include "3.3.2/include/GLFW/glfw3.h"

const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

static float rotateXZ = 0.0;
static float rotateXY = 0.0;
static float zoom = 0.0;

static float posX = 0.0;
static float posY = 0.0;
static float posZ = 0.0; //radius;

static float viewX = 0.0;
static float viewY = 0.0;
static float viewZ = 0.0;

static float upX = 0.0;
static float upY = 1.0;
static float upZ = 0.0;

// Camera
Camera  camera(glm::vec3( 0.0f, 0.0f, 3.0f ) );
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

static void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.5f);

    // Create camera transformation
    glm::mat4 view;
    view = camera.GetViewMatrix( );

    // gluLookAt(posX, posY, posZ,
    //           viewX + cos(rotateXZ * M_PI / 180), viewY, viewZ + sin(rotateXZ * M_PI / 180),
    //           upX + cos(rotateXY * M_PI / 180), upY + sin(rotateXY * M_PI / 180), upZ);

    glScalef(1.0 + zoom, 1.0 + zoom, 1.0 + zoom);

    //body pesawat di koordinat 0 Z
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex3f( 1.0, 0.2, 0);
    glVertex3f( 1.0, -0.2, 0);
    glVertex3f( 0.9, -0.25, 0);
    glVertex3f( 0.6, -0.3, 0);
    glVertex3f( -0.8, -0.35, 0);
    glVertex3f( -0.9, -0.25, 0);
    glEnd();

    //body pesawat di koordinat -0.2 Z
    glBegin(GL_POLYGON);
    glColor3f(0,100,0);
    glVertex3f( 1.0, 0.2, -0.2);
    glVertex3f( 1.0, -0.2, -0.2);
    glVertex3f( 0.9, -0.25, -0.2);
    glVertex3f( 0.6, -0.3, -0.2);
    glVertex3f( -0.8, -0.35, -0.2);
    glVertex3f( -0.9, -0.25, -0.2);
    glEnd();

    //body pesawat penampang baling2
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f( 1.0, 0.2, 0);
    glVertex3f( 1.0, 0.2, -0.2);
    glVertex3f( 1.0, -0.2, -0.2);
    glVertex3f( 1.0, -0.2, 0);
    glEnd();

    //body pesawat bagian atas
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( 1.0, 0.2, 0);
    glVertex3f( 1.0, 0.2, -0.2);
    glVertex3f( -0.9, -0.25, -0.2);
    glVertex3f( -0.9, -0.25, 0);
    glEnd();

    //body pesawat bagian atas belakang
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( -0.9, -0.25, -0.2);
    glVertex3f( -0.9, -0.25, 0);
    glVertex3f( -0.8, -0.35, -0.2);
    glVertex3f( -0.8, -0.35, 0);
    glEnd();

    //body pesawat bagian bawah
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex3f( -0.8, -0.35, -0.2);
    glVertex3f( -0.8, -0.35, 0);
    glVertex3f( 0.6, -0.3, 0);
    glVertex3f( 0.9, -0.25, 0);
    glVertex3f( 1, -0.2, 0);
    glVertex3f( 1, -0.2, -0.2);
    glVertex3f( 0.9, -0.25, -0.2);
    glVertex3f( 0.6, -0.3, -0.2);

    glEnd();

    glFlush();
    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;
        case 'w':
            rotateXY+=10;
            upY = 0;
            break;
        case 's':
            rotateXY-=10;
            upY = 0;
            break;
        case 'a':
            rotateXZ+=10;
            break;
        case 'd':
            rotateXZ-=10;
            break;
        case 'z':
            zoom+=0.1;
            break;
        case 'x':
            zoom-=0.1;
            break;
        case 'r':
            rotateXZ = 0;
            rotateXY = 0;
            zoom = 0;
            upY = 1;
            break;

    }

    glutPostRedisplay();
}

static void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Airplane");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "func.cpp"
#include "model.cpp"
#include "camera.cpp"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialKeys);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
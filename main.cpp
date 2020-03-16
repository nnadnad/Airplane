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

void printHelp()
{
    cout << "      Airplane Model with GLUT OpenGL      " << endl
              << "___________________________________________" << endl
              << "|       |                                 |" << endl
              << "|   q   |   exit                          |" << endl
              << "|   r   |   reset default view            |" << endl
              << "|   w   |   rotate model right (Z-axis)   |" << endl
              << "|   a   |   rotate model left (Y-axis)    |" << endl
              << "|   s   |   rotate model left (Z-axis)    |" << endl
              << "|   d   |   rotate model right (Y-axis)   |" << endl
              << "|   z   |   zoom in                       |" << endl
              << "|   x   |   zoom out                      |" << endl
              << "|   ↑   |   move camera closer            |" << endl
              << "|   ←   |   move camera left              |" << endl
              << "|   ↓   |   move camera away              |" << endl
              << "|   →   |   move camera right             |" << endl
              << "|_______|_________________________________|" << endl
              << endl;
}

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        if (argv[1] == "-h" || argv[1] == "--help")
        {
            printHelp()
        } else {
            cout << "Unknown arguments detected" << endl
        }
    } else {
        glutInit(&argc, argv);
        init();
        glutDisplayFunc(display);
        glutReshapeFunc(resize);
        glutKeyboardFunc(key);
        glutSpecialFunc(specialKeys);
        glutIdleFunc(idle);
        glutMainLoop();
    }

    return 0;
}
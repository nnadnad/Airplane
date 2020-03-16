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
    std::cout << "      Airplane Model with GLUT OpenGL      " << std::endl
              << "___________________________________________" << std::endl
              << "|       |                                 |" << std::endl
              << "|   q   |   exit                          |" << std::endl
              << "|   r   |   reset default view            |" << std::endl
              << "|   w   |   rotate model right (Z-axis)   |" << std::endl
              << "|   a   |   rotate model left (Y-axis)    |" << std::endl
              << "|   s   |   rotate model left (Z-axis)    |" << std::endl
              << "|   d   |   rotate model right (Y-axis)   |" << std::endl
              << "|   z   |   zoom in                       |" << std::endl
              << "|   x   |   zoom out                      |" << std::endl
              << "|   ↑   |   move camera closer            |" << std::endl
              << "|   ←   |   move camera left              |" << std::endl
              << "|   ↓   |   move camera away              |" << std::endl
              << "|   →   |   move camera right             |" << std::endl
              << "|_______|_________________________________|" << std::endl
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        if (argv[1] == "-h" || argv[1] == "--help")
        {
            printHelp()
        } else {
            std::cout << "Unknown arguments detected" << std::endl
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
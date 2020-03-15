#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

    gluLookAt(posX, posY, posZ,
              viewX + cos(rotateXZ * M_PI / 180), viewY, viewZ + sin(rotateXZ * M_PI / 180),
              upX + cos(rotateXY * M_PI / 180), upY + sin(rotateXY * M_PI / 180), upZ);

    glScalef(1.0 + zoom, 1.0 + zoom, 1.0 + zoom);


    /*sayap bawah*/

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, -0.3, 0);
    glVertex3f( 0.3, -0.31, 0);
    glVertex3f( 0.3, -0.31, 1);
    glVertex3f( 0.6, -0.3, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, -0.27, 0);
    glVertex3f( 0.3, -0.29, 0);
    glVertex3f( 0.3, -0.31, 1);
    glVertex3f( 0.6, -0.3, 1);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, -0.3,-0.2);
    glVertex3f( 0.3, -0.31, -0.2);
    glVertex3f( 0.3, -0.31, -1.2);
    glVertex3f( 0.6, -0.3, -1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, -0.27, -0.2);
    glVertex3f( 0.3, -0.29, -0.2);
    glVertex3f( 0.3, -0.31, -1.2);
    glVertex3f( 0.6, -0.3, -1.2);

    glEnd();

    /*sayap atas*/

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, 0.3, 0);
    glVertex3f( 0.3, 0.29, 0);
    glVertex3f( 0.3, 0.29, 1);
    glVertex3f( 0.6, 0.3, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, 0.33, 0);
    glVertex3f( 0.3, 0.29, 0);
    glVertex3f( 0.3, 0.29, 1);
    glVertex3f( 0.6, 0.30, 1);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, 0.3,-0.2);
    glVertex3f( 0.3, 0.29, -0.2);
    glVertex3f( 0.3, 0.29, -1.2);
    glVertex3f( 0.6, 0.3, -1.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, 0.33, -0.2);
    glVertex3f( 0.3, 0.29, -0.2);
    glVertex3f( 0.3, 0.31, -1.2);
    glVertex3f( 0.6, 0.3, -1.2);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f( 0.6, 0.33, -0.2);
    glVertex3f( 0.3, 0.29, -0.2);
    glVertex3f( 0.3, 0.29, 0);
    glVertex3f( 0.6, 0.33, 0);

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
//        case 'z':
  //          zoom+=0.1;
    //        break;
      //  case 'x':
        //    zoom-=0.1;
          //  break;
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

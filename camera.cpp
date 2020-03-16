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
            viewX = 0;
            viewZ = 0;
            posX = 0;
            posZ = 0;
            zoom = 0;
            upY = 1;
            break;
    }
    glutPostRedisplay();
}

static void specialKeys(int key, int xx, int yy)
{
    float fraction = 0.1f;

    switch (key)
    {
        case GLUT_KEY_LEFT:
            angle -= 0.01f;
            viewX = sin(angle);
            viewZ = -cos(angle);
            break;
        case GLUT_KEY_RIGHT:
            angle += 0.01f;
            viewX = sin(angle);
            viewZ = -cos(angle);
            break;
        case GLUT_KEY_UP:
            posX += viewX * fraction;
            posZ += viewZ * fraction;
            break;
        case GLUT_KEY_DOWN:
            posX -= viewX * fraction;
            posZ -= viewZ * fraction;
            break;
    }
}

static void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

static void idle(void)
{
    glutPostRedisplay();
}
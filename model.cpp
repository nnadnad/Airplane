static float rotateXZ = 0.0;
static float rotateXY = 0.0;
static float zoom = 0.0;

static float posX = 0.0f;
static float posY = 0.0f;
static float posZ = 0.0f; //radius;

static float viewX = 0.0f;
static float viewY = 0.0f;
static float viewZ = 0.0f;

static float upX = 0.0f;
static float upY = 1.0f;
static float upZ = 0.0f;

// angle of rotation for the camera direction
float angle = 0.0;


static void display(void)
{
    glClear(GL_glColor3f_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.5f);

    gluLookAt(posX, posY, posZ,
              viewX + cos(rotateXZ * M_PI / 180), viewY, viewZ + sin(rotateXZ * M_PI / 180),
              upX + cos(rotateXY * M_PI / 180), upY + sin(rotateXY * M_PI / 180), upZ);

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
    glColor3f(0.0,1.0,1.0);
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

    //ekor vertikal pesawat
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    glVertex3f(-1.2, 0.1, -0.2);
    glVertex3f(-1.2, 0.1, 0);
    glVertex3f(-0.8, -0.35, 0);
    glVertex3f(-0.8, -0.35, -0.2);
    glEnd();

    //ekor horizontal pesawat
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 1);
    glVertex3f(-1.2, -0.02, -0.4);
    glVertex3f(-1.2, -0.02, 0.2);
    glVertex3f(-1.2, -0.07, 0.2);
    glVertex3f(-1.2, -0.07, -0.4);
    glVertex3f(-0.8, -0.07, -0.4);
    glVertex3f(-0.8, -0.07, 0.2);
    glVertex3f(-0.8, -0.02, 0.2);
    glVertex3f(-0.8, -0.02, -0.4);
    glVertex3f(-1.2, -0.02, -0.4);
    glVertex3f(-1.2, -0.02, 0.2);
    glEnd();

    //sayap atas horizontal pesawat
    glBegin(GL_POLYGON);
    glColor3f(0.5, 1, 1);
    glVertex3f(0.5, 0.3, -1.2);
    glVertex3f(0.5, 0.3, 1.0);
    glVertex3f(0.5, 0.2, 1.0);
    glVertex3f(0.5, 0.2, -1.2);
    glVertex3f(0.2, 0.2, -1.2);
    glVertex3f(0.2, 0.2, 1.0);
    glVertex3f(0.5, 0.2, 1.0);
    glVertex3f(0.5, 0.3, 1.0);
    glVertex3f(0.2, 0.3, 1.0);
    glVertex3f(0.2, 0.3, -1.2);
    glEnd();

    //sayap kanan bawah horizontal pesawat
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 1);
    glVertex3f(0.5, -0.25, 0);
    glVertex3f(0.5, -0.25, 1.0);
    glVertex3f(0.5, -0.30, 1.0);
    glVertex3f(0.5, -0.30, 0);
    glVertex3f(0.2, -0.30, 0);
    glVertex3f(0.2, -0.30, 1.0);
    glVertex3f(0.5, -0.30, 1.0);
    glVertex3f(0.5, -0.25, 1.0);
    glVertex3f(0.2, -0.25, 1.0);
    glVertex3f(0.2, -0.25, 0);
    glEnd();

    //sayap kiri bawah horizontal pesawat
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0.5);
    glVertex3f(0.5, -0.25, -1.2);
    glVertex3f(0.5, -0.25, -0.2);
    glVertex3f(0.5, -0.30, -0.2);
    glVertex3f(0.5, -0.30, -1.2);
    glVertex3f(0.2, -0.30, -1.2);
    glVertex3f(0.2, -0.30, -0.2);
    glVertex3f(0.5, -0.30, -0.2);
    glVertex3f(0.5, -0.25, -0.2);
    glVertex3f(0.2, -0.25, -0.2);
    glVertex3f(0.2, -0.25, -1.2);
    glEnd();

    //baling" vertikal
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3,0.3);
    for (int i=0; i < 50; i++) {
        glVertex3f(1+i*0.001, 0.35, -0.080);
        glVertex3f(1+i*0.001, 0.35, -0.130);
        glVertex3f(1+i*0.001, -0.35, -0.080);
        glVertex3f(1+i*0.001, -0.35, -0.130);
    }
    glEnd();

    //baling" horizontal
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3,0.3);
    for (int i=0; i < 50; i++) {
        glVertex3f(1+i*0.001, 0.025, 0.30);
        glVertex3f(1+i*0.001, 0.025, -0.50);
        glVertex3f(1+i*0.001, -0.025, -0.50);
        glVertex3f(1+i*0.001, -0.025, 0.30);
    }
    glEnd();

    // roda
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    for (int j = 0; j < 50; j++){
        for (int i=0; i < 359; i++)
       {
          float degInRad = i*3.14/180;
          glVertex3f((cos(degInRad)*0.09)+0.45,(sin(degInRad)*0.09)-0.5,0.2+j*0.002);
       }
    }

   glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    for (int j = 0; j < 50; j++){
        for (int i=0; i < 359; i++)
       {
          float degInRad = i*3.14/180;
          glVertex3f((cos(degInRad)*0.09)+0.45,(sin(degInRad)*0.09)-0.5,-0.4-j*0.002);
       }
    }
    glEnd();

   //Sambungan roda
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(0.6,-0.3,0);
    glVertex3f(0.575,-0.3,0);
    glVertex3f(0.475,-0.5,0.2);
    glVertex3f(0.45,-0.5,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(0.3,-0.3,0);
    glVertex3f(0.325,-0.3,0);
    glVertex3f(0.475,-0.5,0.2);
    glVertex3f(0.45,-0.5,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(0.3,-0.3,-0.2);
    glVertex3f(0.325,-0.3,-0.2);
    glVertex3f(0.475,-0.5,-0.4);
    glVertex3f(0.45,-0.5,-0.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.3,0.3);
    glVertex3f(0.6,-0.3,-0.2);
    glVertex3f(0.575,-0.3,-0.2);
    glVertex3f(0.475,-0.5,-0.4);
    glVertex3f(0.45,-0.5,-0.4);
    glEnd();



    glFlush();
    glutSwapBuffers();
}
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.5f);

    gluLookAt(posX, posY, posZ,
              viewX + cos(rotateXZ * M_PI / 180), viewY, viewZ + sin(rotateXZ * M_PI / 180),
              upX + cos(rotateXY * M_PI / 180), upY + sin(rotateXY * M_PI / 180), upZ);

    glScalef(1.0 + zoom, 1.0 + zoom, 1.0 + zoom);

    ifstream file("model.txt");
    string temp;
    float arrValue[3];
    while(file >> temp) {
        if(temp=="#begin"){
            glBegin(GL_POLYGON);
        }
        else if(temp=="#color"){            
            for(int i=0;i<3;i++){
                
                file>>temp;
                if(i!=2){
                    temp=temp.substr(0,temp.length()-1);
                }
                arrValue[i]=stof(temp);
            }
            glColor3f(arrValue[0],arrValue[1],arrValue[2]);
        }
        else if(temp=="#vertex"){
            for(int i=0;i<3;i++){
                file>>temp;
                if(i!=2){
                    temp=temp.substr(0,temp.length()-1);
                }
                arrValue[i]=stof(temp);
            }
            glVertex3f(arrValue[0],arrValue[1],arrValue[2]);

        }
        else if(temp=="#end"){
            glEnd();
        }
    }


    glFlush();
    glutSwapBuffers();
}
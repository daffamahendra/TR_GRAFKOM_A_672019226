#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float xrot = 0;
float zrot = 0;
float xdiff = 0;
float zdiff = 0;
bool mousedown = false;
int is_depth;

void mouseMove(int x, int z) {
    if (mousedown) {
        zrot = x - xdiff;
        xrot = z + zdiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int z) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - zrot;
        zdiff = -z + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.4, 0.4, 0.4, 0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}


void home()
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(zrot, 0, 0, 1);
    //========================================lantai 1=============================================

    //AlasSeluruh
    glBegin(GL_QUADS);
    glColor3f(0, 0.9, 0);
    glVertex3f(-48, -50, 0);
    glVertex3f(-15, -50, 0);
    glVertex3f(-15, 50, 0);
    glVertex3f(-48, 50, 0);
    glEnd();

    //Alas1
    glBegin(GL_QUADS);
    glColor3f(0, 0.9, 0);
    glVertex3f(48, -50, 0);
    glVertex3f(78, -50, 0);
    glVertex3f(78, 50, 0);
    glVertex3f(48, 50, 0);
    glEnd();

    //Alas2
    glBegin(GL_QUADS);
    glColor3f(0, 0.9, 0);
    glVertex3f(-15, -50, 0);
    glVertex3f(48, -50, 0);
    glVertex3f(48, -30, 0);
    glVertex3f(-15, -30, 0);
    glEnd();

    //Alas3
    glBegin(GL_QUADS);
    glColor3f(0, 0.9, 0);
    glVertex3f(-15, 20, 0);
    glVertex3f(48, 20, 0);
    glVertex3f(48, 50, 0);
    glVertex3f(-15, 50, 0);
    glEnd();

    //Alas4
    glBegin(GL_QUADS);
    glColor3f(0, 0.9, 0);
    glVertex3f(15, 20, 0);
    glVertex3f(18, 20, 0);
    glVertex3f(18, -30, 0);
    glVertex3f(15, -30, 0);
    glEnd();

    //bwh alas
    glBegin(GL_QUADS);
    glColor3f(0.97, 1, 0.89);
    glVertex3f(-15, 20, 0);//a
    glVertex3f(-15, -30, 0); //b
    glVertex3f(15, -30, 0);//c
    glVertex3f(15, 20, 0);//d
    glEnd();

    glBegin(GL_QUADS); //kiri
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-15, 20, 10);//g
    glVertex3f(-15, 0, 10); //i
    glVertex3f(-15, 0, 0);//e
    glVertex3f(-15, 20, 0);//a
    glEnd();

    glBegin(GL_QUADS); //knan
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(15, 0, 10);//j
    glVertex3f(15, 20, 10); //h
    glVertex3f(15, 20, 0);//d
    glVertex3f(15, 0, 0);//f
    glEnd();

    //dinding depan kiri
    glBegin(GL_QUADS); //dpn
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-15, 0, 10);//i
    glVertex3f(-7, 0, 10); //j
    glVertex3f(-7, 0, 0);//f
    glVertex3f(-15, 0, 0);//e
    glEnd();

    //dinding depan kanan
    glBegin(GL_QUADS); //dpn
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(7, 0, 10);//i
    glVertex3f(15, 0, 10); //j
    glVertex3f(15, 0, 0);//f
    glVertex3f(7, 0, 0);//e
    glEnd();

    //dinding depan atas pintu
    glBegin(GL_QUADS); //dpn
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(7, 0, 10);
    glVertex3f(-7, 0, 10);
    glVertex3f(-7, 0, 7);
    glVertex3f(7, 0, 7);
    glEnd();

    //pintu masuk
    glBegin(GL_QUADS); //dpn
    glColor4f(0.0, 0.0, 0.0, 0.5);
    glVertex3f(7, 0, 7);
    glVertex3f(-7, 0, 7);
    glVertex3f(-7, 0, 0);
    glVertex3f(7, 0, 0);
    glEnd();

    glBegin(GL_QUADS); //blkg
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-15, 20, 10);//g
    glVertex3f(15, 20, 10); //h
    glVertex3f(15, 20, 0);//d
    glVertex3f(-15, 20, 0);//a
    glEnd();

    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 10);//i
    glVertex3f(-15, 20, 10);//g
    glVertex3f(15, 20, 10); //h
    glVertex3f(15, 0, 10);//j
    glEnd();

    //PilarKiri1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -30, 0);
    glVertex3f(-11, -30, 0);
    glVertex3f(-11, -30, 10);
    glVertex3f(-15, -30, 10);
    glEnd();

    //PilarKiri2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -26, 0);
    glVertex3f(-11, -26, 0);
    glVertex3f(-11, -26, 10);
    glVertex3f(-15, -26, 10);
    glEnd();

    //PilarKiri3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -30, 0);
    glVertex3f(-15, -26, 0);
    glVertex3f(-15, -26, 10);
    glVertex3f(-15, -30, 10);
    glEnd();

    //PilarKiri4
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-11, -30, 0);
    glVertex3f(-11, -26, 0);
    glVertex3f(-11, -26, 10);
    glVertex3f(-11, -30, 10);
    glEnd();

    //PilarKanan1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(11, -30, 0);
    glVertex3f(15, -30, 0);
    glVertex3f(15, -30, 10);
    glVertex3f(11, -30, 10);
    glEnd();

    //PilarKiri2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(11, -26, 0);
    glVertex3f(15, -26, 0);
    glVertex3f(15, -26, 10);
    glVertex3f(11, -26, 10);
    glEnd();

    //PilarKiri3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(11, -30, 0);
    glVertex3f(11, -26, 0);
    glVertex3f(11, -26, 10);
    glVertex3f(11, -30, 10);
    glEnd();

    //PilarKiri4
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(15, -30, 0);
    glVertex3f(15, -26, 0);
    glVertex3f(15, -26, 10);
    glVertex3f(15, -30, 10);
    glEnd();

    //Atap Pilar 1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -30, 10);
    glVertex3f(15, -30, 10);
    glVertex3f(15, 0, 10);
    glVertex3f(-15, 0, 10);
    glEnd();

    //Atap Pilar 2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -30, 11);
    glVertex3f(15, -30, 11);
    glVertex3f(15, 0, 11);
    glVertex3f(-15, 0, 11);
    glEnd();

    //Atap Pilar 3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -30, 10);
    glVertex3f(-15, 0, 10);
    glVertex3f(-15, 0, 11);
    glVertex3f(-15, -30, 11);
    glEnd();

    //Atap Pilar 4
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(15, -30, 10);
    glVertex3f(15, 0, 10);
    glVertex3f(15, 0, 11);
    glVertex3f(15, -30, 11);
    glEnd();

    //Atap Pilar 5
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15, -30, 10);
    glVertex3f(15, -30, 10);
    glVertex3f(15, -30, 11);
    glVertex3f(-15, -30, 11);
    glEnd();

    //=====================================lantai 2=======================================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 20);
    glVertex3f(-15, 20, 20);
    glVertex3f(15, 20, 20);
    glVertex3f(15, 0, 20);
    glEnd();

    //belakang bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 11);
    glVertex3f(15, 20, 11);
    glVertex3f(15, 20, 10);
    glVertex3f(-15, 20, 10);
    glEnd();

    glBegin(GL_QUADS); //kursi
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 11, 15);
    glVertex3f(-2, 13, 15);
    glVertex3f(-2, 13, 12);
    glVertex3f(-2, 11, 12);
    glEnd();

    glBegin(GL_QUADS); //tmpt duduk
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 13, 12);
    glVertex3f(-2, 11, 12);
    glVertex3f(-4, 11, 12);
    glVertex3f(-4, 13, 12);
    glEnd();

    glBegin(GL_LINES); //kaki 1
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-4, 13, 12);
    glVertex3f(-4, 13, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 2
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-4, 11, 12);
    glVertex3f(-4, 11, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 3
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 11, 12);
    glVertex3f(-2, 11, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 4
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 13, 12);
    glVertex3f(-2, 13, 10);
    glEnd();

    glBegin(GL_QUADS); //kursi 2
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 8, 15);
    glVertex3f(-2, 10, 15);
    glVertex3f(-2, 10, 12);
    glVertex3f(-2, 8, 12);
    glEnd();


    glBegin(GL_QUADS); //tmpt duduk 2
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 10, 12);
    glVertex3f(-2, 8, 12);
    glVertex3f(-4, 8, 12);
    glVertex3f(-4, 10, 12);
    glEnd();

    glBegin(GL_LINES); //kaki 1
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-4, 10, 12);
    glVertex3f(-4, 10, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 2
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-4, 8, 12);
    glVertex3f(-4, 8, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 3
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 8, 12);
    glVertex3f(-2, 8, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 4
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 10, 12);
    glVertex3f(-2, 10, 10);
    glEnd();


    glBegin(GL_QUADS); //kursi 3
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 15, 15);
    glVertex3f(-2, 17, 15);
    glVertex3f(-2, 17, 12);
    glVertex3f(-2, 15, 12);
    glEnd();

    glBegin(GL_QUADS); //tmpt duduk
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 17, 12);
    glVertex3f(-2, 15, 12);
    glVertex3f(-4, 15, 12);
    glVertex3f(-4, 17, 12);
    glEnd();

    glBegin(GL_LINES); //kaki 1
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-4, 17, 12);
    glVertex3f(-4, 17, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 2
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-4, 15, 12);
    glVertex3f(-4, 15, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 3
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 15, 12);
    glVertex3f(-2, 15, 10);
    glEnd();

    glBegin(GL_LINES); //kaki 4
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-2, 17, 12);
    glVertex3f(-2, 17, 10);
    glEnd();

    glBegin(GL_QUADS); //meja
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-12, 9, 14);
    glVertex3f(-12, 15, 14);
    glVertex3f(-8, 15, 14);
    glVertex3f(-8, 9, 14);
    glEnd();


    glBegin(GL_QUADS); //kaki meja knan
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-8, 15, 14);
    glVertex3f(-12, 15, 14);
    glVertex3f(-12, 15, 10);
    glVertex3f(-8, 15, 10);
    glEnd();

    glBegin(GL_QUADS); //kaki meja kiri
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-8, 9, 14);
    glVertex3f(-8, 9, 10);
    glVertex3f(-13, 9, 10);
    glVertex3f(-13, 9, 14);
    glEnd();

    glBegin(GL_QUADS); //papan
    glColor3f(1, 1, 1);
    glVertex3f(-14, 17, 18);
    glVertex3f(-14, 3, 18);
    glVertex3f(-14, 3, 12);
    glVertex3f(-14, 17, 12);
    glEnd();


    glBegin(GL_QUADS); //papan 3d dpn
    glColor3f(1, 1, 1);
    glVertex3f(-13.5, 3, 18);
    glVertex3f(-13.5, 17, 18);
    glVertex3f(-13.5, 17, 12);
    glVertex3f(-13.5, 3, 12);
    glEnd();

    glBegin(GL_QUADS); //papan 3d knan
    glColor3f(1, 1, 1);
    glVertex3f(-14, 3, 18);
    glVertex3f(-13.5, 3, 18);
    glVertex3f(-13.5, 3, 12);
    glVertex3f(-14, 3, 12);
    glEnd();

    glBegin(GL_QUADS); //papan 3d kiri
    glColor3f(1, 1, 1);
    glVertex3f(-14, 17, 18);
    glVertex3f(-13.5, 17, 18);
    glVertex3f(-13.5, 17, 12);
    glVertex3f(-14, 17, 12);
    glEnd();

    glBegin(GL_QUADS); //kaki papan
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-14, 17, 12);
    glVertex3f(-14, 16.5, 12);
    glVertex3f(-14, 16.5, 10);
    glVertex3f(-14, 17, 10);
    glEnd();

    glBegin(GL_QUADS); //kaki 3d papan
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-14, 3, 12);
    glVertex3f(-13.5, 3, 12);
    glVertex3f(-13.5, 3, 10);
    glVertex3f(-14, 3, 10);
    glEnd();

    glBegin(GL_QUADS); //kaki papan 2
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-14, 3.5, 12);
    glVertex3f(-14, 3, 12);
    glVertex3f(-14, 3, 10);
    glVertex3f(-14, 3.5, 10);
    glEnd();

    glBegin(GL_QUADS); //kaki 3d papan
    glColor3f(0.23, 0.14, 0.02);
    glVertex3f(-13.5, 17, 12);
    glVertex3f(-14, 17, 12);
    glVertex3f(-14, 17, 10);
    glVertex3f(-13.5, 17, 10);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 18);
    glVertex3f(-15, 20, 18);
    glVertex3f(-15, 20, 11);
    glVertex3f(-10, 20, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 18);
    glVertex3f(-15, 20, 18);
    glVertex3f(-15, 20, 11);
    glVertex3f(-10, 20, 11);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 18);
    glVertex3f(-10, 20, 18);
    glVertex3f(-10, 20, 11);
    glVertex3f(-5, 20, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 18);
    glVertex3f(-10, 20, 18);
    glVertex3f(-10, 20, 11);
    glVertex3f(-5, 20, 11);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 18);
    glVertex3f(-5, 20, 18);
    glVertex3f(-5, 20, 11);
    glVertex3f(0, 20, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 18);
    glVertex3f(-5, 20, 18);
    glVertex3f(-5, 20, 11);
    glVertex3f(0, 20, 11);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 18);
    glVertex3f(0, 20, 18);
    glVertex3f(0, 20, 11);
    glVertex3f(5, 20, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 18);
    glVertex3f(0, 20, 18);
    glVertex3f(0, 20, 11);
    glVertex3f(5, 20, 11);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 18);
    glVertex3f(5, 20, 18);
    glVertex3f(5, 20, 11);
    glVertex3f(10, 20, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 18);
    glVertex3f(5, 20, 18);
    glVertex3f(5, 20, 11);
    glVertex3f(10, 20, 11);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 18);
    glVertex3f(10, 20, 18);
    glVertex3f(10, 20, 11);
    glVertex3f(15, 20, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 18);
    glVertex3f(10, 20, 18);
    glVertex3f(10, 20, 11);
    glVertex3f(15, 20, 11);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 20);
    glVertex3f(15, 20, 20);
    glVertex3f(15, 20, 18);
    glVertex3f(-15, 20, 18);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 11);
    glVertex3f(-15, 20, 11);
    glVertex3f(-15, 20, 10);
    glVertex3f(-15, 0, 10);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 18);
    glVertex3f(-15, 5, 18);
    glVertex3f(-15, 5, 11);
    glVertex3f(-15, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 18);
    glVertex3f(-15, 5, 18);
    glVertex3f(-15, 5, 11);
    glVertex3f(-15, 0, 11);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 18);
    glVertex3f(-15, 10, 18);
    glVertex3f(-15, 10, 11);
    glVertex3f(-15, 5, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 18);
    glVertex3f(-15, 10, 18);
    glVertex3f(-15, 10, 11);
    glVertex3f(-15, 5, 11);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 18);
    glVertex3f(-15, 15, 18);
    glVertex3f(-15, 15, 11);
    glVertex3f(-15, 10, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 18);
    glVertex3f(-15, 15, 18);
    glVertex3f(-15, 15, 11);
    glVertex3f(-15, 10, 11);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 18);
    glVertex3f(-15, 20, 18);
    glVertex3f(-15, 20, 11);
    glVertex3f(-15, 15, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 18);
    glVertex3f(-15, 20, 18);
    glVertex3f(-15, 20, 11);
    glVertex3f(-15, 15, 11);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 20);
    glVertex3f(-15, 20, 20);
    glVertex3f(-15, 20, 18);
    glVertex3f(-15, 0, 18);
    glEnd();

    //kanan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 11);
    glVertex3f(15, 20, 11);
    glVertex3f(15, 20, 10);
    glVertex3f(15, 0, 10);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 18);
    glVertex3f(15, 5, 18);
    glVertex3f(15, 5, 11);
    glVertex3f(15, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 18);
    glVertex3f(15, 5, 18);
    glVertex3f(15, 5, 11);
    glVertex3f(15, 0, 11);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 18);
    glVertex3f(15, 10, 18);
    glVertex3f(15, 10, 11);
    glVertex3f(15, 5, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 18);
    glVertex3f(15, 10, 18);
    glVertex3f(15, 10, 11);
    glVertex3f(15, 5, 11);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 18);
    glVertex3f(15, 15, 18);
    glVertex3f(15, 15, 11);
    glVertex3f(15, 10, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 18);
    glVertex3f(15, 15, 18);
    glVertex3f(15, 15, 11);
    glVertex3f(15, 10, 11);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 18);
    glVertex3f(15, 20, 18);
    glVertex3f(15, 20, 11);
    glVertex3f(15, 15, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 18);
    glVertex3f(15, 20, 18);
    glVertex3f(15, 20, 11);
    glVertex3f(15, 15, 11);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 20);
    glVertex3f(15, 20, 20);
    glVertex3f(15, 20, 18);
    glVertex3f(15, 0, 18);
    glEnd();

    //depan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 11);
    glVertex3f(-15, 0, 11);
    glVertex3f(-15, 0, 10);
    glVertex3f(15, 0, 10);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 18);
    glVertex3f(-15, 0, 18);
    glVertex3f(-15, 0, 11);
    glVertex3f(-10, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 18);
    glVertex3f(-15, 0, 18);
    glVertex3f(-15, 0, 11);
    glVertex3f(-10, 0, 11);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 18);
    glVertex3f(-10, 0, 18);
    glVertex3f(-10, 0, 11);
    glVertex3f(-5, 0, 11);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 18);
    glVertex3f(-10, 0, 18);
    glVertex3f(-10, 0, 11);
    glVertex3f(-5, 0, 11);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 18);
    glVertex3f(-5, 0, 18);
    glVertex3f(-5, 0, 11);
    glVertex3f(0, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 18);
    glVertex3f(-5, 0, 18);
    glVertex3f(-5, 0, 11);
    glVertex3f(0, 0, 11);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 18);
    glVertex3f(0, 0, 18);
    glVertex3f(0, 0, 11);
    glVertex3f(5, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 18);
    glVertex3f(0, 0, 18);
    glVertex3f(0, 0, 11);
    glVertex3f(5, 0, 11);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 18);
    glVertex3f(5, 0, 18);
    glVertex3f(5, 0, 11);
    glVertex3f(10, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 18);
    glVertex3f(5, 0, 18);
    glVertex3f(5, 0, 11);
    glVertex3f(10, 0, 11);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 18);
    glVertex3f(10, 0, 18);
    glVertex3f(10, 0, 11);
    glVertex3f(15, 0, 11);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 18);
    glVertex3f(10, 0, 18);
    glVertex3f(10, 0, 11);
    glVertex3f(15, 0, 11);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 20);
    glVertex3f(-15, 0, 20);
    glVertex3f(-15, 0, 18);
    glVertex3f(15, 0, 18);
    glEnd();

    //=========================================lantai 3==========================================

    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 29);
    glVertex3f(-15, 20, 29);
    glVertex3f(15, 20, 29);
    glVertex3f(15, 0, 29);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 28);
    glVertex3f(-15, 20, 28);
    glVertex3f(-15, 20, 20);
    glVertex3f(-10, 20, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 28);
    glVertex3f(-15, 20, 28);
    glVertex3f(-15, 20, 20);
    glVertex3f(-10, 20, 20);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 28);
    glVertex3f(-10, 20, 28);
    glVertex3f(-10, 20, 20);
    glVertex3f(-5, 20, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 28);
    glVertex3f(-10, 20, 28);
    glVertex3f(-10, 20, 20);
    glVertex3f(-5, 20, 20);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 28);
    glVertex3f(-5, 20, 28);
    glVertex3f(-5, 20, 20);
    glVertex3f(0, 20, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 28);
    glVertex3f(-5, 20, 28);
    glVertex3f(-5, 20, 20);
    glVertex3f(0, 20, 20);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 28);
    glVertex3f(0, 20, 28);
    glVertex3f(0, 20, 20);
    glVertex3f(5, 20, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 28);
    glVertex3f(0, 20, 28);
    glVertex3f(0, 20, 20);
    glVertex3f(5, 20, 20);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 28);
    glVertex3f(5, 20, 28);
    glVertex3f(5, 20, 20);
    glVertex3f(10, 20, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 28);
    glVertex3f(5, 20, 28);
    glVertex3f(5, 20, 20);
    glVertex3f(10, 20, 20);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 28);
    glVertex3f(10, 20, 28);
    glVertex3f(10, 20, 20);
    glVertex3f(15, 20, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 28);
    glVertex3f(10, 20, 28);
    glVertex3f(10, 20, 20);
    glVertex3f(15, 20, 20);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 30);
    glVertex3f(15, 20, 30);
    glVertex3f(15, 20, 28);
    glVertex3f(-15, 20, 28);
    glEnd();

    //kiri
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 28);
    glVertex3f(-15, 5, 28);
    glVertex3f(-15, 5, 20);
    glVertex3f(-15, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 28);
    glVertex3f(-15, 5, 28);
    glVertex3f(-15, 5, 20);
    glVertex3f(-15, 0, 20);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 28);
    glVertex3f(-15, 10, 28);
    glVertex3f(-15, 10, 20);
    glVertex3f(-15, 5, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 28);
    glVertex3f(-15, 10, 28);
    glVertex3f(-15, 10, 20);
    glVertex3f(-15, 5, 20);
    glEnd();
    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 28);
    glVertex3f(-15, 15, 28);
    glVertex3f(-15, 15, 20);
    glVertex3f(-15, 10, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 28);
    glVertex3f(-15, 15, 28);
    glVertex3f(-15, 15, 20);
    glVertex3f(-15, 10, 20);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 28);
    glVertex3f(-15, 20, 28);
    glVertex3f(-15, 20, 20);
    glVertex3f(-15, 15, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 28);
    glVertex3f(-15, 20, 28);
    glVertex3f(-15, 20, 20);
    glVertex3f(-15, 15, 20);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 30);
    glVertex3f(-15, 20, 30);
    glVertex3f(-15, 20, 28);
    glVertex3f(-15, 0, 28);
    glEnd();

    //kanan
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 28);
    glVertex3f(15, 5, 28);
    glVertex3f(15, 5, 20);
    glVertex3f(15, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 28);
    glVertex3f(15, 5, 28);
    glVertex3f(15, 5, 20);
    glVertex3f(15, 0, 20);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 28);
    glVertex3f(15, 10, 28);
    glVertex3f(15, 10, 20);
    glVertex3f(15, 5, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 28);
    glVertex3f(15, 10, 28);
    glVertex3f(15, 10, 20);
    glVertex3f(15, 5, 20);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 28);
    glVertex3f(15, 15, 28);
    glVertex3f(15, 15, 20);
    glVertex3f(15, 10, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 28);
    glVertex3f(15, 15, 28);
    glVertex3f(15, 15, 20);
    glVertex3f(15, 10, 20);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 28);
    glVertex3f(15, 20, 28);
    glVertex3f(15, 20, 20);
    glVertex3f(15, 15, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 28);
    glVertex3f(15, 20, 28);
    glVertex3f(15, 20, 20);
    glVertex3f(15, 15, 20);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 30);
    glVertex3f(15, 20, 30);
    glVertex3f(15, 20, 28);
    glVertex3f(15, 0, 28);
    glEnd();

    //depan bwh
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 28);
    glVertex3f(-15, 0, 28);
    glVertex3f(-15, 0, 20);
    glVertex3f(-10, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 28);
    glVertex3f(-15, 0, 28);
    glVertex3f(-15, 0, 20);
    glVertex3f(-10, 0, 20);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 28);
    glVertex3f(-10, 0, 28);
    glVertex3f(-10, 0, 20);
    glVertex3f(-5, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 28);
    glVertex3f(-10, 0, 28);
    glVertex3f(-10, 0, 20);
    glVertex3f(-5, 0, 20);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 28);
    glVertex3f(-5, 0, 28);
    glVertex3f(-5, 0, 20);
    glVertex3f(0, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 28);
    glVertex3f(-5, 0, 28);
    glVertex3f(-5, 0, 20);
    glVertex3f(0, 0, 20);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 28);
    glVertex3f(0, 0, 28);
    glVertex3f(0, 0, 20);
    glVertex3f(5, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 28);
    glVertex3f(0, 0, 28);
    glVertex3f(0, 0, 20);
    glVertex3f(5, 0, 20);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 28);
    glVertex3f(5, 0, 28);
    glVertex3f(5, 0, 20);
    glVertex3f(10, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 28);
    glVertex3f(5, 0, 28);
    glVertex3f(5, 0, 20);
    glVertex3f(10, 0, 20);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 28);
    glVertex3f(10, 0, 28);
    glVertex3f(10, 0, 20);
    glVertex3f(15, 0, 20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 28);
    glVertex3f(10, 0, 28);
    glVertex3f(10, 0, 20);
    glVertex3f(15, 0, 20);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 30);
    glVertex3f(-15, 0, 30);
    glVertex3f(-15, 0, 28);
    glVertex3f(15, 0, 28);
    glEnd();

    //=========================================lantai 4==========================================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 40);
    glVertex3f(-15, 20, 40);
    glVertex3f(15, 20, 40);
    glVertex3f(15, 0, 40);
    glEnd();
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 38);
    glVertex3f(-15, 20, 38);
    glVertex3f(-15, 20, 30);
    glVertex3f(-10, 20, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 38);
    glVertex3f(-15, 20, 38);
    glVertex3f(-15, 20, 30);
    glVertex3f(-10, 20, 30);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 38);
    glVertex3f(-10, 20, 38);
    glVertex3f(-10, 20, 30);
    glVertex3f(-5, 20, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 38);
    glVertex3f(-10, 20, 38);
    glVertex3f(-10, 20, 30);
    glVertex3f(-5, 20, 30);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 38);
    glVertex3f(-5, 20, 38);
    glVertex3f(-5, 20, 30);
    glVertex3f(0, 20, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 38);
    glVertex3f(-5, 20, 38);
    glVertex3f(-5, 20, 30);
    glVertex3f(0, 20, 30);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 38);
    glVertex3f(0, 20, 38);
    glVertex3f(0, 20, 30);
    glVertex3f(5, 20, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 38);
    glVertex3f(0, 20, 38);
    glVertex3f(0, 20, 30);
    glVertex3f(5, 20, 30);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 38);
    glVertex3f(5, 20, 38);
    glVertex3f(5, 20, 30);
    glVertex3f(10, 20, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 38);
    glVertex3f(5, 20, 38);
    glVertex3f(5, 20, 30);
    glVertex3f(10, 20, 30);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 38);
    glVertex3f(10, 20, 38);
    glVertex3f(10, 20, 30);
    glVertex3f(15, 20, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 38);
    glVertex3f(10, 20, 38);
    glVertex3f(10, 20, 30);
    glVertex3f(15, 20, 30);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 40);
    glVertex3f(15, 20, 40);
    glVertex3f(15, 20, 38);
    glVertex3f(-15, 20, 38);
    glEnd();

    //kiri
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 38);
    glVertex3f(-15, 5, 38);
    glVertex3f(-15, 5, 30);
    glVertex3f(-15, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 38);
    glVertex3f(-15, 5, 38);
    glVertex3f(-15, 5, 30);
    glVertex3f(-15, 0, 30);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 38);
    glVertex3f(-15, 10, 38);
    glVertex3f(-15, 10, 30);
    glVertex3f(-15, 5, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 38);
    glVertex3f(-15, 10, 38);
    glVertex3f(-15, 10, 30);
    glVertex3f(-15, 5, 30);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 38);
    glVertex3f(-15, 15, 38);
    glVertex3f(-15, 15, 30);
    glVertex3f(-15, 10, 30);

    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 38);
    glVertex3f(-15, 15, 38);
    glVertex3f(-15, 15, 30);
    glVertex3f(-15, 10, 30);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 38);
    glVertex3f(-15, 20, 38);
    glVertex3f(-15, 20, 30);
    glVertex3f(-15, 15, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 38);
    glVertex3f(-15, 20, 38);
    glVertex3f(-15, 20, 30);
    glVertex3f(-15, 15, 30);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 40);
    glVertex3f(-15, 20, 40);
    glVertex3f(-15, 20, 38);
    glVertex3f(-15, 0, 38);
    glEnd();

    //kanan
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 38);
    glVertex3f(15, 5, 38);
    glVertex3f(15, 5, 30);
    glVertex3f(15, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 38);
    glVertex3f(15, 5, 38);
    glVertex3f(15, 5, 30);
    glVertex3f(15, 0, 30);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 38);
    glVertex3f(15, 10, 38);
    glVertex3f(15, 10, 30);
    glVertex3f(15, 5, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 38);
    glVertex3f(15, 10, 38);
    glVertex3f(15, 10, 30);
    glVertex3f(15, 5, 30);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 38);
    glVertex3f(15, 15, 38);
    glVertex3f(15, 15, 30);
    glVertex3f(15, 10, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 38);
    glVertex3f(15, 15, 38);
    glVertex3f(15, 15, 30);
    glVertex3f(15, 10, 30);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 38);
    glVertex3f(15, 20, 38);
    glVertex3f(15, 20, 30);
    glVertex3f(15, 15, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 38);
    glVertex3f(15, 20, 38);
    glVertex3f(15, 20, 30);
    glVertex3f(15, 15, 30);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 40);
    glVertex3f(15, 20, 40);
    glVertex3f(15, 20, 38);
    glVertex3f(15, 0, 38);
    glEnd();

    //depan
    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 38);
    glVertex3f(-15, 0, 38);
    glVertex3f(-15, 0, 30);
    glVertex3f(-10, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 38);
    glVertex3f(-15, 0, 38);
    glVertex3f(-15, 0, 30);
    glVertex3f(-10, 0, 30);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 38);
    glVertex3f(-10, 0, 38);
    glVertex3f(-10, 0, 30);
    glVertex3f(-5, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 38);
    glVertex3f(-10, 0, 38);
    glVertex3f(-10, 0, 30);
    glVertex3f(-5, 0, 30);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 38);
    glVertex3f(-5, 0, 38);
    glVertex3f(-5, 0, 30);
    glVertex3f(0, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 38);
    glVertex3f(-5, 0, 38);
    glVertex3f(-5, 0, 30);
    glVertex3f(0, 0, 30);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 38);
    glVertex3f(0, 0, 38);
    glVertex3f(0, 0, 30);
    glVertex3f(5, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 38);
    glVertex3f(0, 0, 38);
    glVertex3f(0, 0, 30);
    glVertex3f(5, 0, 30);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 38);
    glVertex3f(5, 0, 38);
    glVertex3f(5, 0, 30);
    glVertex3f(10, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 38);
    glVertex3f(5, 0, 38);
    glVertex3f(5, 0, 30);
    glVertex3f(10, 0, 30);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 38);
    glVertex3f(10, 0, 38);
    glVertex3f(10, 0, 30);
    glVertex3f(15, 0, 30);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 38);
    glVertex3f(10, 0, 38);
    glVertex3f(10, 0, 30);
    glVertex3f(15, 0, 30);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 40);
    glVertex3f(-15, 0, 40);
    glVertex3f(-15, 0, 38);
    glVertex3f(15, 0, 38);
    glEnd();


    //=====================================lantai 5=======================================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 50);
    glVertex3f(-15, 20, 50);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    //belakang bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 40);
    glVertex3f(15, 20, 40);
    glVertex3f(15, 20, 40);
    glVertex3f(-15, 20, 40);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 48);
    glVertex3f(-15, 20, 48);
    glVertex3f(-15, 20, 40);
    glVertex3f(-10, 20, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 48);
    glVertex3f(-15, 20, 48);
    glVertex3f(-15, 20, 40);
    glVertex3f(-10, 20, 40);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 48);
    glVertex3f(-10, 20, 48);
    glVertex3f(-10, 20, 40);
    glVertex3f(-5, 20, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 48);
    glVertex3f(-10, 20, 48);
    glVertex3f(-10, 20, 40);
    glVertex3f(-5, 20, 40);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 48);
    glVertex3f(-5, 20, 48);
    glVertex3f(-5, 20, 40);
    glVertex3f(0, 20, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 48);
    glVertex3f(-5, 20, 48);
    glVertex3f(-5, 20, 40);
    glVertex3f(0, 20, 40);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 48);
    glVertex3f(0, 20, 48);
    glVertex3f(0, 20, 40);
    glVertex3f(5, 20, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 48);
    glVertex3f(0, 20, 48);
    glVertex3f(0, 20, 40);
    glVertex3f(5, 20, 40);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 48);
    glVertex3f(5, 20, 48);
    glVertex3f(5, 20, 40);
    glVertex3f(10, 20, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 48);
    glVertex3f(5, 20, 48);
    glVertex3f(5, 20, 40);
    glVertex3f(10, 20, 40);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 48);
    glVertex3f(10, 20, 48);
    glVertex3f(10, 20, 40);
    glVertex3f(15, 20, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 48);
    glVertex3f(10, 20, 48);
    glVertex3f(10, 20, 40);
    glVertex3f(15, 20, 40);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 50);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 20, 48);
    glVertex3f(-15, 20, 48);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 40);
    glVertex3f(-15, 20, 40);
    glVertex3f(-15, 20, 40);
    glVertex3f(-15, 0, 40);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 48);
    glVertex3f(-15, 5, 48);
    glVertex3f(-15, 5, 40);
    glVertex3f(-15, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 48);
    glVertex3f(-15, 5, 48);
    glVertex3f(-15, 5, 40);
    glVertex3f(-15, 0, 40);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 48);
    glVertex3f(-15, 10, 48);
    glVertex3f(-15, 10, 40);
    glVertex3f(-15, 5, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 48);
    glVertex3f(-15, 10, 48);
    glVertex3f(-15, 10, 40);
    glVertex3f(-15, 5, 40);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 48);
    glVertex3f(-15, 15, 48);
    glVertex3f(-15, 15, 40);
    glVertex3f(-15, 10, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 48);
    glVertex3f(-15, 15, 48);
    glVertex3f(-15, 15, 40);
    glVertex3f(-15, 10, 40);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 48);
    glVertex3f(-15, 20, 48);
    glVertex3f(-15, 20, 40);
    glVertex3f(-15, 15, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 48);
    glVertex3f(-15, 20, 48);
    glVertex3f(-15, 20, 40);
    glVertex3f(-15, 15, 40);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 50);
    glVertex3f(-15, 20, 50);
    glVertex3f(-15, 20, 48);
    glVertex3f(-15, 0, 48);
    glEnd();

    //kanan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 40.1);
    glVertex3f(15, 20, 40.1);
    glVertex3f(15, 20, 40.1);
    glVertex3f(15, 0, 40.1);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 48);
    glVertex3f(15, 5, 48);
    glVertex3f(15, 5, 40);
    glVertex3f(15, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 48);
    glVertex3f(15, 5, 48);
    glVertex3f(15, 5, 40);
    glVertex3f(15, 0, 40);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 48);
    glVertex3f(15, 10, 48);
    glVertex3f(15, 10, 40);
    glVertex3f(15, 5, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 48);
    glVertex3f(15, 10, 48);
    glVertex3f(15, 10, 40);
    glVertex3f(15, 5, 40);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 48);
    glVertex3f(15, 15, 48);
    glVertex3f(15, 15, 40);
    glVertex3f(15, 10, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 48);
    glVertex3f(15, 15, 48);
    glVertex3f(15, 15, 40);
    glVertex3f(15, 10, 40);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 48);
    glVertex3f(15, 20, 48);
    glVertex3f(15, 20, 40);
    glVertex3f(15, 15, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 48);
    glVertex3f(15, 20, 48);
    glVertex3f(15, 20, 40);
    glVertex3f(15, 15, 40);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 50);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 20, 48);
    glVertex3f(15, 0, 48);
    glEnd();

    //depan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 40.1);
    glVertex3f(-15, 0, 40.1);
    glVertex3f(-15, 0, 40.1);
    glVertex3f(15, 0, 40.1);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 48);
    glVertex3f(-15, 0, 48);
    glVertex3f(-15, 0, 40);
    glVertex3f(-10, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 48);
    glVertex3f(-15, 0, 48);
    glVertex3f(-15, 0, 40);
    glVertex3f(-10, 0, 40);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 48);
    glVertex3f(-10, 0, 48);
    glVertex3f(-10, 0, 40);
    glVertex3f(-5, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 48);
    glVertex3f(-10, 0, 48);
    glVertex3f(-10, 0, 40);
    glVertex3f(-5, 0, 40);
    glEnd();
    //kaca 3

    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 48);
    glVertex3f(-5, 0, 48);
    glVertex3f(-5, 0, 40);
    glVertex3f(0, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 48);
    glVertex3f(-5, 0, 48);
    glVertex3f(-5, 0, 40);
    glVertex3f(0, 0, 40);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 48);
    glVertex3f(0, 0, 48);
    glVertex3f(0, 0, 40);
    glVertex3f(5, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 48);
    glVertex3f(0, 0, 48);
    glVertex3f(0, 0, 40);
    glVertex3f(5, 0, 40);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 48);
    glVertex3f(5, 0, 48);
    glVertex3f(5, 0, 40);
    glVertex3f(10, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 48);
    glVertex3f(5, 0, 48);
    glVertex3f(5, 0, 40);
    glVertex3f(10, 0, 40);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 48);
    glVertex3f(10, 0, 48);
    glVertex3f(10, 0, 40);
    glVertex3f(15, 0, 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 48);
    glVertex3f(10, 0, 48);
    glVertex3f(10, 0, 40);
    glVertex3f(15, 0, 40);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 50);
    glVertex3f(-15, 0, 50);
    glVertex3f(-15, 0, 48);
    glVertex3f(15, 0, 48);
    glEnd();

    //=====================================lantai 6=======================================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 60);
    glVertex3f(-15, 20, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    //belakang
    //kaca
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 58);
    glVertex3f(-15, 20, 58);
    glVertex3f(-15, 20, 50);
    glVertex3f(-10, 20, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 58);
    glVertex3f(-15, 20, 58);
    glVertex3f(-15, 20, 50);
    glVertex3f(-10, 20, 50);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 58);
    glVertex3f(-10, 20, 58);
    glVertex3f(-10, 20, 50);
    glVertex3f(-5, 20, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 58);
    glVertex3f(-10, 20, 58);
    glVertex3f(-10, 20, 50);
    glVertex3f(-5, 20, 50);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 58);
    glVertex3f(-5, 20, 58);
    glVertex3f(-5, 20, 50);
    glVertex3f(0, 20, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 58);
    glVertex3f(-5, 20, 58);
    glVertex3f(-5, 20, 50);
    glVertex3f(0, 20, 50);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 58);
    glVertex3f(0, 20, 58);
    glVertex3f(0, 20, 50);
    glVertex3f(5, 20, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 58);
    glVertex3f(0, 20, 58);
    glVertex3f(0, 20, 50);
    glVertex3f(5, 20, 50);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 58);
    glVertex3f(5, 20, 58);
    glVertex3f(5, 20, 50);
    glVertex3f(10, 20, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 58);
    glVertex3f(5, 20, 58);
    glVertex3f(5, 20, 50);
    glVertex3f(10, 20, 50);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 58);
    glVertex3f(10, 20, 58);
    glVertex3f(10, 20, 50);
    glVertex3f(15, 20, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 58);
    glVertex3f(10, 20, 58);
    glVertex3f(10, 20, 50);
    glVertex3f(15, 20, 50);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 20, 58);
    glVertex3f(-15, 20, 58);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 50);
    glVertex3f(-15, 20, 50);
    glVertex3f(-15, 20, 50);
    glVertex3f(-15, 0, 50);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 58);
    glVertex3f(-15, 5, 58);
    glVertex3f(-15, 5, 50);
    glVertex3f(-15, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 58);
    glVertex3f(-15, 5, 58);
    glVertex3f(-15, 5, 50);
    glVertex3f(-15, 0, 50);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 58);
    glVertex3f(-15, 10, 58);
    glVertex3f(-15, 10, 50);
    glVertex3f(-15, 5, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 58);
    glVertex3f(-15, 10, 58);
    glVertex3f(-15, 10, 50);
    glVertex3f(-15, 5, 50);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 58);
    glVertex3f(-15, 15, 58);
    glVertex3f(-15, 15, 50);
    glVertex3f(-15, 10, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 58);
    glVertex3f(-15, 15, 58);
    glVertex3f(-15, 15, 50);
    glVertex3f(-15, 10, 50);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 58);
    glVertex3f(-15, 20, 58);
    glVertex3f(-15, 20, 50);
    glVertex3f(-15, 15, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 58);
    glVertex3f(-15, 20, 58);
    glVertex3f(-15, 20, 50);
    glVertex3f(-15, 15, 50);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 60);
    glVertex3f(-15, 20, 60);
    glVertex3f(-15, 20, 58);
    glVertex3f(-15, 0, 58);
    glEnd();

    //kanan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 50);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 58);
    glVertex3f(15, 5, 58);
    glVertex3f(15, 5, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 58);
    glVertex3f(15, 5, 58);
    glVertex3f(15, 5, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 58);
    glVertex3f(15, 10, 58);
    glVertex3f(15, 10, 50);
    glVertex3f(15, 5, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 58);
    glVertex3f(15, 10, 58);
    glVertex3f(15, 10, 50);
    glVertex3f(15, 5, 50);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 58);
    glVertex3f(15, 15, 58);
    glVertex3f(15, 15, 50);
    glVertex3f(15, 10, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 58);
    glVertex3f(15, 15, 58);
    glVertex3f(15, 15, 50);
    glVertex3f(15, 10, 50);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 58);
    glVertex3f(15, 20, 58);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 15, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 58);
    glVertex3f(15, 20, 58);
    glVertex3f(15, 20, 50);
    glVertex3f(15, 15, 50);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 20, 58);
    glVertex3f(15, 0, 58);
    glEnd();

    //depan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 50);
    glVertex3f(-15, 0, 50);
    glVertex3f(-15, 0, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 58);
    glVertex3f(-15, 0, 58);
    glVertex3f(-15, 0, 50);
    glVertex3f(-10, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 58);
    glVertex3f(-15, 0, 58);
    glVertex3f(-15, 0, 50);
    glVertex3f(-10, 0, 50);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 58);
    glVertex3f(-10, 0, 58);
    glVertex3f(-10, 0, 50);
    glVertex3f(-5, 0, 50);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 58);
    glVertex3f(-10, 0, 58);
    glVertex3f(-10, 0, 50);
    glVertex3f(-5, 0, 50);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 58);
    glVertex3f(-5, 0, 58);
    glVertex3f(-5, 0, 50);
    glVertex3f(0, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 58);
    glVertex3f(-5, 0, 58);
    glVertex3f(-5, 0, 50);
    glVertex3f(0, 0, 50);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 58);
    glVertex3f(0, 0, 58);
    glVertex3f(0, 0, 50);
    glVertex3f(5, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 58);
    glVertex3f(0, 0, 58);
    glVertex3f(0, 0, 50);
    glVertex3f(5, 0, 50);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 58);
    glVertex3f(5, 0, 58);
    glVertex3f(5, 0, 50);
    glVertex3f(10, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 58);
    glVertex3f(5, 0, 58);
    glVertex3f(5, 0, 50);
    glVertex3f(10, 0, 50);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 58);
    glVertex3f(10, 0, 58);
    glVertex3f(10, 0, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 58);
    glVertex3f(10, 0, 58);
    glVertex3f(10, 0, 50);
    glVertex3f(15, 0, 50);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 60);
    glVertex3f(-15, 0, 60);
    glVertex3f(-15, 0, 58);
    glVertex3f(15, 0, 58);
    glEnd();

    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 70);
    glVertex3f(-15, 20, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    //belakang bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(-15, 20, 60);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 68);
    glVertex3f(-15, 20, 68);
    glVertex3f(-15, 20, 60);
    glVertex3f(-10, 20, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 68);
    glVertex3f(-15, 20, 68);
    glVertex3f(-15, 20, 60);
    glVertex3f(-10, 20, 60);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 68);
    glVertex3f(-10, 20, 68);
    glVertex3f(-10, 20, 60);
    glVertex3f(-5, 20, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 68);
    glVertex3f(-10, 20, 68);
    glVertex3f(-10, 20, 60);
    glVertex3f(-5, 20, 60);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 68);
    glVertex3f(-5, 20, 68);
    glVertex3f(-5, 20, 60);
    glVertex3f(0, 20, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 68);
    glVertex3f(-5, 20, 68);
    glVertex3f(-5, 20, 60);
    glVertex3f(0, 20, 60);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 68);
    glVertex3f(0, 20, 68);
    glVertex3f(0, 20, 60);
    glVertex3f(5, 20, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 68);
    glVertex3f(0, 20, 68);
    glVertex3f(0, 20, 60);
    glVertex3f(5, 20, 60);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 68);
    glVertex3f(5, 20, 68);
    glVertex3f(5, 20, 60);
    glVertex3f(10, 20, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 68);
    glVertex3f(5, 20, 68);
    glVertex3f(5, 20, 60);
    glVertex3f(10, 20, 60);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 68);
    glVertex3f(10, 20, 68);
    glVertex3f(10, 20, 60);
    glVertex3f(15, 20, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 68);
    glVertex3f(10, 20, 68);
    glVertex3f(10, 20, 60);
    glVertex3f(15, 20, 60);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 20, 68);
    glVertex3f(-15, 20, 68);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 60);
    glVertex3f(-15, 20, 60);
    glVertex3f(-15, 20, 60);
    glVertex3f(-15, 0, 60);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 68);
    glVertex3f(-15, 5, 68);
    glVertex3f(-15, 5, 60);
    glVertex3f(-15, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 68);
    glVertex3f(-15, 5, 68);
    glVertex3f(-15, 5, 60);
    glVertex3f(-15, 0, 60);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 68);
    glVertex3f(-15, 10, 68);
    glVertex3f(-15, 10, 60);
    glVertex3f(-15, 5, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 68);
    glVertex3f(-15, 10, 68);
    glVertex3f(-15, 10, 60);
    glVertex3f(-15, 5, 60);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 68);
    glVertex3f(-15, 15, 68);
    glVertex3f(-15, 15, 60);
    glVertex3f(-15, 10, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 68);
    glVertex3f(-15, 15, 68);
    glVertex3f(-15, 15, 60);
    glVertex3f(-15, 10, 60);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 68);
    glVertex3f(-15, 20, 68);
    glVertex3f(-15, 20, 60);
    glVertex3f(-15, 15, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 68);
    glVertex3f(-15, 20, 68);
    glVertex3f(-15, 20, 60);
    glVertex3f(-15, 15, 60);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 70);
    glVertex3f(-15, 20, 70);
    glVertex3f(-15, 20, 68);
    glVertex3f(-15, 0, 68);
    glEnd();

    //kanan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 68);
    glVertex3f(15, 5, 68);
    glVertex3f(15, 5, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 68);
    glVertex3f(15, 5, 68);
    glVertex3f(15, 5, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 68);
    glVertex3f(15, 10, 68);
    glVertex3f(15, 10, 60);
    glVertex3f(15, 5, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 68);
    glVertex3f(15, 10, 68);
    glVertex3f(15, 10, 60);
    glVertex3f(15, 5, 60);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 68);
    glVertex3f(15, 15, 68);
    glVertex3f(15, 15, 60);
    glVertex3f(15, 10, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 68);
    glVertex3f(15, 15, 68);
    glVertex3f(15, 15, 60);
    glVertex3f(15, 10, 60);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 68);
    glVertex3f(15, 20, 68);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 15, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 68);
    glVertex3f(15, 20, 68);
    glVertex3f(15, 20, 60);
    glVertex3f(15, 15, 60);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 20, 68);
    glVertex3f(15, 0, 68);
    glEnd();

    //depan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 60);
    glVertex3f(-15, 0, 60);
    glVertex3f(-15, 0, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 68);
    glVertex3f(-15, 0, 68);
    glVertex3f(-15, 0, 60);
    glVertex3f(-10, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 68);
    glVertex3f(-15, 0, 68);
    glVertex3f(-15, 0, 60);
    glVertex3f(-10, 0, 60);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 68);
    glVertex3f(-10, 0, 68);
    glVertex3f(-10, 0, 60);
    glVertex3f(-5, 0, 60);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 68);
    glVertex3f(-10, 0, 68);
    glVertex3f(-10, 0, 60);
    glVertex3f(-5, 0, 60);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 68);
    glVertex3f(-5, 0, 68);
    glVertex3f(-5, 0, 60);
    glVertex3f(0, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 68);
    glVertex3f(-5, 0, 68);
    glVertex3f(-5, 0, 60);
    glVertex3f(0, 0, 60);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 68);
    glVertex3f(0, 0, 68);
    glVertex3f(0, 0, 60);
    glVertex3f(5, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 68);
    glVertex3f(0, 0, 68);
    glVertex3f(0, 0, 60);
    glVertex3f(5, 0, 60);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 68);
    glVertex3f(5, 0, 68);
    glVertex3f(5, 0, 60);
    glVertex3f(10, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 68);
    glVertex3f(5, 0, 68);
    glVertex3f(5, 0, 60);
    glVertex3f(10, 0, 60);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 68);
    glVertex3f(10, 0, 68);
    glVertex3f(10, 0, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 68);
    glVertex3f(10, 0, 68);
    glVertex3f(10, 0, 60);
    glVertex3f(15, 0, 60);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 70);
    glVertex3f(-15, 0, 70);
    glVertex3f(-15, 0, 68);
    glVertex3f(15, 0, 68);
    glEnd();

    //============================================lantai 8================================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 0, 80);
    glVertex3f(-15, 20, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 0, 80);
    glEnd();

    //belakang bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(-15, 20, 70);
    glEnd();

    //kaca
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 78);
    glVertex3f(-15, 20, 78);
    glVertex3f(-15, 20, 70);
    glVertex3f(-10, 20, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 78);
    glVertex3f(-15, 20, 78);
    glVertex3f(-15, 20, 70);
    glVertex3f(-10, 20, 70);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 78);
    glVertex3f(-10, 20, 78);
    glVertex3f(-10, 20, 70);
    glVertex3f(-5, 20, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 78);
    glVertex3f(-10, 20, 78);
    glVertex3f(-10, 20, 70);
    glVertex3f(-5, 20, 70);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 78);
    glVertex3f(-5, 20, 78);
    glVertex3f(-5, 20, 70);
    glVertex3f(0, 20, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 78);
    glVertex3f(-5, 20, 78);
    glVertex3f(-5, 20, 70);
    glVertex3f(0, 20, 70);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 78);
    glVertex3f(0, 20, 78);
    glVertex3f(0, 20, 70);
    glVertex3f(5, 20, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 78);
    glVertex3f(0, 20, 78);
    glVertex3f(0, 20, 70);
    glVertex3f(5, 20, 70);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 78);
    glVertex3f(5, 20, 78);
    glVertex3f(5, 20, 70);
    glVertex3f(10, 20, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 78);
    glVertex3f(5, 20, 78);
    glVertex3f(5, 20, 70);
    glVertex3f(10, 20, 70);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 78);
    glVertex3f(10, 20, 78);
    glVertex3f(10, 20, 70);
    glVertex3f(15, 20, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 78);
    glVertex3f(10, 20, 78);
    glVertex3f(10, 20, 70);
    glVertex3f(15, 20, 70);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 20, 78);
    glVertex3f(-15, 20, 78);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 70);
    glVertex3f(-15, 20, 70);
    glVertex3f(-15, 20, 70);
    glVertex3f(-15, 0, 70);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 0, 78);
    glVertex3f(-15, 5, 78);
    glVertex3f(-15, 5, 70);
    glVertex3f(-15, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 0, 78);
    glVertex3f(-15, 5, 78);
    glVertex3f(-15, 5, 70);
    glVertex3f(-15, 0, 70);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 78);
    glVertex3f(-15, 10, 78);
    glVertex3f(-15, 10, 70);
    glVertex3f(-15, 5, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 78);
    glVertex3f(-15, 10, 78);
    glVertex3f(-15, 10, 70);
    glVertex3f(-15, 5, 70);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 78);
    glVertex3f(-15, 15, 78);
    glVertex3f(-15, 15, 70);
    glVertex3f(-15, 10, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 78);
    glVertex3f(-15, 15, 78);
    glVertex3f(-15, 15, 70);
    glVertex3f(-15, 10, 70);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 78);
    glVertex3f(-15, 20, 78);
    glVertex3f(-15, 20, 70);
    glVertex3f(-15, 15, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 78);
    glVertex3f(-15, 20, 78);
    glVertex3f(-15, 20, 70);
    glVertex3f(-15, 15, 70);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 80);
    glVertex3f(-15, 20, 80);
    glVertex3f(-15, 20, 78);
    glVertex3f(-15, 0, 78);
    glEnd();

    //kanan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 78);
    glVertex3f(15, 5, 78);
    glVertex3f(15, 5, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 78);
    glVertex3f(15, 5, 78);
    glVertex3f(15, 5, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 78);
    glVertex3f(15, 10, 78);
    glVertex3f(15, 10, 70);
    glVertex3f(15, 5, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 78);
    glVertex3f(15, 10, 78);
    glVertex3f(15, 10, 70);
    glVertex3f(15, 5, 70);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 78);
    glVertex3f(15, 15, 78);
    glVertex3f(15, 15, 70);
    glVertex3f(15, 10, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 78);
    glVertex3f(15, 15, 78);
    glVertex3f(15, 15, 70);
    glVertex3f(15, 10, 70);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 78);
    glVertex3f(15, 20, 78);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 15, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 78);
    glVertex3f(15, 20, 78);
    glVertex3f(15, 20, 70);
    glVertex3f(15, 15, 70);
    glEnd();

    //kanan ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 20, 78);
    glVertex3f(15, 0, 78);
    glEnd();

    //depan bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 70);
    glVertex3f(-15, 0, 70);
    glVertex3f(-15, 0, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 0, 78);
    glVertex3f(-15, 0, 78);
    glVertex3f(-15, 0, 70);
    glVertex3f(-10, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 0, 78);
    glVertex3f(-15, 0, 78);
    glVertex3f(-15, 0, 70);
    glVertex3f(-10, 0, 70);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 0, 78);
    glVertex3f(-10, 0, 78);
    glVertex3f(-10, 0, 70);
    glVertex3f(-5, 0, 70);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 0, 78);
    glVertex3f(-10, 0, 78);
    glVertex3f(-10, 0, 70);
    glVertex3f(-5, 0, 70);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 0, 78);
    glVertex3f(-5, 0, 78);
    glVertex3f(-5, 0, 70);
    glVertex3f(0, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 0, 78);
    glVertex3f(-5, 0, 78);
    glVertex3f(-5, 0, 70);
    glVertex3f(0, 0, 70);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 0, 78);
    glVertex3f(0, 0, 78);
    glVertex3f(0, 0, 70);
    glVertex3f(5, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 0, 78);
    glVertex3f(0, 0, 78);
    glVertex3f(0, 0, 70);
    glVertex3f(5, 0, 70);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 0, 78);
    glVertex3f(5, 0, 78);
    glVertex3f(5, 0, 70);
    glVertex3f(10, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 0, 78);
    glVertex3f(5, 0, 78);
    glVertex3f(5, 0, 70);
    glVertex3f(10, 0, 70);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 0, 78);
    glVertex3f(10, 0, 78);
    glVertex3f(10, 0, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 0, 78);
    glVertex3f(10, 0, 78);
    glVertex3f(10, 0, 70);
    glVertex3f(15, 0, 70);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 80);
    glVertex3f(-15, 0, 80);
    glVertex3f(-15, 0, 78);
    glVertex3f(15, 0, 78);
    glEnd();

    //==========================9=============================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 20, 85);
    glVertex3f(-15, 20, 85);
    glVertex3f(15, 20, 85);
    glVertex3f(15, 20, 85);
    glEnd();

    //kaca kiri segi3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-14, 1, 100);
    glVertex3f(-14, 10, 90);
    glVertex3f(-14, 1, 80);
    glEnd();

    //kaca kiri segi3 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(-14.1, 1, 90);
    glVertex3f(-14.1, 10, 90);
    glVertex3f(-14.1, 5.5, 85);
    glVertex3f(-14.1, 1, 85);
    glEnd();

    //kaca kiri segi3 3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-14.1, 1, 100);
    glVertex3f(-14.1, 5.5, 95);
    glVertex3f(-14.1, 1, 95);
    glEnd();

    //kaca depan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(14, 1, 100);
    glVertex3f(-14, 1, 100);
    glVertex3f(-14, 1, 80);
    glVertex3f(14, 1, 80);
    glEnd();

    //kaca depan2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(13.9, 0.9, 90);
    glVertex3f(-13.9, 0.9, 90);
    glVertex3f(-13.9, 0.9, 85);
    glVertex3f(13.9, 0.9, 85);
    glEnd();

    //kaca depan3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(13.9, 0.9, 100);
    glVertex3f(-13.9, 0.9, 100);
    glVertex3f(-13.9, 0.9, 95);
    glVertex3f(13.9, 0.9, 95);
    glEnd();

    //garis kaca depan
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(14, 1, 100);
    glVertex3f(-14, 1, 100);
    glVertex3f(-14, 1, 80);
    glVertex3f(14, 1, 80);
    glEnd();

    //kaca kanan segi3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(14, 1, 100);
    glVertex3f(14, 10, 90);
    glVertex3f(14, 1, 80);
    glEnd();

    //kaca kanan segi3 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(14.1, 1, 90);
    glVertex3f(14.1, 10, 90);
    glVertex3f(14.1, 5.5, 85);
    glVertex3f(14.1, 1, 85);
    glEnd();

    //kaca kanan segi3 3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(14.1, 1, 100);
    glVertex3f(14.1, 5.5, 95);
    glVertex3f(14.1, 1, 95);
    glEnd();

    //garis segitiga kiri
    glBegin(GL_LINES);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    //atas
    glVertex3f(-14, 1, 100);
    glVertex3f(-14, 10, 90);
    //bawah
    glVertex3f(-14, 10, 90);
    glVertex3f(-14, 1, 80);
    glEnd();

    //garis segitiga kanan
    glBegin(GL_LINES);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    //atas
    glVertex3f(14, 1, 100);
    glVertex3f(14, 10, 90);
    //bawah
    glVertex3f(14, 10, 90);
    glVertex3f(14, 1, 80);
    glEnd();

    //belakang bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(-15, 20, 80);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 85);
    glVertex3f(-15, 20, 85);
    glVertex3f(-15, 20, 80);
    glVertex3f(-10, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 85);
    glVertex3f(-15, 20, 85);
    glVertex3f(-15, 20, 80);
    glVertex3f(-10, 20, 80);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 85);
    glVertex3f(-10, 20, 85);
    glVertex3f(-10, 20, 80);
    glVertex3f(-5, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 85);
    glVertex3f(-10, 20, 85);
    glVertex3f(-10, 20, 80);
    glVertex3f(-5, 20, 80);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 85);
    glVertex3f(-5, 20, 85);
    glVertex3f(-5, 20, 80);
    glVertex3f(0, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 85);
    glVertex3f(-5, 20, 85);
    glVertex3f(-5, 20, 80);
    glVertex3f(0, 20, 80);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 85);
    glVertex3f(0, 20, 85);
    glVertex3f(0, 20, 80);
    glVertex3f(5, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 85);
    glVertex3f(0, 20, 85);
    glVertex3f(0, 20, 80);
    glVertex3f(5, 20, 80);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 85);
    glVertex3f(5, 20, 85);
    glVertex3f(5, 20, 80);
    glVertex3f(10, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 85);
    glVertex3f(5, 20, 85);
    glVertex3f(5, 20, 80);
    glVertex3f(10, 20, 80);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 85);
    glVertex3f(10, 20, 85);
    glVertex3f(10, 20, 80);
    glVertex3f(15, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 85);
    glVertex3f(10, 20, 85);
    glVertex3f(10, 20, 80);
    glVertex3f(15, 20, 80);
    glEnd();

    //belakang ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 86.5);
    glVertex3f(15, 20, 86.5);
    glVertex3f(15, 20, 85);
    glVertex3f(-15, 20, 85);
    glEnd();

    //kiri ats
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 7, 86.5);
    glVertex3f(-15, 20, 86.5);
    glVertex3f(-15, 20, 85);
    glVertex3f(-15, 5, 85);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 0, 80);
    glVertex3f(-15, 20, 80);
    glVertex3f(-15, 20, 80);
    glVertex3f(-15, 0, 80);
    glEnd();

    //kaca 1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 85);
    glVertex3f(-15, 5, 80);
    glVertex3f(-15, 1, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 85);
    glVertex3f(-15, 5, 85);
    glVertex3f(-15, 5, 80);
    glVertex3f(-15, 1, 80);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 5, 85);
    glVertex3f(-15, 10, 85);
    glVertex3f(-15, 10, 80);
    glVertex3f(-15, 5, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 5, 85);
    glVertex3f(-15, 10, 85);
    glVertex3f(-15, 10, 80);
    glVertex3f(-15, 5, 80);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 85);
    glVertex3f(-15, 15, 85);
    glVertex3f(-15, 15, 80);
    glVertex3f(-15, 10, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 85);
    glVertex3f(-15, 15, 85);
    glVertex3f(-15, 15, 80);
    glVertex3f(-15, 10, 80);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 85);
    glVertex3f(-15, 20, 85);
    glVertex3f(-15, 20, 80);
    glVertex3f(-15, 15, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 85);
    glVertex3f(-15, 20, 85);
    glVertex3f(-15, 20, 80);
    glVertex3f(-15, 15, 80);
    glEnd();

    //========================================10===========================================
    glBegin(GL_QUADS); //tutup
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15, 20, 90);
    glVertex3f(-15, 20, 90);
    glVertex3f(15, 20, 90);
    glVertex3f(15, 20, 90);
    glEnd();

    //belakang bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(-15, 20, 86);
    glVertex3f(15, 20, 86);
    glVertex3f(15, 20, 86);
    glVertex3f(-15, 20, 86);
    glEnd();

    //kaca 1
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-10, 20, 90);
    glVertex3f(-15, 20, 90);
    glVertex3f(-15, 20, 86.5);
    glVertex3f(-10, 20, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-10, 20, 90);
    glVertex3f(-15, 20, 90);
    glVertex3f(-15, 20, 86.5);
    glVertex3f(-10, 20, 86.5);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-5, 20, 90);
    glVertex3f(-10, 20, 90);
    glVertex3f(-10, 20, 86.5);
    glVertex3f(-5, 20, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-5, 20, 90);
    glVertex3f(-10, 20, 90);
    glVertex3f(-10, 20, 86.5);
    glVertex3f(-5, 20, 86.5);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(0, 20, 90);
    glVertex3f(-5, 20, 90);
    glVertex3f(-5, 20, 86.5);
    glVertex3f(0, 20, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(0, 20, 90);
    glVertex3f(-5, 20, 90);
    glVertex3f(-5, 20, 86.5);
    glVertex3f(0, 20, 86.5);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(5, 20, 90);
    glVertex3f(0, 20, 90);
    glVertex3f(0, 20, 86.5);
    glVertex3f(5, 20, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(5, 20, 90);
    glVertex3f(0, 20, 90);
    glVertex3f(0, 20, 86.5);
    glVertex3f(5, 20, 86.5);
    glEnd();

    //kaca 5
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(10, 20, 90);
    glVertex3f(5, 20, 90);
    glVertex3f(5, 20, 86.5);
    glVertex3f(10, 20, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(10, 20, 90);
    glVertex3f(5, 20, 90);
    glVertex3f(5, 20, 86.5);
    glVertex3f(10, 20, 86.5);
    glEnd();

    //kaca 6
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 20, 90);
    glVertex3f(10, 20, 90);
    glVertex3f(10, 20, 86.5);
    glVertex3f(15, 20, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 20, 90);
    glVertex3f(10, 20, 90);
    glVertex3f(10, 20, 86.5);
    glVertex3f(15, 20, 86.5);
    glEnd();

    //kiri
    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 90);
    glVertex3f(-15, 10, 90);
    glVertex3f(-15, 10, 86.5);
    glVertex3f(-15, 5, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 90);
    glVertex3f(-15, 10, 90);
    glVertex3f(-15, 10, 86.5);
    glVertex3f(-15, 5, 86.5);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 10, 90);
    glVertex3f(-15, 15, 90);
    glVertex3f(-15, 15, 86.5);
    glVertex3f(-15, 10, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 10, 90);
    glVertex3f(-15, 15, 90);
    glVertex3f(-15, 15, 86.5);
    glVertex3f(-15, 10, 86.5);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(-15, 15, 90);
    glVertex3f(-15, 20, 90);
    glVertex3f(-15, 20, 86.5);
    glVertex3f(-15, 15, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(-15, 15, 90);
    glVertex3f(-15, 20, 90);
    glVertex3f(-15, 20, 86.5);
    glVertex3f(-15, 15, 86.5);
    glEnd();

    //kanan
   //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 90);
    glVertex3f(15, 10, 90);
    glVertex3f(15, 10, 86.5);
    glVertex3f(15, 5, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 90);
    glVertex3f(15, 10, 90);
    glVertex3f(15, 10, 86.5);
    glVertex3f(15, 5, 86.5);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 90);
    glVertex3f(15, 15, 90);
    glVertex3f(15, 15, 86.5);
    glVertex3f(15, 10, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 90);
    glVertex3f(15, 15, 90);
    glVertex3f(15, 15, 86.5);
    glVertex3f(15, 10, 86.5);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 90);
    glVertex3f(15, 20, 90);
    glVertex3f(15, 20, 86.5);
    glVertex3f(15, 15, 86.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 90);
    glVertex3f(15, 20, 90);
    glVertex3f(15, 20, 86.5);
    glVertex3f(15, 15, 86.5);
    glEnd();

    //kiri bwh
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9803921568627451, 0.9803921568627451);
    glVertex3f(15, 0, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 0, 80);
    glEnd();

    //kaca 1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 85);
    glVertex3f(15, 5, 80);
    glVertex3f(15, 1, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 85);
    glVertex3f(15, 5, 85);
    glVertex3f(15, 5, 80);
    glVertex3f(15, 1, 80);
    glEnd();

    //kaca 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 5, 85);
    glVertex3f(15, 10, 85);
    glVertex3f(15, 10, 80);
    glVertex3f(15, 5, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 5, 85);
    glVertex3f(15, 10, 85);
    glVertex3f(15, 10, 80);
    glVertex3f(15, 5, 80);
    glEnd();

    //kaca 3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 10, 85);
    glVertex3f(15, 15, 85);
    glVertex3f(15, 15, 80);
    glVertex3f(15, 10, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 10, 85);
    glVertex3f(15, 15, 85);
    glVertex3f(15, 15, 80);
    glVertex3f(15, 10, 80);
    glEnd();

    //kaca 4
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(15, 15, 85);
    glVertex3f(15, 20, 85);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 15, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(15, 15, 85);
    glVertex3f(15, 20, 85);
    glVertex3f(15, 20, 80);
    glVertex3f(15, 15, 80);
    glEnd();

    //atap atas
    glBegin(GL_QUADS); //tutup
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-15, 0.5, 101);
    glVertex3f(-15, 10, 91);
    glVertex3f(15, 10, 91);
    glVertex3f(15, 0.5, 101);
    glEnd();

    glBegin(GL_QUADS); //tutup
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-15, 20, 90);
    glVertex3f(-15, 9, 90);
    glVertex3f(15, 9, 90);
    glVertex3f(15, 20, 90);
    glEnd();


    //-------------GEDUNG 2-----------//
    //Dinding Kiri Bawah
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(18, 20, 0);
    glVertex3f(18, 0, 0);
    glVertex3f(18, 0, 10);
    glVertex3f(18, 20, 10);
    glEnd();

    //DindingBelakangBawah
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(18, 20, 0);
    glVertex3f(48, 20, 0);
    glVertex3f(48, 20, 10);
    glVertex3f(18, 20, 10);
    glEnd();

    //DindingKananBawah
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(48, 20, 0);
    glVertex3f(48, 0, 0);
    glVertex3f(48, 0, 10);
    glVertex3f(48, 20, 10);
    glEnd();

    //DindingDepanBawah
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(18, 0, 0);
    glVertex3f(48, 0, 0);
    glVertex3f(48, 0, 10);
    glVertex3f(18, 0, 10);
    glEnd();

    //AlasDepanBawah
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 0);
    glVertex3f(48, 20, 0);
    glVertex3f(48, -30, 0);
    glVertex3f(18, -30, 0);
    glEnd();

    //AlasAtas
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 10);
    glVertex3f(48, 20, 10);
    glVertex3f(48, 0, 10);
    glVertex3f(18, 0, 10);
    glEnd();

    //PintuDepan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0, 0.5);
    glVertex3f(26, -1, 0);
    glVertex3f(40, -1, 0);
    glVertex3f(40, -1, 7);
    glVertex3f(26, -1, 7);
    glEnd();

    //PilarKiri1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -30, 0);
    glVertex3f(22, -30, 0);
    glVertex3f(22, -30, 10);
    glVertex3f(18, -30, 10);
    glEnd();

    //PilarKiri2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -26, 0);
    glVertex3f(22, -26, 0);
    glVertex3f(22, -26, 10);
    glVertex3f(18, -26, 10);
    glEnd();

    //PilarKiri3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -30, 0);
    glVertex3f(18, -26, 0);
    glVertex3f(18, -26, 10);
    glVertex3f(18, -30, 10);
    glEnd();

    //PilarKiri4
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(22, -30, 0);
    glVertex3f(22, -26, 0);
    glVertex3f(22, -26, 10);
    glVertex3f(22, -30, 10);
    glEnd();

    //PilarKanan1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(44, -30, 0);
    glVertex3f(48, -30, 0);
    glVertex3f(48, -30, 10);
    glVertex3f(44, -30, 10);
    glEnd();

    //PilarKiri2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(44, -26, 0);
    glVertex3f(48, -26, 0);
    glVertex3f(48, -26, 10);
    glVertex3f(44, -26, 10);
    glEnd();

    //PilarKiri3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(44, -30, 0);
    glVertex3f(44, -26, 0);
    glVertex3f(44, -26, 10);
    glVertex3f(44, -30, 10);
    glEnd();

    //PilarKiri4
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(48, -30, 0);
    glVertex3f(48, -26, 0);
    glVertex3f(48, -26, 10);
    glVertex3f(48, -30, 10);
    glEnd();

    //Atap Pilar 1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -30, 10);
    glVertex3f(48, -30, 10);
    glVertex3f(48, 0, 10);
    glVertex3f(18, 0, 10);
    glEnd();

    //Atap Pilar 2
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -30, 11);
    glVertex3f(48, -30, 11);
    glVertex3f(48, 0, 11);
    glVertex3f(18, 0, 11);
    glEnd();

    //Atap Pilar 3
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -30, 10);
    glVertex3f(18, 0, 10);
    glVertex3f(18, 0, 11);
    glVertex3f(18, -30, 11);
    glEnd();

    //Atap Pilar 4
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(48, -30, 10);
    glVertex3f(48, 0, 10);
    glVertex3f(48, 0, 11);
    glVertex3f(48, -30, 11);
    glEnd();

    //Atap Pilar 5
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(18, -30, 10);
    glVertex3f(48, -30, 10);
    glVertex3f(48, -30, 11);
    glVertex3f(18, -30, 11);
    glEnd();


    //--------Lantai2--------//
    //AlasDepan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 10);
    glVertex3f(48, 0, 10);
    glVertex3f(48, 0, 11);
    glVertex3f(18, 0, 11);
    glEnd();

    //AlasKanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 10);
    glVertex3f(48, 20, 10);
    glVertex3f(48, 20, 11);
    glVertex3f(48, 0, 11);
    glEnd();

    //AlasBelakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 10);
    glVertex3f(48, 20, 10);
    glVertex3f(48, 20, 11);
    glVertex3f(18, 20, 11);
    glEnd();

    //AlasKiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 10);
    glVertex3f(18, 20, 10);
    glVertex3f(18, 20, 11);
    glVertex3f(18, 0, 11);
    glEnd();

    //Kaca1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 11);
    glVertex3f(23, 0, 11);
    glVertex3f(23, 0, 18);
    glVertex3f(18, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 11);
    glVertex3f(23, 0, 11);
    glVertex3f(23, 0, 18);
    glVertex3f(18, 0, 18);
    glEnd();

    //Kaca2
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 0, 11);
    glVertex3f(28, 0, 11);
    glVertex3f(28, 0, 18);
    glVertex3f(23, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 0, 11);
    glVertex3f(28, 0, 11);
    glVertex3f(28, 0, 18);
    glVertex3f(23, 0, 18);
    glEnd();

    //Kaca3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 0, 11);
    glVertex3f(33, 0, 11);
    glVertex3f(33, 0, 18);
    glVertex3f(28, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 0, 11);
    glVertex3f(33, 0, 11);
    glVertex3f(33, 0, 18);
    glVertex3f(28, 0, 18);
    glEnd();

    //Kaca4
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 0, 11);
    glVertex3f(38, 0, 11);
    glVertex3f(38, 0, 18);
    glVertex3f(33, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 0, 11);
    glVertex3f(38, 0, 11);
    glVertex3f(38, 0, 18);
    glVertex3f(33, 0, 18);
    glEnd();

    //Kaca5
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 0, 11);
    glVertex3f(43, 0, 11);
    glVertex3f(43, 0, 18);
    glVertex3f(38, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 0, 11);
    glVertex3f(43, 0, 11);
    glVertex3f(43, 0, 18);
    glVertex3f(38, 0, 18);
    glEnd();

    //Kaca6
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 0, 11);
    glVertex3f(48, 0, 11);
    glVertex3f(48, 0, 18);
    glVertex3f(43, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 0, 11);
    glVertex3f(48, 0, 11);
    glVertex3f(48, 0, 18);
    glVertex3f(43, 0, 18);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 0, 11);
    glVertex3f(48, 5, 11);
    glVertex3f(48, 5, 18);
    glVertex3f(48, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 0, 11);
    glVertex3f(48, 5, 11);
    glVertex3f(48, 5, 18);
    glVertex3f(48, 0, 18);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 5, 11);
    glVertex3f(48, 10, 11);
    glVertex3f(48, 10, 18);
    glVertex3f(48, 5, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 5, 11);
    glVertex3f(48, 10, 11);
    glVertex3f(48, 10, 18);
    glVertex3f(48, 5, 18);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 10, 11);
    glVertex3f(48, 15, 11);
    glVertex3f(48, 15, 18);
    glVertex3f(48, 10, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 10, 11);
    glVertex3f(48, 15, 11);
    glVertex3f(48, 15, 18);
    glVertex3f(48, 10, 18);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 15, 11);
    glVertex3f(48, 20, 11);
    glVertex3f(48, 20, 18);
    glVertex3f(48, 15, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 15, 11);
    glVertex3f(48, 20, 11);
    glVertex3f(48, 20, 18);
    glVertex3f(48, 15, 18);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 20, 11);
    glVertex3f(23, 20, 11);
    glVertex3f(23, 20, 18);
    glVertex3f(18, 20, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 20, 11);
    glVertex3f(23, 20, 11);
    glVertex3f(23, 20, 18);
    glVertex3f(18, 20, 18);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 11);
    glVertex3f(28, 20, 11);
    glVertex3f(28, 20, 18);
    glVertex3f(23, 20, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 11);
    glVertex3f(28, 20, 11);
    glVertex3f(28, 20, 18);
    glVertex3f(23, 20, 18);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 11);
    glVertex3f(33, 20, 11);
    glVertex3f(33, 20, 18);
    glVertex3f(28, 20, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 11);
    glVertex3f(33, 20, 11);
    glVertex3f(33, 20, 18);
    glVertex3f(28, 20, 18);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 11);
    glVertex3f(38, 20, 11);
    glVertex3f(38, 20, 18);
    glVertex3f(33, 20, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 11);
    glVertex3f(38, 20, 11);
    glVertex3f(38, 20, 18);
    glVertex3f(33, 20, 18);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 11);
    glVertex3f(43, 20, 11);
    glVertex3f(43, 20, 18);
    glVertex3f(38, 20, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 11);
    glVertex3f(43, 20, 11);
    glVertex3f(43, 20, 18);
    glVertex3f(38, 20, 18);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 11);
    glVertex3f(48, 20, 11);
    glVertex3f(48, 20, 18);
    glVertex3f(43, 20, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 11);
    glVertex3f(48, 20, 11);
    glVertex3f(48, 20, 18);
    glVertex3f(43, 20, 18);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 11);
    glVertex3f(18, 5, 11);
    glVertex3f(18, 5, 18);
    glVertex3f(18, 0, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 11);
    glVertex3f(18, 5, 11);
    glVertex3f(18, 5, 18);
    glVertex3f(18, 0, 18);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 5, 11);
    glVertex3f(18, 10, 11);
    glVertex3f(18, 10, 18);
    glVertex3f(18, 5, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 5, 11);
    glVertex3f(18, 10, 11);
    glVertex3f(18, 10, 18);
    glVertex3f(18, 5, 18);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 10, 11);
    glVertex3f(18, 15, 11);
    glVertex3f(18, 15, 18);
    glVertex3f(18, 10, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 10, 11);
    glVertex3f(18, 15, 11);
    glVertex3f(18, 15, 18);
    glVertex3f(18, 10, 18);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 15, 11);
    glVertex3f(18, 20, 11);
    glVertex3f(18, 20, 18);
    glVertex3f(18, 15, 18);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 15, 11);
    glVertex3f(18, 20, 11);
    glVertex3f(18, 20, 18);
    glVertex3f(18, 15, 18);
    glEnd();

    //--------------Lantai3-----------//

    //AlasLantai
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 20);
    glVertex3f(48, 0, 20);
    glVertex3f(48, 20, 20);
    glVertex3f(18, 20, 20);
    glEnd();

    //AlasDepan
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 18);
    glVertex3f(48, 0, 18);
    glVertex3f(48, 0, 20);
    glVertex3f(18, 0, 20);
    glEnd();

    //AlasKiri
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 18);
    glVertex3f(18, 20, 18);
    glVertex3f(18, 20, 20);
    glVertex3f(18, 0, 20);
    glEnd();

    //AlasBelakang
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 18);
    glVertex3f(48, 20, 18);
    glVertex3f(48, 20, 20);
    glVertex3f(18, 20, 20);
    glEnd();

    //AlasKanan
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 18);
    glVertex3f(48, 20, 18);
    glVertex3f(48, 20, 20);
    glVertex3f(48, 0, 20);
    glEnd();

    //Kaca1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 20);
    glVertex3f(23, 0, 20);
    glVertex3f(23, 0, 28);
    glVertex3f(18, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 20);
    glVertex3f(23, 0, 20);
    glVertex3f(23, 0, 28);
    glVertex3f(18, 0, 28);
    glEnd();

    //Kaca2
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 0, 20);
    glVertex3f(28, 0, 20);
    glVertex3f(28, 0, 28);
    glVertex3f(23, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 0, 20);
    glVertex3f(28, 0, 20);
    glVertex3f(28, 0, 28);
    glVertex3f(23, 0, 28);
    glEnd();

    //Kaca3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 0, 20);
    glVertex3f(33, 0, 20);
    glVertex3f(33, 0, 28);
    glVertex3f(28, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 0, 20);
    glVertex3f(33, 0, 20);
    glVertex3f(33, 0, 28);
    glVertex3f(28, 0, 28);
    glEnd();

    //Kaca4
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 0, 20);
    glVertex3f(38, 0, 20);
    glVertex3f(38, 0, 28);
    glVertex3f(33, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 0, 20);
    glVertex3f(38, 0, 20);
    glVertex3f(38, 0, 28);
    glVertex3f(33, 0, 28);
    glEnd();

    //Kaca5
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 0, 20);
    glVertex3f(43, 0, 20);
    glVertex3f(43, 0, 28);
    glVertex3f(38, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 0, 20);
    glVertex3f(43, 0, 20);
    glVertex3f(43, 0, 28);
    glVertex3f(38, 0, 28);
    glEnd();

    //Kaca6
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 0, 20);
    glVertex3f(48, 0, 20);
    glVertex3f(48, 0, 28);
    glVertex3f(43, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 0, 20);
    glVertex3f(48, 0, 20);
    glVertex3f(48, 0, 28);
    glVertex3f(43, 0, 28);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 0, 20);
    glVertex3f(48, 5, 20);
    glVertex3f(48, 5, 28);
    glVertex3f(48, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 0, 20);
    glVertex3f(48, 5, 20);
    glVertex3f(48, 5, 28);
    glVertex3f(48, 0, 28);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 5, 20);
    glVertex3f(48, 10, 20);
    glVertex3f(48, 10, 28);
    glVertex3f(48, 5, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 5, 20);
    glVertex3f(48, 10, 20);
    glVertex3f(48, 10, 28);
    glVertex3f(48, 5, 28);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 10, 20);
    glVertex3f(48, 15, 20);
    glVertex3f(48, 15, 28);
    glVertex3f(48, 10, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 10, 20);
    glVertex3f(48, 15, 20);
    glVertex3f(48, 15, 28);
    glVertex3f(48, 10, 28);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 15, 20);
    glVertex3f(48, 20, 20);
    glVertex3f(48, 20, 28);
    glVertex3f(48, 15, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 15, 20);
    glVertex3f(48, 20, 20);
    glVertex3f(48, 20, 28);
    glVertex3f(48, 15, 28);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 20, 20);
    glVertex3f(23, 20, 20);
    glVertex3f(23, 20, 28);
    glVertex3f(18, 20, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 20, 20);
    glVertex3f(23, 20, 20);
    glVertex3f(23, 20, 28);
    glVertex3f(18, 20, 28);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 20);
    glVertex3f(28, 20, 20);
    glVertex3f(28, 20, 28);
    glVertex3f(23, 20, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 20);
    glVertex3f(28, 20, 20);
    glVertex3f(28, 20, 28);
    glVertex3f(23, 20, 28);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 20);
    glVertex3f(33, 20, 20);
    glVertex3f(33, 20, 28);
    glVertex3f(28, 20, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 20);
    glVertex3f(33, 20, 20);
    glVertex3f(33, 20, 28);
    glVertex3f(28, 20, 28);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 20);
    glVertex3f(38, 20, 20);
    glVertex3f(38, 20, 28);
    glVertex3f(33, 20, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 20);
    glVertex3f(38, 20, 20);
    glVertex3f(38, 20, 28);
    glVertex3f(33, 20, 28);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 20);
    glVertex3f(43, 20, 20);
    glVertex3f(43, 20, 28);
    glVertex3f(38, 20, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 20);
    glVertex3f(43, 20, 20);
    glVertex3f(43, 20, 28);
    glVertex3f(38, 20, 28);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 20);
    glVertex3f(48, 20, 20);
    glVertex3f(48, 20, 28);
    glVertex3f(43, 20, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 20);
    glVertex3f(48, 20, 20);
    glVertex3f(48, 20, 28);
    glVertex3f(43, 20, 28);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 20);
    glVertex3f(18, 5, 20);
    glVertex3f(18, 5, 28);
    glVertex3f(18, 0, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 20);
    glVertex3f(18, 5, 20);
    glVertex3f(18, 5, 28);
    glVertex3f(18, 0, 28);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 5, 20);
    glVertex3f(18, 10, 20);
    glVertex3f(18, 10, 28);
    glVertex3f(18, 5, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 5, 20);
    glVertex3f(18, 10, 20);
    glVertex3f(18, 10, 28);
    glVertex3f(18, 5, 28);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 10, 20);
    glVertex3f(18, 15, 20);
    glVertex3f(18, 15, 28);
    glVertex3f(18, 10, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 10, 20);
    glVertex3f(18, 15, 20);
    glVertex3f(18, 15, 28);
    glVertex3f(18, 10, 28);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 15, 20);
    glVertex3f(18, 20, 20);
    glVertex3f(18, 20, 28);
    glVertex3f(18, 15, 28);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 15, 20);
    glVertex3f(18, 20, 20);
    glVertex3f(18, 20, 28);
    glVertex3f(18, 15, 28);
    glEnd();

    //--------Lantai4--------//
    //AlasDepan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 28);
    glVertex3f(48, 0, 28);
    glVertex3f(48, 0, 30);
    glVertex3f(18, 0, 30);
    glEnd();

    //AlasKanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 28);
    glVertex3f(48, 20, 28);
    glVertex3f(48, 20, 30);
    glVertex3f(48, 0, 30);
    glEnd();

    //AlasBelakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 28);
    glVertex3f(48, 20, 28);
    glVertex3f(48, 20, 30);
    glVertex3f(18, 20, 30);
    glEnd();

    //AlasKiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 28);
    glVertex3f(18, 20, 28);
    glVertex3f(18, 20, 30);
    glVertex3f(18, 0, 30);
    glEnd();

    //AlasLantai
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 30);
    glVertex3f(48, 0, 30);
    glVertex3f(48, 20, 30);
    glVertex3f(18, 20, 30);
    glEnd();

    //Kaca1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 30);
    glVertex3f(23, 0, 30);
    glVertex3f(23, 0, 38);
    glVertex3f(18, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 30);
    glVertex3f(23, 0, 30);
    glVertex3f(23, 0, 38);
    glVertex3f(18, 0, 38);
    glEnd();

    //Kaca2
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 0, 30);
    glVertex3f(28, 0, 30);
    glVertex3f(28, 0, 38);
    glVertex3f(23, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 0, 30);
    glVertex3f(28, 0, 30);
    glVertex3f(28, 0, 38);
    glVertex3f(23, 0, 38);
    glEnd();

    //Kaca3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 0, 30);
    glVertex3f(33, 0, 30);
    glVertex3f(33, 0, 38);
    glVertex3f(28, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 0, 30);
    glVertex3f(33, 0, 30);
    glVertex3f(33, 0, 38);
    glVertex3f(28, 0, 38);
    glEnd();

    //Kaca4
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 0, 30);
    glVertex3f(38, 0, 30);
    glVertex3f(38, 0, 38);
    glVertex3f(33, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 0, 30);
    glVertex3f(38, 0, 30);
    glVertex3f(38, 0, 38);
    glVertex3f(33, 0, 38);
    glEnd();

    //Kaca5
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 0, 30);
    glVertex3f(43, 0, 30);
    glVertex3f(43, 0, 38);
    glVertex3f(38, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 0, 30);
    glVertex3f(43, 0, 30);
    glVertex3f(43, 0, 38);
    glVertex3f(38, 0, 38);
    glEnd();

    //Kaca6
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 0, 30);
    glVertex3f(48, 0, 30);
    glVertex3f(48, 0, 38);
    glVertex3f(43, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 0, 30);
    glVertex3f(48, 0, 30);
    glVertex3f(48, 0, 38);
    glVertex3f(43, 0, 38);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 0, 30);
    glVertex3f(48, 5, 30);
    glVertex3f(48, 5, 38);
    glVertex3f(48, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 0, 30);
    glVertex3f(48, 5, 30);
    glVertex3f(48, 5, 38);
    glVertex3f(48, 0, 38);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 5, 30);
    glVertex3f(48, 10, 30);
    glVertex3f(48, 10, 38);
    glVertex3f(48, 5, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 5, 30);
    glVertex3f(48, 10, 30);
    glVertex3f(48, 10, 38);
    glVertex3f(48, 5, 38);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 10, 30);
    glVertex3f(48, 15, 30);
    glVertex3f(48, 15, 38);
    glVertex3f(48, 10, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 10, 30);
    glVertex3f(48, 15, 30);
    glVertex3f(48, 15, 38);
    glVertex3f(48, 10, 38);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 15, 30);
    glVertex3f(48, 20, 30);
    glVertex3f(48, 20, 38);
    glVertex3f(48, 15, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 15, 30);
    glVertex3f(48, 20, 30);
    glVertex3f(48, 20, 38);
    glVertex3f(48, 15, 38);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 20, 30);
    glVertex3f(23, 20, 30);
    glVertex3f(23, 20, 38);
    glVertex3f(18, 20, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 20, 30);
    glVertex3f(23, 20, 30);
    glVertex3f(23, 20, 38);
    glVertex3f(18, 20, 38);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 30);
    glVertex3f(28, 20, 30);
    glVertex3f(28, 20, 38);
    glVertex3f(23, 20, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 30);
    glVertex3f(28, 20, 30);
    glVertex3f(28, 20, 38);
    glVertex3f(23, 20, 38);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 30);
    glVertex3f(33, 20, 30);
    glVertex3f(33, 20, 38);
    glVertex3f(28, 20, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 30);
    glVertex3f(33, 20, 30);
    glVertex3f(33, 20, 38);
    glVertex3f(28, 20, 38);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 30);
    glVertex3f(38, 20, 30);
    glVertex3f(38, 20, 38);
    glVertex3f(33, 20, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 30);
    glVertex3f(38, 20, 30);
    glVertex3f(38, 20, 38);
    glVertex3f(33, 20, 38);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 30);
    glVertex3f(43, 20, 30);
    glVertex3f(43, 20, 38);
    glVertex3f(38, 20, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 30);
    glVertex3f(43, 20, 30);
    glVertex3f(43, 20, 38);
    glVertex3f(38, 20, 38);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 30);
    glVertex3f(48, 20, 30);
    glVertex3f(48, 20, 38);
    glVertex3f(43, 20, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 30);
    glVertex3f(48, 20, 30);
    glVertex3f(48, 20, 38);
    glVertex3f(43, 20, 38);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 30);
    glVertex3f(18, 5, 30);
    glVertex3f(18, 5, 38);
    glVertex3f(18, 0, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 30);
    glVertex3f(18, 5, 30);
    glVertex3f(18, 5, 38);
    glVertex3f(18, 0, 38);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 5, 30);
    glVertex3f(18, 10, 30);
    glVertex3f(18, 10, 38);
    glVertex3f(18, 5, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 5, 30);
    glVertex3f(18, 10, 30);
    glVertex3f(18, 10, 38);
    glVertex3f(18, 5, 38);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 10, 30);
    glVertex3f(18, 15, 30);
    glVertex3f(18, 15, 38);
    glVertex3f(18, 10, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 10, 30);
    glVertex3f(18, 15, 30);
    glVertex3f(18, 15, 38);
    glVertex3f(18, 10, 38);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 15, 30);
    glVertex3f(18, 20, 30);
    glVertex3f(18, 20, 38);
    glVertex3f(18, 15, 38);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 15, 30);
    glVertex3f(18, 20, 30);
    glVertex3f(18, 20, 38);
    glVertex3f(18, 15, 38);
    glEnd();



    //--------Lantai5--------//
    //AlasDepan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 38);
    glVertex3f(48, 0, 38);
    glVertex3f(48, 0, 40);
    glVertex3f(18, 0, 40);
    glEnd();

    //AlasKanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 38);
    glVertex3f(48, 20, 38);
    glVertex3f(48, 20, 40);
    glVertex3f(48, 0, 40);
    glEnd();

    //AlasBelakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 38);
    glVertex3f(48, 20, 38);
    glVertex3f(48, 20, 40);
    glVertex3f(18, 20, 40);
    glEnd();

    //AlasKiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 38);
    glVertex3f(18, 20, 38);
    glVertex3f(18, 20, 40);
    glVertex3f(18, 0, 40);
    glEnd();

    //AlasLantai
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 40);
    glVertex3f(48, 0, 40);
    glVertex3f(48, 20, 40);
    glVertex3f(18, 20, 40);
    glEnd();

    //Kaca1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 40);
    glVertex3f(23, 0, 40);
    glVertex3f(23, 0, 48);
    glVertex3f(18, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 40);
    glVertex3f(23, 0, 40);
    glVertex3f(23, 0, 48);
    glVertex3f(18, 0, 48);
    glEnd();

    //Kaca2
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 0, 40);
    glVertex3f(28, 0, 40);
    glVertex3f(28, 0, 48);
    glVertex3f(23, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 0, 40);
    glVertex3f(28, 0, 40);
    glVertex3f(28, 0, 48);
    glVertex3f(23, 0, 48);
    glEnd();

    //Kaca3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 0, 40);
    glVertex3f(33, 0, 40);
    glVertex3f(33, 0, 48);
    glVertex3f(28, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 0, 40);
    glVertex3f(33, 0, 40);
    glVertex3f(33, 0, 48);
    glVertex3f(28, 0, 48);
    glEnd();

    //Kaca4
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 0, 40);
    glVertex3f(38, 0, 40);
    glVertex3f(38, 0, 48);
    glVertex3f(33, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 0, 40);
    glVertex3f(38, 0, 40);
    glVertex3f(38, 0, 48);
    glVertex3f(33, 0, 48);
    glEnd();

    //Kaca5
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 0, 40);
    glVertex3f(43, 0, 40);
    glVertex3f(43, 0, 48);
    glVertex3f(38, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 0, 40);
    glVertex3f(43, 0, 40);
    glVertex3f(43, 0, 48);
    glVertex3f(38, 0, 48);
    glEnd();

    //Kaca6
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 0, 40);
    glVertex3f(48, 0, 40);
    glVertex3f(48, 0, 48);
    glVertex3f(43, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 0, 40);
    glVertex3f(48, 0, 40);
    glVertex3f(48, 0, 48);
    glVertex3f(43, 0, 48);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 0, 40);
    glVertex3f(48, 5, 40);
    glVertex3f(48, 5, 48);
    glVertex3f(48, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 0, 40);
    glVertex3f(48, 5, 40);
    glVertex3f(48, 5, 48);
    glVertex3f(48, 0, 48);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 5, 40);
    glVertex3f(48, 10, 40);
    glVertex3f(48, 10, 48);
    glVertex3f(48, 5, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 5, 40);
    glVertex3f(48, 10, 40);
    glVertex3f(48, 10, 48);
    glVertex3f(48, 5, 48);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 10, 40);
    glVertex3f(48, 15, 40);
    glVertex3f(48, 15, 48);
    glVertex3f(48, 10, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 10, 40);
    glVertex3f(48, 15, 40);
    glVertex3f(48, 15, 48);
    glVertex3f(48, 10, 48);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 15, 40);
    glVertex3f(48, 20, 40);
    glVertex3f(48, 20, 48);
    glVertex3f(48, 15, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 15, 40);
    glVertex3f(48, 20, 40);
    glVertex3f(48, 20, 48);
    glVertex3f(48, 15, 48);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 20, 40);
    glVertex3f(23, 20, 40);
    glVertex3f(23, 20, 48);
    glVertex3f(18, 20, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 20, 40);
    glVertex3f(23, 20, 40);
    glVertex3f(23, 20, 48);
    glVertex3f(18, 20, 48);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 40);
    glVertex3f(28, 20, 40);
    glVertex3f(28, 20, 48);
    glVertex3f(23, 20, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 40);
    glVertex3f(28, 20, 40);
    glVertex3f(28, 20, 48);
    glVertex3f(23, 20, 48);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 40);
    glVertex3f(33, 20, 40);
    glVertex3f(33, 20, 48);
    glVertex3f(28, 20, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 40);
    glVertex3f(33, 20, 40);
    glVertex3f(33, 20, 48);
    glVertex3f(28, 20, 48);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 40);
    glVertex3f(38, 20, 40);
    glVertex3f(38, 20, 48);
    glVertex3f(33, 20, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 40);
    glVertex3f(38, 20, 40);
    glVertex3f(38, 20, 48);
    glVertex3f(33, 20, 48);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 40);
    glVertex3f(43, 20, 40);
    glVertex3f(43, 20, 48);
    glVertex3f(38, 20, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 40);
    glVertex3f(43, 20, 40);
    glVertex3f(43, 20, 48);
    glVertex3f(38, 20, 48);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 40);
    glVertex3f(48, 20, 40);
    glVertex3f(48, 20, 48);
    glVertex3f(43, 20, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 40);
    glVertex3f(48, 20, 40);
    glVertex3f(48, 20, 48);
    glVertex3f(43, 20, 48);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 40);
    glVertex3f(18, 5, 40);
    glVertex3f(18, 5, 48);
    glVertex3f(18, 0, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 40);
    glVertex3f(18, 5, 40);
    glVertex3f(18, 5, 48);
    glVertex3f(18, 0, 48);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 5, 40);
    glVertex3f(18, 10, 40);
    glVertex3f(18, 10, 48);
    glVertex3f(18, 5, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 5, 40);
    glVertex3f(18, 10, 40);
    glVertex3f(18, 10, 48);
    glVertex3f(18, 5, 48);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 10, 40);
    glVertex3f(18, 15, 40);
    glVertex3f(18, 15, 48);
    glVertex3f(18, 10, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 10, 40);
    glVertex3f(18, 15, 40);
    glVertex3f(18, 15, 48);
    glVertex3f(18, 10, 48);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 15, 40);
    glVertex3f(18, 20, 40);
    glVertex3f(18, 20, 48);
    glVertex3f(18, 15, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 15, 40);
    glVertex3f(18, 20, 40);
    glVertex3f(18, 20, 48);
    glVertex3f(18, 15, 48);
    glEnd();

    //--------Lantai6--------//
   //AlasDepan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 48);
    glVertex3f(48, 0, 48);
    glVertex3f(48, 0, 50);
    glVertex3f(18, 0, 50);
    glEnd();

    //AlasKanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 48);
    glVertex3f(48, 20, 48);
    glVertex3f(48, 20, 50);
    glVertex3f(48, 0, 50);
    glEnd();

    //AlasBelakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 48);
    glVertex3f(48, 20, 48);
    glVertex3f(48, 20, 50);
    glVertex3f(18, 20, 50);
    glEnd();

    //AlasKiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 48);
    glVertex3f(18, 20, 48);
    glVertex3f(18, 20, 50);
    glVertex3f(18, 0, 50);
    glEnd();

    //AlasLantai
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 50);
    glVertex3f(48, 0, 50);
    glVertex3f(48, 20, 50);
    glVertex3f(18, 20, 50);
    glEnd();

    //Kaca1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 50);
    glVertex3f(23, 0, 50);
    glVertex3f(23, 0, 58);
    glVertex3f(18, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 50);
    glVertex3f(23, 0, 50);
    glVertex3f(23, 0, 58);
    glVertex3f(18, 0, 58);
    glEnd();

    //Kaca2
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 0, 50);
    glVertex3f(28, 0, 50);
    glVertex3f(28, 0, 58);
    glVertex3f(23, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 0, 50);
    glVertex3f(28, 0, 50);
    glVertex3f(28, 0, 58);
    glVertex3f(23, 0, 58);
    glEnd();

    //Kaca3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 0, 50);
    glVertex3f(33, 0, 50);
    glVertex3f(33, 0, 58);
    glVertex3f(28, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 0, 50);
    glVertex3f(33, 0, 50);
    glVertex3f(33, 0, 58);
    glVertex3f(28, 0, 58);
    glEnd();

    //Kaca4
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 0, 50);
    glVertex3f(38, 0, 50);
    glVertex3f(38, 0, 58);
    glVertex3f(33, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 0, 50);
    glVertex3f(38, 0, 50);
    glVertex3f(38, 0, 58);
    glVertex3f(33, 0, 58);
    glEnd();

    //Kaca5
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 0, 50);
    glVertex3f(43, 0, 50);
    glVertex3f(43, 0, 58);
    glVertex3f(38, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 0, 50);
    glVertex3f(43, 0, 50);
    glVertex3f(43, 0, 58);
    glVertex3f(38, 0, 58);
    glEnd();

    //Kaca6
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 0, 50);
    glVertex3f(48, 0, 50);
    glVertex3f(48, 0, 58);
    glVertex3f(43, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 0, 50);
    glVertex3f(48, 0, 50);
    glVertex3f(48, 0, 58);
    glVertex3f(43, 0, 58);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 0, 50);
    glVertex3f(48, 5, 50);
    glVertex3f(48, 5, 58);
    glVertex3f(48, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 0, 50);
    glVertex3f(48, 5, 50);
    glVertex3f(48, 5, 58);
    glVertex3f(48, 0, 58);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 5, 50);
    glVertex3f(48, 10, 50);
    glVertex3f(48, 10, 58);
    glVertex3f(48, 5, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 5, 50);
    glVertex3f(48, 10, 50);
    glVertex3f(48, 10, 58);
    glVertex3f(48, 5, 58);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 10, 50);
    glVertex3f(48, 15, 50);
    glVertex3f(48, 15, 58);
    glVertex3f(48, 10, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 10, 50);
    glVertex3f(48, 15, 50);
    glVertex3f(48, 15, 58);
    glVertex3f(48, 10, 58);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 15, 50);
    glVertex3f(48, 20, 50);
    glVertex3f(48, 20, 58);
    glVertex3f(48, 15, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 15, 50);
    glVertex3f(48, 20, 50);
    glVertex3f(48, 20, 58);
    glVertex3f(48, 15, 58);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 20, 50);
    glVertex3f(23, 20, 50);
    glVertex3f(23, 20, 58);
    glVertex3f(18, 20, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 20, 50);
    glVertex3f(23, 20, 50);
    glVertex3f(23, 20, 58);
    glVertex3f(18, 20, 58);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 50);
    glVertex3f(28, 20, 50);
    glVertex3f(28, 20, 58);
    glVertex3f(23, 20, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 50);
    glVertex3f(28, 20, 50);
    glVertex3f(28, 20, 58);
    glVertex3f(23, 20, 58);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 50);
    glVertex3f(33, 20, 50);
    glVertex3f(33, 20, 58);
    glVertex3f(28, 20, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 50);
    glVertex3f(33, 20, 50);
    glVertex3f(33, 20, 58);
    glVertex3f(28, 20, 58);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 50);
    glVertex3f(38, 20, 50);
    glVertex3f(38, 20, 58);
    glVertex3f(33, 20, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 50);
    glVertex3f(38, 20, 50);
    glVertex3f(38, 20, 58);
    glVertex3f(33, 20, 58);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 50);
    glVertex3f(43, 20, 50);
    glVertex3f(43, 20, 58);
    glVertex3f(38, 20, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 50);
    glVertex3f(43, 20, 50);
    glVertex3f(43, 20, 58);
    glVertex3f(38, 20, 58);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 50);
    glVertex3f(48, 20, 50);
    glVertex3f(48, 20, 58);
    glVertex3f(43, 20, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 50);
    glVertex3f(48, 20, 50);
    glVertex3f(48, 20, 58);
    glVertex3f(43, 20, 58);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 50);
    glVertex3f(18, 5, 50);
    glVertex3f(18, 5, 58);
    glVertex3f(18, 0, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 50);
    glVertex3f(18, 5, 50);
    glVertex3f(18, 5, 58);
    glVertex3f(18, 0, 58);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 5, 50);
    glVertex3f(18, 10, 50);
    glVertex3f(18, 10, 58);
    glVertex3f(18, 5, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 5, 50);
    glVertex3f(18, 10, 50);
    glVertex3f(18, 10, 58);
    glVertex3f(18, 5, 58);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 10, 50);
    glVertex3f(18, 15, 50);
    glVertex3f(18, 15, 58);
    glVertex3f(18, 10, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 10, 50);
    glVertex3f(18, 15, 50);
    glVertex3f(18, 15, 58);
    glVertex3f(18, 10, 58);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 15, 50);
    glVertex3f(18, 20, 50);
    glVertex3f(18, 20, 58);
    glVertex3f(18, 15, 58);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 15, 50);
    glVertex3f(18, 20, 50);
    glVertex3f(18, 20, 58);
    glVertex3f(18, 15, 58);
    glEnd();

    //--------Lantai7--------//
//AlasDepan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 58);
    glVertex3f(48, 0, 58);
    glVertex3f(48, 0, 60);
    glVertex3f(18, 0, 60);
    glEnd();

    //AlasKanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 58);
    glVertex3f(48, 20, 58);
    glVertex3f(48, 20, 60);
    glVertex3f(48, 0, 60);
    glEnd();

    //AlasBelakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 58);
    glVertex3f(48, 20, 58);
    glVertex3f(48, 20, 60);
    glVertex3f(18, 20, 60);
    glEnd();

    //AlasKiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 58);
    glVertex3f(18, 20, 58);
    glVertex3f(18, 20, 60);
    glVertex3f(18, 0, 60);
    glEnd();

    //AlasLantai
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 60);
    glVertex3f(48, 0, 60);
    glVertex3f(48, 20, 60);
    glVertex3f(18, 20, 60);
    glEnd();

    //Kaca1
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 60);
    glVertex3f(23, 0, 60);
    glVertex3f(23, 0, 68);
    glVertex3f(18, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 60);
    glVertex3f(23, 0, 60);
    glVertex3f(23, 0, 68);
    glVertex3f(18, 0, 68);
    glEnd();

    //Kaca2
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 0, 60);
    glVertex3f(28, 0, 60);
    glVertex3f(28, 0, 68);
    glVertex3f(23, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 0, 60);
    glVertex3f(28, 0, 60);
    glVertex3f(28, 0, 68);
    glVertex3f(23, 0, 68);
    glEnd();

    //Kaca3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 0, 60);
    glVertex3f(33, 0, 60);
    glVertex3f(33, 0, 68);
    glVertex3f(28, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 0, 60);
    glVertex3f(33, 0, 60);
    glVertex3f(33, 0, 68);
    glVertex3f(28, 0, 68);
    glEnd();

    //Kaca4
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 0, 60);
    glVertex3f(38, 0, 60);
    glVertex3f(38, 0, 68);
    glVertex3f(33, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 0, 60);
    glVertex3f(38, 0, 60);
    glVertex3f(38, 0, 68);
    glVertex3f(33, 0, 68);
    glEnd();

    //Kaca5
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 0, 60);
    glVertex3f(43, 0, 60);
    glVertex3f(43, 0, 68);
    glVertex3f(38, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 0, 60);
    glVertex3f(43, 0, 60);
    glVertex3f(43, 0, 68);
    glVertex3f(38, 0, 68);
    glEnd();

    //Kaca6
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 0, 60);
    glVertex3f(48, 0, 60);
    glVertex3f(48, 0, 68);
    glVertex3f(43, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 0, 60);
    glVertex3f(48, 0, 60);
    glVertex3f(48, 0, 68);
    glVertex3f(43, 0, 68);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 0, 60);
    glVertex3f(48, 5, 60);
    glVertex3f(48, 5, 68);
    glVertex3f(48, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 0, 60);
    glVertex3f(48, 5, 60);
    glVertex3f(48, 5, 68);
    glVertex3f(48, 0, 68);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 5, 60);
    glVertex3f(48, 10, 60);
    glVertex3f(48, 10, 68);
    glVertex3f(48, 5, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 5, 60);
    glVertex3f(48, 10, 60);
    glVertex3f(48, 10, 68);
    glVertex3f(48, 5, 68);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 10, 60);
    glVertex3f(48, 15, 60);
    glVertex3f(48, 15, 68);
    glVertex3f(48, 10, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 10, 60);
    glVertex3f(48, 15, 60);
    glVertex3f(48, 15, 68);
    glVertex3f(48, 10, 68);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(48, 15, 60);
    glVertex3f(48, 20, 60);
    glVertex3f(48, 20, 68);
    glVertex3f(48, 15, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(48, 15, 60);
    glVertex3f(48, 20, 60);
    glVertex3f(48, 20, 68);
    glVertex3f(48, 15, 68);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 20, 60);
    glVertex3f(23, 20, 60);
    glVertex3f(23, 20, 68);
    glVertex3f(18, 20, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 20, 60);
    glVertex3f(23, 20, 60);
    glVertex3f(23, 20, 68);
    glVertex3f(18, 20, 68);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 60);
    glVertex3f(28, 20, 60);
    glVertex3f(28, 20, 68);
    glVertex3f(23, 20, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 60);
    glVertex3f(28, 20, 60);
    glVertex3f(28, 20, 68);
    glVertex3f(23, 20, 68);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 60);
    glVertex3f(33, 20, 60);
    glVertex3f(33, 20, 68);
    glVertex3f(28, 20, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 60);
    glVertex3f(33, 20, 60);
    glVertex3f(33, 20, 68);
    glVertex3f(28, 20, 68);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 60);
    glVertex3f(38, 20, 60);
    glVertex3f(38, 20, 68);
    glVertex3f(33, 20, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 60);
    glVertex3f(38, 20, 60);
    glVertex3f(38, 20, 68);
    glVertex3f(33, 20, 68);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 60);
    glVertex3f(43, 20, 60);
    glVertex3f(43, 20, 68);
    glVertex3f(38, 20, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 60);
    glVertex3f(43, 20, 60);
    glVertex3f(43, 20, 68);
    glVertex3f(38, 20, 68);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 60);
    glVertex3f(48, 20, 60);
    glVertex3f(48, 20, 68);
    glVertex3f(43, 20, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 60);
    glVertex3f(48, 20, 60);
    glVertex3f(48, 20, 68);
    glVertex3f(43, 20, 68);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 0, 60);
    glVertex3f(18, 5, 60);
    glVertex3f(18, 5, 68);
    glVertex3f(18, 0, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 0, 60);
    glVertex3f(18, 5, 60);
    glVertex3f(18, 5, 68);
    glVertex3f(18, 0, 68);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 5, 60);
    glVertex3f(18, 10, 60);
    glVertex3f(18, 10, 68);
    glVertex3f(18, 5, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 5, 60);
    glVertex3f(18, 10, 60);
    glVertex3f(18, 10, 68);
    glVertex3f(18, 5, 68);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 10, 60);
    glVertex3f(18, 15, 60);
    glVertex3f(18, 15, 68);
    glVertex3f(18, 10, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 10, 60);
    glVertex3f(18, 15, 60);
    glVertex3f(18, 15, 68);
    glVertex3f(18, 10, 68);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(18, 15, 60);
    glVertex3f(18, 20, 60);
    glVertex3f(18, 20, 68);
    glVertex3f(18, 15, 68);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(18, 15, 60);
    glVertex3f(18, 20, 60);
    glVertex3f(18, 20, 68);
    glVertex3f(18, 15, 68);
    glEnd();

    //--------Lantai8--------//
   //AlasDepan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 68);
    glVertex3f(48, 0, 68);
    glVertex3f(48, 0, 70);
    glVertex3f(18, 0, 70);
    glEnd();

    //AlasKanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(48, 0, 68);
    glVertex3f(48, 20, 68);
    glVertex3f(48, 20, 70);
    glVertex3f(48, 0, 70);
    glEnd();

    //AlasBelakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 20, 68);
    glVertex3f(48, 20, 68);
    glVertex3f(48, 20, 70);
    glVertex3f(18, 20, 70);
    glEnd();

    //AlasKiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 68);
    glVertex3f(18, 20, 68);
    glVertex3f(18, 20, 70);
    glVertex3f(18, 0, 70);
    glEnd();

    //AlasLantai
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(18, 0, 70);
    glVertex3f(48, 0, 70);
    glVertex3f(48, 20, 70);
    glVertex3f(18, 20, 70);
    glEnd();

    //kaca depan
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 1, 90);
    glVertex3f(47, 1, 90);
    glVertex3f(47, 1, 70);
    glVertex3f(19, 1, 70);
    glEnd();

    //kaca depan2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(18.9, 0.9, 80);
    glVertex3f(46.9, 0.9, 80);
    glVertex3f(46.9, 0.9, 75);
    glVertex3f(18.9, 0.9, 75);
    glEnd();

    //kaca depan3
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(18.9, 0.9, 90);
    glVertex3f(46.9, 0.9, 90);
    glVertex3f(46.9, 0.9, 85);
    glVertex3f(18.9, 0.9, 85);
    glEnd();

    //garis kaca depan
    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(19, 1, 90);
    glVertex3f(47, 1, 90);
    glVertex3f(47, 1, 70);
    glVertex3f(19, 1, 70);
    glEnd();

    //kaca kanan segi3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 1, 90);
    glVertex3f(19, 10, 80);
    glVertex3f(19, 1, 70);
    glEnd();

    //kaca kanan segi3 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(19.1, 1, 80);
    glVertex3f(19.1, 10, 80);
    glVertex3f(19.1, 5.5, 75);
    glVertex3f(19.1, 1, 75);
    glEnd();

    //kaca kanan segi3 3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19.1, 1, 90);
    glVertex3f(19.1, 5.5, 85);
    glVertex3f(19.1, 1, 85);
    glEnd();

    //kaca kiri segi3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(47, 1, 90);
    glVertex3f(47, 10, 80);
    glVertex3f(47, 1, 70);
    glEnd();

    //kaca kiri segi3 2
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.7490196078431373, 1.0, 0.2);
    glVertex3f(47.1, 1, 80);
    glVertex3f(47.1, 10, 80);
    glVertex3f(47.1, 5.5, 75);
    glVertex3f(47.1, 1, 75);
    glEnd();

    //kaca kiri segi3 3
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(47.1, 1, 90);
    glVertex3f(47.1, 5.5, 85);
    glVertex3f(47.1, 1, 85);
    glEnd();

    //garis segitiga kiri
    glBegin(GL_LINES);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    //atas
    glVertex3f(19, 1, 90);
    glVertex3f(19, 10, 80);
    //bawah
    glVertex3f(19, 10, 80);
    glVertex3f(19, 1, 70);
    glEnd();

    //garis segitiga kanan
    glBegin(GL_LINES);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    //atas
    glVertex3f(47, 1, 90);
    glVertex3f(47, 10, 80);
    //bawah
    glVertex3f(47, 10, 80);
    glVertex3f(47, 1, 70);
    glEnd();

    //Kaca7
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(47, 1, 70);
    glVertex3f(47, 5, 70);
    glVertex3f(47, 5, 74.5);
    glVertex3f(47, 1, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(47, 1, 70);
    glVertex3f(47, 5, 70);
    glVertex3f(47, 5, 74.5);
    glVertex3f(47, 1, 70);
    glEnd();

    //Kaca8
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(47, 5, 70);
    glVertex3f(47, 10, 70);
    glVertex3f(47, 10, 80);
    glVertex3f(47, 5, 74.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(47, 5, 70);
    glVertex3f(47, 10, 70);
    glVertex3f(47, 10, 80);
    glVertex3f(47, 5, 74.5);
    glEnd();

    //Kaca9
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(47, 10, 70);
    glVertex3f(47, 15, 70);
    glVertex3f(47, 15, 80);
    glVertex3f(47, 10, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(47, 10, 70);
    glVertex3f(47, 15, 70);
    glVertex3f(47, 15, 80);
    glVertex3f(47, 10, 80);
    glEnd();

    //Kaca10
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(47, 15, 70);
    glVertex3f(47, 20, 70);
    glVertex3f(47, 20, 80);
    glVertex3f(47, 15, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(47, 15, 70);
    glVertex3f(47, 20, 70);
    glVertex3f(47, 20, 80);
    glVertex3f(47, 15, 80);
    glEnd();

    //Kaca11
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 20, 70);
    glVertex3f(23, 20, 70);
    glVertex3f(23, 20, 80);
    glVertex3f(19, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(19, 20, 70);
    glVertex3f(23, 20, 70);
    glVertex3f(23, 20, 80);
    glVertex3f(19, 20, 80);
    glEnd();

    //Kaca12
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(23, 20, 70);
    glVertex3f(28, 20, 70);
    glVertex3f(28, 20, 80);
    glVertex3f(23, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(23, 20, 70);
    glVertex3f(28, 20, 70);
    glVertex3f(28, 20, 80);
    glVertex3f(23, 20, 80);
    glEnd();

    //Kaca13
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(28, 20, 70);
    glVertex3f(33, 20, 70);
    glVertex3f(33, 20, 80);
    glVertex3f(28, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(28, 20, 70);
    glVertex3f(33, 20, 70);
    glVertex3f(33, 20, 80);
    glVertex3f(28, 20, 80);
    glEnd();

    //Kaca14
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(33, 20, 70);
    glVertex3f(38, 20, 70);
    glVertex3f(38, 20, 80);
    glVertex3f(33, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(33, 20, 70);
    glVertex3f(38, 20, 70);
    glVertex3f(38, 20, 80);
    glVertex3f(33, 20, 80);
    glEnd();

    //Kaca15
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(38, 20, 70);
    glVertex3f(43, 20, 70);
    glVertex3f(43, 20, 80);
    glVertex3f(38, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(38, 20, 70);
    glVertex3f(43, 20, 70);
    glVertex3f(43, 20, 80);
    glVertex3f(38, 20, 80);
    glEnd();

    //Kaca16
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(43, 20, 70);
    glVertex3f(47, 20, 70);
    glVertex3f(47, 20, 80);
    glVertex3f(43, 20, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(43, 20, 70);
    glVertex3f(47, 20, 70);
    glVertex3f(47, 20, 80);
    glVertex3f(43, 20, 80);
    glEnd();

    //Kaca17
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 1, 70);
    glVertex3f(19, 5, 70);
    glVertex3f(19, 5, 74.5);
    glVertex3f(19, 1, 70);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(19, 1, 70);
    glVertex3f(19, 5, 70);
    glVertex3f(19, 5, 74.5);
    glVertex3f(19, 1, 70);
    glEnd();

    //Kaca18
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 5, 70);
    glVertex3f(19, 10, 70);
    glVertex3f(19, 10, 80);
    glVertex3f(19, 5, 74.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(19, 5, 70);
    glVertex3f(19, 10, 70);
    glVertex3f(19, 10, 80);
    glVertex3f(19, 5, 74.5);
    glEnd();

    //Kaca19
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 10, 70);
    glVertex3f(19, 15, 70);
    glVertex3f(19, 15, 80);
    glVertex3f(19, 10, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(19, 10, 70);
    glVertex3f(19, 15, 70);
    glVertex3f(19, 15, 80);
    glVertex3f(19, 10, 80);
    glEnd();

    //Kaca20
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 0.2);
    glVertex3f(19, 15, 70);
    glVertex3f(19, 20, 70);
    glVertex3f(19, 20, 80);
    glVertex3f(19, 15, 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.7529411764705882, 0.7529411764705882, 0.7529411764705882);
    glVertex3f(19, 15, 70);
    glVertex3f(19, 20, 70);
    glVertex3f(19, 20, 80);
    glVertex3f(19, 15, 80);
    glEnd();

    //Atap1
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(19, 1, 90);
    glVertex3f(47, 1, 90);
    glVertex3f(47, 10, 80);
    glVertex3f(19, 10, 80);
    glEnd();

    //Atap2
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(19, 10, 80);
    glVertex3f(47, 10, 80);
    glVertex3f(47, 20, 80);
    glVertex3f(19, 20, 80);
    glEnd();
 

    glPopMatrix();
    glutSwapBuffers();
}


void keyboar(unsigned char key, int x, int y) {
    switch (key)
    {
    case'w':
    case'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case'd':
    case'D':
        glTranslatef(3.0, 0.0, 0.0);
    case's':
    case'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case'a':
    case'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case'7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case'9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case'2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case'8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case'6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case'4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case'1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case'3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case'5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    home();
}


void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 20.0, 200.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(200, 80);
    glutInitWindowSize(800, 800);
    glutCreateWindow("672019120 - 672019226 - 	672019241");
    init();
    glutDisplayFunc(home);
    glutKeyboardFunc(keyboar);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

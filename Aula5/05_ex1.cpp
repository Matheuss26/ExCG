#include <iostream>
#include <GL/glut.h>
#include <stdio.h>

void plotTriangle (float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f (x1, y1);    glVertex2f (x2, y2);    glVertex2f (x3, y3);
    glEnd();
}


float T1_x = 0.3, T1_y = 0.4, 
      T1_x_DIR = 0.1, T1_y_DIR = 0.1,
      T1_x_LIM_SUP = 0.6, T1_y_LIM_SUP = 0.5,
      T1_x_LIM_INF = 0.2, T1_y_LIM_INF = 0.2;

float T2_x = 0.2, T2_y = 0.2,
      T2_x_DIR = 0.1, T2_y_DIR = 0.1,
      T2_x_LIM_SUP = 0.6, T2_y_LIM_SUP = 0.6,
      T2_x_LIM_INF = 0.4, T2_y_LIM_INF = 0.5;

void display(void){
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glColor3f (0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(T1_x, T1_y, 0);
    glBegin(GL_TRIANGLES);
    plotTriangle(0.5, T1_y_LIM_INF, T1_x_LIM_SUP, 0.4, T1_x_LIM_INF, T1_y_LIM_SUP);
    glEnd();
    glPopMatrix();
    glColor3f (1.0, 0.0, 1.0);

    glPushMatrix();
    glTranslatef(T2_x, T2_y, 0);
    plotTriangle(0.5, T2_y_LIM_SUP, T2_x_LIM_SUP, T2_y_LIM_INF, T2_x_LIM_INF, 0.5);
    glPopMatrix();

    glutSwapBuffers ();
}
float tempoAnterior = 0.0;
void idle(){
    float My_FPS = 10;
    float FPS, FPObjetivo, FPReal;

    FPS = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    FPReal = FPS - tempoAnterior;
    FPObjetivo = 1/(float)(My_FPS);

    if( FPReal <= FPObjetivo) return;
    else {
        tempoAnterior = FPS;

        if(T1_x_LIM_SUP + T1_x >= 1 || T1_x_LIM_INF + T1_x <= 0.1) T1_x_DIR *= -1;
        if(T1_y_LIM_SUP + T1_y >= 1 || T1_y_LIM_INF + T1_y <= 0.1) T1_y_DIR *= -1;
        if(T2_x_LIM_SUP + T2_x >= 1 || T2_x_LIM_INF + T2_x <= 0) T2_x_DIR *= -1;
        if(T2_y_LIM_SUP + T2_y >= 1 || T2_y_LIM_INF + T2_y <= 0) T2_y_DIR *= -1;

        T1_x += T1_x_DIR;
        T1_y += T1_y_DIR;
        T2_x += T2_x_DIR;
        T2_y += T2_y_DIR;

        glutPostRedisplay();
    }
}

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("screensaver");

    glutIdleFunc(idle);
    init();
    glutFullScreen();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

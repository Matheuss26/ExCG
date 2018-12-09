#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(void)
{
   glClearColor(0.0,0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);
}

// Eixos coordenados
void DesenhaEixos()
{
   glBegin(GL_LINES);
      glColor3f (1.0, 0.0, 0.0);
      glVertex3f(-10.0, 0.0, 0.0);
      glVertex3f( 10.0, 0.0, 0.0);
      glColor3f (  0.0,   1.0, 0.0);
      glVertex3f(0.0, -10.0, 0.0);
      glVertex3f(0.0,  10.0, 0.0);
   glEnd();
}

void DesenhaObjetos()
{  
   //triangulo amarelo
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f(2.0-1, 2.0, 0.0);
      glVertex3f(8.0-1, 2.0, 0.0);
      glVertex3f(2.0-1, 8.0, 0.0);
   glEnd();

   //triangulo vermelho
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f(2.0, -2.0, 0.0);
      glVertex3f(8.0, -2.0, 0.0);
      glVertex3f(2.0, -8.0, 0.0);
   glEnd();

   //quadrado verde
   glColor3f(0.0, 1.0, 0.0); 
   glBegin(GL_POLYGON);
      glVertex3f(-4.0, -3.5, 0.0);
      glVertex3f(-1.0, -3.5, 0.0);
      glVertex3f(-1.0, -0.5, 0.0);
      glVertex3f(-4.0, -0.5, 0.0);
   glEnd();

   //quadrado azul
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex3f(-4.0, 5.0, 0.0);
      glVertex3f(-1.0, 5.0, 0.0);
      glVertex3f(-1.0, 2.0, 0.0);
      glVertex3f(-4.0, 2.0, 0.0);
   glEnd();
}

///////////////////////////////////////////////////////////
// Glut and image functions
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Define viewport do canto inferior esquerdo
   glViewport ((int) 10, (int) 10, (int) 190, (int) 190);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-10.0, 10.0, -10.0, 10.0, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   DesenhaEixos();
   DesenhaObjetos();
   
   
   // quadrado azul
   glViewport ((int) 400, (int) 10, (int) 190, (int) 190);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-4, 1, -1, 5, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   DesenhaEixos();
   DesenhaObjetos();

    // quadrado verde
   glViewport ((int) 20, (int) 250, (int) 190, (int) 190);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-4, 1.0, -4.5, 0.5, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   DesenhaEixos();
   DesenhaObjetos();


   // Define segunda viewport
   glViewport ((int) 400, (int) 250, (int) 190, (int) 190);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-0.5, 9.0, 1.0, 9.0, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   DesenhaEixos();
   DesenhaObjetos();
   glutSwapBuffers();
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize(640, 480);
   glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
   glutCreateWindow("Viewport");
   init();
   
   glutDisplayFunc(display);  // Eh quem ira chamar todo o restante das funçoes
   
   glutMainLoop();


   return 0;
}

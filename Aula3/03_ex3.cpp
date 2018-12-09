#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int desiredFPS = 30;

float xtrans = -2.5, ytrans = -2.5, xtransTemp = xtrans, ytransTemp = ytrans;

void display(void);
void init (void);
void idle();
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (480, 480);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("tabuleiro");
   glutIdleFunc( idle);
   glutMouseFunc( mouse );
   init ();
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}

void tabuleiro () {
  for (int linha = -3; linha < 3; linha++) {
      for (int coluna = -3; coluna < 3; coluna ++) {
        
        if (linha % 2 == 0) {
          if (coluna % 2 == 0) glColor3f (255.0, 255.0, 255.0);
          else glColor3f (0.0, 0.0, 0.0);
        } else {
          if (coluna % 2 == 0) glColor3f (0.0, 0.0, 0.0);
          else glColor3f (255.0, 255.0, 255.0);
        }

        glBegin(GL_POLYGON);
          glVertex3f(linha, coluna, 0);
          glVertex3f(linha + 1, coluna, 0);
          glVertex3f(linha + 1, coluna + 1, 0);
          glVertex3f(linha, coluna + 1, 0);
        glEnd();
      }
   }
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity(); 

   tabuleiro();

   glPushMatrix();
      glColor3f(255.0, 0.0, 0.0);
      glTranslatef(xtransTemp, ytransTemp, 0.0);
      glutSolidSphere(0.5, 20, 20);
   glPopMatrix();

   glutSwapBuffers ();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-3, 3, -3, 3, -3, 3);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void attCircle () {
    if (xtransTemp < xtrans)
      xtransTemp += 0.25;
    else if (xtransTemp > xtrans)
      xtransTemp -= 0.25;
    if (ytransTemp < ytrans)
      ytransTemp += 0.25;
    else if (ytransTemp > ytrans)
      ytransTemp -= 0.25;
}

void idle()
{
    float t, desiredFrameTime, frameTime;
    static float tLast = 0.0;
    t = glutGet(GLUT_ELAPSED_TIME);
    t /= 1000.0;
    frameTime = t - tLast;
    desiredFrameTime = 1.0 / (float) (desiredFPS);
    if( frameTime <= desiredFrameTime)
        return;
     attCircle();
    tLast = t;
    glutPostRedisplay();

}

float defCoord (int x) {
  if (x == 0) 
    return - 2.5;
  else if (x == 1) 
    return - 1.5;
  else if (x == 2) 
    return - 0.5;
  else if (x == 3) 
    return 0.5;
  else if (x == 4) 
    return 1.5;
  else 
    return 2.5;
}

void mouse(int button, int state, int x, int y)
{
  if (xtrans == xtransTemp && ytrans == ytransTemp) {
    int posX = x / 80, posY = (480 - y) / 80;
    xtrans = defCoord(posX);
    ytrans = defCoord(posY);
  }

}

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "extras.h"
#include <math.h>

// Globals
int width  = 1000, height = 500;
float rotationX = 0.0, rotationY = 0.0, sphereSize = 30.0, itX = 8, itY = -1;
float x = 20, y = 400, desiredFPS = 30, y_piv = 20, hMax = 400;

void updatePos () {
   if (x >= 990 || x < 10){ 
      itX *= -1;
      }
   x += itX;
   if (itY < 0) {
      if (y_piv > 4) {
         y_piv += itY;
         y = pow(y_piv, 2);
      } else {
         itY *= -1;
         hMax *= 0.75;
      }
   } else if (itY > 0) {
      y_piv += itY;
      float pivot = pow(y_piv, 2);
      if (pivot <= hMax) {
         y = pivot;
      } else {
         itY *= -1;
      }
   } 
}

void idle()
{
   float t, desiredFrameTime, frameTime;
   static float tLast = 0.0;
   t = glutGet(GLUT_ELAPSED_TIME);
   t /= 1000.0;
   frameTime = t - tLast;
   desiredFrameTime = 1.0 / (float) (desiredFPS);
   if( frameTime <= desiredFrameTime){
     return;
   }
   updatePos();
   tLast = t;
   glutPostRedisplay();
}

void init(void)
{
   glClearColor (0.5, 0.5, 0.5, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);              
	 initLight(width, height);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(0.0, width, 0.0, height, -sphereSize, sphereSize);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   setMaterial();
   glPushMatrix();
      glTranslatef(x, y, 0.0);
      glutSolidSphere(20.0, 100, 100);
    glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   width = w;
   height = h;
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

void specialKeysPress(int key, int x, int y)
{
   switch(key)
   {
      case GLUT_KEY_UP:
         y+=10;
         y_piv += 10;         
      break;

      case GLUT_KEY_RIGHT:
         if (itX != 0) itX += 1;
      break;
      case GLUT_KEY_LEFT:
         if (itX != 0) itX = itX - 1 < 1 ? 1 : itX - 1;
        break;
      default:
   break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (width, height);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Animation Base");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(specialKeysPress);
   glutIdleFunc(idle);
   glutMainLoop();
   return 0;
}

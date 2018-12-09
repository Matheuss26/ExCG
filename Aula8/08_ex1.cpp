#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int width  = 700;
int height = 700;

int anguloRotacao = 0;
float kc = 0.1f;
float kl = 0.04f;
float kq = 0.0005f;

int greenLight = 1, blueLight = 1, redLight = 1;

GLfloat base_ambient[]   = { 0.1, 0.1, 0.1, 1.0 };
GLfloat base_difusa[]    = { 0.8, 0.0, 0.0, 1.0 };
GLfloat base_especular[] = { 0.8, 0.0, 0.0, 1.0 };
GLfloat base_emissao[]   = { 0.0, 0.0, 0.0, 1.0 };
GLfloat base_brilho[]    = { 128.0 };

GLfloat object_ambient[]   = { 0.25725, 0.1995, 0.0745, 1.0 };
GLfloat object_difusa[]    = { 0.80164, 0.60648, 0.22648, 1.0 };
GLfloat object_especular[] = { 0.828281, 0.555802, 0.366065, 1.0 };
GLfloat object_emissao[]   = { 0.0, 0.0, 0.0, 1.0 };
GLfloat object_brilho[]    = { 160.0 };

GLfloat color_light_amb[]	= { 0.02, 0.02, 0.02, 0.02};
GLfloat cor_emissao[]	= { 0.2, 0.2, 0.0, 1.0 };

GLfloat pos_green[] = { -10.0f, 7.0f, 3.5, 1.0};
GLfloat color_green[] = { 0.0, 1.0, 0.0, 1.0};

GLfloat pos_red[] = { 10.0f, 7.0f, 3.5, 1.0};
GLfloat color_red[] = { 1.0, 0.0, 0.0, 1.0};

GLfloat pos_blue[] = { -10.0f, 7.0f, 3.5, 1.0};
GLfloat color_blue[] = { 0.0, 0.0, 1.0, 1.0};

GLfloat tp_ambient[]   = { 0.5, 0.5, 0.5, 1.0 };
GLfloat tp_difusa[]    = { 0.5, 0.5, 0.5, 1.0 };
GLfloat tp_especular[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat tp_emissao[]   = { 0.0, 0.0, 0.0, 1.0 };
GLfloat tp_brilho[]    = { 128.0 };

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);               // Habilita Z-buffer
   glEnable(GL_LIGHTING);                 // Habilita luz
   glEnable(GL_LIGHT0);                   // habilita luz 0
   glEnable(GL_LIGHT1);
   glEnable(GL_LIGHT2);

   GLfloat color_green[] = { 0, 1, 0, 1.0};
   GLfloat color_red[] = { 1, 0, 0, 1.0};
   GLfloat color_blue[] = { 0, 0, 1, 1.0};

   glLightfv(GL_LIGHT0, GL_AMBIENT, color_light_amb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, color_green);
   glLightfv(GL_LIGHT0, GL_SPECULAR, color_green);
   glLightfv(GL_LIGHT0, GL_POSITION, pos_green);

   glLightfv(GL_LIGHT1, GL_AMBIENT, color_light_amb);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, color_red);
   glLightfv(GL_LIGHT1, GL_SPECULAR, color_red);
   glLightfv(GL_LIGHT1, GL_POSITION, pos_red);

   glLightfv(GL_LIGHT2, GL_AMBIENT, color_light_amb);
   glLightfv(GL_LIGHT2, GL_DIFFUSE, color_blue);
   glLightfv(GL_LIGHT2, GL_SPECULAR, color_blue);
   glLightfv(GL_LIGHT2, GL_POSITION, pos_blue);

   printf("\nMenu");
   printf("\n====\n\n");
   printf("Keyboard:\n");
   printf("'q' para ligar ou desligar a luz Azul,  'w' para ligar ou desligar a luz Verde, 'e' para ou desligar a luz Vermelha.\n");
   printf("'a', 's' para girar o bule.\n");
   printf("Setas direita e esquerda movem a luz verde.\n");
   printf("Setas cima e baixo movem a luz vermelha.\n");
   printf("'PageUp' e 'PageDown' movem a luz azul.\n");
   printf("Pressione ESC para sair.\n");
}

void setMaterial(GLfloat *ambiente, GLfloat *difusa, GLfloat *especular,
					  GLfloat *brilho, GLfloat *emissao )
{
   glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, difusa);
   glMaterialfv(GL_FRONT, GL_SPECULAR, especular);
   glMaterialfv(GL_FRONT, GL_SHININESS, brilho);
   glMaterialfv(GL_FRONT, GL_EMISSION, emissao);
}

void drawLines () {
   setMaterial(tp_ambient, tp_difusa, tp_especular, tp_brilho, tp_emissao);
   glLineWidth(4); 
   
   glBegin(GL_LINES); 
      glVertex3f(10.0f, 7.0f, 3.5);
      glVertex3f(10.0f, -2.5f, 10.0);
   glEnd();

   glBegin(GL_LINES);
      glVertex3f(-10.0f, 7.0f, 3.5);
      glVertex3f(-10.0f, -2.5f, 10.0);
   glEnd();

   glBegin(GL_LINES); 
      glVertex3f(-10.0f, 7.0f, 3.5);
      glVertex3f(10.0f, 7.0f, 3.5);
   glEnd();

   glBegin(GL_LINES);
      glVertex3f(9.0f, 7.5f, -10.0);
      glVertex3f(10.0f, -2.5f, -10.0);
   glEnd();

   glBegin(GL_LINES);
      glVertex3f(-9.0f, 7.5f, -10.0);
      glVertex3f(-10.0f, -2.5f, -10.0);
   glEnd();

   glBegin(GL_LINES);
      glVertex3f(10.0f, 7.0f, 3.5);
      glVertex3f(10.0f, 7.0f, -13.0);
   glEnd();

   glBegin(GL_LINES);
      glVertex3f(-10.0f, 7.0f, 3.5);
      glVertex3f(-10.0f, 7.0f, -13.0);
   glEnd();
}

void drawLights() {

   glPushMatrix();
      glTranslatef(pos_green[0],pos_green[1],pos_green[2]);
      glLightfv(GL_LIGHT0, GL_POSITION, pos_green);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, color_green);
      glMaterialfv(GL_FRONT, GL_EMISSION, cor_emissao);
      glutSolidSphere(0.2,30,30);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(pos_red[0],pos_red[1],pos_red[2]);
      glLightfv(GL_LIGHT1, GL_POSITION, pos_red);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, color_red);
      glMaterialfv(GL_FRONT, GL_EMISSION, cor_emissao);
      glutSolidSphere(0.2,30,30);
   glPopMatrix();

   glPushMatrix();
      glTranslatef(pos_blue[0],pos_blue[1],pos_blue[2]);
      glLightfv(GL_LIGHT2, GL_POSITION, pos_blue);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, color_blue);
      glMaterialfv(GL_FRONT, GL_EMISSION, cor_emissao);
      glutSolidSphere(0.2,30,30);
   glPopMatrix();

}

void definirConstantesAtenuacao () {

   glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, kc);
   glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, kl);
   glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, kq);

   glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, kc);
   glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, kl);
   glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, kq);

   glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, kc);
   glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, kl);
   glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, kq);

}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) width/(GLfloat) height, 1.0, 200.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
   gluLookAt (0.0, 15.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   drawLights();
   definirConstantesAtenuacao();

   glPushMatrix();
      setMaterial(object_ambient,object_difusa,object_especular,object_brilho,object_emissao);
      glRotatef(anguloRotacao, 0.0, 1.0, 0.0);
      glutSolidTeapot(5.0);
   glPopMatrix();

	setMaterial(base_ambient,base_difusa,base_especular,base_brilho,base_emissao);
   glBegin(GL_POLYGON);
      glNormal3f(0.5f, 0.35f, 0.05f);
      glVertex3f(-10.0f, -2.5f, -10.0);
      glVertex3f( 10.0f, -2.5f, -10.0);
      glVertex3f( 10.0f, -2.5f,  10.0);
      glVertex3f(-10.0f, -2.5f,  10.0);
   glEnd();

   drawLines();

   glutSwapBuffers();
}

void idle ()
{
   glutPostRedisplay();
}

void reshape (int w, int h)
{
   width = w;
   height = h;
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

void special(int key, int x, int y)
{
   switch (key)
   {
      case GLUT_KEY_LEFT:
         pos_green[0] = pos_green[0] - 0.2 > -10.0 ? pos_green[0] - 0.2 : pos_green[0];
      break;
      case GLUT_KEY_RIGHT:
         pos_green[0] = pos_green[0] - 0.2 < 10.0 ? pos_green[0] + 0.2 : pos_green[0];
      break;
      case GLUT_KEY_UP:
         pos_red[2] = pos_red[2] - 0.2 > -13.0 ? pos_red[2] - 0.2 : pos_red[2];
      break;
      case GLUT_KEY_DOWN:
         pos_red[2] = pos_red[2] + 0.2 < 3.5 ? pos_red[2] + 0.2 : pos_red[2];
      break;
      case GLUT_KEY_PAGE_DOWN:
         pos_blue[2] = pos_blue[2] + 0.2 < 3.5 ? pos_blue[2] + 0.2 : pos_blue[2];;
      break;
      case GLUT_KEY_PAGE_UP:
         pos_blue[2] = pos_blue[2] - 0.2 > -13.0 ? pos_blue[2] - 0.2 : pos_blue[2];
      break;
   }
   glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y)
{
   switch (tolower(key))
   {
      case 'a':
         anguloRotacao = (anguloRotacao + 1) % 360;
         break;
      case 's':
         anguloRotacao = (anguloRotacao - 1) % 360;
         break;
      case 'q':
         blueLight = !blueLight;
         break;
      case 'w':
         greenLight = !greenLight;
         break;
      case 'e':
         redLight = !redLight;
         break;
      case 27:	   exit(0);
         break;
   }

   if (greenLight) glEnable(GL_LIGHT0);
   else glDisable(GL_LIGHT0);

   if (redLight) glEnable(GL_LIGHT1);
   else glDisable(GL_LIGHT1);

   if (blueLight) glEnable(GL_LIGHT2);
   else glDisable(GL_LIGHT2);

   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (width, height);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutIdleFunc(idle);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

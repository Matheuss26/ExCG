#include <stdio.h>
#include <GL/glut.h>


int pos = 0;
void A(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.5, 1.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(0.0, 0.5, 0.0);
		glVertex3f(1.0, 0.5, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f (0.5, 0.5, 0.0);
		glVertex3f (1.0, 0.5, 0.0);
		glVertex3f (0.75, 1.0, 0.0);
		
	glEnd();


   glutSwapBuffers ();
}

void B(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.5, 1.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(0.0, 0.5, 0.0);
		glVertex3f(1.0, 0.5, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f (0.5, 0.5, 0.0);
		glVertex3f (1.0, 0.5, 0.0);
		glVertex3f (0.75, 1.0, 0.0);
		
	glEnd();


   glutSwapBuffers ();
}

void C(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.5, 1.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(0.0, 0.5, 0.0);
		glVertex3f(1.0, 0.5, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
		glVertex3f (0.5, 0.5, 0.0);
		glVertex3f (1.0, 0.5, 0.0);
		glVertex3f (0.75, 1.0, 0.0);
		
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f (0.5, 0.5, 0.0);
		glVertex3f (0.0, 0.5, 0.0);
		glVertex3f (0.25, 0.0, 0.0);
		
	glEnd();


   glutSwapBuffers ();
}

void D(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.5, 1.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(0.0, 0.5, 0.0);
		glVertex3f(1.0, 0.5, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.75, 0.9, 0.0);
		glVertex3f(0.9, 0.5, 0.0);
		glVertex3f(0.75, 0.15, 0.0);
		glVertex3f(0.5, 0.15, 0.0);
		glVertex3f(0.25, 0.15, 0.0);
		glVertex3f(0.1, 0.5, 0.0);
		glVertex3f(0.25, 0.9, 0.0);
		
	glEnd();


   glutSwapBuffers ();
}

void init (void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);              // Seleciona Matriz de Projeção
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); // Aqui que delimita o tamanho do espaco que vai desenhar

   glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
   glLoadIdentity();           // Inicializa com matriz identidade
}

void specialKeysPress(int key, int x, int y)
{
   
   switch(key)
   {
    	case GLUT_KEY_RIGHT:
    		if(pos >= 3)
    			pos = 0;
    		else
    			pos++;
        	switch(pos)
        	{
        		case 0:
					glutDisplayFunc(A);
				break;

				case 1:
					glutDisplayFunc(B);
				break;

				case 2:
					glutDisplayFunc(C);
				break;

				case 3:
					glutDisplayFunc(D);
				break;      		  	
        	}
      	break;    	

   
   }
   glutPostRedisplay();
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
	glutCreateWindow("Aula 2 - Exercicio 1");
	init();
	glutDisplayFunc(A);
	glutSpecialFunc(specialKeysPress);

	glutMainLoop();

	printf("Teste");

	return 0;
}
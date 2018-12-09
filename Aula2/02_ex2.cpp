#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int pos = 0;
void senoideA(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.0, 2.0, 0.0);
		glVertex3f(0.0, -2.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(-5.0, 0.0, 0.0);
		glVertex3f(390.0, 0.0, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);

	float x, y;

	glBegin(GL_LINE_STRIP);
		for(x = 0; x <= 360; x += 60){
		
			y = sin(x*(M_PI/180));
			
			glVertex3f(x, y, 0.0);

	}
		glEnd();
		


   glutSwapBuffers ();
}

void senoideB(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.0, 2.0, 0.0);
		glVertex3f(0.0, -2.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(-5.0, 0.0, 0.0);
		glVertex3f(390.0, 0.0, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);

	float x, y;

	glBegin(GL_LINE_STRIP);
		for(x = 0; x <= 360; x += 30){
		
			y = sin(x*(M_PI/180));
			
			glVertex3f(x, y, 0.0);

	}
		glEnd();
		


   glutSwapBuffers ();
}

void senoideC(){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES); // Vertical
		glVertex3f(0.0, 2.0, 0.0);
		glVertex3f(0.0, -2.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // Horizontal
		glVertex3f(-5.0, 0.0, 0.0);
		glVertex3f(390.0, 0.0, 0.0);
	glEnd();

	glColor3f (0.0, 0.0, 1.0);

	float x, y;

	glBegin(GL_LINE_STRIP);
		for(x = 0; x <= 360; x += 2){
		
			y = sin(x*(M_PI/180));
			
			glVertex3f(x, y, 0.0);

	}
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
   glOrtho(-10.0, 390, -2, 2, -1.0, 1.0); // Aqui que delimita o tamanho do espaco que vai desenhar

   glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
   glLoadIdentity();           // Inicializa com matriz identidade
}

void specialKeysPress(int key, int x, int y)
{
   
   switch(key)
   {
    	case GLUT_KEY_RIGHT:
    		if(pos >= 2)
    			pos = 0;
    		else
    			pos++;
        	switch(pos)
        	{
        		case 0:
					glutDisplayFunc(senoideA);
				break;

				case 1:
					glutDisplayFunc(senoideB);
				break;

				case 2:
					glutDisplayFunc(senoideC);
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
	glutCreateWindow("Aula 2 - Exercicio 2");
	init();
	glutDisplayFunc(senoideA);
	glutSpecialFunc(specialKeysPress);

	glutMainLoop();


	return 0;
}
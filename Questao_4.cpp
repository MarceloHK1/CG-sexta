#include <GL/glut.h>

float x_position = 0;
float speed = 0.05;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();		//Cria uma cópia da matriz de transformação atual na pilha, para poder alterar sem afetar a original.
						//Para poder estabelecer um ponto fixo (0,0)
	glTranslatef(x_position, 0, 0);

	glColor3f(0.502, 0, 0.502);
	glBegin(GL_QUADS);
	glVertex2f(-3, -3);
	glVertex2f(-3, 3);
	glVertex2f(3, 3);
	glVertex2f(3, -3);
	glEnd();

	glPopMatrix();	//Retira a cópia da matriz da pilha

	glFlush();
}

void anima(int timer)
{
	x_position += speed;

	if (x_position > 4 || x_position < -4) {
		speed = -speed;
	}

	glutPostRedisplay();
	glutTimerFunc(10, anima, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(20, 40);
	glutCreateWindow("Transformacoes");
	glutDisplayFunc(display);

	glutTimerFunc(10, anima, 0);

	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}

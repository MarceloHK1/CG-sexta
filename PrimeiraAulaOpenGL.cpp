//Quadrado girando - questao 5

#include <GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glTranslatef(0, 0, 0);
	glRotatef(-3, 0, 0, 1);

	glBegin(GL_QUADS);
	glVertex2f(-3, -3);
	glVertex2f(-3, 3);
	glVertex2f(3, 3);
	glVertex2f(3, -3);
	glEnd();

	glFlush();
}

void anima(int timer)
{
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

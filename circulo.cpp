#include <GL/glut.h>
#include <math.h>

void circle(float radius)
{
	float angle;
	int i;

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++) {
		angle = i * 3.14159 / 180;
		glVertex2f(radius * cos(angle), radius * sin(angle));
	}
	
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	//glTranslatef(0, 0, 0);
	glRotatef(-2, 0, 0, 1);
	//glScalef(1.001, 1.00101, 1);

	/*
	glBegin(GL_QUADS);
	glVertex2f(-3, -3);
	glVertex2f(-3, 3);
	glVertex2f(3, 3);
	glVertex2f(3, -3);
	glEnd();
	*/

	circle(2);
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

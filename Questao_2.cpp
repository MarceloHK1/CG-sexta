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
	glColor3f(0, 0, 0.2);
	circle(7);

	glColor3f(0, 0, 0.6);
	circle(5);

	glColor3f(0, 0, 0.2);
	circle(3);

	glColor3f(1, 1, 1);
	circle(1);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(20, 40);
	glutCreateWindow("Transformacoes");
	glutDisplayFunc(display);

	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}

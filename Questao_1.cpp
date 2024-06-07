#include <GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.76, 0.76, 0.76);
	glBegin(GL_TRIANGLES);
	glVertex2f(-3, 6);
	glVertex2f(-6, 0);
	glVertex2f(3, 0);
	glEnd();

	glColor3f(0.502, 0.25, 0);
	glBegin(GL_QUADS);
	glVertex2f(-3.25, 5.9);
	glVertex2f(-2.75, 5.9);
	glVertex2f(-2.75, -1.6);
	glVertex2f(-3.25, -1.6);
	glEnd();

	glColor3f(0.247, 0.282, 0.8);
	glBegin(GL_QUADS);
	glVertex2f(-3.25, 5.9);
	glVertex2f(-3.25, 6.65);
	glVertex2f(-1.15, 6.65);
	glVertex2f(-1.15, 5.9);
	glEnd();

	glColor3f(0.929, 0.110, 0.141);
	glBegin(GL_POLYGON);
	glVertex2f(-8, -1.6);
	glVertex2f(5, -1.6);
	glVertex2f(3, -4.1);
	glVertex2f(-6, -4.1);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(20, 40);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(display);

	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1.0, 0.957, 0.816, 0.0);
	glutMainLoop();
	return 0;
}

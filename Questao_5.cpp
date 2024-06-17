#include <GL/glut.h>
#include <math.h>

void circle(float radius)
{
	float angle;
	int i;

	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++) {
		angle = i * 3.14159 / 180;
		
		float r = sin(angle * 3) * 0.5 + 0.5;
        	float g = sin(angle * 3 + 2) * 0.5 + 0.5;
        	float b = sin(angle * 3 + 4) * 0.5 + 0.5;

        	glColor3f(r, g, b);
		
		glVertex2f(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glRotatef(-0.2, 0, 0, 1);

	circle(5);
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
	glutCreateWindow("Tasdfsajkfwuhqw");
	glutDisplayFunc(display);

	glutTimerFunc(10, anima, 0);

	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}

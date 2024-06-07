#include <GL/glut.h>
#include <math.h>

float y_position = 0.0;

void circle(float radius) {
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

	glTranslatef(0, y_position, 0);

	circle(2);
	glFlush();
}

void teclado(unsigned char key, int x, int y)
{
	//Tabela ascii 32 = "[espaço]"
	if (key == 32) {
		y_position += 0.001;
	}
	else if (key != 32) {
		y_position += 0;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(20, 40);
	glutCreateWindow("Input");
	glutDisplayFunc(display);

	glutKeyboardFunc(teclado);

	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}

#include <GL/glut.h>
#include <math.h>

float y_position = 0.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glTranslatef(0, y_position, 0);

	glBegin(GL_QUADS);
	glVertex2f(-3, -3);
	glVertex2f(-3, 3);
	glVertex2f(3, 3);
	glVertex2f(3, -3);
	glEnd();

	glFlush();
}

void teclado(unsigned char key, int x, int y)
{
	//Tabela ascii 32 = "[espaço]"
	if (key == 32) {
		y_position += 0.025;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(20, 40);
	glutCreateWindow("Tres");
	glutDisplayFunc(display);

	glutKeyboardFunc(teclado);

	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}

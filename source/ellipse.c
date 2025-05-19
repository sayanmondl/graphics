#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define POINT_SIZE 10

#define ORTHO_LEFT -(int)(WIN_WIDTH / POINT_SIZE) / 2
#define ORTHO_RIGHT (int)(WIN_WIDTH / POINT_SIZE) / 2
#define ORTHO_BOTTOM -(int)(WIN_HEIGHT / POINT_SIZE) / 2
#define ORTHO_TOP (int)(WIN_HEIGHT / POINT_SIZE) / 2

void drawEllipse(int xc, int yc, int rx, int ry)
{
	/* Region 1 */
	int x = 0;
	int y = ry;

	int rxSquare = rx * rx;
	int rySquare = ry * ry;

	float p1 = rySquare - (rxSquare * ry) + (rxSquare * 0.25);

	while (2 * rySquare * x < 2 * rxSquare * y) {
		glColor3f(0.416, 0.173, 0.439);
		glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glEnd();

		x = x + 1;
		if (p1 < 0) {
			p1 = p1 + (2 * rySquare * x) + rySquare;
		} else {
			y = y - 1;
			p1 = p1 + (2 * rySquare * x) - (2 * rxSquare * y) +
			     rySquare;
		}
	}

	/* Region 2 */
	float p2 = rySquare * ((x + 0.5) * (x + 0.5)) +
		   rxSquare * ((y - 1) * (y - 1)) - (rxSquare * rySquare);

	while (y >= 0) {
		glColor3f(0.416, 0.173, 0.439);
		glBegin(GL_POINTS);
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glEnd();

		y = y - 1;
		if (p2 > 0) {
			p2 = p2 - (2 * rxSquare * y) + rxSquare;
		} else {
			x = x + 1;
			p2 = p2 - (2 * rxSquare * y) + (2 * rySquare * x) +
			     rxSquare;
		}

		printf("(%d, %d)\n", x, y);
	}
}

void drawAxes()
{
	glColor3f(0.941, 0.541, 0.365);
	glBegin(GL_LINES);
	glVertex2i(ORTHO_LEFT, 0);
	glVertex2i(ORTHO_RIGHT, 0);
	glVertex2i(0, ORTHO_BOTTOM);
	glVertex2i(0, ORTHO_TOP);
	glEnd();
}

void displayFunc()
{
	glClearColor(0.976, 0.929, 0.412, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxes();
	drawEllipse(5, 9, 15, 10);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("MidPoint Ellipse");

	gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP);
	glPointSize(POINT_SIZE);

	glutDisplayFunc(displayFunc);
	glutMainLoop();
}
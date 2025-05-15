#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define NVERTS 4

typedef struct Point {
	float x, y;
} Point;

const double pi = 3.14159265359;

float tx = 0.0, ty = 0.0;
float sx = 1, sy = 1;
double theta = 0;

Point origVerts[NVERTS] = {
    {20.0, 20.0},
    {20.0, 50.0},
    {50.0, 50.0},
    {50.0, 20.0}
};

Point verts[NVERTS];

void translate2d(Point verts[])
{
	for (int i = 0; i < NVERTS; i++) {
		verts[i].x = verts[i].x + tx;
		verts[i].y = verts[i].y + ty;
		printf("[%f, %f]\n", verts[i].x, verts[i].y);
	}
}

void rotate2d(Point verts[], Point pvtPt)
{
	for (int i = 0; i < NVERTS; i++) {
		float x = verts[i].x - pvtPt.x;
		float y = verts[i].y - pvtPt.y;

		float rotatedX = x * cos(theta) - y * sin(theta);
		float rotatedY = x * sin(theta) + y * cos(theta);

		verts[i].x = pvtPt.x + rotatedX;
		verts[i].y = pvtPt.y + rotatedY;
	}
}

void scale2d(Point verts[], Point fixedPt)
{
	for (int i = 0; i < NVERTS; i++) {
		verts[i].x = verts[i].x * sx + fixedPt.x * (1 - sx);
		verts[i].y = verts[i].y * sy + fixedPt.y * (1 - sy);
		printf("[%f, %f]\n", verts[i].x, verts[i].y);
	}
}

void drawAxes()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-(int)(WIN_WIDTH / 2), 0);
	glVertex2f((int)(WIN_WIDTH / 2), 0);
	glVertex2f(0, -(int)(WIN_HEIGHT / 2));
	glVertex2f(0, (int)(WIN_HEIGHT / 2));
	glEnd();
}

void drawPolygon(Point verts[])
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < NVERTS; i++) {
		glVertex2f(verts[i].x, verts[i].y);
	}
	glEnd();
}

void displayFunc()
{
    for (int i = 0; i < NVERTS; ++i) {
        verts[i] = origVerts[i];
    }

	Point center;
	center.x = (verts[0].x + verts[1].x + verts[2].x + verts[3].x) / 4.0f;
	center.y = (verts[0].y + verts[1].y + verts[2].y + verts[3].y) / 4.0f;

	glClearColor(0.118, 0.118, 0.18, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	scale2d(verts, center);
	rotate2d(verts, center);
	translate2d(verts);

    drawPolygon(verts);
	drawAxes();

	glFlush();
}

void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		ty += 10.0;
		break;
	case 's':
		ty -= 10.0;
		break;
	case 'a':
		tx -= 10.0;
		break;
	case 'd':
		tx += 10.0;
		break;
	case 'l':
		sx += 0.05;
		sy += 0.05;
		break;
	case 'k':
		sx -= 0.05;
		sy -= 0.05;
		break;
	case 'r':
		theta += (pi * 5) / 180;
		break;
	}
	glutPostRedisplay();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-WIN_WIDTH / 2, WIN_WIDTH / 2, -WIN_HEIGHT / 2,
		   WIN_HEIGHT / 2);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("Two dimensional transformation");

	init();
	glutDisplayFunc(displayFunc);
	glutKeyboardFunc(keyboardFunc);
	glutMainLoop();
}

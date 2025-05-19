#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define NVERTS 3

typedef struct Point {
	float x, y;
} Point;

/**
 * Reflect on a point pReflect.
 * Transformation matrix:-
 * [-1  0  2 * pReflect.x]
 * [0  -1  2 * pReflect.y]
 * [0   0  1			 ]
 */
void reflect(int nVerts, Point verts[], Point reflVerts[], Point pReflect)
{
	for (int i = 0; i < nVerts; i++) {
		reflVerts[i].x = -verts[i].x + 2 * pReflect.x;
		reflVerts[i].y = -verts[i].y + 2 * pReflect.y;
	}
}

/**
 * Reflect about X axis (y = 0).
 * Transformation matrix:-
 * [1  0  0]
 * [0 -1  0]
 * [0  0  1]
 */
void reflectX(int nVerts, Point verts[], Point reflVerts[])
{
	for (int i = 0; i < nVerts; i++) {
		reflVerts[i].x = verts[i].x;
		reflVerts[i].y = -verts[i].y;
	}
}

/**
 * Reflect about Y axis (x = 0).
 * Transformation matrix:-
 * [-1  0  0]
 * [ 0  1  0]
 * [ 0  0  1]
 */
void reflectY(int nVerts, Point verts[], Point reflVerts[])
{
	for (int i = 0; i < nVerts; i++) {
		reflVerts[i].x = -verts[i].x;
		reflVerts[i].y = verts[i].y;
	}
}

/**
 * Reflect diagonally (y = x).
 * Transformation matrix:-
 * [0  1  0]
 * [1  0  0]
 * [0  0  1]
 */
void reflectDiag(int nVerts, Point verts[], Point reflVerts[])
{
	for (int i = 0; i < nVerts; i++) {
		reflVerts[i].x = verts[i].y;
		reflVerts[i].y = verts[i].x;
	}
}

/**
 * Reflect diagonally (y = -x).
 * Transformation matrix:-
 * [ 0 -1  0]
 * [-1  0  0]
 * [ 0  0  1]
 */
void reflectDiag2(int nVerts, Point verts[], Point reflVerts[])
{
	for (int i = 0; i < nVerts; i++) {
		reflVerts[i].x = -verts[i].y;
		reflVerts[i].y = -verts[i].x;
	}
}

void drawPolygon(int nVerts, Point *verts, float colors[])
{
	glColor3f(colors[0], colors[1], colors[2]);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < nVerts; i++) {
		glVertex2f(verts[i].x, verts[i].y);
	}
	glEnd();
}

void drawAxes()
{
	glColor3f(0.941, 0.541, 0.365);
	glBegin(GL_LINES);
	glVertex2i(-(int)(WIN_WIDTH / 2), 0);
	glVertex2i((int)(WIN_WIDTH / 2), 0);
	glVertex2i(0, -(int)(WIN_HEIGHT / 2));
	glVertex2i(0, (int)(WIN_HEIGHT / 2));
	glEnd();
}

void displayFunc()
{
	int nVerts = NVERTS;

	Point verts[NVERTS] = { { 50.0, 50.0 },
				{ 80.0, 100.0 },
				{ 110.0, 60.0 } };
	Point reflVerts[NVERTS];
	Point pReflect = { 20.0, 10.0 };

	float color1[3] = { 1.0, 0.0, 0.0 };
	float color2[3] = { 0.0, 0.0, 1.0 };

	glClearColor(0.976, 0.929, 0.412, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	drawAxes();
	drawPolygon(nVerts, verts, color1);
	reflect(nVerts, verts, reflVerts, pReflect);
	drawPolygon(nVerts, reflVerts, color2);

	glFlush();
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
	glutCreateWindow("2D Reflection");

	init();
	glutDisplayFunc(displayFunc);
	glutMainLoop();

	return 0;
}

#include <GL/freeglut.h>
#include <math.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define NVERTS 4

typedef struct Point {
	float x, y;
} Point;

void scale(Point verts[], Point scaleVerts[], Point fixedPt, int nVerts,
	   float sx, float sy)
{
	for (int i = 0; i < nVerts; i++) {
		scaleVerts[i].x = verts[i].x * sx + fixedPt.x * (1 - sx);
		scaleVerts[i].y = verts[i].y * sy + fixedPt.y * (1 - sy);
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
	glVertex2f(-(int)(WIN_WIDTH / 2), 0);
	glVertex2f((int)(WIN_WIDTH / 2), 0);
	glVertex2f(0, -(int)(WIN_HEIGHT / 2));
	glVertex2f(0, (int)(WIN_HEIGHT / 2));
	glEnd();
}

void displayFunc()
{
	int nVerts = NVERTS;
	float sx = 1.3;
	float sy = 1.3;

	Point fixedPt = { 120.0, 120.0 };
	Point verts[NVERTS] = {
		{ 50, 50 }, { 50, 100 }, { 100, 100 }, { 100, 50 }
	};
	Point scaleVerts[NVERTS];
	float color1[3] = { 1.0, 0, 0 };
	float color2[3] = { 0, 0, 1.0 };

	glClearColor(0.976, 0.929, 0.412, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	drawAxes();
	drawPolygon(nVerts, verts, color1);
	scale(verts, scaleVerts, fixedPt, nVerts, sx, sy);
	drawPolygon(nVerts, scaleVerts, color2);

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
	glutCreateWindow("2D Polygon Scaling");

	init();
	glutDisplayFunc(displayFunc);
	glutMainLoop();

	return 0;
}

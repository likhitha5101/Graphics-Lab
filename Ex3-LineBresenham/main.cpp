#include<glut.h>
#include<math.h>
#include<stdio.h>
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.33, 0.85, 0.93);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(3);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void line(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int p, incx, incy, inc1, inc2, x, y;
	
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;

	glBegin(GL_POINTS);
	if (dx > dy) {
		glVertex2d(x, y);
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (int i = 0; i < dx; i++) {
			if (p >= 0) {
				y += incy;
				p += inc1;
			}
			else
				p += inc2;
			x += incx;
			glVertex2d(x, y);
		}

	}
	else {
		glVertex2d(x, y);
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (int i = 0; i < dy; i++) {
			if (p >= 0) {
				x += incx;
				p += inc1;
			}
			else
				p += inc2;
			y += incy;
			glVertex2d(x, y);
		}
	}
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// |m| < 1
	line(100, 350, 350, 400);
	// |m| >= 1
	line(100, 110, 200, 300);
	glFlush();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Line Bresenham");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}
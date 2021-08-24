#include<stdlib.h>
#include<glut.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.53, 0.06, 0.74);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(2);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
int round(float num) {
	return floor(num + 0.5);
}
void lineDDA(int x1, int y1, int x2, int y2) {
	float x = x1, y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float xi = dx / (float)steps;
	float yi = dy / (float)steps;

	glBegin(GL_POINTS);
	for (int i = 0; i <= steps; ++i) {
		glVertex2d(round(x), round(y));
		x += xi;
		y += yi;
	}
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	srand((unsigned)time(NULL));
	int x1, y1, x2, y2, dis;
	for (int i = 0; i < 200; ++i) {
		x1 = abs(rand() % 500 + 1);
		y1 = abs(rand() % 500 + 1);
		dis = abs(rand() % 130 + 10);
		x2 = int(sqrt((dis * dis) / 2)) + x1;
		y2 = int(sqrt((dis * dis) / 2)) + y1;
		lineDDA(x1, y1, x2, y2);
	}
	glFlush();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Line Exercise");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}
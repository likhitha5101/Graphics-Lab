#include<glut.h>
#include<math.h>
#include<stdio.h>
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.53, 0.06, 0.74);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(3);
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
	//i) + slope left to right, m>1
	lineDDA(30, 300, 80, 390);
	//ii) + slope left to right, m<=1
	lineDDA(50, 300, 150, 360);
	glColor3f(0.06, 0.74, 0.17);
	//iii) + slope right to left, m>1
	lineDDA(220, 390, 180, 300);
	//iv) + slope right to left, m<=1
	lineDDA(380,360, 300, 300);
	glColor3f(1, 0.6, 0.12);
	//v) + slope left to right, m>1
	lineDDA(30,250,70,150);
	//vi) + slope left to right, m<=1
	lineDDA(100, 210, 180, 150);
	glColor3f(1, 0.12, 0.21);
	//vii) + slope right to left, m>1
	lineDDA(230, 260, 250, 150);
	//viii) + slope right to left, m<=1
	lineDDA(270, 210, 380, 170);
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
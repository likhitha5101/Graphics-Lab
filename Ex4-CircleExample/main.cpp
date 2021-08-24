#include<glut.h>
#include<math.h>
#include<stdio.h>
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.34, 0.74, 0.96);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(7);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void midPointCircleAlgo(int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	float p = 5 / 4 - r;
	glBegin(GL_POINTS);
	glVertex2d(x + xc, y + yc);

	while (y > x)
	{
		if (p < 0)
		{
			x++;
			p += 2 * x + 1;
		}
		else
		{
			y--;
			x++;
			p += 2 * (x - y) + 1;
		}
		glVertex2d(x + xc, y + yc);
		glVertex2d(x + xc, -y + yc);
		glVertex2d(-x + xc, y + yc);
		glVertex2d(-x + xc, -y + yc);
		glVertex2d(y + xc, x + yc);
		glVertex2d(-y + xc, x + yc);
		glVertex2d(y + xc, -x + yc);
		glVertex2d(-y + xc, -x + yc);
	}
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	//blue ring
	midPointCircleAlgo(100, 400, 50);
	//yellow ring
	glColor3f(1.0, 1.0, 0);
	midPointCircleAlgo(160, 350, 50);
	//black ring
	glColor3f(0, 0, 0);
	midPointCircleAlgo(220, 400, 50);
	//green ring
	glColor3f(0, 0.78, 0.27);
	midPointCircleAlgo(280, 350, 50);
	//red ring
	glColor3f(1, 0, 0);
	midPointCircleAlgo(340, 400, 50);

	glFlush();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Circle object");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}
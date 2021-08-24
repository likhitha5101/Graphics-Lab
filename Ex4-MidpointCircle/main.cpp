#include<glut.h>
#include<math.h>
#include<stdio.h>
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.82, 0.15, 0.29);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(2);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void midPointCircleAlgo(int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	float p = 5 / 4 - r;
	glBegin(GL_POINTS);
	glVertex2d(x+xc,y+yc);

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
	midPointCircleAlgo(150, 350, 70);
	glFlush();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Midpoint Circle Algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}
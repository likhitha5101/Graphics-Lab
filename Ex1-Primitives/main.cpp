#include<glut.h>
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.2, 0.0);
	glPointSize(7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//points
	glBegin(GL_POINTS);
	glVertex2d(40,470);
	glVertex2d(65, 470);
	glVertex2d(40, 450);
	glEnd();
	//line
	glBegin(GL_LINES);
	glVertex2d(100, 400);
	glVertex2d(130, 475);
	glEnd();
	//line strip
	glBegin(GL_LINE_STRIP);
	glVertex2d(150, 400);
	glVertex2d(200, 475);
	glVertex2d(250, 400);
	glVertex2d(300, 475);
	glVertex2d(350, 400);
	glVertex2d(400, 475);
	glEnd();
	//line loop
	glBegin(GL_LINE_LOOP);
	glVertex2d(450, 400);
	glVertex2d(430, 475);
	glVertex2d(520, 440);
	glVertex2d(550, 400);
	glEnd();
	//triangle
	glBegin(GL_TRIANGLES);
	glVertex2d(40,250);
	glVertex2d(80, 350);
	glVertex2d(105, 200);
	glEnd();
	//triangle strip
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(140, 250);
	glVertex2d(140, 350);
	glVertex2d(200, 350);
	glColor3f(0.0f, 0.2f, 1.0f);
	glVertex2d(200, 250);
	glEnd();
	//triangle fan
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(120, 80);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(220, 80);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(170, 180);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(70, 180);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(20, 80);
	glEnd();
	//quads
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.2f, 1.0f);
	glVertex2d(400, 200);
	glVertex2d(500, 200);
	glVertex2d(500, 300);
	glVertex2d(400, 300);
	glEnd();
	//quad strip
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.65f, 0.35f, 0.5f);
	glVertex2d(350, 280);
	glVertex2d(250, 280);
	glVertex2d(320, 250);
	glVertex2d(250, 180);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2d(350, 180);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2d(300, 80);	
	glEnd();
	//Polygon
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.7f, 0.2f);
	glVertex2d(400, 50);
	glVertex2d(500, 50);
	glVertex2d(550, 100);
	glVertex2d(500, 150);
	glVertex2d(400, 150);
	glVertex2d(350, 100);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("First Exercise");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}
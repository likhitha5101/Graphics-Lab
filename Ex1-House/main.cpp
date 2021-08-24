#include <glut.h>  
void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);   
    //rectangle
    glBegin(GL_QUADS);
    glColor3f(0.74f, 0.45f, 0.95f);
    glVertex2f(120, 10);
    glVertex2f(380, 10);
    glVertex2f(380, 200);
    glVertex2f(120, 200);
    glEnd();

    //triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.74f, 0.45f, 0.95f);
    glVertex2f(80, 200);
    glVertex2f(420, 200);
    glVertex2f(250, 350);
    glEnd();

    //line under triangle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(80, 200);
    glVertex2f(80, 210);
    glVertex2f(420, 210);
    glVertex2f(420, 200);
    
    glEnd();

    //chimney
    glBegin(GL_QUADS);
    glColor3f(0.74f, 0.45f, 0.95f);
    glVertex2f(320, 240);
    glVertex2f(370, 240);
    glVertex2f(370, 300);
    glVertex2f(320, 300);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3f(0.68, 1, 0);
    glVertex2f(200, 10);
    glVertex2f(300, 10);
    glVertex2f(300, 150);
    glVertex2f(200, 150);
    glEnd();

    //doorknob
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(220.0, 70.0);
    glEnd();

    //steps
    glBegin(GL_QUADS);
    glColor3f(1, 0.47, 0);
    glVertex2f(150, 10);
    glVertex2f(350, 10);
    glVertex2f(350, 30);
    glVertex2f(150, 30);
    glEnd();

    //left-window
    glBegin(GL_QUADS);
    glColor3f(0.68, 1, 0);
    glVertex2f(140, 130);
    glVertex2f(190, 130);
    glVertex2f(190, 180);
    glVertex2f(140, 180);
    glEnd();

    //left window grills
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(140, 156);
    glVertex2f(190, 155);

    glVertex2f(165, 130);
    glVertex2f(165, 180);
    glEnd();

    //right-window
    glBegin(GL_QUADS);
    glColor3f(0.68, 1, 0);
    glVertex2f(310, 130);
    glVertex2f(360, 130);
    glVertex2f(360, 180);
    glVertex2f(310, 180);
    glEnd();

    //right window grills
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(310, 156);
    glVertex2f(360, 155);

    glVertex2f(335, 130);
    glVertex2f(335, 180);
    glEnd();

    glFlush();  
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);         
    glutCreateWindow("House");  
    glutInitWindowSize(500, 500);   
    glutInitWindowPosition(0, 0); 
    glutDisplayFunc(display);       
    initGL();                       
    glutMainLoop();                 
    return 0;
}
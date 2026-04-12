#include <GL/glut.h>
void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);

    glColor3f(1.0, 0.0, 0.0); // red
    glBegin(GL_QUADS);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glColor3f(0.0, 0.0, 1.0); // blue
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    glutSolidSphere(0.15, 12, 2); // draw a sphere
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
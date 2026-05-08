#include <GL/freeglut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 3.0, 0.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(3.0, 3.0, 1.5);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(3.0, 5.0, 0.0);

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 5.0, -1.5);
    glEnd();

    glFlush();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 6.0, 0.0, 8.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
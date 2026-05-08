#include <GL/freeglut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Shrink the pyramid size and move it to the screen center
    glScalef(0.6f, 0.6f, 0.6f);
    glTranslatef(0.3f, 1.1f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    // Top vertex - Red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 3.0f, 0.0f);

    // Bottom left - Blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    // Bottom right - Yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, 0.0f, 0.0f);

    // Middle - Cyan
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(2.0f, 1.0f, 0.0f);

    glEnd();

    glFlush();
}

void init(void)
{
    // Background color: Black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Viewing area
    glOrtho(0.0, 3.0, 0.0, 4.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Small Colored Pyramid");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
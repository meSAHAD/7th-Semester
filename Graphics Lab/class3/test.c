// #include <windows.h>
#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(50, 1.0, 1.0, 1.0);

    glBegin(GL_TRIANGLES);

    // Front face
    glColor3f(1.0, 0.0, 0.0); // red
    glVertex3f(0.0, 0.6, 0.0);

    glColor3f(0.5, 0.0, 1.0); // purple
    glVertex3f(-0.6, -0.6, 0.6);

    glColor3f(0.0, 0.0, 1.0); // blue
    glVertex3f(0.6, -0.6, 0.6);

    // Right face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.6, 0.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.6, -0.6, 0.6);

    glColor3f(0.5, 0.0, 1.0);
    glVertex3f(0.0, -0.6, -0.6);

    // Left face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.6, 0.0);

    glColor3f(0.5, 0.0, 1.0);
    glVertex3f(0.0, -0.6, -0.6);

    glColor3f(0.5, 0.0, 1.0);
    glVertex3f(-0.6, -0.6, 0.6);

    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tetrahedron");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
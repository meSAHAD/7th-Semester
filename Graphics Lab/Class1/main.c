#include <GL/glut.h>

float angle = 0.0f;

/* ---------- DISPLAY ---------- */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Cube */
    glPushMatrix();
    glTranslatef(-2.0, 0.0, 0.0);
    glRotatef(angle, 1.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.0);
    glPopMatrix();

    /* Sphere */
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidSphere(0.6, 30, 30);
    glPopMatrix();

    /* Cone */
    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef(angle, 1.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCone(0.6, 1.2, 30, 30);
    glPopMatrix();

    glutSwapBuffers();
}

/* ---------- TIMER (ANIMATION) ---------- */
void timer(int value)
{
    angle += 2.0f;
    if (angle > 360)
        angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

/* ---------- INITIALIZATION ---------- */
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 3, 6, 0, 0, 0, 0, 1, 0);
}

/* ---------- MAIN ---------- */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Moving 3D Objects - GLUT");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

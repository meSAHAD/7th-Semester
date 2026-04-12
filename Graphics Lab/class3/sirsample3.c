#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int a1 = 0, a2 = 0;
static int tx = 0, ty = 0;

void init()
{
    glClearColor(1, 1, 1, 1.0);

    // Projection setup (Correct matrix mode)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 500.0, 0.0, 500.0, -500.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void special(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        tx -= 5;
        break;
    case GLUT_KEY_RIGHT:
        tx += 5;
        break;
    case GLUT_KEY_UP:
        ty += 5;
        break;
    case GLUT_KEY_DOWN:
        ty -= 5;
        break;

    case GLUT_KEY_F1:
        a1 += 5;
        break; // Z rotation
    case GLUT_KEY_F2:
        a2 += 5;
        break; // X rotation
    case GLUT_KEY_F3:
        a1 -= 5;
        break;
    }

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Move to object center before rotating
    glTranslatef(tx + 50, ty + 50, 0.0);

    glRotatef((GLfloat)a1, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)a2, 1.0, 0.0, 0.0);

    // Move back so quad rotates around its center
    glTranslatef(-50, -50, 0.0);

    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);

    glColor3f(0, 0, 1);
    glVertex3f(100, 0, 0);

    glColor3f(1, 0, 0);
    glVertex3f(100, 100, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 100, 0);

    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Fixed Rotating Quad");

    glutDisplayFunc(display);
    glutSpecialFunc(special);

    init();
    glutMainLoop();
    return 0;
}
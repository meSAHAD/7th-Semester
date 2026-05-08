// #include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int a = 0, a1 = 0;
double x = 0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0;
double posx = 0, posy = 0, posz = 2, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;
static void idle(void)
{
    glutPostRedisplay();
}

void ballMoveFront(void)
{
    Sx = Sx + 0.5;
    Sy = Sy + 0.5;
    Sz = Sz + 0.5;

    if (Sx > 9 || Sy > 9 || Sz > 9)
    {
        Sx = Sx - 9;
        Sy = Sy - 9;
        Sz = Sz - 9;
    }

    tx = tx - 0.1;
    ty = ty - 0.1;
    tz = tz + 0.1;

    if (tx < -1.9 || ty < -1.9 || tz > 1.9)
    {
        tx = tx + 1.9;
        ty = ty + 1.9;
        tz = tz - 1.9;
    }

    glutPostRedisplay();
}

void ballMoveBack(void)
{
    Sx = Sx - 0.5;
    Sy = Sy - 0.5;
    Sz = Sz - 0.5;

    if (Sx <= 0.5 || Sy <= 0.5 || Sz <= 0.5)
    {
        Sx = 0;
        Sy = 0;
        Sz = 0;
    }

    tx = tx + 0.1;
    ty = ty + 0.1;
    tz = tz - 0.1;

    if (tx >= 3 || ty >= 3 || tz <= -3)
    {
        tx = 0;
        ty = 0;
        tz = 0;
    }

    glutPostRedisplay();
}

void special(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        x = (x - 0.1);
        if (x < -1)
        {
            x = 3.5;
        }
        break;
    case GLUT_KEY_RIGHT:
        x = (x + 0.1);
        if (x > 3.5)
        {
            x = x - 3.5;
        }
        break;
    case GLUT_KEY_F1:
        (a -= 5) %= 360;
        break;
    case GLUT_KEY_F2:
        ballMoveFront();
        break;
    case GLUT_KEY_F3:
        ballMoveBack();
        break;
    case GLUT_KEY_F4:
        posx += 0.5;
        break;
    case GLUT_KEY_F5:
        posx -= 0.5;
        break;
    case GLUT_KEY_F6:
        posy += 0.5;
        break;
    case GLUT_KEY_F7:
        posy -= 0.5;
        break;
    case GLUT_KEY_F8:
        posz += 0.5;
        break;
    case GLUT_KEY_F9:
        posz -= 0.5;
        break;
    default:
        return;
    }
    glutPostRedisplay();
}

void spin(int value)
{
    a1 = a1 - 5;
    if (a1 < -360)
    {
        a1 = a1 + 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, spin, 0);
}

void fan()
{
    // fan1
    // back
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.2, 0.4, 0);
    glVertex3f(0, 0.7, 0);
    glVertex3f(-0.05, 0.8, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.05, 0.8, 0);

    glVertex3f(-0.05, 0.8, 0);
    glVertex3f(0, 0.7, 0);

    glVertex3f(0, 0.7, 0);
    glVertex3f(-0.2, 0.4, 0);

    glVertex3f(-0.2, 0.4, 0);
    glVertex3f(-0.25, 0.5, 0);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.05, 0.8, 0.05);
    glVertex3f(-0.05, 0.8, 0);
    glVertex3f(-0.25, 0.5, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.05, 0.8, 0.05);

    glVertex3f(-0.05, 0.8, 0.05);
    glVertex3f(-0.05, 0.8, 0);

    glVertex3f(-0.05, 0.8, 0);
    glVertex3f(-0.25, 0.5, 0);

    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.25, 0.5, 0.05);
    glEnd();

    // right
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.2, 0.4, 0.05);
    glVertex3f(0, 0.7, 0.05);
    glVertex3f(0, 0.7, 0);
    glVertex3f(-0.2, 0.4, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.2, 0.4, 0.05);
    glVertex3f(0, 0.7, 0.05);

    glVertex3f(0, 0.7, 0.05);
    glVertex3f(0, 0.7, 0);

    glVertex3f(0, 0.7, 0);
    glVertex3f(-0.2, 0.4, 0);

    glVertex3f(-0.2, 0.4, 0);
    glVertex3f(-0.2, 0.4, 0.05);
    glEnd();

    // bottom
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.2, 0.4, 0.05);
    glVertex3f(-0.2, 0.4, 0);
    glVertex3f(-0.25, 0.5, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.2, 0.4, 0.05);

    glVertex3f(-0.2, 0.4, 0.05);
    glVertex3f(-0.2, 0.4, 0);

    glVertex3f(-0.2, 0.4, 0);
    glVertex3f(-0.25, 0.5, 0);

    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.25, 0.5, 0.05);
    glEnd();

    // top
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.05, 0.8, 0.05);
    glVertex3f(0, 0.7, 0.05);
    glVertex3f(0, 0.7, 0);
    glVertex3f(-0.05, 0.8, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.05, 0.8, 0.05);
    glVertex3f(0, 0.7, 0.05);

    glVertex3f(0, 0.7, 0.05);
    glVertex3f(0, 0.7, 0);

    glVertex3f(0, 0.7, 0);
    glVertex3f(-0.05, 0.8, 0);

    glVertex3f(-0.05, 0.8, 0);
    glVertex3f(-0.05, 0.8, 0.05);
    glEnd();

    // front
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.2, 0.4, 0.05);
    glVertex3f(0, 0.7, 0.05);
    glVertex3f(-0.05, 0.8, 0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.275, 0.45, 0.05);
    glVertex3f(-0.05, 0.8, 0.05);

    glVertex3f(-0.05, 0.8, 0.05);
    glVertex3f(0, 0.7, 0.05);

    glVertex3f(0, 0.7, 0.05);
    glVertex3f(-0.2, 0.4, 0.05);

    glVertex3f(-0.2, 0.4, 0.05);
    glVertex3f(-0.25, 0.5, 0.05);
    glEnd();

    // fan2
    // back
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.4, 0);
    glVertex3f(-0.3, 0.3, 0);
    glVertex3f(-0.1, 0, 0);
    glVertex3f(-0.05, 0.1, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, 0.4, 0);
    glVertex3f(-0.3, 0.3, 0);

    glVertex3f(-0.3, 0.3, 0);
    glVertex3f(-0.1, 0, 0);

    glVertex3f(-0.1, 0, 0);
    glVertex3f(-0.05, 0.1, 0);

    glVertex3f(-0.05, 0.1, 0);
    glVertex3f(-0.25, 0.4, 0);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.4, 0.05);
    glVertex3f(-0.05, 0.1, 0.05);
    glVertex3f(-0.05, 0.1, 0);
    glVertex3f(-0.25, 0.4, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, 0.4, 0.05);
    glVertex3f(-0.05, 0.1, 0.05);

    glVertex3f(-0.05, 0.1, 0.05);
    glVertex3f(-0.05, 0.1, 0);

    glVertex3f(-0.05, 0.1, 0);
    glVertex3f(-0.25, 0.4, 0);

    glVertex3f(-0.25, 0.4, 0);
    glVertex3f(-0.25, 0.4, 0.05);
    glEnd();

    // right
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.3, 0.05);
    glVertex3f(-0.1, 0, 0.05);
    glVertex3f(-0.1, 0, 0);
    glVertex3f(-0.3, 0.3, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.3, 0.3, 0.05);
    glVertex3f(-0.1, 0, 0.05);

    glVertex3f(-0.1, 0, 0.05);
    glVertex3f(-0.1, 0, 0);

    glVertex3f(-0.1, 0, 0);
    glVertex3f(-0.3, 0.3, 0);

    glVertex3f(-0.3, 0.3, 0);
    glVertex3f(-0.3, 0.3, 0.05);
    glEnd();

    // bottom
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.4, 0.05);
    glVertex3f(-0.3, 0.3, 0.05);
    glVertex3f(-0.3, 0.3, 0);
    glVertex3f(-0.25, 0.4, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, 0.4, 0.05);
    glVertex3f(-0.3, 0.3, 0.05);

    glVertex3f(-0.3, 0.3, 0.05);
    glVertex3f(-0.3, 0.3, 0);

    glVertex3f(-0.3, 0.3, 0);
    glVertex3f(-0.25, 0.4, 0);

    glVertex3f(-0.25, 0.4, 0);
    glVertex3f(-0.25, 0.4, 0.05);
    glEnd();

    // top
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.05, 0.1, 0.05);
    glVertex3f(-0.1, 0, 0.05);
    glVertex3f(-0.1, 0, 0);
    glVertex3f(-0.05, 0.1, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.05, 0.1, 0.05);
    glVertex3f(-0.1, 0, 0.05);

    glVertex3f(-0.1, 0, 0.05);
    glVertex3f(-0.1, 0, 0);

    glVertex3f(-0.1, 0, 0);
    glVertex3f(-0.05, 0.1, 0);

    glVertex3f(-0.05, 0.1, 0);
    glVertex3f(-0.05, 0.1, 0.05);
    glEnd();

    // front
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.25, 0.4, 0.05);
    glVertex3f(-0.3, 0.3, 0.05);
    glVertex3f(-0.1, 0, 0.05);
    glVertex3f(-0.05, 0.1, 0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.275, 0.45, 0.05);
    glVertex3f(-0.05, 0.1, 0.05);

    glVertex3f(-0.05, 0.1, 0.05);
    glVertex3f(-0.1, 0, 0.05);

    glVertex3f(-0.1, 0, 0.05);
    glVertex3f(-0.3, 0.3, 0.05);

    glVertex3f(-0.3, 0.3, 0.05);
    glVertex3f(-0.25, 0.4, 0.05);
    glEnd();

    // fan3
    // back
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.4, 0);
    glVertex3f(-0.5, 0.1, 0);
    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.35, 0.5, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.3, 0.4, 0);
    glVertex3f(-0.5, 0.1, 0);

    glVertex3f(-0.5, 0.1, 0);
    glVertex3f(-0.55, 0.2, 0);

    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.35, 0.5, 0);

    glVertex3f(-0.35, 0.5, 0);
    glVertex3f(-0.3, 0.4, 0);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.4, 0.05);
    glVertex3f(-0.5, 0.1, 0.05);
    glVertex3f(-0.5, 0.1, 0);
    glVertex3f(-0.3, 0.4, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.3, 0.4, 0.05);
    glVertex3f(-0.5, 0.1, 0.05);

    glVertex3f(-0.5, 0.1, 0.05);
    glVertex3f(-0.5, 0.1, 0);

    glVertex3f(-0.5, 0.1, 0);
    glVertex3f(-0.3, 0.4, 0);

    glVertex3f(-0.3, 0.4, 0);
    glVertex3f(-0.3, 0.4, 0.05);
    glEnd();

    // right
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.35, 0.5, 0.05);
    glVertex3f(-0.55, 0.2, 0.05);
    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.35, 0.5, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.35, 0.5, 0.05);
    glVertex3f(-0.55, 0.2, 0.05);

    glVertex3f(-0.55, 0.2, 0.05);
    glVertex3f(-0.55, 0.2, 0);

    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.35, 0.5, 0);

    glVertex3f(-0.35, 0.5, 0);
    glVertex3f(-0.35, 0.5, 0.05);
    glEnd();

    // bottom
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.35, 0.5, 0.05);
    glVertex3f(-0.3, 0.4, 0.05);
    glVertex3f(-0.3, 0.4, 0);
    glVertex3f(-0.35, 0.5, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.35, 0.5, 0.05);
    glVertex3f(-0.3, 0.4, 0.05);

    glVertex3f(-0.3, 0.4, 0.05);
    glVertex3f(-0.3, 0.4, 0);

    glVertex3f(-0.3, 0.4, 0);
    glVertex3f(-0.35, 0.5, 0);

    glVertex3f(-0.35, 0.5, 0);
    glVertex3f(-0.35, 0.5, 0.05);
    glEnd();

    // top
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.55, 0.2, 0.05);
    glVertex3f(-0.5, 0.1, 0.05);
    glVertex3f(-0.5, 0.1, 0);
    glVertex3f(-0.55, 0.2, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.55, 0.2, 0.05);
    glVertex3f(-0.5, 0.1, 0.05);

    glVertex3f(-0.5, 0.1, 0.05);
    glVertex3f(-0.5, 0.1, 0);

    glVertex3f(-0.5, 0.1, 0);
    glVertex3f(-0.55, 0.2, 0);

    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.55, 0.2, 0.05);
    glEnd();

    // front
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.4, 0.05);
    glVertex3f(-0.5, 0.1, 0.05);
    glVertex3f(-0.55, 0.2, 0.05);
    glVertex3f(-0.35, 0.5, 0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.275, 0.45, 0.05);
    glVertex3f(-0.5, 0.1, 0.05);

    glVertex3f(-0.5, 0.1, 0.05);
    glVertex3f(-0.55, 0.2, 0.05);

    glVertex3f(-0.55, 0.2, 0.05);
    glVertex3f(-0.35, 0.5, 0.05);

    glVertex3f(-0.35, 0.5, 0.05);
    glVertex3f(-0.3, 0.4, 0.05);
    glEnd();

    // fan4
    // back
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.5, 0);
    glVertex3f(-0.5, 0.8, 0);
    glVertex3f(-0.45, 0.9, 0);
    glVertex3f(-0.25, 0.6, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.3, 0.5, 0);
    glVertex3f(-0.5, 0.8, 0);

    glVertex3f(-0.5, 0.8, 0);
    glVertex3f(-0.45, 0.9, 0);

    glVertex3f(-0.45, 0.9, 0);
    glVertex3f(-0.25, 0.6, 0);

    glVertex3f(-0.25, 0.6, 0);
    glVertex3f(-0.3, 0.5, 0);
    glEnd();

    // left
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.5, 0.8, 0.05);
    glVertex3f(-0.3, 0.5, 0.05);
    glVertex3f(-0.3, 0.5, 0);
    glVertex3f(-0.5, 0.8, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.5, 0.8, 0.05);
    glVertex3f(-0.3, 0.5, 0.05);

    glVertex3f(-0.3, 0.5, 0.05);
    glVertex3f(-0.3, 0.5, 0);

    glVertex3f(-0.3, 0.5, 0);
    glVertex3f(-0.5, 0.8, 0);

    glVertex3f(-0.5, 0.8, 0);
    glVertex3f(-0.5, 0.8, 0.05);
    glEnd();

    // right
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.45, 0.9, 0.05);
    glVertex3f(-0.25, 0.6, 0.05);
    glVertex3f(-0.25, 0.6, 0);
    glVertex3f(-0.45, 0.9, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.45, 0.9, 0.05);
    glVertex3f(-0.25, 0.6, 0.05);

    glVertex3f(-0.25, 0.6, 0.05);
    glVertex3f(-0.25, 0.6, 0);

    glVertex3f(-0.25, 0.6, 0);
    glVertex3f(-0.45, 0.9, 0);

    glVertex3f(-0.45, 0.9, 0);
    glVertex3f(-0.45, 0.9, 0.05);
    glEnd();

    // bottom
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.5, 0.05);
    glVertex3f(-0.35, 0.6, 0.05);
    glVertex3f(-0.35, 0.6, 0);
    glVertex3f(-0.3, 0.5, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.3, 0.5, 0.05);
    glVertex3f(-0.35, 0.6, 0.05);

    glVertex3f(-0.35, 0.6, 0.05);
    glVertex3f(-0.35, 0.6, 0);

    glVertex3f(-0.35, 0.6, 0);
    glVertex3f(-0.3, 0.5, 0);

    glVertex3f(-0.3, 0.5, 0);
    glVertex3f(-0.3, 0.5, 0.05);
    glEnd();

    // top
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.5, 0.8, 0.05);
    glVertex3f(-0.45, 0.9, 0.05);
    glVertex3f(-0.45, 0.9, 0);
    glVertex3f(-0.5, 0.8, 0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.5, 0.8, 0.05);
    glVertex3f(-0.45, 0.9, 0.05);

    glVertex3f(-0.45, 0.9, 0.05);
    glVertex3f(-0.45, 0.9, 0);

    glVertex3f(-0.45, 0.9, 0);
    glVertex3f(-0.5, 0.8, 0);

    glVertex3f(-0.5, 0.8, 0);
    glVertex3f(-0.5, 0.8, 0.05);
    glEnd();

    // front
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.3, 0.5, 0.05);
    glVertex3f(-0.5, 0.8, 0.05);
    glVertex3f(-0.45, 0.9, 0.05);
    glVertex3f(-0.25, 0.6, 0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-0.275, 0.45, 0.05);
    glVertex3f(-0.5, 0.8, 0.05);

    glVertex3f(-0.5, 0.8, 0.05);
    glVertex3f(-0.45, 0.9, 0.05);

    glVertex3f(-0.45, 0.9, 0.05);
    glVertex3f(-0.25, 0.6, 0.05);

    glVertex3f(-0.25, 0.6, 0.05);
    glVertex3f(-0.3, 0.5, 0.05);
    glEnd();
}

void cloud()
{
    glColor3f(1, 1, 1); // first cloud
    glPushMatrix();
    glTranslatef(0.5, 1.8, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4, 1.75, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 1.8, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, 1.9, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.35, 1.88, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();

    // second cloud
    glPushMatrix();
    glTranslatef(1.2, 1.8, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.3, 1.85, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25, 1.75, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.4, 1.8, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.35, 1.73, 0);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
}

void tiang()
{
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    // back
    glVertex3f(-0.3, -0.3, 0);
    glVertex3f(-0.25, -0.3, 0);
    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.3, 0.5, 0);
    // left
    glColor3f(0, 0, 0);
    glVertex3f(-0.3, -0.3, 0.05);
    glVertex3f(-0.3, -0.3, 0);
    glVertex3f(-0.3, 0.5, 0);
    glVertex3f(-0.3, 0.5, 0.05);
    // right
    glColor3f(0, 0, 0);
    glVertex3f(-0.25, -0.3, 0.05);
    glVertex3f(-0.25, -0.3, 0);
    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.25, 0.5, 0.05);
    // bottom
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-0.3, -0.3, 0.05);
    glVertex3f(-0.25, -0.3, 0.05);
    glVertex3f(-0.25, -0.3, 0);
    glVertex3f(-0.3, -0.3, 0);
    // top
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-0.3, 0.5, 0.05);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.25, 0.5, 0);
    glVertex3f(-0.3, 0.5, 0);
    // front
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-0.3, -0.3, 0.05);
    glVertex3f(-0.25, -0.3, 0.05);
    glVertex3f(-0.25, 0.5, 0.05);
    glVertex3f(-0.3, 0.5, 0.05);

    glEnd();
}

void tree()
{
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.2, 0.14);
    // back
    glVertex3f(-0.3, -0.3, 1.45);
    glVertex3f(-0.25, -0.3, 1.45);
    glVertex3f(-0.25, 0, 1.45);
    glVertex3f(-0.3, 0, 1.45);
    // left
    glVertex3f(-0.3, -0.3, 1.5);
    glVertex3f(-0.3, -0.3, 1.45);
    glVertex3f(-0.3, 0, 1.45);
    glVertex3f(-0.3, 0, 1.5);
    // right
    glVertex3f(-0.25, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.45);
    glVertex3f(-0.25, 0, 1.45);
    glVertex3f(-0.25, 0, 1.5);
    // bottom
    glVertex3f(-0.3, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.45);
    glVertex3f(-0.3, -0.3, 1.45);
    // top
    glVertex3f(-0.3, 0, 1.5);
    glVertex3f(-0.25, 0, 1.5);
    glVertex3f(-0.25, 0, 1.45);
    glVertex3f(-0.3, 0, 1.45);
    // front
    glVertex3f(-0.3, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.5);
    glVertex3f(-0.25, 0, 1.5);
    glVertex3f(-0.3, 0, 1.5);

    glEnd();

    // leave
    glColor3f(0.4, 1, 0.2);
    glPushMatrix();
    glTranslatef(-0.3, -0.05, 1.4);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.2, 0.05, 1.4);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.4, -0.03, 1.4);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.35, 0.1, 1.4);
    glutSolidSphere(0.1, 36, 2);
    glPopMatrix();
}

void lamp()
{
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    // back
    glVertex3f(-0.3, -0.3, 1.45);
    glVertex3f(-0.25, -0.3, 1.45);
    glVertex3f(-0.25, 0, 1.45);
    glVertex3f(-0.3, 0, 1.45);
    // left
    glVertex3f(-0.3, -0.3, 1.5);
    glVertex3f(-0.3, -0.3, 1.45);
    glVertex3f(-0.3, 0, 1.45);
    glVertex3f(-0.3, 0, 1.5);
    // right
    glVertex3f(-0.25, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.45);
    glVertex3f(-0.25, 0, 1.45);
    glVertex3f(-0.25, 0, 1.5);
    // bottom
    glVertex3f(-0.3, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.45);
    glVertex3f(-0.3, -0.3, 1.45);
    // top
    glVertex3f(-0.3, 0, 1.5);
    glVertex3f(-0.25, 0, 1.5);
    glVertex3f(-0.25, 0, 1.45);
    glVertex3f(-0.3, 0, 1.45);
    // front
    glVertex3f(-0.3, -0.3, 1.5);
    glVertex3f(-0.25, -0.3, 1.5);
    glVertex3f(-0.25, 0, 1.5);
    glVertex3f(-0.3, 0, 1.5);
    glEnd();

    glColor3f(1.0, 1.0, 0);
    glPushMatrix();
    glTranslatef(-0.28, 0.02, 1.43);
    glutSolidSphere(0.08, 36, 2);
    glPopMatrix();
}
void background()
{
    // field
    glTranslatef(-0.5, -0.4, 0);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(10, 1, 1, 0);

    // front
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 2);
    glVertex3f(1.1, 0, 2);
    glVertex3f(1.1, 0.1, 2);
    glVertex3f(0, 0.1, 2);
    glEnd();

    // bottom
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 2);
    glVertex3f(1.1, 0, 2);
    glVertex3f(1.6, 0, 0);
    glVertex3f(0, 0, 0);
    glEnd();

    // up
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0.1, 2);
    glVertex3f(1.1, 0.1, 2);
    glVertex3f(1.6, 0.1, 0);
    glVertex3f(0, 0.1, 0);
    glEnd();

    // left
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 2);
    glVertex3f(0, 0.1, 2);
    glVertex3f(0, 0.1, 0);
    glEnd();

    // right
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(1.1, 0, 2);
    glVertex3f(1.6, 0, 0);
    glVertex3f(1.6, 0.1, 0);
    glVertex3f(1.1, 0.1, 2);
    glEnd();

    // back
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(1.6, 0, 0);
    glVertex3f(1.6, 0.1, 0);
    glVertex3f(0, 0.1, 0);
    glVertex3f(0, 0, 0);
    glEnd();

    // 1
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 2);
    glVertex3f(1.1, 0, 2);
    glEnd();
    // 2
    glColor3f(0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(0, 0.1, 2);
    glVertex3f(1.1, 0.1, 2);
    glEnd();
    // 3
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 2);
    glVertex3f(0, 0.1, 2);
    glEnd();
    // 4
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0.1, 2);
    glVertex3f(0, 0.1, 0);
    glEnd();
    // 5
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 2);
    glVertex3f(0, 0, 0);
    glEnd();
    // 6
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0.1, 0);
    glVertex3f(0, 0, 0);
    glEnd();
    // 7
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0.1, 0);
    glVertex3f(1.6, 0.1, 0);
    glEnd();

    // Road
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    // front
    glVertex3f(1.1, 0, 2);
    glVertex3f(2, 0, 2);
    glVertex3f(2, 0.1, 2);
    glVertex3f(1.1, 0.1, 2);
    // bottom
    glVertex3f(1.1, 0, 2);
    glVertex3f(2, 0, 2);
    glVertex3f(2, 0, 0);
    glVertex3f(1.6, 0, 0);
    // back
    glVertex3f(2, 0, 0);
    glVertex3f(1.6, 0, 0);
    glVertex3f(1.6, 0.1, 0);
    glVertex3f(2, 0.1, 0);
    // up
    glVertex3f(1.6, 0.1, 0);
    glVertex3f(2, 0.1, 0);
    glVertex3f(2, 0.1, 2);
    glVertex3f(1.1, 0.1, 2);
    // left
    glVertex3f(1.1, 0, 2);
    glVertex3f(1.6, 0, 0);
    glVertex3f(1.6, 0.1, 0);
    glVertex3f(1.1, 0.1, 2);
    // right
    glVertex3f(2, 0, 2);
    glVertex3f(2, 0, 0);
    glVertex3f(2, 0.1, 0);
    glVertex3f(2, 0.1, 2);
    glEnd();
}

void mountain()
{
    glBegin(GL_TRIANGLES);
    // front
    glVertex3f(-2, -0.28, 0);
    glVertex3f(-1, 0.3, -0.5);
    glVertex3f(0.5, -0.28, 0);
    // right
    glVertex3f(0.5, -0.28, 0);
    glVertex3f(-1, 0.3, -0.5);
    glVertex3f(0.5, -0.28, -1);
    // back
    glVertex3f(0.5, -0.28, -1);
    glVertex3f(-1, 0.3, -0.5);
    glVertex3f(-2, -0.28, -1);
    // left
    glVertex3f(-2, -0.28, 0);
    glVertex3f(-1, 0.3, -0.5);
    glVertex3f(-2, -0.28, -1);
    // bottom
    glVertex3f(-2, -0.28, 0);
    glVertex3f(0.5, -0.28, 0);
    glVertex3f(0.5, -0.28, -1);
    glVertex3f(-2, -0.28, -1);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    // 1
    glVertex3f(-2, -0.28, 0);
    glVertex3f(-1, 0.3, -0.5);
    glEnd();
    glBegin(GL_LINES);
    // 2
    glVertex3f(0.5, -0.28, 0);
    glVertex3f(-1, 0.3, -0.5);
    glEnd();
    glBegin(GL_LINES);
    // 3
    glVertex3f(0.5, -0.28, -1);
    glVertex3f(-1, 0.3, -0.5);
    glEnd();
    glBegin(GL_LINES);
    // 4
    glVertex3f(0.5, -0.28, 0);
    glVertex3f(0.5, -0.28, -1);
    glEnd();
    glBegin(GL_LINES);
    // 5
    glVertex3f(-2, -0.28, -1);
    glVertex3f(-1, 0.3, -0.5);
    glEnd();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    // 3rd mountain
    glPushMatrix();
    glScalef(1.2, 1.2, 1.2);
    glTranslatef(1.8, 0, 0);
    glColor3f(0.2, 0.3, 0.1);
    mountain();
    glPopMatrix();

    // 1st mountain
    glPushMatrix();
    glColor3f(0.419, 0.556, 0.137);
    mountain();
    glPopMatrix();

    // 2nd mountain
    glPushMatrix();
    glScalef(0.5, 0.7, 0.5);
    glTranslatef(1.2, -0.11, 0);
    glColor3f(0.5, 0.6, 0.1);
    mountain();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.6, 0);
    glScalef(3, 2.5, 2.5);
    background();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5, 1, 1);
    glTranslatef(-2.5 + x, -0.9, 0);
    cloud();
    glPopMatrix();

    // left windmill
    glPushMatrix();
    glTranslatef(0.3, 0, 0);
    // glRotatef(10,0,-1,0);
    tiang();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0, 0);
    // glRotatef(10,0,-1,0);
    glTranslatef(-0.275, 0.45, 0.2);
    glRotatef((GLfloat)a1, 0, 0, 1);
    glTranslatef(0.275, -0.45, -0.2);
    fan();
    glPopMatrix();

    // right windmill
    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    tiang();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    glTranslatef(-0.275, 0.45, 0.2);
    glRotatef((GLfloat)a, 0, 0, 1);
    glTranslatef(0.275, -0.45, -0.2);
    fan();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(1.1 + tx, -0.3 + ty, 0 + tz);
    glScalef(1 + Sx, 1 + Sy, 1 + Sz);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();

    // tree
    glPushMatrix();
    glTranslatef(-0.25, 0, -0.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 0, 0.2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.5, 0, 0.2);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 0, -1.5);
    lamp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88, 0, -1);
    lamp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8, 0, -0.5);
    lamp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.72, 0, 0);
    lamp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.64, 0, 0.5);
    lamp();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

    glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init()
{

    // Set the current clear color to black and the current drawing color to
    // white.
    glClearColor(0.4, 0.85, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);

    // Set the camera lens to have a 60 degree (vertical) field of view, an
    // aspect ratio of 4/3, and have everything closer than 1 unit to the
    // camera and greater than 40 units distant clipped away.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0 / 3.0, 1, 20);

    // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
    // <0, 1, 0> pointing upward.
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Project");

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(special);
    glutTimerFunc(25, spin, 0);
    // glutTimerFunc(0,time,0);
    init();
    glutMainLoop();
}
// #include <windows.h>
#ifdef APPLE_CC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static float a1 = 0, a2 = 0;
static int tx = 0, ty = 0;

void init() {
    glClearColor(1, 1, 1, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

// Special keys (F1, F2, F3 + arrows)
void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:  tx -= 5; break;
        case GLUT_KEY_RIGHT: tx += 5; break;
        case GLUT_KEY_UP:    ty += 5; break;
        case GLUT_KEY_DOWN:  ty -= 5; break;

        case GLUT_KEY_F1: a1 += 5; break;   // rotate Z +
        case GLUT_KEY_F3: a1 -= 5; break;   // rotate Z -
        case GLUT_KEY_F2: a2 += 5; break;   // rotate X

        default: return;
    }
    glutPostRedisplay();
}

// Idle for continuous redraw
void idle() {
    glutPostRedisplay();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Move object
    glTranslatef(tx, ty, 0.0);

    // Rotate around center
    glTranslatef(50, 50, 0);
    glRotatef(a1, 0, 0, 1);   // Z axis
    glRotatef(a2, 1, 0, 0);   // X axis
    glTranslatef(-50, -50, 0);

    // Draw quad
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex3f(0,   0,   0);
        glColor3f(0, 0, 1); glVertex3f(100, 0,   0);
        glColor3f(1, 0, 0); glVertex3f(100, 100, 0);
        glColor3f(0, 1, 0); glVertex3f(0,   100, 0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Quad");

    glutDisplayFunc(display);
    glutSpecialFunc(special);
    glutIdleFunc(idle);   // IMPORTANT for smooth update

    init();
    glutMainLoop();
}
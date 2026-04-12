#include <GL/glut.h>

static float angle = 0.0f;

/* Draw a 3D wireframe cube using lines */
void drawWireCube(float size)
{
    float s = size * 0.5f;
    float v[8][3] = {
        {-s, -s, -s}, {s, -s, -s}, {s, s, -s}, {-s, s, -s}, {-s, -s, s}, {s, -s, s}, {s, s, s}, {-s, s, s}};

    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, /* back face */
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4}, /* front face */
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7} /* connectors */
    };

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < 12; ++i)
    {
        glVertex3fv(v[edges[i][0]]);
        glVertex3fv(v[edges[i][1]]);
    }
    glEnd();
    glLineWidth(1.0f);
}

void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 1.0f, 1.0f, 0.0f);

    drawWireCube(2.0f);

    glutSwapBuffers();
}

void update(int value)
{
    angle += 0.8f;
    if (angle > 360.0f)
        angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void reshape(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Wireframe Cube - sample3.c");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}

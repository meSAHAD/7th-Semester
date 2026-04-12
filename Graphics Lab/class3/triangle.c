#include <GL/glut.h>

float angle = 0.0f;

// Cube vertices
float vertices[8][3] = {
    {-0.5, -0.5, -0.5}, // 0
    {0.5, -0.5, -0.5},  // 1
    {0.5, 0.5, -0.5},   // 2
    {-0.5, 0.5, -0.5},  // 3
    {-0.5, -0.5, 0.5},  // 4
    {0.5, -0.5, 0.5},   // 5
    {0.5, 0.5, 0.5},    // 6
    {-0.5, 0.5, 0.5}    // 7
};

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void drawTriangle()
{
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.8, -0.6, 0.0); // B
    glVertex3f(0.8, -0.6, 0.0);  // C
    glVertex3f(0.0, 0.8, 0.0);   // D
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.6);   // A
    glVertex3f(-0.8, -0.6, 0.0); // B

    glVertex3f(0.0, 0.0, 0.6);  // A
    glVertex3f(0.8, -0.6, 0.0); // C

    glVertex3f(0.0, 0.0, 0.6); // A
    glVertex3f(0.0, 0.8, 0.0); // D
    glEnd();
}

void drawCube()
{
    glPointSize(6.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 8; i++)
    {
        glVertex3fv(vertices[i]);
    }
    glEnd();
    glBegin(GL_LINES);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[0]);

    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[4]);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-1.5, 0.0, -3.0);
    glRotatef(25, 1.0, 1.0, 0.0);
    drawTriangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0.0, -3.0);
    glRotatef(angle, 1.0, 1.0, 0.0);
    drawCube();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangle and Cube");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
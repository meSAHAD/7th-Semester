/*
 * OpenGL GLUT Cube Viewer
 * Compile: gcc cube.c -o cube -lGL -lGLU -lglut -lm
 * Or on macOS: gcc cube.c -o cube -framework OpenGL -framework GLUT
 *
 * Controls:
 *   Left/Right Arrow  - rotate around Y axis
 *   Up/Down Arrow     - rotate around X axis
 *   +/-               - zoom in/out
 *   R                 - reset view
 *   ESC / Q           - quit
 */

#include <GL/glut.h>
#include <math.h>

/* Rotation and zoom state */
static float rotX = 25.0f;
static float rotY = 35.0f;
static float zoom = -5.0f;

/* Draw one face using exactly 4 vertices (GL_QUADS) */
static void drawFace(
    float x0, float y0, float z0,
    float x1, float y1, float z1,
    float x2, float y2, float z2,
    float x3, float y3, float z3,
    float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS); /* 4 glVertex calls per face */
    glVertex3f(x0, y0, z0);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();
}

/* Draw the cube – 6 faces, each with 4 vertices */
static void drawCube(void)
{
    float s = 1.0f; /* half-size */

    /* Front  face  (z = +s) – red */
    drawFace(-s, -s, s, s, -s, s, s, s, s, -s, s, s, 1.0f, 0.2f, 0.2f);

    /* Back   face  (z = -s) – green */
    drawFace(s, -s, -s, -s, -s, -s, -s, s, -s, s, s, -s, 0.2f, 0.8f, 0.2f);

    /* Left   face  (x = -s) – blue */
    drawFace(-s, -s, -s, -s, -s, s, -s, s, s, -s, s, -s, 0.2f, 0.4f, 1.0f);

    /* Right  face  (x = +s) – yellow */
    drawFace(s, -s, s, s, -s, -s, s, s, -s, s, s, s, 1.0f, 0.9f, 0.1f);

    /* Top    face  (y = +s) – cyan */
    drawFace(-s, s, s, s, s, s, s, s, -s, -s, s, -s, 0.1f, 0.9f, 0.9f);

    /* Bottom face  (y = -s) – magenta */
    drawFace(-s, -s, -s, s, -s, -s, s, -s, s, -s, -s, s, 0.9f, 0.1f, 0.9f);

    /* Wireframe overlay for depth cues */
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.5f);
    glutWireCube(2.0); /* side length = 2*s */
}

/* ------------------------------------------------------------------ */

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, zoom);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);

    drawCube();

    glutSwapBuffers();
}

static void reshape(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

static void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '+':
        zoom += 0.2f;
        break;
    case '-':
        zoom -= 0.2f;
        break;
    case 'r':
    case 'R':
        rotX = 25.0f;
        rotY = 35.0f;
        zoom = -5.0f;
        break;
    case 'q':
    case 'Q':
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

static void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        rotY -= 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        rotY += 5.0f;
        break;
    case GLUT_KEY_UP:
        rotX -= 5.0f;
        break;
    case GLUT_KEY_DOWN:
        rotX += 5.0f;
        break;
    }
    glutPostRedisplay();
}

/* ------------------------------------------------------------------ */

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube – 4 glVertex per face");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.12f, 0.12f, 0.15f, 1.0f);

    /* Simple lighting feel via polygon offset so wireframe stays sharp */
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    printf("Controls:\n");
    printf("  Arrow Keys  – rotate cube\n");
    printf("  + / -       – zoom in / out\n");
    printf("  R           – reset view\n");
    printf("  Q / ESC     – quit\n");

    glutMainLoop();
    return 0;
}
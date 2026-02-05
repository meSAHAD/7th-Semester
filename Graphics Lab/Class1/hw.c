#include <GL/glut.h>

void display()
{
    // 1. Clear the screen to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // 2. Draw the Main Body (Beige Rectangle)
    glColor3f(0.95f, 0.91f, 0.81f); // Beige color
    glBegin(GL_QUADS);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.7f, 0.2f);
    glVertex2f(-0.7f, 0.2f);
    glEnd();

    // 3. Draw the Roof Outline (Brown Trapezoid)
    glColor3f(0.58f, 0.29f, 0.0f); // Brown color
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7f, 0.2f);
    glVertex2f(-0.4f, 0.6f);
    glVertex2f(0.4f, 0.6f);
    glVertex2f(0.7f, 0.2f);
    glEnd();

    // 4. Draw the Door (Brown Rectangle)
    glColor3f(0.58f, 0.29f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.6f);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(-0.15f, 0.0f);
    glEnd();

    // 5. Draw the Windows (Light Blue Squares)
    glColor3f(0.67f, 0.84f, 0.9f); // Light Blue
    // Left Window
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.5f, -0.1f);
    glEnd();
    // Right Window
    glBegin(GL_QUADS);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.3f, -0.1f);
    glEnd();

    // 6. Window Frames (Black Lines)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    // Left window cross
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.3f, -0.2f);
    // Right window cross
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    // Door vertical line
    glVertex2f(0.0f, -0.6f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    // 7. Door Knob (Black Point)
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, -0.3f);
    glEnd();

    glFlush(); // Send all commands to the GPU
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Simple OpenGL House");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
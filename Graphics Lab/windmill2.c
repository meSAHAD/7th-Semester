#include <GL/glut.h>
#include <math.h>
float angle = 0.0;
// Draw a single blade (a simple triangle)
void drawBlade()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);   // base center
    glVertex2f(0.05, 0.3);  // tip right
    glVertex2f(-0.05, 0.3); // tip left
    glEnd();

    // Tiny red bulb at the right corner tip of the blade
    glColor3f(1.0, 0.0, 0.0); // red color
    glBegin(GL_QUADS);
    glVertex2f(0.03, 0.28); // bottom left
    glVertex2f(0.06, 0.28); // bottom right
    glVertex2f(0.06, 0.32); // top right
    glVertex2f(0.03, 0.32); // top left
    glEnd();
}

// Draw all 4 blades (rotated 90 degrees apart)
void drawBlades()
{
    int i;
    for (i = 0; i < 4; i++)
    {
        glPushMatrix();
        glRotatef(angle + i * 90.0, 0, 0, 1); // rotate each blade
        glColor3f(0.2, 0.6, 0.9);             // blade color (blue)
        drawBlade();
        glPopMatrix();
    }
}

// Draw the windmill tower (a trapezoid)
void drawTower()
{
    glColor3f(0.5, 0.35, 0.2); // brown color
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.8); // bottom left
    glVertex2f(0.08, -0.8);  // bottom right
    glVertex2f(0.04, 0.0);   // top right
    glVertex2f(-0.04, 0.0);  // top left
    glEnd();
}

// Draw a simple square box to the right of the windmill
void drawBox()
{
    // Box body
    glColor3f(0.9, 0.9, 0.9); // light gray box
    glBegin(GL_QUADS);
    glVertex2f(0.45, -0.95);
    glVertex2f(0.75, -0.95);
    glVertex2f(0.75, -0.55);
    glVertex2f(0.45, -0.55);
    glEnd();

    // Box outline
    glColor3f(0.0, 0.0, 0.0); // black border
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.45, -0.95);
    glVertex2f(0.75, -0.95);
    glVertex2f(0.75, -0.55);
    glVertex2f(0.45, -0.55);
    glEnd();
}

// Main display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw sky background
    glClearColor(0.53, 0.81, 0.92, 1.0); // light blue sky
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw ground
    glColor3f(0.3, 0.7, 0.2);

    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);

    glVertex2f(1.0, -0.75);
    glVertex2f(-1.0, -0.75);
    glEnd();

    // Draw the windmill
    drawTower();
    drawBlades();
    drawBox();
    // drawHub();

    glutSwapBuffers();
}

// Timer: update rotation angle
void update(int value)
{
    angle += 2.0; 
    if (angle > 360.0)
        angle -= 360.0;

    glutPostRedisplay();          // request redraw
    glutTimerFunc(16, update, 0); // ~60 FPS
}

// Window resize handler
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 1000);
    glutCreateWindow("Rotating Windmill - OpenGL");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0); 

    glutMainLoop();
    return 0;
}
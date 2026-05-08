#include <GL/freeglut.h>
#include <cmath>

// Rotation angle for blades
float angle = 0.0f;
float posX = 0.0f;
float posY = 0.0f;
float scale = 1.0f;
float rotateWindmill = 0.0f;
float camX = 0.0f;
float camY = 4.0f;
float camZ = 15.0f;
bool isRotating = true;
float treeAngle = 0.0f;
float treeRotation = 0.0f;
float treePosX = 9.0f;
float treePosY = 0.0f;

float treeTilt = 0.0f; // upside-down rotation

// -------------------------------------------------
// Draw Ground
// -------------------------------------------------
void drawGround()
{
    glColor3f(0.0f, 0.8f, 0.0f);

    glBegin(GL_QUADS);
    glVertex3f(-10.0f, -2.0f, -10.0f);
    glVertex3f(10.0f, -2.0f, -10.0f);
    glVertex3f(10.0f, -2.0f, 10.0f);
    glVertex3f(-10.0f, -2.0f, 10.0f);
    glEnd();
}

// -------------------------------------------------
// Draw Tower
// -------------------------------------------------
void drawTower()
{
    GLUquadric *quad = gluNewQuadric();

    glColor3f(0.7f, 0.4f, 0.2f);

    glPushMatrix();

    glTranslatef(0.0f, -2.0f, 0.0f);

    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    // Tapered cylinder
    gluCylinder(
        quad,
        1.5, // bottom radius
        1.0, // top radius
        4.0, // height
        30,
        30);

    glPopMatrix();

    gluDeleteQuadric(quad);
}

// -------------------------------------------------
// Draw Roof
// -------------------------------------------------
void drawRoof()
{
    GLUquadric *quad = gluNewQuadric();

    glColor3f(0.8f, 0.1f, 0.1f);

    glPushMatrix();

    glTranslatef(0.0f, 2.0f, 0.0f);

    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    gluCylinder(
        quad,
        1.2,
        0.0,
        1.2,
        30,
        30);

    glPopMatrix();

    gluDeleteQuadric(quad);
}

// -------------------------------------------------
// Draw One Blade
// -------------------------------------------------
void drawBlade()
{
    glDisable(GL_LIGHTING);

    glColor3f(0.95f, 0.9f, 0.7f);

    float length = 3.0f;               // blade length
    float rectWidth = 2.6f;            // almost full blade length
    float rectHeight = 0.55f;          // thicker rectangle
    float offsetY = rectHeight / 2.0f; // makes rectangle TOUCH blade

    // --- Blade line ---
    glLineWidth(6.0f);

    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(length, 0.0f, 0.0f);
    glEnd();

    // --- Rectangle attached to blade ---
    // --- Transparent rectangle panel ---

    glDisable(GL_LIGHTING);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float zOffset = 0.01f; // prevents flickering

    // Transparent fill
    glColor4f(0.95f, 0.9f, 0.7f, 0.35f); // last value = transparency

    glBegin(GL_QUADS);

    glVertex3f(length - rectWidth, offsetY + rectHeight / 2, zOffset);
    glVertex3f(length, offsetY + rectHeight / 2, zOffset);
    glVertex3f(length, offsetY - rectHeight / 2, zOffset);
    glVertex3f(length - rectWidth, offsetY - rectHeight / 2, zOffset);

    glEnd();

    // --- Dark grid lines ---

    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.5f);

    glBegin(GL_LINES);

    // Vertical grid lines
    for (float x = length - rectWidth + 0.2f; x < length; x += 0.25f)
    {
        glVertex3f(x, offsetY + rectHeight / 2, zOffset);
        glVertex3f(x, offsetY - rectHeight / 2, zOffset);
    }

    // Horizontal grid lines
    for (float y = offsetY - rectHeight / 2 + 0.15f;
         y < offsetY + rectHeight / 2;
         y += 0.15f)
    {
        glVertex3f(length - rectWidth, y, zOffset);
        glVertex3f(length, y, zOffset);
    }

    glEnd();

    // --- Red border ---

    glColor3f(0.9f, 0.1f, 0.1f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);

    glVertex3f(length - rectWidth, offsetY + rectHeight / 2, zOffset);
    glVertex3f(length, offsetY + rectHeight / 2, zOffset);
    glVertex3f(length, offsetY - rectHeight / 2, zOffset);
    glVertex3f(length - rectWidth, offsetY - rectHeight / 2, zOffset);

    glEnd();

    glEnable(GL_LIGHTING);
}
// -------------------------------------------------
// Draw All Blades
// -------------------------------------------------
void drawBlades()
{
    glPushMatrix();

    glTranslatef(0.0f, 2.0f, 1.8f);

    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    for (int i = 0; i < 4; i++)
    {
        drawBlade();
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    }

    glPopMatrix();
}
// -------------------------------------------------
// Draw Tree
// -------------------------------------------------
void drawTree()
{
    GLUquadric *quad = gluNewQuadric();

    // ---- Tree trunk (Cylinder) ----
    glColor3f(0.55f, 0.27f, 0.07f);

    glPushMatrix();
    glTranslatef(-4.0f, -2.0f, -2.0f);

    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    gluCylinder(
        quad,
        0.4,
        0.4,
        2.5,
        20,
        20);
    glPopMatrix();

    // ---- Leaves (Multiple spheres) ----
    glColor3f(0.0f, 0.6f, 0.0f);

    glPushMatrix();
    glTranslatef(-4.0f, 1.0f, -2.0f);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5f, 1.5f, -2.0f);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5f, 1.5f, -2.0f);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();

    gluDeleteQuadric(quad);
}

// -------------------------------------------------
// Draw Sun
// -------------------------------------------------
void drawSun()
{
    glColor3f(1.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(5.0f, 4.0f, -5.0f);
    glutSolidSphere(1.0, 30, 30);
    glPopMatrix();
}

// -------------------------------------------------
// Setup Lighting
// -------------------------------------------------
void setupLighting()
{
    GLfloat lightPos[] = {5.0f, 8.0f, 5.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

// -------------------------------------------------
// Draw Door
// -------------------------------------------------
void drawDoor()
{
    glColor3f(0.8f, 0.2f, 0.2f); // red door

    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 0.76f);
    glScalef(0.6f, 1.2f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
}

// -------------------------------------------------
// Draw Window
// -------------------------------------------------
void drawWindow()
{
    glColor3f(0.7f, 0.9f, 1.0f); // light blue window

    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.76f);
    glScalef(0.5f, 0.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();
}

// -------------------------------------------------
// Draw Text
// -------------------------------------------------
void drawText(float x, float y, const char *text)
{
    glRasterPos2f(x, y);

    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *text);
        text++;
    }
}

void drawGrid()
{
    glColor3f(0.3f, 0.3f, 0.3f);

    glLineWidth(1.0f);

    glBegin(GL_LINES);

    for (int i = -10; i <= 10; i++)
    {
        // Lines parallel to Z-axis
        glVertex3f(i, -1.99f, -10);
        glVertex3f(i, -1.99f, 10);

        // Lines parallel to X-axis
        glVertex3f(-10, -1.99f, i);
        glVertex3f(10, -1.99f, i);
    }

    glEnd();
}

// -------------------------------------------------
// Draw Hub (Sphere at center of blades)
// -------------------------------------------------
void drawHub()
{
    glColor3f(0.9f, 0.3f, 0.2f);

    glPushMatrix();

    glTranslatef(0.0f, 2.0f, 2.0f);
    glutSolidSphere(0.25, 20, 20);

    glPopMatrix();
}
// -------------------------------------------------
// Display Function
// -------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
   
    glLoadIdentity();
    setupLighting();

    gluLookAt(
        camX, camY, camZ,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    drawGround();
    drawGrid();

    glPushMatrix();

    glTranslatef(treePosX, treePosY, -2.0f);

    // Left-right rotation (R / L keys)
    glRotatef(treeRotation, 0.0f, 1.0f, 0.0f);

    // Upside-down rotation (UP / DOWN keys)
    glRotatef(treeTilt, 1.0f, 0.0f, 0.0f);

    drawTree();

    glPopMatrix();

    glTranslatef(posX, posY, 0.0f);
    glScalef(scale, scale, scale);
    glRotatef(rotateWindmill, 0.0f, 0.0f, 1.0f);

    drawTower();
    drawRoof();
    drawDoor();
    drawWindow();
    drawHub();
    drawBlades();

    glPopMatrix();

    // Switch to 2D mode for text
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(0.0f, 0.0f, 0.0f);

    drawText(10, 780, "Arrow Keys: Move tree / Tilt tree");
    drawText(10, 760, "W A S D: Move Camera");
    drawText(10, 740, "+ / - : Scale");
    drawText(10, 720, "R: Rotate Tree Right");
    drawText(10, 700, "L: Rotate Tree Left");
    drawText(10, 680, "P: Pause / Resume");
    drawText(10, 660, "0: Reset View");

    // Restore matrices
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
}

// -------------------------------------------------
// Initialize OpenGL
// -------------------------------------------------
void init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    // Lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        1.0,
        1.0,
        100.0);
}

// -------------------------------------------------
// Update Function for Animation
// -------------------------------------------------
void update(int value)
{
    if (isRotating)
    {
        angle += 2.0f;

        if (angle > 360)
            angle -= 360;
    }

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}
// -------------------------------------------------
// Keyboard Input
// -------------------------------------------------
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
    case 'R':
        treeRotation += 5.0f;
        break;

    case 'l':
    case 'L':
        treeRotation -= 5.0f;
        break;
    case '+':
        scale += 0.1f;
        break;

    case '-':
        scale -= 0.1f;
        if (scale < 0.2f)
            scale = 0.2f;
        break;

        // Camera movement

    case 'w':
        camZ -= 0.5f;
        break;

    case 's':
        camZ += 0.5f;
        break;

    case 'a':
        camX -= 0.5f;
        break;

    case 'd':
        camX += 0.5f;
        break;
    case '0':

        // Reset camera
        camX = 0.0f;
        camY = 4.0f;
        camZ = 15.0f;

        // Reset windmill
        posX = 0.0f;
        posY = 0.0f;
        scale = 1.0f;
        rotateWindmill = 0.0f;

        // Reset blade rotation
        angle = 0.0f;
        isRotating = true;

        // Reset tree position and rotation
        treePosX = 9.0f;
        treePosY = 0.0f;
        treeRotation = 0.0f;
        treeTilt = 0.0f;

        glutPostRedisplay();
        break;

    case 'p':
    case 'P':
        isRotating = !isRotating;
        break;
    }
    
    glutPostRedisplay();
}

// -------------------------------------------------
// Special Keys for Camera Movement
// -------------------------------------------------
void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        treePosX -= 0.5f;
        break;

    case GLUT_KEY_RIGHT:
        treePosX += 0.5f;
        break;

    case GLUT_KEY_UP:
        treeTilt += 5.0f;
        break;

    case GLUT_KEY_DOWN:
        treeTilt -= 5.0f;
        break;
    }

    glutPostRedisplay();
}

// -------------------------------------------------
// Main Function
// -------------------------------------------------
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH);

    glutInitWindowSize(800, 800);

    glutCreateWindow("Rotating Windmill");

    init();

    glutDisplayFunc(display);

    // Register input AFTER window creation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    // Start animation timer
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
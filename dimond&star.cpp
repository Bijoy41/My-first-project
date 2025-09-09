#include <GL/glut.h>
#include <iostream>
using namespace std;
// Function to plot a point
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
// ---------------- DDA Algorithm ----------------
void DDA(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;
    float x = x0, y = y0;
    for (int i = 0; i <= steps; i++) {
        drawPixel((int)x, (int)y);
        x += xInc;
        y += yInc;
    }
}
// ---------------- DLD Algorithm ----------------
void DLD(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    while (true) {
        drawPixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}
// ---------------- Display Function ----------------
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1); // White color
    // Draw axis (for 4 quadrants)
    DDA(-300, 0, 300, 0);  // X-axis
    DDA(0, -300, 0, 300);  // Y-axis
    // ---- Diamond using DDA (Top-left quadrant, bigger & shifted up) ----
    DDA(-225, 75, -150, 150);
    DDA(-150, 150, -75, 75);
    DDA(-75, 75, -150, 0);
    DDA(-150, 0, -225, 75);
    // ---- Star using DLD (Top-right quadrant, bigger) ----
    DLD(75, 0, 135, 120);
    DLD(135, 120, 15, 45);
    DLD(15, 45, 135, 45);
    DLD(135, 45, 15, 120);
    DLD(15, 120, 75, 0);
    glFlush();
}
// ---------------- Main Function ----------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bigger Diamond & Star");
    glClearColor(0, 0, 0, 0); // Black background
    glColor3f(1, 1, 1);       // White color
    glPointSize(4.0);         // Point size
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-350, 350, -350, 350);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

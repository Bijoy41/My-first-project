#include <GL/glut.h>
 #include <cmath>
 void drawE(float xShift, float yShift, float size) {
 float x, y;
 for (y = 0.0f; y <= 0.4f; y += 0.001f) {
glVertex2f(xShift + 0.0f * size, yShift + y * size);
 }
 for (x = 0.0f; x <= 0.3f; x += 0.001f) {
 glVertex2f(xShift + x * size, yShift + 0.4f * size);
 }
 for (x = 0.0f; x <= 0.25f; x += 0.001f) {
 glVertex2f(xShift + x * size, yShift + 0.2f * size);
 }
 for (x = 0.0f; x <= 0.3f; x += 0.001f) {
 glVertex2f(xShift + x * size, yShift + 0.0f * size);
 }
 }
 void drawA(float xShift, float yShift, float size) {
 float x, y;
 for (x = 0.0f; x <= 0.4f; x += 0.001f) {
 y =x;
 glVertex2f(xShift + x * size, yShift + y * size);
 }
 for (x = 0.0f; x <= 0.4f; x += 0.001f) {
 y =0.4f- x;
 glVertex2f(xShift + (0.3f + x) * size, yShift + y * size);
 }
 for (x = 0.1f; x <= 0.6f; x += 0.001f) {
 glVertex2f(xShift + x * size, yShift + 0.2f * size);
 }
}
 void renderScene() {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1, 1, 1); // White
 glPointSize(4.0f);
 glBegin(GL_POINTS);
 drawA(0.45f, 0.5f, 0.7f); // A in 2nd quadrant
 drawE(0.05f, 0.05f, 0.8f); // E in 3rd quadrant
 glEnd();
 glFlush();
 }
 void setupGraphics() {
 glClearColor(0, 0, 0, 1); // Black background
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0, 1, 0, 1); // 2D view (0–1)
 }
 int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Drawing Letters A & E using GL_POINTS");
 setupGraphics();
 glutDisplayFunc(renderScene);
 glutMainLoop();
return 0;
 }
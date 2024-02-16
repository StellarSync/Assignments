#include <GL/glut.h>
#include <stdio.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
  int dx = x2 - x1;
  int dy = y2 - y1;
  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // Choose larger absolute change
  float x_increment = dx / (float)steps;
  float y_increment = dy / (float)steps;

  float x = x1, y = y1;
  for (int i = 0; i <= steps; ++i) {
    glBegin(GL_POINTS);
    glVertex2f(x, y); // Set pixel at (x, y)
    glEnd();
    x += x_increment;
    y += y_increment;
  }
}

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
  glClear(GL_COLOR_BUFFER_BIT);

  // Get user input for line coordinates
  int x1, y1, x2, y2;
  printf("Enter starting point (x1, y1): ");
  scanf("%d %d", &x1, &y1);
  printf("Enter ending point (x2, y2): ");
  scanf("%d %d", &x2, &y2);

  // Draw the line using user-provided coordinates
  drawLineDDA(x1, y1, x2, y2);

  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("DDA Line Drawing with User Input");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


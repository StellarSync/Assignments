#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include<math.h>
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int main() {
    Display *display;
    Window window;
    GC gc;
    int screen_num;
    unsigned long white, black;

    // Get X11 display and screen
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Error: Cannot open display.\n");
        exit(1);
    }
    screen_num = XDefaultScreen(display);

    // Get window colors
    white = WhitePixel(display, screen_num);
    black = BlackPixel(display, screen_num);

    // Create window
    window = XCreateSimpleWindow(display, RootWindow(display, screen_num),
                                 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 1,
                                 black, white);
    XSetWindowBorder(display, window, "DDA Line Drawing");
    XMapWindow(display, window);

    // Create graphics context
    gc = XCreateGC(display, window, 0, NULL);
    XSetForeground(display, gc, white);
    XSetLineAttributes(display, gc, 1, LineSolid, CapRound, JoinRound);

    // Get user input for line coordinates
    int x1, y1, x2, y2;
    printf("Enter starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Calculate DDA parameters
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_increment = dx / (float)steps;
    float y_increment = dy / (float)steps;

    // Draw the line using DDA
    float x = x1, y = y1;
    for (int i = 0; i <= steps; ++i) {
        XDrawPoint(display, window, gc, (int)round(x), (int)round(y));
        x += x_increment;
        y += y_increment;
    }

    // Handle events and window closure
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        if (event.type == KeyPress && event.xkey.keycode == 27) {
            break;
        }
    }

    // Clean up resources
    XDestroyWindow(display, window);
    XFreeGC(display, gc);
    XCloseDisplay(display);

    return 0;
}


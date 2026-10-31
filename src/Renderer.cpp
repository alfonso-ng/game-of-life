#include "Renderer.hpp"
#include <X11/Xlib.h>

Renderer::Renderer()
{
    display = XOpenDisplay(nullptr);
    screen = DefaultScreen(display);
}

void Renderer::createWindow(int w, int h, char* name)
{
    window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,
        w, h,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XStoreName(display, window, "Game of Life");

}

void Renderer::displayWindow()
{
    // Register events
    XSelectInput(display, window, ExposureMask | ButtonPressMask);

    // Make the window visible
    XMapWindow(display, window);

    // Process pending X11 requests
    XFlush(display);
}

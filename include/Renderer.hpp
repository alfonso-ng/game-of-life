#ifndef RENDERER_H
#define RENDERER_H

#include <X11/Xlib.h>

class Renderer
{
private:
    Display* display;
    int screen;
    Window window;

public:
    Renderer();

    void createWindow(int w, int h);
    void displayWindow(Window window);
};

#endif

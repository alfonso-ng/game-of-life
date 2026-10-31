#include "Game.hpp"
#include "Renderer.hpp"


int main(int argc, char **argv)
{
    Vec2List list = Vec2List();

    vec2 p1 = {1, 2};
    vec2 p2 = {2, 0};
    vec2 p3 = {1, 1};

    list.push_back(p1);
    list.push_back(p2);
    list.push_back(p3);


    Game g = Game(16, 16, list);

    Renderer renderer = Renderer();
    renderer.createWindow(800, 600);

    g.simulate();

    return 0;
}

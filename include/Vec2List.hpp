#ifndef VEC2LIST_H
#define VEC2LIST_H

#include <cstddef>


typedef struct {
    int x;
    int y;
} vec2;

class Vec2List
{
private:
    vec2* items;
    size_t size;
    size_t capacity;

public:
    Vec2List();
    ~Vec2List();

    int getSize();

    void push_back(vec2 item);
    vec2 item_at(int index);
};

#endif

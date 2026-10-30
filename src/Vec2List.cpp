#include "Vec2List.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

Vec2List::Vec2List()
{
    items = NULL;
    size = 0;
    capacity = 0;
}

Vec2List::~Vec2List()
{
    free(items);
}

void Vec2List::push_back(vec2 item)
{
    if (items == NULL) {
        items = (vec2*)malloc(sizeof(vec2));
        capacity = 1;
    }
    else if (size >= capacity) {
        capacity *= 2;
        items = (vec2*)realloc(items, capacity * sizeof(vec2));
    }
    items[size] = item;
    size++;
}

vec2 Vec2List::item_at(int index)
{
    if (index < 0 || index >= size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    return items[index];
}

int Vec2List::getSize()
{
    return size;
}

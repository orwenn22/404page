#ifndef BRICK_H
#define BRICK_H

#include <raylib.h>

class Brick {
    public:
    Rectangle hitbox;
    bool exist = false;

    void Init(float x, float y);
    void Draw();
};

#endif
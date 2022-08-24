#ifndef BALL_H
#define BALL_H

#include <raylib.h>

#include "brick.h"

class Ball {
    public:
    Rectangle hitbox;
    Vector2 direction;


    void Init(Vector2 position);
    void Update(Brick *gamebricks);
    void Draw();
};

#endif
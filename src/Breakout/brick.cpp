#include "brick.h"

void Brick::Init(float x, float y) {
    exist = true;
    hitbox = {x, y, 75, 20};
}

void Brick::Draw() {
    if(exist) DrawRectangleRec(hitbox, RED);
}
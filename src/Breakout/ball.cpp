#include "ball.h"
#include "brick.h"

#include <raylib.h>

void Ball::Init(Vector2 position) {
    hitbox = {position.x, position.y, 16, 16};
    direction = {4, -4};
}

void Ball::Update(Brick *gamebricks) {
    hitbox.x += direction.x;

    for(int i = 0; i < 25; i++) {
        if(CheckCollisionRecs(hitbox, gamebricks[i].hitbox) && gamebricks[i].exist == true) {
            direction.x = -direction.x;
            gamebricks[i].exist = false;
        }
    }

    hitbox.y += direction.y;
    for(int i = 0; i < 25; i++) {
        if(CheckCollisionRecs(hitbox, gamebricks[i].hitbox) && gamebricks[i].exist == true) {
            direction.y = -direction.y;
            gamebricks[i].exist = false;
        }
    }

    if(hitbox.x < 0 || hitbox.x > 484) direction.x = -direction.x;
    if(hitbox.y <0) direction.y =-direction.y;
}

void Ball::Draw() {
    DrawCircle(hitbox.x + 8, hitbox.y + 8, 8, RED);
}
#include "player.h"
#include "ball.h"

#include <raylib.h>

extern bool g_isonmobile;
extern int g_winwidth;

void Player::Init(int x, int y) {
    hitbox = {(float)x, (float)y, 50, 10};
}

void Player::Update(Ball &gameball) {
    if(g_isonmobile) {
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if(GetMousePosition().x < g_winwidth/2) hitbox.x -= 5;
            else hitbox.x += 5;
        }
    } else {
        if(IsKeyDown(KEY_LEFT)) hitbox.x -= 5;
        if(IsKeyDown(KEY_RIGHT)) hitbox.x += 5;
    }

    if(CheckCollisionRecs(hitbox, gameball.hitbox)) {
        gameball.direction.y = - gameball.direction.y;
        gameball.direction.x = ((gameball.hitbox.x + 8) - (hitbox.x + 25)) / 4;
    }
}

void Player::Draw() {
    DrawRectangleRec(hitbox, RED);
}
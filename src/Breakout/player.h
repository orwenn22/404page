#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

#include "ball.h"

class Player {
    public:
    Rectangle hitbox;

    void Init(int x, int y);
    void Update(Ball &gameball);
    void Draw();
};

#endif
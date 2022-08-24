#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <raylib.h>

#include "ball.h"
#include "player.h"
#include "brick.h"

class Breakout {
    public:
    Breakout();
    ~Breakout();

    void Update();
    void Draw(int x, int y);


    Ball gameBall;
    Player gamePlayer;
    Brick gameBricks[25];

    RenderTexture2D render;
    RenderTexture2D finalRender;
};

#endif
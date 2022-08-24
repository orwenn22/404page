#include "breakout.h"
#include "ball.h"
#include "player.h"
#include "brick.h"

Breakout::Breakout() {
    render = LoadRenderTexture(500, 500);
    finalRender = LoadRenderTexture(500, 500);

    for(int y = 0; y < 5; y++) {
        for(int x = 0; x < 5; x++) {
            gameBricks[y*5 + x].Init(5+ x*100, 10 + y*25);
        }
    }

    gameBall.Init({242, 242});
    gamePlayer.Init(225, 480);
}

Breakout::~Breakout() {
    UnloadRenderTexture(render);
    UnloadRenderTexture(finalRender);
}

void Breakout::Update() {
    gameBall.Update(gameBricks);
    gamePlayer.Update(gameBall);


    BeginTextureMode(render);
        ClearBackground(BLACK);
        gamePlayer.Draw();
        gameBall.Draw();
        for(int i = 0; i < 25; i++) gameBricks[i].Draw();
    EndTextureMode();

    BeginTextureMode(finalRender);
        DrawTexture(render.texture, 0, 0, WHITE);
    EndTextureMode();
}

void Breakout::Draw(int x, int y) {
    DrawTexture(finalRender.texture, x, y, WHITE);
}
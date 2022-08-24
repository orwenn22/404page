#include "AmigaState.h"
#include "../Breakout/breakout.h"

#include <raylib.h>

extern int g_winwidth;
extern int g_winheight;

AmigaState::AmigaState() : State() {
    m_havegame = false;
}

AmigaState::~AmigaState() {
    if(m_havegame) {
        delete m_game;
        m_havegame = false;
    }
}


void AmigaState::Update() {
    if(m_havegame == false && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        m_game = new Breakout();
        m_havegame = true;
    }

    if(m_havegame) {
        m_game->Update();
    }
}

void AmigaState::Draw() {
    ClearBackground(BLACK);
    DrawRectangle(g_winwidth/2 - 310, g_winheight/2 - 230, 620, 70, RED);
    DrawRectangle(g_winwidth/2 - 305, g_winheight/2 -225, 610, 60, BLACK);

    DrawText("Software Failure.     Press left mouse button to continue.\n          Error: 404", g_winwidth/2 - 300, g_winheight/2 - 224, 20, RED);

    if(m_havegame) {
        DrawRectangle(g_winwidth/2 - 255, g_winheight/2 - 155, 510, 510, RED);
        m_game->Draw(g_winwidth/2 - 250, g_winheight/2 - 150);
    }
}
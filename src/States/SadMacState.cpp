#include "SadMacState.h"

#include <raylib.h>

extern int g_winwidth;
extern int g_winheight;

extern Texture2D g_sadmac;

SadMacState::SadMacState() : State() {}

void SadMacState::Draw() {
    ClearBackground(BLACK);
    DrawTextureEx(g_sadmac, {(float)(g_winwidth/2 - 50), (float)(g_winheight/2 - 50)}, 0, 2,WHITE);
}
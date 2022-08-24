#include "BluescreenState.h"

#include <raylib.h>

#if defined __EMSCRIPTEN__
#include<emscripten.h>
#endif

extern int g_winwidth;
extern int g_winheight;


void Rickroll() {
    #if defined __EMSCRIPTEN__
    emscripten_run_script("window.location.replace('https://www.youtube.com/watch?v=dQw4w9WgXcQ')");
    #endif
}

BluescreenState::BluescreenState() : State() {}

void BluescreenState::Update() {
        for(int i = 32; i < 91; i++) if(IsKeyPressed(i)) Rickroll();
        for(int i = 256; i < 284; i++) if(IsKeyPressed(i)) Rickroll();
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) Rickroll();
}

void BluescreenState::Draw() {
    ClearBackground({0, 0, 200, 255});
    DrawRectangle(g_winwidth/2 - 35, g_winheight/2 - 150, 70, 20, GRAY);
    DrawText("ERROR", g_winwidth/2 - 34, g_winheight/2 - 150, 20, {0, 0, 255, 255});

    DrawText("An error has occurred. To continue:\n\nPress F5 to reload the page. If you do this,\nyou will lose any unsaved informations.\n\n Error: 404", 
                g_winwidth/2 - 300, g_winheight/2 - 80, 20, WHITE);
        
    DrawText("Press any key to continue _", g_winwidth/2 - 120, g_winheight/2 + 100, 20, WHITE);
}
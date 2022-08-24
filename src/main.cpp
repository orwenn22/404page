#include <raylib.h>

#include "StateManager.h"
#include "State.h"

#include "States/LoadingState.h"

int g_winwidth;
int g_winheight;
bool g_isonmobile;

#if defined __EMSCRIPTEN__

#include <emscripten.h>

EM_JS(int, getWindowWidth, (), {
    return window.innerWidth;
});
EM_JS(int, getWindowHeight, (), {
    return window.innerHeight;
});

EM_JS(bool, detectMobile, (), {
    const toMatch = [
        /Android/i,
        /webOS/i,
        /iPhone/i,
        /iPad/i,
        /iPod/i,
        /BlackBerry/i,
        /Windows Phone/i
    ];
    return toMatch.some((toMatchItem) => {
        return navigator.userAgent.match(toMatchItem);
    });
})

void UpdateCanvasSize() {
    int newwidth = getWindowWidth();
    int newheight = getWindowHeight();

    if(g_winwidth != newwidth || g_winheight != newheight) {
        g_winwidth = newwidth; g_winheight = newheight;
        SetWindowSize(g_winwidth, g_winheight);
    }
}

#endif

Texture2D g_sadmac;

int main() {
    #if defined __EMSCRIPTEN__
    g_isonmobile = detectMobile();
    
    g_winwidth = getWindowWidth();
    g_winheight = getWindowHeight();

    #else   //DESKTOP
    g_winwidth = 960;
    g_winheight = 540;

    g_isonmobile = false;
    #endif

    InitWindow(g_winwidth, g_winheight, "404");
    SetTargetFPS(60);

    g_sadmac = LoadTexture("res/404mac.png");

    //StateManager* manager = new StateManager(new LoadingState());
    StateManager* manager = new StateManager(new LoadingState());


    while (!WindowShouldClose()) {
        #if defined __EMSCRIPTEN__
        UpdateCanvasSize();
        #endif

        manager->Update();

        BeginDrawing();
            ClearBackground(BLACK);
            manager->Draw();
        EndDrawing();
    }
    
    delete manager;

    UnloadTexture(g_sadmac);
    CloseWindow();
    return 0;
}
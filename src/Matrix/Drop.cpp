#include "Drop.h"
#include "DropContainer.h"

#include <raylib.h>

extern int g_winwidth;
extern int g_winheight;

namespace Matrix404 {

    Drop::Drop(DropContainer* p) {
        //chr = GetRandomValue(33, 125);

        x = GetRandomValue(0, (int)(g_winwidth/15)) * 15;
        y = -21;

        parrent = p;
    }

    void Drop::Update() {
        y += 21;

        if(y > g_winheight) {
            parrent->Delete(this);
        }
    }

    void Drop::Draw() {
        //DrawTextCodepoint(GetFontDefault(), chr, {(float)x, (float)y}, 20, GREEN);
        DrawTextCodepoint(GetFontDefault(), '4', {(float)x, (float)y }       , 20, GREEN);
        DrawTextCodepoint(GetFontDefault(), '0', {(float)x, (float)y - 21.0f}, 20, GREEN);
        DrawTextCodepoint(GetFontDefault(), '4', {(float)x, (float)y - 42.0f}, 20, GREEN);
    }

};
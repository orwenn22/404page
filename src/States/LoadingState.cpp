#include "LoadingState.h"

#include "../StateManager.h"
#include "BluescreenState.h"
#include "SadMacState.h"
#include "AmigaState.h"
#include "MatrixState.h"
#include "DVDState.h"

#include <raylib.h>

extern int g_winwidth;
extern int g_winheight;

LoadingState::LoadingState() : State() {
    m_load = 0;
}

void LoadingState::Update() {
    int randnum = GetRandomValue(0, 4);
    m_load += 0.25f;

    if(IsKeyDown(KEY_S)) m_load = 75.0f;

    if(m_load >= 75.0f) { 
        switch(randnum) {
            case 0:  m_manager->SetState(new BluescreenState()); break;
            case 1:  m_manager->SetState(new SadMacState());     break;
            case 2:  m_manager->SetState(new AmigaState());      break;
            case 3:  m_manager->SetState(new MatrixState());     break;
            case 4:  m_manager->SetState(new DVDStstate());      break;
            default: m_manager->SetState(new BluescreenState()); break;
        }
    }
}

void LoadingState::Draw() {
    DrawRectangleLines((int)(g_winwidth/2 - 200), (int)(g_winheight/2 - 60), 400, 50, WHITE);
    DrawRectangle((int)(g_winwidth/2 - 200) + 3, (int)(g_winheight/2 - 60) + 3, (int)(m_load*4), 44, WHITE);


}
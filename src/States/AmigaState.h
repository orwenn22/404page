#ifndef AMIGA_STATE_H
#define AMIGA_STATE_H

#include "../State.h"

class Breakout;

class AmigaState : public State {
    public:
    AmigaState();
    virtual ~AmigaState();

    void Update() override;
    void Draw() override;

    Breakout* m_game;
    bool m_havegame;
};

#endif
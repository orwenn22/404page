#ifndef BLUESCREEN_STATE_H
#define BLUESCREEN_STATE_H

#include "../State.h"

class BluescreenState : public State {
    public:
    BluescreenState();

    void Update() override;
    void Draw() override;
};

#endif
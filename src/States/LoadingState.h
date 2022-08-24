#ifndef LOADING_STATE_H
#define LOADING_STATE_H

#include "../State.h"

class LoadingState : public State {
    public:
    LoadingState();

    void Update() override;
    void Draw() override;

    float m_load;
};

#endif
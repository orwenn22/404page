#ifndef SAD_MAC_STATE_H
#define SAD_MAC_STATE_H

#include "../State.h"

class SadMacState : public State {
    public:
    SadMacState();

    void Draw() override;
};

#endif
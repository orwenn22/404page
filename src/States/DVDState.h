#ifndef DVD_STATE_H
#define DVD_STATE_H

#include "../State.h"

class DVDStstate : public State {
    public:
    DVDStstate();

    void Update() override;
    void Draw() override;

    int m_x;
    int m_y;

    int m_xdir;
    int m_ydir;

    int m_speed;
};

#endif
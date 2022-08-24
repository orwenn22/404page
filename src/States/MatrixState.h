#ifndef MATRIX_STATE_H
#define MATRIX_STATE_H

#include "../State.h"

namespace Matrix404 {
    class DropContainer;
};

class MatrixState : public State {
    public:
    MatrixState();
    virtual ~MatrixState();

    void Update() override;
    void Draw() override;

    Matrix404::DropContainer* m_charcontainer;
};

#endif
#include "MatrixState.h"

#include "../Matrix/DropContainer.h"
#include "../Matrix/Drop.h"

#include <raylib.h>

MatrixState::MatrixState() : State() {
    m_charcontainer = new Matrix404::DropContainer();
}

MatrixState::~MatrixState() {
    delete m_charcontainer;
}

void MatrixState::Update() {
    m_charcontainer->Add(new Matrix404::Drop(m_charcontainer));
    m_charcontainer->Add(new Matrix404::Drop(m_charcontainer));
    m_charcontainer->Update();
}

void MatrixState::Draw() {
    m_charcontainer->Draw();
}
#include "State.h"
#include "StateManager.h"

#include <raylib.h>

#include <stdio.h>

State::State() {
    m_isinmanager = false;
    m_havesubstate = false;

    m_haveparrent = false;
    m_blockparrentupdate = false;
    m_blockparrentdraw = false;

    printf("CREATED STATE\n");
}

State::~State() {
    ClearSubState();
    printf("DELETED STATE\n");
}

void State::SetSubState(State* state) {
    ClearSubState();
    m_substate = state;
    m_havesubstate = true;

    m_substate->m_parrent = this;
    m_substate->m_haveparrent = true;
}

void State::ClearSubState() {
    if(m_havesubstate) {
        delete m_substate;
        m_havesubstate = false;
    }
}

void State::Update() {}

void State::Draw() {}


void State::UpdateP() {
    if(m_havesubstate) {
        if(m_substate->m_blockparrentupdate == false) {
            Update();
        }
        m_substate->UpdateP();
    } else {
        Update();
    }
}

void State::DrawP() {
    if(m_havesubstate) {
        if(m_substate->m_blockparrentdraw == false) {
            Draw();
        }
        m_substate->DrawP();
    } else {
        Draw();
    }
}
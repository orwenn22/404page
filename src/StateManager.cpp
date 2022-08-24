#include "StateManager.h"
#include "State.h"

StateManager::StateManager(State* state) {
    m_havestate = false;
    SetState(state);
}

StateManager::StateManager() {
    m_havestate = false;
}

StateManager::~StateManager() {
    DeleteState();
}


void StateManager::SetState(State* state) {
    DeleteState();
    m_state = state;
    m_havestate = true;

    m_state->m_manager = this;
    m_state->m_isinmanager = true;
}

void StateManager::DeleteState() {
    if(m_havestate) {
        delete m_state;
        m_havestate = false;
    }
}

void StateManager::Update() {
    if(m_havestate) {
        m_state->UpdateP();
    }
}

void StateManager::Draw() {
    if(m_havestate) {
        m_state->DrawP();
    }
}
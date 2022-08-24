#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class State;

class StateManager {
    public:
    StateManager(State* state);
    StateManager();

    ~StateManager();


    void SetState(State* state);
    void DeleteState();

    void Update();
    void Draw();


    State* m_state;
    bool m_havestate;
};

#endif
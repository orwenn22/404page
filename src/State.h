#ifndef STATE_H
#define STATE_H

class StateManager;

class State {
    public:
    State();
    virtual ~State();

    void SetSubState(State* state);
    void ClearSubState();

    //user-redefinable.
    virtual void Update();
    virtual void Draw();

    //called by parrent (manager or parrent state).
    void UpdateP();
    void DrawP();

    //parrent manager.
    StateManager* m_manager;
    bool m_isinmanager;

    //parrent related properties.
    State* m_parrent;
    bool m_haveparrent;
    bool m_blockparrentupdate;
    bool m_blockparrentdraw;

    //substate.
    State* m_substate;
    bool m_havesubstate;
};

#endif
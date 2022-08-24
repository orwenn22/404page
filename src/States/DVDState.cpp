#include "DVDState.h"

#include <raylib.h>

extern int g_winwidth;
extern int g_winheight;

DVDStstate::DVDStstate() {
    m_speed = 2;

    m_x = g_winwidth / 2;
    m_y = g_winheight / 2;

    m_xdir = m_speed;
    m_ydir = m_speed;
}

void DVDStstate::Update() {
    if(m_x > g_winwidth-36) {
        m_xdir = -m_speed;
        m_x = g_winwidth-36;
    }
    if(m_y > g_winheight-20) {
        m_ydir = -m_speed;
        m_y = g_winheight-20;
    }
    if(m_x < 0) m_xdir = m_speed;
    if(m_y < 0) m_ydir = m_speed;

    m_x += m_xdir;
    m_y += m_ydir;
}

void DVDStstate::Draw() {
    DrawText("404", m_x, m_y, 20, WHITE);
}
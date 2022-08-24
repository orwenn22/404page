#include "DropContainer.h"
#include "Drop.h"

namespace Matrix404 {

    DropContainer::DropContainer() {
        m_size = 0;
    }

    DropContainer::~DropContainer() {
        for(int i = 0; i < m_size; i++) {
            delete m_chars[i];
        }
    }

    void DropContainer::Update() {
        for(int i = 0; i < m_size; i++) {
            m_chars[i]->Update();
        }
    }

    void DropContainer::Draw() {
        for(int i = 0; i < m_size; i++) {
            m_chars[i]->Draw();
        }
    }

    void DropContainer::Add(Drop* matrixchar) {
        m_chars.push_back(matrixchar);
        m_size++;
    }

    void DropContainer::Delete(Drop* matrixchar) {
        int index = -1;
        for(int i = 0; i < m_size; i++) {
            if(m_chars[i] == matrixchar) {
                index = i;
                break;
            }
        }
        if(index != -1) {
            delete m_chars[index];
            m_chars.erase(m_chars.begin()+index);
            m_size--;
        }
    }

};
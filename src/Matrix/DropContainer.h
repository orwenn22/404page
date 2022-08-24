#ifndef CHAR_CONTAINER_H
#define CHAR_CONTAINER_H

#include <vector>

namespace Matrix404 {
    class Drop;

    class DropContainer {
        public:
        DropContainer();
        ~DropContainer();
        void Update();
        void Draw();
        void Add(Drop* matrixchar);
        void Delete(Drop* matrixchar);



        std::vector<Drop*> m_chars;
        int m_size;
    };
}

#endif
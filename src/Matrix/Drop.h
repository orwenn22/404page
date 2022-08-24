#ifndef MATRIX_CHAR_H
#define MATRIX_CHAR_H

namespace Matrix404 {
    class DropContainer;

    class Drop {
        public:
        Drop(DropContainer* p);
        void Update();
        void Draw();

        int x;
        int y;
        //char chr;
        DropContainer* parrent;
    };

};

#endif
#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "object3d.h"
#include <QImage>
class chess_board:public _object3D
{
public:
    chess_board();
    void draw_unlit(QImage Image);
    void draw_flat(QImage Image);
    void draw_smooth(QImage Image);
};

#endif // CHESS_BOARD_H

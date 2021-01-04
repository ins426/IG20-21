#ifndef MATRIX_PLYS_H
#define MATRIX_PLYS_H

#include "_ply.h"
#include "colors.h"

class matrix_plys:public _ply
{
public:
    matrix_plys(_ply Ply);
    vector<vector<_ply>> Plys;
    int selected_ply = -1;

    void draw_fill();
    void draw_selection();
    void selectedPly(int id);
};

#endif // MATRIX_PLYS_H

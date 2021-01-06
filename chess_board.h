#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "object3d.h"
#include <QImage>
/**
  * @author Inés Nieto Sánchez
**/
class chess_board:public _object3D
{
public:
/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _chess_board
*/
    chess_board();

/***********************************************************************/
/**
* @brief Funciones para los distintos modos de dibujado
*/
    void draw_unlit(QImage Image);
    void draw_flat(QImage Image);
    void draw_smooth(QImage Image);
};

#endif // CHESS_BOARD_H

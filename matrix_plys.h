#ifndef MATRIX_PLYS_H
#define MATRIX_PLYS_H

#include "_ply.h"
#include "colors.h"
/**
  * @author Inés Nieto Sánchez
**/
class matrix_plys:public _ply
{
public:
    vector<vector<_ply>> Plys;
    int selected_ply = -1;

/***********************************************************************/
/**
* @brief Constructor con parámetros. Crea un objeto _matrix_plys
* @param Ply, ply del cual se va a crear una matriz en la escena
*/
    matrix_plys(_ply Ply);

/***********************************************************************/
/**
* @brief Función para el dibujado en fill de los plys
*/
    void draw_fill();

/***********************************************************************/
/**
* @brief Dibujado de los distintos plys para realizar la selección por color
*/
    void draw_selection();


/***********************************************************************/
/**
* @brief Cambia el objecto ply seleccionado
* @param id, nuevo ply seleccionado
*/
    void selectedPly(int id);
};

#endif // MATRIX_PLYS_H

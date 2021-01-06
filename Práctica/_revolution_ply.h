#ifndef _REVOLUTION_PLY_H
#define _REVOLUTION_PLY_H

#include "revolution_object.h"
#include "_ply.h"
/**
  * @author Inés Nieto Sánchez
**/
class _revolution_ply: public revolution_object, _ply
{
public:

/***********************************************************************/
/**
* @brief Constructor. Crea un objeto _revolution_ply
* @param File_name, nombre del fichero del que se leerá el ply
*/
    _revolution_ply(string File_name = "../ply_models/revolution_ply.ply");

/***********************************************************************/
/**
* @brief Revoluciona el perfil leído del fichero File_name
* @param File_name, nombre del fichero del que se leerá el ply
* @param N, número de caras a generar
*/
    void rota_ply(const string &File_name, int N=10);
};

#endif // _REVOLUTION_PLY_H

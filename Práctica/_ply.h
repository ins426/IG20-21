#ifndef _PLY_H
#define _PLY_H

#include "object3d.h"
#include "file_ply_stl.h"
/**
  * @author Inés Nieto Sánchez
**/
class _ply: virtual public _object3D
{
public:
/***********************************************************************/
/**
* @brief Constructor. Crea un objeto _ply
* @param File_name, nombre del fichero del que se leerá el ply
*/
    _ply(string File_name= "../ply_models/beethoven.ply");

/***********************************************************************/
/**
* @brief Lee un fichero ply
* @param File_name, nombre del fichero del que se leerá el ply
* @returns devuelve true si se ha leído correctamente, false en caso contrario
*/
    bool readPly(const string &File_name);
};

#endif // _PLY_H

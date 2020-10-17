#include "_revolution_ply.h"

_revolution_ply::_revolution_ply(string File_name)
{
    rota_ply(File_name);
}

void _revolution_ply::rota_ply(const string &File_name){
 readPly(File_name);
 crearRevolutionObject(10);
}

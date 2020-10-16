#include "_revolution_ply.h"

_revolution_ply::_revolution_ply()
{
    rota_ply("/home/ines/Escritorio/Universidad/3o/IG/Prácticas/practicas/ply_models/mio.ply");
}

void _revolution_ply::rota_ply(const string &File_name){
 readPly(File_name);
 crearRevolutionObject(10);
}

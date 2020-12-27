#ifndef _REVOLUTION_PLY_H
#define _REVOLUTION_PLY_H

#include "revolution_object.h"
#include "_ply.h"

class _revolution_ply: public revolution_object, _ply
{
public:
    _revolution_ply(string File_name = "/home/ines/Documentos/GitHub/IG20-21/ply_models/revolution_ply.ply");
    void rota_ply(const string &File_name, int N=10);
};

#endif // _REVOLUTION_PLY_H

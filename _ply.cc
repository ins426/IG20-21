#include "_ply.h"

_ply::_ply()
{
}

bool _ply::readPly(const string &File_name){
     _file_ply file_ply;

     if(file_ply.open(File_name)){
       file_ply.read(Vertices,Triangles);
       file_ply.close();

       return true;
     }
     else{
         return false;
     }
}

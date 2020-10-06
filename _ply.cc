#include "_ply.h"

_ply::_ply()
{

}

bool _ply::readPly(){
     _file_ply file_ply;

     if(file_ply.open("/home/ines/Escritorio/Universidad/3o/IG/Prácticas/practicas/ply_models/beethoven.ply")){
       file_ply.read(Vertices,Triangles);
       file_ply.close();

       return true;
     }
     else{
         return false;
     }
}

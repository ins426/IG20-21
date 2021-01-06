#include "_revolution_ply.h"

/*****************************************************************************************/
_revolution_ply::_revolution_ply(string File_name)
{
    rota_ply(File_name);
}
/*****************************************************************************************/
void _revolution_ply::rota_ply(const string &File_name, int N){
 readPly(File_name);
 vector<_vertex3f> generatrix_curve;
 generatrix_curve.resize(Vertices.size());

 for(int i = 0; i < Vertices.size(); i++){
     generatrix_curve[i] = Vertices[i];
 }

 Vertices.clear();
 crearRevolutionObject(N, generatrix_curve);

}
/*****************************************************************************************/

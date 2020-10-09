#include "revolution_object.h"
#include <cmath>

revolution_object::revolution_object()
{

}

void revolution_object::createRevolutionObject(const float R, const int N, vector<_vertex3f> profile_points){
    //Primero crear vértices
    //Unir vértices en orden para crear triángulos y almacenarlos


}

void revolution_object::createPoints(const int N, int nrotar){
    const float INCREMENTO_ANGULO = DOS_PI/N;
    float angulo = INCREMENTO_ANGULO;
    int mod = Vertices.size();
    int indice = mod;
    Vertices.resize(N*nrotar);

    for(int i = 0;i < N-1;i++ ){
        for(int j = 0; j < nrotar; j++){
            Vertices[indice] = _vertex3f(Vertices[indice%mod].x*cos(angulo),Vertices[indice%mod].y,-Vertices[indice%mod].x*sin(angulo));
            indice++;
        }
        angulo += INCREMENTO_ANGULO;
    }

}

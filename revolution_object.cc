#include "revolution_object.h"
#include <cmath>

revolution_object::revolution_object()
{

}

void revolution_object::createRevolutionObject(const float R, const int N, vector<_vertex3f> profile_points){
    //Primero crear vértices
    //Unir vértices en orden para crear triángulos y almacenarlos


}

//N: número de perfiles
//R: radio
//profile_points: puntos a rotar
//Vértices del primer perfil ya dados
void revolution_object::createPoints(const float R,const int N, vector<_vertex3f> profile_points){
    const float incremento_angulo = DOS_PI/N;
    float angulo = incremento_angulo;

    Vertices.resize(N*profile_points.size());

    for(int i = 0; i < N-profile_points.size(); i++){
        for(int j = 0; j < profile_points.size(); j++){
            Vertices[i] = _vertex3f(R*cos(angulo),profile_points[j].y,-R*sin(angulo)); //El índice de los vértices es el número de punto
        }
        angulo += incremento_angulo;
    }

    //Almaceno al final los extremos
    int indice = N-profile_points.size();
    for(int i = 0; i < profile_points.size(); i++){
           Vertices[indice] = profile_points[i];
     }

}

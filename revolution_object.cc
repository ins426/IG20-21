#include "revolution_object.h"
#include <cmath>

revolution_object::revolution_object()
{

}

void revolution_object::crearRevolutionObject(const int N){
    bool tapa_superior = false;
    bool tapa_inferior = false;
    _vertex3f vsuperior;
    _vertex3f vinferior;
    int num_rotar = Vertices.size();

    if(Vertices[Vertices.size()-1].x == 0.0){
        tapa_inferior = true;
        vinferior = Vertices[Vertices.size()-1];
        Vertices.erase(Vertices.begin()+Vertices.size()-1);
    }

    if(Vertices[Vertices.size()-1].x == 0.0 && Vertices[Vertices.size()-2].y != 0){
        tapa_superior = true;
        vsuperior = Vertices[Vertices.size()-1];
        Vertices.erase(Vertices.begin()+Vertices.size()-1);
    }

    if(tapa_superior && tapa_inferior){
       num_rotar -= 2;
    }
    else{
        if((tapa_inferior && !tapa_superior) || (tapa_superior && !tapa_inferior))
            num_rotar -= 1;
    }

    Vertices.resize(Vertices.size()*N);
    rotarPuntos(N,num_rotar);

    Triangles.resize(num_rotar*N);
    crearCara(N,num_rotar);

    if(tapa_superior){
        Vertices.resize(Vertices.size()+1);
        Vertices[Vertices.size()-1] = vsuperior;
        Triangles.resize(N+Triangles.size());
        crearTapaSuperior(N,num_rotar);
    }

    if(tapa_inferior){
        Vertices.resize(Vertices.size()+1);
        Vertices[Vertices.size()-1] = vinferior;
        Triangles.resize(N+Triangles.size());
        crearTapaInferior(N,num_rotar);
    }
}

void revolution_object::rotarPuntos(const int N, int num_rotar){
    const float INCREMENTO_ANGULO = DOS_PI/N;
    float angulo = INCREMENTO_ANGULO;
    int mod = num_rotar;
    int indice = mod;

    for(int i = 0;i < N-1;i++ ){
        for(int j = 0; j < num_rotar; j++){
            Vertices[indice] = _vertex3f(Vertices[indice%mod].x*cos(angulo),Vertices[indice%mod].y,-Vertices[indice%mod].x*sin(angulo));
            indice++;
        }
        angulo += INCREMENTO_ANGULO;
    }
}

void revolution_object::crearCara(const int N, int num_rotar){
    int incremento = num_rotar;
    int num_triangulos = N*num_rotar;

    for(int i = 0; i < num_triangulos; i+=2){
       Triangles[i] = _vertex3ui(i%num_triangulos,(incremento)%num_triangulos,(i+1)%num_triangulos);
       Triangles[i+1] = _vertex3ui((i+1)%num_triangulos,(incremento+1)%num_triangulos,i%num_triangulos);
       incremento += num_rotar;
    }
}

void revolution_object::crearTapaSuperior(int N,int num_rotar){
    int indice = Triangles.size()-N;
    int num_triangulos = N*num_rotar;

    for(int i = 1; i <= num_triangulos; i+=2){
        Triangles[indice] = _vertex3ui(i,(i+2)%num_triangulos, Vertices.size()-1);
        indice++;
    }
}

void revolution_object::crearTapaInferior(int N,int num_rotar){
    int indice = Triangles.size()-N;
    int num_triangulos = N*num_rotar;

    for(int i = 0; i < num_triangulos; i+=2){
        Triangles[indice] = _vertex3ui(i,(i+2)%num_triangulos, Vertices.size()-1);
        indice++;
    }
}






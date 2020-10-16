#include "revolution_object.h"
#include <cmath>

revolution_object::revolution_object()
{

}

//sentido 0: mi sentido
//sentido 1: al revés
void revolution_object::crearRevolutionObject(const int N){
    bool tapa_superior = false;
    bool tapa_inferior = false;
    _vertex3f vsuperior;
    _vertex3f vinferior;
    int num_rotar = Vertices.size();
    int sentido = 0;

    if(Vertices[0].x == 0)
        sentido = 1;

    if(sentido == 1){
        cambiarSentido();
    }

    if(Vertices[Vertices.size()-1].x == 0.0){
        tapa_inferior = true;
        vinferior = Vertices[Vertices.size()-1];
        Vertices.erase(Vertices.begin()+Vertices.size()-1);
    }

    if(Vertices[Vertices.size()-1].x == 0.0){
        tapa_superior = true;
        vsuperior = Vertices[Vertices.size()-1];
        Vertices.erase(Vertices.begin()+Vertices.size()-1);
    }

    num_rotar = Vertices.size();

    Vertices.resize(Vertices.size()*N);
    rotarPuntos(N,num_rotar);

    if(num_rotar > 1){
        Triangles.resize(num_rotar*N);
        crearCara(N,num_rotar);
    }

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
       Triangles[i+1] = _vertex3ui((incremento)%num_triangulos,(incremento+1)%num_triangulos,(i+1)%num_triangulos);
       incremento += num_rotar;
    }
}

//Triángulos impares: i = 1 se empieza
void revolution_object::crearTapaSuperior(int N,int num_rotar){
    int indice = Triangles.size()-N;
    int num_triangulos = N*num_rotar;

    for(int i = num_rotar-1; i < num_triangulos+(num_rotar-1); i+=num_rotar){
        Triangles[indice] = _vertex3ui(i,(i+num_rotar)%num_triangulos, Vertices.size()-1);
        indice++;
    }
}

//Triángulos pares: i = 0 se empieza
void revolution_object::crearTapaInferior(int N,int num_rotar){
    int indice = Triangles.size()-N;
    int num_triangulos = N*num_rotar;

    for(int i = 0; i < num_triangulos; i+=num_rotar){
        Triangles[indice] = _vertex3ui(Vertices.size()-1,(i+num_rotar)%num_triangulos,i);
        indice++;
    }
}

void revolution_object::cambiarSentido(){
    int num_intercambios = Vertices.size()/2;

    for(int i = 0; i < num_intercambios;i++){
        _vertex3f aux = Vertices[i];
        Vertices[i] = Vertices[Vertices.size()-1-i];
        Vertices[Vertices.size()-1-i] = aux;
    }
}





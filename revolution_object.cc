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
        Triangles.resize((num_rotar-1)*N*2);
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
            Vertices[indice] = _vertex3f(Vertices[j%mod].x*cos(angulo),Vertices[j%mod].y,-Vertices[j%mod].x*sin(angulo));
            indice++;
        }
        angulo += INCREMENTO_ANGULO;
    }
}

void revolution_object::crearCara(const int N, int num_rotar){
    int indice = 0;

    for(int k=1; k <= N; k++){
        for(int j = 1; j < num_rotar;j++){
            int i = k*num_rotar+j;
            Triangles[indice] = _vertex3ui((i-num_rotar)%Vertices.size(),i%Vertices.size(),(i-num_rotar)%Vertices.size());
            Triangles[indice+1] = _vertex3ui(i%Vertices.size(),(i-1)%Vertices.size(),(i-num_rotar-1)%Vertices.size());
            indice+=2;
        }
    }
}

//Triángulos pares: i = 0 se empieza
void revolution_object::crearTapaSuperior(int N,int num_rotar){
    int indice = Triangles.size()-N;

    for(int i = 0; indice < Triangles.size();indice++, i+=num_rotar){
        Triangles[indice] = _vertex3ui(i%Vertices.size(),(i+num_rotar)%Triangles.size(), Vertices.size()-1);
    }
}

//Triángulos pares: i = 1 se empieza
//Triangles.size-1 para que no me haga un triángulo del vértice de la tapa superiror a la inferior
void revolution_object::crearTapaInferior(int N,int num_rotar){
    int indice = Triangles.size()-N;

    for(int i = num_rotar-1; indice < Triangles.size()-1; indice++,i+=num_rotar){
        Triangles[indice] = _vertex3ui(i,(i+num_rotar)%Triangles.size(),Vertices.size()-1);
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





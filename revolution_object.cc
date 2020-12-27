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

    num_rotar = Vertices.size(); //puntos sin contar tapas

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
    int indice = num_rotar;

    for(int i = 0;i < N-1;i++ ){
        for(int j = 0; j < num_rotar; j++){
            Vertices[indice] = _vertex3f(Vertices[j].x*cos(angulo),Vertices[j].y,-Vertices[j].x*sin(angulo));
            indice++;
        }
        angulo += INCREMENTO_ANGULO;
    }
}

void revolution_object::crearCara(const int N, int num_rotar){
    int indice = 0;
    int k;

    for(int i = 0; i < num_rotar-1; i++ ){
        k = i+num_rotar;
        for(int j = 0; j < N; j++){
            Triangles[indice] = _vertex3ui((k-num_rotar)%Vertices.size(),k%Vertices.size(),(k-num_rotar+1)%Vertices.size());
            Triangles[indice+1] = _vertex3ui(k%Vertices.size(),(k+1)%Vertices.size(),(k-num_rotar+1)%Vertices.size());
            k += num_rotar;
            indice+=2;
        }
    }
}

void revolution_object::crearTapaSuperior(int N,int num_rotar){
    int indice = Triangles.size()-N;

    for(int i = num_rotar-1; indice < Triangles.size(); indice++,i+=num_rotar){
        Triangles[indice] = _vertex3ui(i,(i+num_rotar)%(Vertices.size()-1),Vertices.size()-1);
    }
}

void revolution_object::crearTapaInferior(int N,int num_rotar){
    int indice = Triangles.size()-N;

    for(int i = 0; indice < Triangles.size();indice++, i+=num_rotar){
        Triangles[indice] = _vertex3ui((i+num_rotar)%(Vertices.size()-2),i%Vertices.size(), Vertices.size()-1);
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

/**************************************************************************************************/
/*************************************************************************************************/
void revolution_object::crearRevolutionObjectNoOptimizado(const int N){
    bool tapa_superior = false;
    bool tapa_inferior = false;
    vector<_vertex3f> vsuperior;
    vector<_vertex3f> vinferior;
    int num_rotar_total;
    int sentido = 0;

    if(Vertices[0].x == 0)
        sentido = 1;

    if(sentido == 1){
        cambiarSentido();
    }

     if(Vertices[Vertices.size()-1].x == 0.0)
        tapa_inferior = true;

     if(Vertices[Vertices.size()-2].x == 0.0)
        tapa_superior = true;

    num_rotar_total = Vertices.size();

    Vertices.resize(Vertices.size()*(N+1));
    rotarPuntosRepetidos(N,num_rotar_total);

    int puntos_cara = num_rotar_total;

    if(tapa_inferior){
        vinferior.resize(N+1);
        for(int i = 0; i < N+1; i++){
            vinferior[i] = *(Vertices.begin()+num_rotar_total*(i+1)-(i+1));
            Vertices.erase(Vertices.begin()+num_rotar_total*(i+1)-(i+1));
         }
        puntos_cara--;
    }

    if(tapa_superior){
        vsuperior.resize(N+1);
        for(int i = 0; i < N+1; i++){
           vsuperior[i] = *(Vertices.begin()+num_rotar_total*(i+1)-(2*(i+1)));
           Vertices.erase(Vertices.begin()+num_rotar_total*(i+1)-(2*(i+1)));
        }
        puntos_cara--;
    }

    if(puntos_cara > 1){
        Triangles.resize((num_rotar_total-3)*N*2); //punto sin tapas-1
        crearCara(N,puntos_cara);
    }

    if(tapa_superior){
        Triangles.resize(Triangles.size()+N);
        Vertices.insert( Vertices.end(), vsuperior.begin(), vsuperior.end() );
        crearTapaSuperiorRepetida(N,num_rotar_total);
   }

    if(tapa_inferior){
        Triangles.resize(Triangles.size()+N);
        Vertices.insert( Vertices.end(), vinferior.begin(), vinferior.end() );
        crearTapaInferiorRepetida(N,num_rotar_total);
     }
}

void revolution_object::rotarPuntosRepetidos(const int N, int num_rotar){
    const float INCREMENTO_ANGULO = DOS_PI/N;
    float angulo = INCREMENTO_ANGULO;
    int mod = num_rotar;
    int indice = mod;

    for(int i = 0;i < N;i++ ){
        for(int j = 0; j < num_rotar; j++){
            Vertices[indice] = _vertex3f(Vertices[j%mod].x*cos(angulo),Vertices[j%mod].y,-Vertices[j%mod].x*sin(angulo));
            indice++;
        }
        angulo += INCREMENTO_ANGULO;
    }
}

void revolution_object::crearTapaSuperiorRepetida(const int N, int num_rotar){
    int indice = Triangles.size()-N;
    int vsuperior = Vertices.size()-N-1;

    for(int i = num_rotar-3; indice < Triangles.size(); indice++,i+=num_rotar-2){
        Triangles[indice] = _vertex3ui(i,(i+num_rotar-2),vsuperior);
        vsuperior++;
    }
}

void revolution_object::crearTapaInferiorRepetida(const int N, int num_rotar){
    int indice = Triangles.size()-N;
    int vinferior = Vertices.size()-N-1;

    for(int i = 0; indice < Triangles.size();indice++, i+=num_rotar-2){
        Triangles[indice] = _vertex3ui(i+num_rotar-2,i, vinferior);
        vinferior++;
    }
}

void revolution_object::crearCaraRepetida(const int N, int num_rotar){
    int indice = 0;
    int k;

    for(int i = 0; i < num_rotar-1; i++ ){
        k = i+num_rotar;
        for(int j = 0; j < N; j++){
            Triangles[indice] = _vertex3ui((k-num_rotar)%Vertices.size(),k%Vertices.size(),(k-num_rotar+1)%Vertices.size());
            Triangles[indice+1] = _vertex3ui(k%Vertices.size(),(k+1)%Vertices.size(),(k-num_rotar+1)%Vertices.size());
            k += num_rotar;
            indice+=2;
        }
    }
}

vector<_vertex2f> revolution_object::calculateTextureCoordinate(const int N, int profile_points){
    vector<_vertex2f> Texture;
    vector<float> distances;

    distances.resize(Vertices.size());
    calculateVerticesDistance(distances,N, profile_points);

    Texture.resize(Vertices.size());

    calculateFaceTextureCoordinate(N,profile_points,Texture,distances);
        calculateTapaTextureCoordinate((profile_points-2)*(N+1),N, profile_points ,Texture,distances);
     calculateTapaTextureCoordinate((profile_points-2)*(N+1)+N+1,N,profile_points ,Texture,distances);

    return Texture;
}

void revolution_object::calculateFaceTextureCoordinate(const int N, int profile_points, vector<_vertex2f> &Texture, vector<float> distances){
    int indice = 0;
    float s;
    float t;
    float M = distances[(profile_points-2)*(N+1)];

    for(float i = 0; i <= N; i++){
       for(int j = 0; j < profile_points-2;j++){
                s = i/(float)(N-1.0);
                t = distances[indice]/M;
                Texture[indice]._0 = s;
                Texture[indice]._1 = t;
                indice++;
           }
       }
}

void revolution_object::calculateTapaTextureCoordinate(int start, const int N, int profile_points, vector<_vertex2f> &Texture, vector<float> distances){
    float s;
    float t;
    float M = distances[(profile_points-2)*(N+1)];

    for(float i = 0; i <= N;i++){
        s = i/(float)(N-1.0);
        t = distances[start]/M;
        Texture[start]._0 = s;
        Texture[start]._1 = t;
        start++;
    }
}

float revolution_object::calculateDistance(_vertex3f v1, _vertex3f v2){
    _vertex3f v;
    float module;

    v._0 = v2._0 - v1._0;
    v._1 = v2._1 - v1._1;
    v._2 = v2._2 - v1._2;
    calculateVectorModule(v,module);

    return module;
}

void revolution_object::calculateVerticesDistance(vector<float>&distances, int N, int profile_points){
    int puntos_sin_tapa = profile_points-2;

    int indice = 0;
    int p;
    for(int i = 0; i <= N;i++){
        p = (profile_points-2)*(N+1)+N+i+1;
        distances[p] = 0;
        distances[indice] = calculateDistance(Vertices[p],Vertices[indice]);
        indice++;
        for(int j = 1; j < puntos_sin_tapa;j++){
            distances[indice]= distances[indice-1] + calculateDistance(Vertices[indice-1],Vertices[indice]);
            indice++;
        }
        p = (profile_points-2)*(N+1)+i;

        distances[p] = distances[indice-1] + calculateDistance(Vertices[indice-1],Vertices[p]);
    }
}



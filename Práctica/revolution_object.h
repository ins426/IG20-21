#ifndef REVOLUTION_OBJECT_H
#define REVOLUTION_OBJECT_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "object3d.h"
/**
  * @author Inés Nieto Sánchez
**/
class revolution_object: virtual public _object3D
{
public:
/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto revolution_object
*/
    revolution_object();

/***********************************************************************/
/**
* @brief Crea el objecto por revolución
* @param N, número de caras del objecto por revolución
* @param generatrix_curve, curva generatriz para generar el objeto por revolución
*/
    void crearRevolutionObject(const int N, vector<_vertex3f> &generatrix_curve );

/***********************************************************************/
/**
* @brief Revoluciona los vértices del perfil
* @param N, número de caras a generar
* @param num_rotar, número de puntos del perfil a revolucionar
* @param generatrix_curve, curva generatriz para la revolución
*/
    void rotarPuntos(const int N, int num_rotar, vector<_vertex3f> generatrix_curve);

/***********************************************************************/
/**
* @brief Une los vértices del objeto para crear las caras
* @param N, número de caras
* @param num_rotar, número de puntos del perfil
*/
    void crearCara(const int N, int num_rotar);

/***********************************************************************/
/**
* @brief Une los vértices del objeto para crear la tapa superior
* @param N, número de caras
* @param num_rotar, número de puntos del perfil
*/
    void crearTapaSuperior(const int N, int num_rotar);

/***********************************************************************/
/**
* @brief Une los vértices del objeto para crear la tapa inferior
* @param N, número de caras
* @param num_rotar, número de puntos del perfil
*/
    void crearTapaInferior(int N,int num_rotar);

/***********************************************************************/
/**
* @brief Invierte el orden en el que se da la curva generatriz
*/
    void cambiarSentido(vector<_vertex3f> &generatrix_curve);

/***********************************************************************/

/***************FUNCIONES PARA LA REVOLUCIÓN P4****************************/
/**
* @brief Crea el objecto por revolución de forma no optimizada
* @param N, número de caras del objecto por revolución
* @param generatrix_curve, curva generatriz para generar el objeto por revolución
*/
    void crearRevolutionObjectNoOptimizado(const int N, vector<_vertex3f> &generatrix_curve);

/***********************************************************************/
/**
* @brief Revoluciona los vértices del perfil de forma no optimizada
* @param N, número de caras a generar
* @param num_rotar, número de puntos del perfil a revolucionar
* @param generatrix_curve, curva generatriz para la revolución
*/
    void rotarPuntosRepetidos(const int N, int num_rotar,  vector<_vertex3f> &generatrix_curve);

/***********************************************************************/
/**
* @brief Une los vértices del objeto para crear la tapa superior de forma no optimizada
* @param N, número de caras
* @param num_rotar, número de puntos del perfil
*/
    void crearCaraRepetida(const int N, int num_rotar);

/***********************************************************************/
/**
* @brief Une los vértices del objeto para crear la tapa superior de forma no optimizada
* @param N, número de caras
* @param num_rotar, número de puntos del perfil
*/
    void crearTapaSuperiorRepetida(const int N, int num_rotar);

/***********************************************************************/
/**
* @brief Une los vértices del objeto para crear la tapa inferior de forma no optimizada
* @param N, número de caras
* @param num_rotar, número de puntos del perfil
*/
    void crearTapaInferiorRepetida(const int N, int num_rotar);

/***********************************************************************/
/**
* @brief Calcula las coordenadas de textura
* @param N, número de caras del objeto
* @param profile_points, número de puntos del perfil
* @returns Devuelve las coordenadas de textura del objeto
*/
    vector<_vertex2f> calculateTextureCoordinate(const int N,int profile_points);

/***********************************************************************/
/**
* @brief Calcula las coordenadas de textura de las caras
* @param N, número de caras del objeto
* @param profile_points, número de puntos del perfil
* @param Texture, vector donde se almacenarán las coordenadas de textura del objeto
* @param distances, vector de las distancias entre los vértices de un perfil
*/
    void calculateFaceTextureCoordinate(const int N, int profile_points,vector<_vertex2f> &Texture, vector<float> distances);

/***********************************************************************/
/**
* @brief Calcula las coordenadas de textura de las tapas
* @param start, índice de inicio del vector de texturas para almacenar valores
* @param profile_points, número de puntos del perfil
* @param Texture, vector donde se almacenarán las coordenadas de textura del objeto
* @param distances, vector de las distancias entre los vértices de un perfil
*/
    void calculateTapaTextureCoordinate(int start,const int N, int profile_points,vector<_vertex2f> &Texture, vector<float> distances);

/***********************************************************************/
/**
* @brief Calcula las distancias entre los vértices de un perfil
* @param distances, vector donde se almacenaran las distancias
* @param N, número de caras
* @param profile_points, número de puntos del perfil
*/
    void calculateVerticesDistance(vector<float>&distances, int N,int profile_points);

/***********************************************************************/
/**
* @brief Calcula la distancia entre dos vértices
* @param v1, primer vértice
* @param v2, segundo vértice
*/
    float calculateDistance(_vertex3f v1, _vertex3f v2);

};

const float PI = M_PI;
const float DOS_PI = 2*PI;

#endif // REVOLUTION_OBJECT_H

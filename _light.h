#ifndef _LIGHT_H
#define _LIGHT_H

#include <GL/gl.h>
#include <vector>

using namespace std;
/**
  * @author Inés Nieto Sánchez
**/
class _light
{
public:
    int angle_light1 = 0;

/***********************************************************************/
/**
* @brief Constructor sin parámetros. Crea un objeto _light
*/
    _light();

/***********************************************************************/
/**
* @brief Define los parámetros de la luz 0
*/
    void defineLight0();

/***********************************************************************/
/**
* @brief Define los parámetros de la luz 1
*/
    void defineLight1();
/***********************************************************************/
/**
* @brief Define los parámetros del material del objeto
* @param N, identificador del material
*/
    void defineMaterial(int N);

/***********************************************************************/
/**
* @brief Incrementa el ángulo de rotación de la luz 1, angle_light1
*/
    void moveLight1();

};

#endif // _LIGHT_H

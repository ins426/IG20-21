#ifndef _LIGHT_H
#define _LIGHT_H

#include <GL/gl.h>
#include <vector>

using namespace std;

class _light
{
public:
    _light();

    int angle_light1 = 0;

    void ActivateLight0();
    void ActivateLight1();
    void DesactivateLight0();
    void DesactivateLight1();
    void DesactivateLights();
    void ActivateLights();

    void defineLight0();
    void defineLight1();
    void defineMaterial(int N);

    void moveLight1();

};

#endif // _LIGHT_H

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

    void defineLight0();
    void defineLight1();
    void defineMaterial(int N);

    void moveLight1();

};

#endif // _LIGHT_H

#ifndef RUEDA_H
#define RUEDA_H

#include "_cylinder.h"
class rueda
{
public:
    rueda();

    _cylinder Cylinder;

    //void _cylinder(unsigned int N=3, float Radius=0.5, float Height=1);

    void draw_point();
    void draw_line();

    void update_alpha(){ Alpha=Alpha+Speed;}
    void increase_speed(){ Speed = Speed+1;};
    void decrease_speed(){ //Si decremento mucho la velocidad va hacia atrás
        Speed = Speed-1;};

private:
    float Alpha=0;
    float Speed=1;
};

#endif // RUEDA_H

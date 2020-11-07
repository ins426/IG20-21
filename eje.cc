#include "eje.h"

eje::eje()
{
}

void eje::draw_point(){

}

void eje::draw_line(){

    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.05,6,0.2);
    Cylinder.draw_line();
    glPopMatrix();
}

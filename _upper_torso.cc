#include "_upper_torso.h"

using namespace _colors_ne;
_upper_torso::_upper_torso()
{

}

void _upper_torso::draw_line(){
    glColor3fv(((GLfloat *) &GREEN));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,0.5,1);
    Cylinder.draw_line();
    glPopMatrix();

}

void _upper_torso::draw_point(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,0.5,1);
    Cylinder.draw_point();
    glPopMatrix();

}

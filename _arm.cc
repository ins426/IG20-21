#include "_arm.h"
using namespace _colors_ne;
_arm::_arm()
{

}

void _arm::draw_line(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_line();
    glPopMatrix();

}

void _arm::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_point();
    glPopMatrix();

}

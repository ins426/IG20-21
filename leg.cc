#include "_leg.h"
using namespace _colors_ne;
_leg::_leg()
{

}

void _leg::draw_line(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_line();
    glPopMatrix();

}

void _leg::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_point();
    glPopMatrix();

}


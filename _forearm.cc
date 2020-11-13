#include "_forearm.h"
using namespace _colors_ne;
_forearm::_forearm()
{

}

void _forearm::draw_line(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_line();
    glPopMatrix();

}

void _forearm::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_point();
    glPopMatrix();

}

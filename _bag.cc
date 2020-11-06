#include "_bag.h"

_bag::_bag()
{

}

void _bag::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_line();
    glPopMatrix();

}

void _bag::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_point();
    glPopMatrix();

}

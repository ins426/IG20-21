#include "_hand.h"

_hand::_hand()
{

}

void _hand::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.05,0);
    glScalef(0.2,0.1,0.01);
    Cube.draw_line();
    glPopMatrix();

}

void _hand::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.05,0);
    glScalef(0.2,0.1,0.01);
    Cube.draw_point();
    glPopMatrix();

}

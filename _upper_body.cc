#include "_upper_body.h"

_upper_body::_upper_body()
{

}
void _upper_body::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    Torso.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.9,0);
    Head.draw_line();
    glPopMatrix();

}

void _upper_body::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    Torso.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.9,0);
    Head.draw_point();
    glPopMatrix();

}

#include "_head_glass.h"

_head_glass::_head_glass()
{

}

void _head_glass::draw_line(){
    Head.draw_line();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.4);
    Glass.draw_line();
    glPopMatrix();

}

void _head_glass::draw_point(){
    Head.draw_point();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.4);
    Glass.draw_point();
    glPopMatrix();

}

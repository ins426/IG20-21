#include "_head.h"
using namespace _colors_ne;
_head::_head()
{

}

void _head::draw_line(){
    glColor3fv(((GLfloat *) &YEllOW));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_line();
    glPopMatrix();

}

void _head::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_point();
    glPopMatrix();

}

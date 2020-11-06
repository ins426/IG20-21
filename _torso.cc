#include "_torso.h"
using namespace _colors_ne;
_torso::_torso()
{

}

void _torso::draw_line(){
    glColor3fv(((GLfloat *) &GREEN));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    glScalef(1,2,1);
    Semisphere.draw_line();
    glPopMatrix();

}

void _torso::draw_point(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    glScalef(1,2,1);
    Semisphere.draw_point();
    glPopMatrix();

}

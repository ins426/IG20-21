#include "_shoulder.h"
using namespace _colors_ne;

/*****************************************************************************************/
_shoulder::_shoulder()
{

}
/*****************************************************************************************/
void _shoulder::draw_line(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _shoulder::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _shoulder::draw_fill(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _shoulder::draw_chess(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/

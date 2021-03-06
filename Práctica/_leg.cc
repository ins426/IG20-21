#include "_leg.h"
using namespace _colors_ne;
/*****************************************************************************************/
_leg::_leg()
{

}
/*****************************************************************************************/
void _leg::draw_line(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg::draw_fill(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_flat_shading();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.5,0.2);
    Cylinder.draw_smooth_shading();
    glPopMatrix();

}

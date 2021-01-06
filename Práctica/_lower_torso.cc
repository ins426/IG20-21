#include "_lower_torso.h"
using namespace _colors_ne;

/*****************************************************************************************/
_lower_torso::_lower_torso()
{

}
/*****************************************************************************************/
void _lower_torso::draw_line(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    Semisphere.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _lower_torso::draw_point(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    Semisphere.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _lower_torso::draw_fill(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    Semisphere.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _lower_torso::draw_chess(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    Semisphere.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _lower_torso::draw_flat(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    Semisphere.draw_flat_shading();
    glPopMatrix();

}
/*****************************************************************************************/
void _lower_torso::draw_smooth(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(180,0,0,1);
    Semisphere.draw_smooth_shading();
    glPopMatrix();

}

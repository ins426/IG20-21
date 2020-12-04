#include "_torso.h"
using namespace _colors_ne;
/*****************************************************************************************/
_torso::_torso()
{

}
/*****************************************************************************************/
void _torso::draw_line(){
    glColor3fv(((GLfloat *) &GREEN));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    Upper_torso.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,0);
    Lower_torso.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _torso::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    Upper_torso.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,0);
    Lower_torso.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _torso::draw_fill(){
    glColor3fv(((GLfloat *) &GREEN));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    Upper_torso.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,0);
    Lower_torso.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _torso::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    Upper_torso.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,0);
    Lower_torso.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/

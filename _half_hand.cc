#include "_half_hand.h"
using namespace _colors_ne;

/*****************************************************************************************/
_half_hand::_half_hand()
{

}
/*****************************************************************************************/
void _half_hand::draw_line(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.2,0.1,0.01);
    Cube.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _half_hand::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.2,0.1,0.01);
    Cube.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _half_hand::draw_fill(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.2,0.1,0.01);
    Cube.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _half_hand::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.2,0.1,0.01);
    Cube.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/

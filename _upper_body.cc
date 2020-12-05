#include "_upper_body.h"

/*****************************************************************************************/
_upper_body::_upper_body()
{

}
/*****************************************************************************************/
void _upper_body::draw_line(){
    Torso.draw_line();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    Head.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _upper_body::draw_point(){
    Torso.draw_point();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    Head.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _upper_body::draw_fill(){
    Torso.draw_fill();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    Head.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _upper_body::draw_chess(){
    Torso.draw_chess();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    Head.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/

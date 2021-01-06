#include "_head_glass.h"

/*****************************************************************************************/
_head_glass::_head_glass()
{

}
/*****************************************************************************************/
void _head_glass::draw_line(){
    Head.draw_line();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.35);
    Glass.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _head_glass::draw_point(){
    Head.draw_point();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.35);
    Glass.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _head_glass::draw_fill(){
    Head.draw_fill();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.35);
    Glass.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _head_glass::draw_chess(){
    Head.draw_chess();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.35);
    Glass.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _head_glass::draw_flat(){
    Head.draw_flat();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.35);
    Glass.draw_flat();
    glPopMatrix();

}
/*****************************************************************************************/
void _head_glass::draw_smooth(){
    Head.draw_smooth();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.2,0.35);
    Glass.draw_smooth();
    glPopMatrix();

}

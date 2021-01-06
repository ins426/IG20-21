#include "_head.h"
using namespace _colors_ne;

/*****************************************************************************************/
_head::_head()
{

}
/*****************************************************************************************/
void _head::draw_line(){
    glColor3fv(((GLfloat *) &YEllOW));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _head::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _head::draw_fill(){
    glColor3fv(((GLfloat *) &YEllOW));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _head::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _head::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_flat_shading();
    glPopMatrix();

}
/*****************************************************************************************/
void _head::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Semisphere.draw_smooth_shading();
    glPopMatrix();

}

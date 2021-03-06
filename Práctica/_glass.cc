#include "_glass.h"
using namespace _colors_ne;

/*****************************************************************************************/
_glass::_glass()
{

}
/*****************************************************************************************/
void _glass::draw_line(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.3,0.3);
    Semisphere.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _glass::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.3,0.3);
    Semisphere.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _glass::draw_fill(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.3,0.3);
    Semisphere.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _glass::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.3,0.3);
    Semisphere.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _glass::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.3,0.3);
    Semisphere.draw_flat_shading();
    glPopMatrix();

}
/*****************************************************************************************/
void _glass::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.3,0.3);
    Semisphere.draw_smooth_shading();
    glPopMatrix();

}

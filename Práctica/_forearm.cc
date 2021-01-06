#include "_forearm.h"
using namespace _colors_ne;
/*****************************************************************************************/
_forearm::_forearm()
{

}
/*****************************************************************************************/
void _forearm::draw_line(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _forearm::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _forearm::draw_fill(){
    glColor3fv(((GLfloat *) &MAGENTA));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _forearm::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _forearm::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_flat_shading();
    glPopMatrix();
}
/*****************************************************************************************/
void _forearm::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.25,0.17,0.2);
    Cylinder.draw_smooth_shading();
    glPopMatrix();
}

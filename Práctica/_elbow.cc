#include "_elbow.h"

using namespace _colors_ne;

/*****************************************************************************************/
_elbow::_elbow()
{

}
/*****************************************************************************************/
void _elbow::draw_line(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _elbow::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _elbow::draw_fill(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _elbow::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _elbow::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_flat_shading();
    glPopMatrix();

}
/*****************************************************************************************/
void _elbow::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_smooth_shading();
    glPopMatrix();

}

#include "_elbow.h"

using namespace _colors_ne;
_elbow::_elbow()
{

}

void _elbow::draw_line(){
    glColor3fv(((GLfloat *) &BLUE));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_line();
    glPopMatrix();

}

void _elbow::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.085,0);
    glScalef(0.17,0.17,0.17);
    Sphere.draw_point();
    glPopMatrix();

}

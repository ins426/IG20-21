#include "_body_legs.h"

_body_legs::_body_legs()
{

}

void _body_legs::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.3,0);
    Body.draw_line();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(0.25,0,0);
    Leg.draw_line();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(-0.25,0,0);
    Leg.draw_line();
    glPopMatrix();

}

void _body_legs::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.3,0);
    Body.draw_point();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(0.25,0,0);
    Leg.draw_point();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(-0.25,0,0);
    Leg.draw_point();
    glPopMatrix();

}

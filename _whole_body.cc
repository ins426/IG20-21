#include "_whole_body.h"

_whole_body::_whole_body()
{

}

void _whole_body::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_line();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(-0.5,1.25,0);
    glRotatef(180,0,0,1);
    Arm.draw_line();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,1.25,0);
    glRotatef(180,0,0,1);
    Arm.draw_line();
    glPopMatrix();

}

void _whole_body::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_point();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(-0.5,1.25,0);
    glRotatef(180,0,0,1);
    Arm.draw_point();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,1.25,0);
    glRotatef(180,0,0,1);
    Arm.draw_point();
    glPopMatrix();

}

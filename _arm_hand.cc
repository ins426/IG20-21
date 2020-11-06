#include "_arm_hand.h"

_arm_hand::_arm_hand()
{

}

void _arm_hand::draw_line(){
    Arm.draw_line();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.5,0.05);
    Hand.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,-0.05);
    Hand.draw_line();
    glPopMatrix();

}

void _arm_hand::draw_point(){
    Arm.draw_point();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.5,0.05);
    Hand.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,-0.05);
    Hand.draw_point();
    glPopMatrix();

}

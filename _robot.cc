#include "_robot.h"

_robot::_robot()
{

}

void _robot::draw_line(){
    Body.draw_line();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_line();
    glPopMatrix();

    glPushMatrix();
    Body.draw_line();
    glPopMatrix();
}

void _robot::draw_point(){
    Body.draw_point();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_point();
    glPopMatrix();
}


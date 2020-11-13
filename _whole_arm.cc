#include "_whole_arm.h"
using namespace _colors_ne;
_whole_arm::_whole_arm()
{

}

void _whole_arm::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.34,0);
    Arm.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.17,0);
    Elbow.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    Forearm.draw_line();
    glPopMatrix();

}

void _whole_arm::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.34,0);
    Arm.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.17,0);
    Elbow.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);
    Forearm.draw_point();
    glPopMatrix();


}

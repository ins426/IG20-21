#include "_leg_wheel.h"

/*****************************************************************************************/
_leg_wheel::_leg_wheel()
{

}
/*****************************************************************************************/
void _leg_wheel::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.15,0.15,0);
    Wheel.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.15,0);
    Leg.draw_line();
    glPopMatrix();
}
/*****************************************************************************************/
void _leg_wheel::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.15,0.15,0);
    Wheel.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.15,0);
    Leg.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg_wheel::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.15,0.15,0);
    Wheel.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.15,0);
    Leg.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _leg_wheel::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.15,0.15,0);
    Wheel.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.15,0);
    Leg.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/

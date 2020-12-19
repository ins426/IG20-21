#include "_robot.h"

/*****************************************************************************************/
_robot::_robot()
{

}
/*****************************************************************************************/
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
/*****************************************************************************************/
void _robot::draw_point(){
    Body.draw_point();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_point();
    glPopMatrix();
}
/*****************************************************************************************/
void _robot::draw_fill(){
    Body.draw_fill();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_fill();
    glPopMatrix();
}
/*****************************************************************************************/
void _robot::draw_chess(){
    Body.draw_chess();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_chess();
    glPopMatrix();
}
/*****************************************************************************************/
void _robot::draw_flat(){
    Body.draw_flat();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_flat();
    glPopMatrix();
}
/*****************************************************************************************/
void _robot::draw_smooth(){
    Body.draw_smooth();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_smooth();
    glPopMatrix();
}

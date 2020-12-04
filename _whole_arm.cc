#include "_whole_arm.h"
/*****************************************************************************************/
_whole_arm::_whole_arm()
{

}
/*****************************************************************************************/
void _whole_arm::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_elbow.draw_line();
    glPopMatrix();

    Shoulder.draw_line();
}
/*****************************************************************************************/
void _whole_arm::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_elbow.draw_point();
    glPopMatrix();

    Shoulder.draw_point();

}
/*****************************************************************************************/
void _whole_arm::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_elbow.draw_fill();
    glPopMatrix();

    Shoulder.draw_fill();

}
/*****************************************************************************************/
void _whole_arm::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_elbow.draw_chess();
    glPopMatrix();

    Shoulder.draw_chess();

}
/*****************************************************************************************/

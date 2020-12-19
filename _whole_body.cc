#include "_whole_body.h"

/*****************************************************************************************/
_whole_body::_whole_body()
{

}
/*****************************************************************************************/
void _whole_body::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25,0);
    glRotatef(-angleArms,1,0,0);
    Arms.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _whole_body::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25,0);
    glRotatef(-angleArms,1,0,0);
    Arms.draw_point();
    glPopMatrix();
}
/*****************************************************************************************/
void _whole_body::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25,0);
    glRotatef(-angleArms,1,0,0);
    Arms.draw_fill();
    glPopMatrix();
}
/*****************************************************************************************/
void _whole_body::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25,0);
    glRotatef(-angleArms,1,0,0);
    Arms.draw_chess();
    glPopMatrix();
}
/*****************************************************************************************/
void _whole_body::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_flat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25,0);
    glRotatef(-angleArms,1,0,0);
    Arms.draw_flat();
    glPopMatrix();
}
/*****************************************************************************************/
void _whole_body::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body_legs.draw_smooth();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.25,0);
    glRotatef(-angleArms,1,0,0);
    Arms.draw_smooth();
    glPopMatrix();
}
/*****************************************************************************************/
void _whole_body::increase_arms(){
    angleArms = angleArms+speedArms;
}
/*****************************************************************************************/
void _whole_body::decrease_arms(){
    angleArms = angleArms-speedArms;
}
/*****************************************************************************************/
void _whole_body::increaseSpeed_arm(){
    speedArms = speedArms + 1;
}
/*****************************************************************************************/
void _whole_body::decreaseSpeed_arm(){
    speedArms = speedArms - 1;
}
/*****************************************************************************************/

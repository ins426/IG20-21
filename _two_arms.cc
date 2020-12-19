#include "_two_arms.h"

/*****************************************************************************************/
_two_arms::_two_arms()
{

}
/*****************************************************************************************/
void _two_arms::draw_line(){
    //Right
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_line();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _two_arms::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    //Right
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_point();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _two_arms::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    //Right
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_fill();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _two_arms::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    //Right
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_chess();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _two_arms::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    //Right
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_flat();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_flat();
    glPopMatrix();

}
/*****************************************************************************************/
void _two_arms::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    //Right
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_smooth();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(180,0,0,1);
    Arm.draw_smooth();
    glPopMatrix();

}

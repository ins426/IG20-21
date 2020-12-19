#include "_body_legs.h"

/*****************************************************************************************/
_body_legs::_body_legs()
{

}
/*****************************************************************************************/
void _body_legs::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glRotatef(angleBody,0,1,0);
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
/*****************************************************************************************/
void _body_legs::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glRotatef(angleBody,0,1,0);
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
/*****************************************************************************************/
void _body_legs::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glRotatef(angleBody,0,1,0);
    Body.draw_fill();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(0.25,0,0);
    Leg.draw_fill();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(-0.25,0,0);
    Leg.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _body_legs::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glRotatef(angleBody,0,1,0);
    Body.draw_chess();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(0.25,0,0);
    Leg.draw_chess();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(-0.25,0,0);
    Leg.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _body_legs::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glRotatef(angleBody,0,1,0);
    Body.draw_flat();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(0.25,0,0);
    Leg.draw_flat();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(-0.25,0,0);
    Leg.draw_flat();
    glPopMatrix();

}
/*****************************************************************************************/
void _body_legs::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glRotatef(angleBody,0,1,0);
    Body.draw_smooth();
    glPopMatrix();

    //Right
    glPushMatrix();
    glTranslatef(0.25,0,0);
    Leg.draw_smooth();
    glPopMatrix();

    //Left
    glPushMatrix();
    glTranslatef(-0.25,0,0);
    Leg.draw_smooth();
    glPopMatrix();

}
/*****************************************************************************************/
void _body_legs::increase_body(){
    angleBody = angleBody + speedBody;
}
/*****************************************************************************************/
void _body_legs::decrease_body(){
    angleBody = angleBody - speedBody;
}
/*****************************************************************************************/
void _body_legs::increaseSpeed_body(){
   speedBody = speedBody + 1;
}
/*****************************************************************************************/
void _body_legs::decreaseSpeed_body(){
    speedBody = speedBody - 1;
}
/*****************************************************************************************/

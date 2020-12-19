#include "_forearm_elbow.h"

/*****************************************************************************************/
_forearm_elbow::_forearm_elbow()
{

}
/*****************************************************************************************/
void _forearm_elbow::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_hand.draw_line();
    glPopMatrix();

    Elbow.draw_line();

}
/*****************************************************************************************/
void _forearm_elbow::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_hand.draw_point();
    glPopMatrix();

    Elbow.draw_point();
}
/*****************************************************************************************/
void _forearm_elbow::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_hand.draw_fill();
    glPopMatrix();

    Elbow.draw_fill();
}
/*****************************************************************************************/
void _forearm_elbow::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_hand.draw_chess();
    glPopMatrix();

    Elbow.draw_chess();
}
/*****************************************************************************************/
void _forearm_elbow::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_hand.draw_flat();
    glPopMatrix();

    Elbow.draw_flat();
}
/*****************************************************************************************/
void _forearm_elbow::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.17,0);
    Forearm_hand.draw_smooth();
    glPopMatrix();

    Elbow.draw_smooth();
}

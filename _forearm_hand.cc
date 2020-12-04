#include "_forearm_hand.h"
using namespace _colors_ne;

/*****************************************************************************************/
_forearm_hand::_forearm_hand()
{

}
/*****************************************************************************************/
void _forearm_hand::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0,0,positionHand);
    glTranslatef(0,0.22,-0.1);
    HalfHand.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-positionHand);
    glTranslatef(0,0.22,0.1);
    HalfHand.draw_line();
    glPopMatrix();

    Forearm.draw_line();

}
/*****************************************************************************************/
void _forearm_hand::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0,0,positionHand);
    glTranslatef(0,0.22,-0.1);
    HalfHand.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-positionHand);
    glTranslatef(0,0.22,0.1);
    HalfHand.draw_point();
    glPopMatrix();

    Forearm.draw_point();

}
/*****************************************************************************************/
void _forearm_hand::draw_fill(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0,0,positionHand);
    glTranslatef(0,0.22,-0.1);
    HalfHand.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-positionHand);
    glTranslatef(0,0.22,0.1);
    HalfHand.draw_fill();
    glPopMatrix();

    Forearm.draw_fill();

}
/*****************************************************************************************/
void _forearm_hand::draw_chess(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0,0,positionHand);
    glTranslatef(0,0.22,-0.1);
    HalfHand.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-positionHand);
    glTranslatef(0,0.22,0.1);
    HalfHand.draw_chess();
    glPopMatrix();

    Forearm.draw_chess();

}
/*****************************************************************************************/
void _forearm_hand::increase_hands(){
    positionHand = positionHand + speedHand;
}
/*****************************************************************************************/
void _forearm_hand::decrease_hands(){
    positionHand = positionHand - speedHand;
}
/*****************************************************************************************/
void _forearm_hand::increaseSpeed_hands(){
   speedHand = speedHand + 0.01;
}
/*****************************************************************************************/
void _forearm_hand::decreaseSpeed_hands(){
    speedHand = speedHand - 0.01;
}
/*****************************************************************************************/

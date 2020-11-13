#include "_arm_hand.h"

_arm_hand::_arm_hand()
{

}

void _arm_hand::draw_line(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,0);
    Arm.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,positionHand);
    glTranslatef(0,0.55,-0.1);
    Hand.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-positionHand);
    glTranslatef(0,0.55,0.1);
    Hand.draw_line();
    glPopMatrix();

}

void _arm_hand::draw_point(){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0,0,0);
    Arm.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,positionHand);
    glTranslatef(0,0.55,-0.1);
    Hand.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-positionHand);
    glTranslatef(0,0.55,0.1);
    Hand.draw_point();
    glPopMatrix();

}

void _arm_hand::increase_hands(){
    positionHand = positionHand + speedHand;
}

void _arm_hand::decrease_hands(){
    positionHand = positionHand - speedHand;
}

void _arm_hand::increaseSpeed_hands(){
   speedHand = speedHand + 0.01;
}

void _arm_hand::decreaseSpeed_hands(){
    speedHand = speedHand - 0.01;
}

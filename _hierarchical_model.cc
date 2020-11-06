#include "_hierarchical_model.h"

_hierarchical_model::_hierarchical_model()
{

}

void _hierarchical_model::draw_line(){
    Body.draw_line();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_line();
    glPopMatrix();



}

void _hierarchical_model::draw_point(){
    Body.draw_point();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0.9,-0.5);
    Bag.draw_point();
    glPopMatrix();



}

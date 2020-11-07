#include "rueda.h"

rueda::rueda(){

}
void rueda::draw_point()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,0.2,1);
    Cylinder.draw_point();
    glPopMatrix();
}

void rueda::draw_line()
{

    glMatrixMode(GL_MODELVIEW);
    glRotatef(Alpha,1,0,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(1,0.2,1);
    //glRotatef(-Alpha,0,1,0);
    Cylinder.draw_line();
    glPopMatrix();
}

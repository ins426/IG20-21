#include "_bag.h"

/*****************************************************************************************/
_bag::_bag()
{

}
/*****************************************************************************************/
void _bag::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_line();
    glPopMatrix();

}
/*****************************************************************************************/
void _bag::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_point();
    glPopMatrix();

}
/*****************************************************************************************/
void _bag::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_fill();
    glPopMatrix();

}
/*****************************************************************************************/
void _bag::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_chess();
    glPopMatrix();

}
/*****************************************************************************************/
void _bag::draw_flat(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_flat_shading();
    glPopMatrix();
}
/*****************************************************************************************/
void _bag::draw_smooth(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,0.5);
    Cube.draw_smooth_shading();
    glPopMatrix();
}

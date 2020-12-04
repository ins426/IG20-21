#include "_wheel.h"
using namespace _colors_ne;
/*****************************************************************************************/
_wheel::_wheel()
{

}
/*****************************************************************************************/
void _wheel::draw_point()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.3,0.3,0.3);
    Cylinder.draw_point();
    glPopMatrix();
}
/*****************************************************************************************/
void _wheel::draw_line()
{
    glColor3fv(((GLfloat *) &BLACK));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.3,0.3,0.3);
    Cylinder.draw_line();
    glPopMatrix();
}
/*****************************************************************************************/
void _wheel::draw_fill()
{
    glColor3fv(((GLfloat *) &BLACK));
    glColor3fv(((GLfloat *) &BLACK));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.3,0.3,0.3);
    Cylinder.draw_fill();
    glPopMatrix();
}
/*****************************************************************************************/
void _wheel::draw_chess()
{
    glColor3fv(((GLfloat *) &BLACK));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.3,0.3,0.3);
    Cylinder.draw_chess();
    glPopMatrix();
}
/*****************************************************************************************/

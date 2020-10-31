#include "eje_rueda.h"

eje_rueda::eje_rueda()
{

}

void eje_rueda::draw_line(){
     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     glTranslatef(1.5,0.5,0);
     Eje.draw_line();
     glPopMatrix();

     //Rueda derecha
     glPushMatrix();
     glTranslated(1.1,0.5,0);
     Rueda.draw_line();
     glPopMatrix();

     //Rueda izda
     glPushMatrix();
     glTranslated(-1.1,0.5,0);
     Rueda.draw_line();
     glPopMatrix();
}

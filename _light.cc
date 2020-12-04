#include "_light.h"

_light::_light()
{

}


void _light::ActivateLight0(){
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void _light::ActivateLight1(){
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

}

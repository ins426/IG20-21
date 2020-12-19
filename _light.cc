#include "_light.h"

_light::_light()
{

}


void _light::ActivateLight0(){
    glEnable(GL_LIGHT0);
}

void _light::ActivateLight1(){
    glEnable(GL_LIGHT1);
}

void _light::DesactivateLight0(){
    glDisable(GL_LIGHT0);
}

void _light::DesactivateLight1(){
    glDisable(GL_LIGHT1);

}

void _light::DesactivateLights(){
    glDisable(GL_LIGHTING);
}

void _light::ActivateLights(){
    glEnable(GL_LIGHTING);
}

void _light::defineLight0(){
    GLfloat light0_position[] = {0, 0, 1.0, 0.0 };
    GLfloat specular0[] = {0.5,0.5,0.5,1.0};
    GLfloat diffuse0[] = {0.8,0.8,0.8,1.0};
    GLfloat ambient0[] = {0.25,0.25,0.25,0};

    glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse0);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient0);
}

void _light::defineLight1(){
     GLfloat light1_position[] = {0, 0.5, 1, 1.0};

     GLfloat specular1[] = {0.3,0.3,0.3,1.0};
     GLfloat diffuse1[] = {1,0,0.9,1.0};
     GLfloat ambient1[] = {0.2,0.2,0.2,0};

     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     glRotatef(angle_light1,0,1,0);
     glLightfv(GL_LIGHT1,GL_POSITION,light1_position);
     glPopMatrix();
     glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse1);
     glLightfv(GL_LIGHT1,GL_SPECULAR,specular1);
     glLightfv(GL_LIGHT1,GL_AMBIENT,ambient1);
}

void _light::moveLight1(){
    angle_light1+=1;
}

void _light::defineMaterial(int N){
    GLfloat material_specular[4];
    GLfloat material_diffuse[4];
    GLfloat material_ambient[4];
    switch (N) {
        //Jade
        case 0:
          material_ambient[0] = 0135;
          material_ambient[1] = 0.225;
          material_ambient[2] = 0.1575;
          material_ambient[3] = 1.0f;

          material_diffuse[0] = 0.54;
          material_diffuse[1] = 0.89;
          material_diffuse[2] = 0.63;
          material_diffuse[3] = 1.0f;

          material_specular[0] = 0.316228;
          material_specular[1] = 0.316228;
          material_specular[2] = 0.316228;
          material_specular[3] = 1.0f;
        break;
        //Emerald
        case 1:
            material_ambient[0] = 0.0215;
            material_ambient[1] = 0.1745;
            material_ambient[2] = 0.0215;
            material_ambient[3] = 1;

            material_diffuse[0] = 0.07568;
            material_diffuse[1] = 0.61424;
            material_diffuse[2] = 0.07568;
            material_diffuse[3] = 1;

            material_specular[0] = 0.633;
            material_specular[1] = 0.727811;
            material_specular[2] = 0.633;
            material_ambient[3] = 1;
        break;
        //Cyan plastic
        case 2:
            material_specular[0] = 0.296648;
            material_specular[1] = 0.296648;
            material_specular[2] = 0.296648 	;
            material_specular[3] = 1;

            material_diffuse[0] = 1;
            material_diffuse[1] = 0.829;
            material_diffuse[2] = 0.829;
            material_diffuse[3] = 1;

            material_ambient[0] = 0.25;
            material_ambient[1] = 0.20725;
            material_ambient[2] = 0.20725;
            material_ambient[3] = 1;
        break;
    }
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,material_specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,material_ambient);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,120);
}

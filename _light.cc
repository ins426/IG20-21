#include "_light.h"

_light::_light()
{

}

void _light::defineLight0(){
    GLfloat light0_position[] = {0, 0, 1.0, 0.0 };

    glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
}

void _light::defineLight1(){
     GLfloat light1_position[] = {0, 1, 1, 1.0};

     GLfloat specular1[] = {1.0f,0.0f,0.6f,1.0};
     GLfloat diffuse1[] = {1.0f,0.0f,0.6f,1.0};
     GLfloat ambient1[] = {0.0f,0.0f,0.0f,1.0};

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
        //White
        case 0:
          material_ambient[0] = 0.0f;
          material_ambient[1] = 0.0f;
          material_ambient[2] = 0.0f;
          material_ambient[3] = 1;

          material_diffuse[0] = 1.0f;
          material_diffuse[1] = 1.0f;
          material_diffuse[2] = 1.0f;
          material_diffuse[3] = 1;

          material_specular[0] = 1.0f;
          material_specular[1] = 1.0f;
          material_specular[2] = 1.0f;
          material_specular[3] = 1;
        break;
        //Blue
        case 1:
            material_ambient[0] = 0.0f;
            material_ambient[1] = 0.0f;
            material_ambient[2] = 0.0f;
            material_ambient[3] = 1.0f;

            material_diffuse[0] = 0.0f;
            material_diffuse[1] = 0.0f;
            material_diffuse[2] = 1.0f;
            material_diffuse[3] = 1.0f;

            material_specular[0] = 0.7f;
            material_specular[1] = 0.0f;
            material_specular[2] = 1.0f;
            material_specular[3] = 1.0f;
        break;
        //Pink
        case 2:
            material_specular[0] = 1.0f;
            material_specular[1] = 1.0f;
            material_specular[2] = 1.0f;
            material_specular[3] = 1;

            material_diffuse[0] = 0.7f;
            material_diffuse[1] = 0.0f;
            material_diffuse[2] = 0.5f;
            material_diffuse[3] = 1;

            material_ambient[0] = 0.0f;
            material_ambient[1] = 0.0f;
            material_ambient[2] = 0.0f;
            material_ambient[3] = 1;
        break;
    }
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,material_specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,material_ambient);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,128);
}

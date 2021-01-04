#include "matrix_plys.h"
using namespace _colors_ne;

matrix_plys::matrix_plys(_ply Ply)
{
    Plys.resize(4);

    for(int i = 0; i < Plys.size();i++)
        Plys[i].resize(4);

    for(int i = 0; i < Plys.size();i++){
        for(int j = 0; j < Plys.size();j++){
            Plys[i][j] = Ply;
        }
    }
}

void matrix_plys::draw_fill(){
    int distance = 10;
    int contador = 0;
    for(int i = 0; i < Plys.size(); i++){
        for(int j = 0; j < Plys[i].size();j++){
            if( contador == selected_ply ){
                glColor3fv((GLfloat *) &YEllOW);
            }
            else{
                glColor3fv((GLfloat *) &BLUE);
            }
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glTranslatef(j*distance,0,i*distance);
            Plys[i][j].draw_fill(false);
            glPopMatrix();

            contador++;
        }
    }
}

void matrix_plys::draw_selection(){
//R:0-255
//G:256-65535
//B:65536-16777215
    _vertex3f id;
    _vertex4f color;
     int distance = 10;
     int contador = 0;

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < Plys.size();i++){
        for(int j = 0; j < Plys[i].size(); j++){
            id.r = (float)((contador & 0x00FF0000) >> 16);
            id.g =  (float)( (contador & 0x0000FF00) >> 8);
            id.b =  (float) (contador & 0x000000FF);
            id = id/255.0f;

            color = _vertex4f(id.r,id.g,id.b,1);

            glColor3fv((GLfloat *) &color);
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
            glTranslatef(j*distance,0,i*distance);
            Plys[i][j].draw_fill(false);
            glPopMatrix();

            contador++;
        }
    }
    glEnd();
}

void matrix_plys::selectedPly(int id){
    selected_ply = id;
}

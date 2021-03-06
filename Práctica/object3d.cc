/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"
#include <cmath>

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glBegin(GL_TRIANGLES);
  for (int i = 0;i < Triangles.size();i++){
    glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
    glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
    glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
  }
  glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill(bool paintTriangle)
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0;i < Triangles.size();i++){
      if(paintTriangle == true){
          if( i == selectedTriangle ){
            glColor3fv((GLfloat *) &YEllOW);
          }
          else {
              glColor3fv((GLfloat *) &BLUE);
          }
      }
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0;i < Triangles.size();i++){
      if(i%2)glColor3fv((GLfloat *) &BLUE);
      else glColor3fv((GLfloat *) &GREEN);

      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

    }
    glEnd();
}

void _object3D::draw_flat_shading(){
    glShadeModel(GL_FLAT);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0;i < Triangles.size();i++){
      glNormal3f((GLfloat)NormalTriangles[i]._0,(GLfloat)NormalTriangles[i]._1,(GLfloat)NormalTriangles[i]._2);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}

void _object3D::draw_smooth_shading(){
    glShadeModel(GL_SMOOTH);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0;i < Triangles.size();i++){
      glNormal3fv((GLfloat *) &NormalVertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glNormal3fv((GLfloat *) &NormalVertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glNormal3fv((GLfloat *) &NormalVertices[Triangles[i]._2]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}

void _object3D::draw_unlit_texture(QImage Image){
    glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Triangles.size(); i++) {

      glTexCoord2f(Texture[Triangles[i]._0].x, Texture[Triangles[i]._0].y);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glTexCoord2f(Texture[Triangles[i]._1].x, Texture[Triangles[i]._1].y);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glTexCoord2f(Texture[Triangles[i]._2].x, Texture[Triangles[i]._2].y);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_texture_flat_shading(QImage Image){
    glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Triangles.size(); i++) {
      glNormal3f((GLfloat)NormalTriangles[i]._0,(GLfloat)NormalTriangles[i]._1,(GLfloat)NormalTriangles[i]._2);

      glTexCoord2f(Texture[Triangles[i]._0].x, Texture[Triangles[i]._0].y);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glTexCoord2f(Texture[Triangles[i]._1].x, Texture[Triangles[i]._1].y);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glTexCoord2f(Texture[Triangles[i]._2].x, Texture[Triangles[i]._2].y);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_texture_smooth_shading(QImage Image){
    glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Triangles.size(); i++) {

      glTexCoord2f(Texture[Triangles[i]._0].x, Texture[Triangles[i]._0].y);
      glNormal3fv((GLfloat *) &NormalVertices[Triangles[i]._0]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
      glTexCoord2f(Texture[Triangles[i]._1].x, Texture[Triangles[i]._1].y);
      glNormal3fv((GLfloat *) &NormalVertices[Triangles[i]._1]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
      glTexCoord2f(Texture[Triangles[i]._2].x, Texture[Triangles[i]._2].y);
      glNormal3fv((GLfloat *) &NormalVertices[Triangles[i]._2]);
      glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void _object3D::draw_selection(){
//R:0-255
//G:256-65535
//B:65536-16777215
    _vertex3f id;
    _vertex4f color;

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < Triangles.size();i++){
        id.r = (float)((i & 0x00FF0000) >> 16);
        id.g =  (float)( (i & 0x0000FF00) >> 8);
        id.b =  (float) (i & 0x000000FF);
        id = id/255.0f;

        color = _vertex4f(id.r,id.g,id.b,1);

        glColor3fv((GLfloat *) &color);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}
/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/
void _object3D::calculateNormalTriangles(){
    NormalTriangles.resize(Triangles.size());
    _vertex3f normal_vector;

    for(int i = 0; i < Triangles.size(); i++){
        calculateNormalTriangle(Triangles[i], normal_vector);
        NormalTriangles[i] = normal_vector;
    }

    //Normalización de un vector
    for(int i = 0; i < Triangles.size();i++)
        normalizeVector(NormalTriangles[i]);
}

void _object3D::calculateNormalTriangle(_vertex3ui Triangle, _vertex3f &normal){
    _vertex3f pointA;
    _vertex3f pointB;
    _vertex3f pointC;

    _vertex3f vectorA;
    _vertex3f vectorB;
    _vertex3f normal_vector;

    //Puntos del triángulo
    pointA = Vertices[Triangle._0];
    pointB = Vertices[Triangle._1];
    pointC = Vertices[Triangle._2];

    //Cálculo vector A
    vectorA._0 = (pointB._0 - pointA._0);
    vectorA._1 = (pointB._1 - pointA._1);
    vectorA._2 = (pointB._2 - pointA._2);

    //Cálculo del vector B
    vectorB._0 = (pointC._0 - pointA._0);
    vectorB._1 = (pointC._1 - pointA._1);
    vectorB._2 = (pointC._2 - pointA._2);

    //Producto vectorial, cálculo del vector normal
    calculateVectorProduct(vectorA,vectorB,normal);
}



void _object3D::calculateNormalVertices(){
    calculateNormalTriangles();
    vector<int> shared_triangles;
    shared_triangles.resize(Vertices.size());

    NormalVertices.resize(Vertices.size());

    for(int i = 0; i < Triangles.size();i++){
        NormalVertices[Triangles[i]._0] += NormalTriangles[i];
        shared_triangles[Triangles[i]._0]++;
        NormalVertices[Triangles[i]._1] += NormalTriangles[i];
        shared_triangles[Triangles[i]._1]++;
        NormalVertices[Triangles[i]._2] += NormalTriangles[i];
        shared_triangles[Triangles[i]._2]++;
    }

    for(int i = 0; i < NormalVertices.size();i++){
        NormalVertices[i]._0 = NormalVertices[i]._0/shared_triangles[i];
        NormalVertices[i]._1 = NormalVertices[i]._1/shared_triangles[i];
        NormalVertices[i]._2 = NormalVertices[i]._2/shared_triangles[i];
    }

    for(int i = 0; i < NormalVertices.size(); i++){
        normalizeVector(NormalVertices[i]);
    }
}

void _object3D::normalizeVector(_vertex3f &v){
    float module;
    calculateVectorModule(v,module);

    v._0 = v._0/module;
    v._1 = v._1/module;
    v._2 = v._2/module;
}

void _object3D::calculateVectorModule(_vertex3f v, float &module){
    module = sqrt(pow(v._0,2)+pow(v._1,2)+pow(v._2,2));
}

void _object3D::calculateVectorProduct(_vertex3f v1, _vertex3f v2, _vertex3f &vector_product){
    int k = 1;
    _vertex3f positive_part;
    _vertex3f negative_part;

    //Cálculo de la parte positiva
    for(int i = 0; i < 3; i++ ){
       positive_part[i] = (v1[k%3]*v2[(k+1)%3]);
       k++;
    }

    k=2;
    //Cálculo de la parte negativa
    for(int i = 0; i < 3; i++ ){
       negative_part[i] = (v1[k%3]*v2[(k-1)%3]);
       k++;
    }

    for(int i = 0; i < 3; i++){
        vector_product[i] = positive_part[i] - negative_part[i];
    }
}

void _object3D::selected_Triangle(int Triangle){
    selectedTriangle = Triangle;
}

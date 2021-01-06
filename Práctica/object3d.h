/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include <QImage>

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/
/**
  * @author Inés Nieto Sánchez
**/
class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;

  vector<_vertex3f> NormalTriangles;
  vector<_vertex3f> NormalVertices;

  vector<_vertex2f> Texture;

  int selectedTriangle = -1;

/***********************************************************************/
/**
* @brief Calcula las normales de los triángulos de un objeto
*/
  void calculateNormalTriangles();

/***********************************************************************/
/**
* @brief Calcula las normales un triángulo de un objeto
* @param Triangle, triángulo del que se va a calcular su normal
* @param normal , la normal del triángulo
*/
  void calculateNormalTriangle(_vertex3ui Triangle, _vertex3f &normal);

/***********************************************************************/
/**
* @brief Calcula las normales de los vértices de un objeto
*/
  void calculateNormalVertices();

/***********************************************************************/
/**
* @brief Calcula el producto vectorial
* @param v1, primer vector
* @param v2, segundo vector
* @param vector_product, resultado del producto vectorial
*/
  void calculateVectorProduct(_vertex3f v1, _vertex3f v2, _vertex3f &vector_product);

/***********************************************************************/
/**
* @brief Normaliza un vector
* @param v, vector a ser normalizado
*/
  void normalizeVector(_vertex3f &v);

/***********************************************************************/
/**
* @brief Calcula el módulo de un vector
*/
  void calculateVectorModule(_vertex3f v, float &module);

/***********************************************************************/
/**
* @brief Funciones para los distintos modos de dibujado
*/
  void draw_line();
  void draw_fill(bool paintTriangle = true);
  void draw_chess();
  void draw_flat_shading();
  void draw_smooth_shading();
  void draw_unlit_texture(QImage Image);
  void draw_texture_flat_shading(QImage Image);
  void draw_texture_smooth_shading(QImage Image);

/***********************************************************************/
/**
* @brief Dibujado del objecto calculando el color asignado a la id de cada triángulo para realizar la selección por color
*/
  void draw_selection();

/***********************************************************************/
/**
* @brief Cambia el triángulo seleccionado
* @param Triangle, nuevo triángulo seleccionado
*/
  void selected_Triangle(int Triangle);

};

#endif

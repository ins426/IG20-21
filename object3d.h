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


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;

  vector<_vertex3f> NormalTriangles;
  vector<_vertex3f> NormalVertices;

  void calculateNormalTriangles();
  void calculateNormalTriangle(_vertex3ui Triangle, _vertex3f &normal);
  void calculateNormalVertices();
  void calculateVectorProduct(_vertex3f v1, _vertex3f v2, _vertex3f &vector_product);
  void normalizeVector(_vertex3f &v);
  void calculateVectorModule(_vertex3f v, float &module);

  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_flat_shading();
};

#endif

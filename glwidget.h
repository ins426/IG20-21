/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "_cube.h"
#include "_cone.h"
#include "_cylinder.h"
#include "_sphere.h"
#include "_semisphere.h"
#include "_revolution_ply.h"
#include "_robot.h"
#include "_whole_arm.h"
#include <QTimer>
#include "_light.h"
#include <QImage>
#include <QImageReader>
#include "chess_board.h"

namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_PLY,OBJECT_REVOLUTIONPLY, OBJECT_CYLINDER,OBJECT_CONE,OBJECT_SPHERE, OBJECT_ROBOT, OBJECT_SEMISPHERE, OBJECT_BOARD} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

  void animation();

  QImage loadTexture(char * file);

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;

private slots:
  void tick();

private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cylinder Cylinder;
  _ply Ply = _ply("/home/ines/Documentos/GitHub/IG20-21/ply_models/beethoven.ply");
  _revolution_ply RevolutionPly;
  _cone Cone;
  _sphere Sphere;
  _semisphere Semisphere;

  _robot Robot;

  _light Light;
  int material = 0;

  chess_board Board;

  _object3D Object3d;

  _gl_widget_ne::_object Object;

  const float MAX_HAND = 0.09;
  const float MIN_HAND = 0;
  const float MAX_ARM = 180;
  const float MIN_ARM = 0;
  const float MAX_BODY = 45;
  const float MIN_BODY = -45;

  bool arms_direction;
  bool hand_direction;
  bool body_direction;

  bool activateLight0;
  bool activateLight1;

  bool change_material;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_flat;
  bool Draw_smooth;
  bool Draw_texture_unlit;
  bool Draw_texture_light_flat;
  bool Draw_texture_light_smooth;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  QTimer Timer;
  bool Animation;
};

#endif

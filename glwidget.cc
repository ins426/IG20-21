/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}

void _gl_widget::mode_points_slot(int State){
    if(State==Qt::Checked)Draw_point=true;
    else Draw_point=false;

    update();
}

void _gl_widget::mode_lines_slot(int State){
    if(State==Qt::Checked)Draw_line=true;
    else Draw_line=false;

    update();
}

void _gl_widget::mode_fill_slot(int State){
    if(State==Qt::Checked)Draw_fill=true;
    else Draw_fill=false;

    update();
}

void _gl_widget::mode_chess_slot(int State){
    if(State==Qt::Checked)Draw_chess=true;
    else Draw_chess=false;

    update();
}

void _gl_widget::mode_objects_slot(int Index){
    switch(Index){
    case 0:Object=OBJECT_TETRAHEDRON;break;
    case 1:Object=OBJECT_CUBE;break;
    case 2:Object=OBJECT_CONE;break;
    case 3:Object=OBJECT_CYLINDER;break;
    case 4:Object=OBJECT_SPHERE;break;
    case 5:Object=OBJECT_PLY;break;
   }

    update();
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:
      Window->change_index_object_widget(0);
      Object=OBJECT_TETRAHEDRON;
  break;
  case Qt::Key_2:
       Window->change_index_object_widget(1);
      Object=OBJECT_CUBE;
  break;
  case Qt::Key_3:
       Window->change_index_object_widget(2);
      Object=OBJECT_CONE;
  break;
  case Qt::Key_4:
       Window->change_index_object_widget(3);
      Object=OBJECT_CYLINDER;
  break;
  case Qt::Key_5:
       Window->change_index_object_widget(4);
      Object=OBJECT_SPHERE;
  break;
  case Qt::Key_6:
      Window->change_index_object_widget(5);
      Object=OBJECT_PLY;
  break;
  case Qt::Key_8:
      Object=RUEDA;
  break;
  case Qt::Key_9:
      Object=EJE;
  break;
  case Qt::Key_0:
      Object=EJE_RUEDA;
  break;


  case Qt::Key_P:
      Draw_point=!Draw_point;
      if(Draw_point==true)Window->change_state_point_widget(true);
      else Window->change_state_point_widget(false);
  break;
  case Qt::Key_L:
      Draw_line=!Draw_line;
      if(Draw_line==true)Window->change_state_line_widget(true);
      else Window->change_state_line_widget(false);
  break;
  case Qt::Key_F:
      Draw_fill=!Draw_fill;
      if(Draw_fill==true)Window->change_state_fill_widget(true);
      else Window->change_state_fill_widget(false);
  break;
  case Qt::Key_C:
      Draw_chess=!Draw_chess;
      if(Draw_chess==true)Window->change_state_chess_widget(true);
      else Window->change_state_line_widget(false);
  break;
  case Qt::Key_D:tick();break;
  case Qt::Key_Q:Rueda.increase_speed();break;
  case Qt::Key_W:Rueda.decrease_speed();break;
  case Qt::Key_A:animation();break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    case RUEDA:Rueda.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    case RUEDA:Rueda.draw_line();break;
    case EJE:Eje.draw_line();break;
    case EJE_RUEDA:Eje_rueda.draw_line();
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill();break;
    case OBJECT_PLY:Ply.draw_fill();break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    default:break;
    }
  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=true;
  Draw_line=false;
  Draw_fill=false;
  Draw_chess=false;

  Object = OBJECT_TETRAHEDRON;

  Timer.setInterval(0);
  connect(&Timer,SIGNAL(timeout()),this,SLOT(tick()));

  Animation = false;
}

void _gl_widget::tick(){
    //update parameters
    Rueda.update_alpha();
    update(); //Actualización de imagen
}

void _gl_widget::animation(){
    Animation=!Animation;

    if(Animation==true)Timer.start();
    else Timer.stop();
}

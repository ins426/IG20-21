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


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_BODY;break;

  case Qt::Key_A:animation();break;
  //1st degree of freedom
  case Qt::Key_Q:
      if(Robot.Body.angleArm < MAX_ARM)Robot.Body.increase_arms();break;
  case Qt::Key_W:
      if(Robot.Body.angleArm > MIN_ARM)Robot.Body.decrease_arms();break;
  case Qt::Key_E:
      Robot.Body.increaseSpeed_arm();break;
  case Qt::Key_R:
      Robot.Body.decreaseSpeed_arm();break;
  //2nd degree of freedom
  case Qt::Key_S:
      cout << Robot.Body.Arm.positionHand << endl;
      if(Robot.Body.Arm.positionHand < MAX_HAND)Robot.Body.Arm.increase_hands();break;
  case Qt::Key_D:
      if(Robot.Body.Arm.positionHand > MIN_HAND)Robot.Body.Arm.decrease_hands();break;
  case Qt::Key_T:
      Robot.Body.Arm.increaseSpeed_hands();break;
  case Qt::Key_Y:
      Robot.Body.Arm.decreaseSpeed_hands();break;
  //3rd degree of freedom
  case Qt::Key_Z:
      if(Robot.Body.Body_legs.angleBody < MAX_BODY)Robot.Body.Body_legs.increase_body();break;
  case Qt::Key_X:
      if(Robot.Body.Body_legs.angleBody > MIN_BODY)Robot.Body.Body_legs.decrease_body();break;
  case Qt::Key_U:
      Robot.Body.Body_legs.increaseSpeed_body();break;
  case Qt::Key_I:
      Robot.Body.Body_legs.decreaseSpeed_body();break;
  case Qt::Key_B:Object=OBJECT_TORSO;break;

  case Qt::Key_P:Draw_point=!Draw_point;
  break;
  case Qt::Key_L:Draw_line=!Draw_line;
  break;
  case Qt::Key_F:Draw_fill=!Draw_fill;
  break;
  case Qt::Key_C:Draw_chess=!Draw_chess;
  break;

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
    case OBJECT_BODY:Robot.draw_point();break;
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
    case OBJECT_BODY:Robot.draw_line();break;
    case OBJECT_TORSO:Torso.draw_line();break;
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
    //case OBJECT_SEMISPHERE:Semisphere.draw_fill();break;
   // case OBJECT_LEG:Leg.draw_fill();break;
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
   // case OBJECT_SEMISPHERE:Semisphere.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    //case OBJECT_LEG:Leg.draw_chess();break;
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

  Timer.setInterval(0);
  connect(&Timer,SIGNAL(timeout()),this,SLOT(tick()));

  Animation = false;

  arms_direction = true;
  hand_direction = true;
  body_direction = true;
  _gl_widget_ne::_object Object = OBJECT_TETRAHEDRON;
}

void _gl_widget::tick(){
    if(Animation){
        if(arms_direction){
            Robot.Body.increase_arms();
            if(Robot.Body.angleArm > MAX_ARM)
                arms_direction = false;
        }else{
            Robot.Body.decrease_arms();
            if(Robot.Body.angleArm < MIN_ARM)
            arms_direction = true;
        }

        if(hand_direction){
            Robot.Body.Arm.increase_hands();
            if(Robot.Body.Arm.positionHand > MAX_HAND)
                hand_direction = false;
        }else{
            Robot.Body.Arm.decrease_hands();
            if(Robot.Body.Arm.positionHand < MIN_HAND)
                hand_direction = true;
        }

        if(body_direction){
            Robot.Body.Body_legs.increase_body();
            if(Robot.Body.Body_legs.angleBody > MAX_BODY)
                body_direction = false;
        }else{
            Robot.Body.Body_legs.decrease_body();
            if(Robot.Body.Body_legs.angleBody < MIN_BODY)
                body_direction = true;
        }
    }
    update();
}

void _gl_widget::animation(){
    Animation=!Animation;

    if(Animation==true)Timer.start();
    else Timer.stop();
}

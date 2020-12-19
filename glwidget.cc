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
  case Qt::Key_7:Object=OBJECT_ROBOT;break;
  case Qt::Key_8:Object=OBJECT_BOARD;break;
  case Qt::Key_9:Object=OBJECT_SEMISPHERE;break;
  case Qt::Key_0:Object=OBJECT_REVOLUTIONPLY;break;

  case Qt::Key_A:animation();break;

  //1st degree of freedom
  case Qt::Key_Q:
      if(Robot.Body.angleArms < MAX_ARM)
          Robot.Body.increase_arms();
      break;
  case Qt::Key_W:
      if(Robot.Body.angleArms > MIN_ARM)
          Robot.Body.decrease_arms();
      break;
  case Qt::Key_E:
      Robot.Body.increaseSpeed_arm();
      break;
  case Qt::Key_R:
      Robot.Body.decreaseSpeed_arm();
      break;
  //2nd degree of freedom
  case Qt::Key_S:
      if(Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.positionHand < MAX_HAND)
          Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.increase_hands();
  break;
  case Qt::Key_D:
      if(Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.positionHand > MIN_HAND)
          Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.decrease_hands();
  break;
  case Qt::Key_T:
      Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.increaseSpeed_hands();break;
  case Qt::Key_Y:
      Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.decreaseSpeed_hands();break;
  //3rd degree of freedom
  case Qt::Key_Z:
      if(Robot.Body.Body_legs.angleBody < MAX_BODY)
          Robot.Body.Body_legs.increase_body();
      break;
  case Qt::Key_X:
      if(Robot.Body.Body_legs.angleBody > MIN_BODY)
          Robot.Body.Body_legs.decrease_body();
      break;
  case Qt::Key_U:
      Robot.Body.Body_legs.increaseSpeed_body();
      break;
  case Qt::Key_I:
      Robot.Body.Body_legs.decreaseSpeed_body();
      break;

  case Qt::Key_P:Draw_point=!Draw_point;
  break;
  case Qt::Key_L:Draw_line=!Draw_line;
  break;
  case Qt::Key_F:Draw_fill=!Draw_fill;
  break;
  case Qt::Key_F2:Draw_chess=!Draw_chess;
  break;
  case Qt::Key_F3:Draw_flat=!Draw_flat;
  break;
  case Qt::Key_F4:Draw_smooth=!Draw_smooth;
  break;
  case Qt::Key_F5:Draw_texture_unlit=!Draw_texture_unlit;
  break;
  case Qt::Key_F6:Draw_texture_light_flat=!Draw_texture_light_flat;
  break;
  case Qt::Key_F7:Draw_texture_light_smooth=!Draw_texture_light_smooth;
  break;

  case Qt::Key_J:activateLight0=!activateLight0;
  break;
  case Qt::Key_K:activateLight1=!activateLight1;
  break;

  case Qt::Key_M:change_material=!change_material;
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

  if(change_material){
      material = (material+1)%3;
      Light.defineMaterial(material);
      change_material = false;
  }

  if(activateLight0){
     Light.ActivateLight0();
  }
  else{
      Light.DesactivateLight0();
  }

  if(activateLight1){
    Light.ActivateLight1();
  }
  else{
      Light.DesactivateLight1();
  }

  if(!Draw_flat && !Draw_smooth)
      Light.DesactivateLights();

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
    case OBJECT_REVOLUTIONPLY:RevolutionPly.draw_point();break;
    case OBJECT_ROBOT:Robot.draw_point();break;
    case OBJECT_SEMISPHERE:Semisphere.draw_point();break;
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
    case OBJECT_REVOLUTIONPLY:RevolutionPly.draw_line();break;
    case OBJECT_ROBOT:Robot.draw_line();break;
    case OBJECT_BOARD:Board.draw_line();break;
    case OBJECT_SEMISPHERE:Semisphere.draw_line();break;
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
    case OBJECT_REVOLUTIONPLY:RevolutionPly.draw_fill();break;
    case OBJECT_ROBOT:Robot.draw_fill();break;
    case OBJECT_SEMISPHERE:Semisphere.draw_fill();break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_ROBOT:Robot.draw_chess();break;
    case OBJECT_SEMISPHERE:Semisphere.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    case OBJECT_REVOLUTIONPLY:RevolutionPly.draw_chess();break;
    default:break;
    }
  }

  if (Draw_flat){
    Light.ActivateLights();
    Light.defineLight0();
    Light.defineLight1();
    switch (Object){
     case OBJECT_CUBE:Cube.draw_flat_shading();break;
     case OBJECT_CYLINDER:Cylinder.draw_flat_shading();break;
     case OBJECT_CONE:Cone.draw_flat_shading();break;
     case OBJECT_SPHERE:Sphere.draw_flat_shading();break;
     case OBJECT_ROBOT:Robot.draw_flat();break;
     case OBJECT_SEMISPHERE:Semisphere.draw_flat_shading();break;
     case OBJECT_BOARD:Board.draw_flat_shading();break;
    default:break;
    }
  }

  if (Draw_smooth){
    Light.ActivateLights();
    Light.defineLight0();
    Light.defineLight1();
    switch (Object){
    case OBJECT_CUBE:Cube.draw_smooth_shading();break;
    case OBJECT_CYLINDER:Cylinder.draw_smooth_shading();break;
    case OBJECT_CONE:Cone.draw_smooth_shading();break;
    case OBJECT_SPHERE:Sphere.draw_smooth_shading();break;
    case OBJECT_ROBOT:Robot.draw_smooth();break;
    case OBJECT_SEMISPHERE:Semisphere.draw_smooth_shading();break;
    case OBJECT_BOARD:Board.draw_smooth_shading();break;
    default:break;
    }
  }

  if(Draw_texture_unlit){
      QImage image;
      switch(Object){
        case OBJECT_BOARD:
          image = loadTexture((char *)"/home/ines/Descargas/chess.jpg");
          Board.draw_unlit_texture(image);
        break;
        case OBJECT_SPHERE:
          image = loadTexture((char *)"/home/ines/Descargas/texturas/dia_8192.jpg");
          Sphere.draw_unlit_texture(image);
         break;
      }
  }

  if(Draw_texture_light_flat){
      Light.ActivateLights();
      Light.defineLight0();
      Light.defineLight1();
      QImage image;
      switch(Object){
        case OBJECT_BOARD:
          image = loadTexture((char *)"/home/ines/Descargas/chess.jpg");
          Board.draw_texture_flat_shading(image);
        break;
        case OBJECT_SPHERE:
          image = loadTexture((char *)"/home/ines/Descargas/texturas/dia_8192.jpg");
          Sphere.draw_texture_flat_shading(image);
         break;
      }
  }

  if(Draw_texture_light_smooth){
      Light.ActivateLights();
      Light.defineLight0();
      Light.defineLight1();
      QImage image;
      switch(Object){
        case OBJECT_BOARD:
          image = loadTexture((char *)"/home/ines/Descargas/chess.jpg");
          Board.draw_texture_smooth_shading(image);
        break;
        case OBJECT_SPHERE:
          image = loadTexture((char *)"/home/ines/Descargas/texturas/dia_8192.jpg");
          Sphere.draw_texture_smooth_shading(image);
         break;
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
  Draw_flat = false;
  Draw_smooth = false;
  Draw_texture_unlit = false;
  Draw_texture_light_flat = false;
  Draw_texture_light_smooth = false;

  Timer.setInterval(0);
  connect(&Timer,SIGNAL(timeout()),this,SLOT(tick()));

  Animation = false;

  activateLight0 = false;
  activateLight1 = false;

  change_material = false;

  arms_direction = true;
  hand_direction = true;
  body_direction = true;

  Light.defineMaterial(0);

  _gl_widget_ne::_object Object = OBJECT_TETRAHEDRON;
}

/*************************************************************************************/
/*************************************************************************************/
void _gl_widget::tick(){
    if(Animation){
        if(arms_direction){
            Robot.Body.increase_arms();
            if(Robot.Body.angleArms > MAX_ARM)
                arms_direction = false;
        }else{
            Robot.Body.decrease_arms();
            if(Robot.Body.angleArms < MIN_ARM)
            arms_direction = true;
        }

        if(hand_direction){
            Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.increase_hands();
            if(Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.positionHand > MAX_HAND)
                hand_direction = false;
        }else{
            Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.decrease_hands();
            if(Robot.Body.Arms.Arm.Forearm_elbow.Forearm_hand.positionHand < MIN_HAND)
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

        if(activateLight1){
            Light.moveLight1();
        }
    }

    update();
}
/*************************************************************************************/
/*************************************************************************************/
void _gl_widget::animation(){
    Animation=!Animation;

    if(Animation==true)Timer.start();
    else Timer.stop();
}

QImage _gl_widget::loadTexture(char * file){
// Code for reading an image
    QString File_name(file);
    QImage Image;
    QImageReader Reader(File_name);
    Reader.setAutoTransform(true);
    Image = Reader.read();
    if (Image.isNull()) {
      QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                               tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
      exit(-1);
    }
    Image=Image.mirrored();
    Image=Image.convertToFormat(QImage::Format_RGB888);

    return Image;
}

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
  //case Qt::Key_0:Object=OBJECT_REVOLUTIONPLY;break;
  case Qt::Key_0:Object=OBJECT_PLYS;break;

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
  case Qt::Key_E:Robot.Body.increaseSpeed_arm();break;
  case Qt::Key_R:Robot.Body.decreaseSpeed_arm();break;

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
  case Qt::Key_U:Robot.Body.Body_legs.increaseSpeed_body();break;
  case Qt::Key_I:Robot.Body.Body_legs.decreaseSpeed_body();break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;

  case Qt::Key_F1:Mode_solid = MODE_SOLID;break;
  case Qt::Key_F2:Mode_solid = MODE_SOLID_CHESS;break;
  case Qt::Key_F3:Mode_solid = MODE_SOLID_FLAT_SHADING;break;
  case Qt::Key_F4:Mode_solid = MODE_SOLID_SMOOTH_SHADING;break;
  case Qt::Key_F5:Mode_solid = MODE_SOLID_TEXTURE;break;
  case Qt::Key_F6:Mode_solid = MODE_SOLID_LIGHT_FLAT_TEXTURE;break;
  case Qt::Key_F7:Mode_solid = MODE_SOLID_LIGHT_SMOOTH_TEXTURE;break;

  case Qt::Key_J:activateLight0=!activateLight0;
  break;
  case Qt::Key_K:activateLight1=!activateLight1;
  break;

  case Qt::Key_M:change_material=!change_material;
  break;

  case Qt::Key_C:Projection=PERSPECTIVE_PROJECTION;break;
  case Qt::Key_V:Projection=PARALLEL_PROJECTION;break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:
      if(Projection == PARALLEL_PROJECTION){
          multiplier*=1.2;
      }
      else{
        Observer_distance*=1.2;
      };
  break;
  case Qt::Key_PageDown:
      if(Projection == PARALLEL_PROJECTION){
          multiplier/=1.2;
      }
      else{
        Observer_distance/=1.2;
      };
  break;
  }

  update();
}

/*****************************************************************************/
/*****************************************************************************/
void _gl_widget::mousePressEvent(QMouseEvent *Event){
    if(Event->buttons() & Qt::RightButton){
        Selection_position_x = Event->x();
        Selection_position_y = height() - Event->y();
    }
}

void _gl_widget::mouseReleaseEvent(QMouseEvent *Event){
    if(Draw_fill){
        if(Event->button() & Qt::RightButton){
            pick();
            update();
        }
    }
}

void _gl_widget::mouseMoveEvent(QMouseEvent *Event){
    if(Event->buttons() & Qt::LeftButton){
        if(mouseX < Event->x())
            Observer_angle_y+=ANGLE_STEP;
        else if (mouseX > Event->x())
            Observer_angle_y-=ANGLE_STEP;
        if(mouseY < Event->y())
            Observer_angle_x+=ANGLE_STEP;
        else if (mouseY > Event->y())
            Observer_angle_x-=ANGLE_STEP;

        mouseX = Event->x();
        mouseY = Event->y();
    }
    update();
}

void _gl_widget::wheelEvent(QWheelEvent *Event){
    int degrees = Event->delta()/8;
    int steps = degrees/15;

    if(Projection == PERSPECTIVE_PROJECTION){
        if(degrees >0){
            Observer_distance = Observer_distance/(steps*2);
        }
        else{
            Observer_distance = Observer_distance*abs(steps*2);
        }
    }else{
        if(degrees > 0){
           multiplier/=2;
        }
        else{
          multiplier*=2;
        }
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

  float proportion=(float)Window_height/(float)Window_width;

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  //glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  if(Projection == PERSPECTIVE_PROJECTION){
      glFrustum(X_MIN,X_MAX,Y_MIN*proportion, Y_MAX*proportion,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  }
  else{
    glOrtho(X_MIN*multiplier, X_MAX*multiplier,Y_MIN*proportion*multiplier,Y_MAX*proportion*multiplier, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
  }

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
     glEnable(GL_LIGHT0);
  }
  else{
      glDisable(GL_LIGHT0);
  }

  if(activateLight1){
    glEnable(GL_LIGHT1);
  }
  else{
      glDisable(GL_LIGHT1);
  }

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

  if(Draw_fill){
      switch (Mode_solid) {
      case MODE_SOLID:
          switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
          case OBJECT_CUBE:Cube.draw_fill();break;
          case OBJECT_CYLINDER:Cylinder.draw_fill();break;
          case OBJECT_CONE:Cone.draw_fill();break;
          case OBJECT_SPHERE:Sphere.draw_fill();break;
          case OBJECT_PLY:Ply.draw_fill();break;
          case OBJECT_REVOLUTIONPLY:RevolutionPly.draw_fill();break;
          case OBJECT_PLYS:Plys.draw_fill();break;
          case OBJECT_ROBOT:Robot.draw_fill();break;
          case OBJECT_SEMISPHERE:Semisphere.draw_fill();break;
          default:break;
          }
      break;
      case MODE_SOLID_CHESS:
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
      break;
      case MODE_SOLID_FLAT_SHADING:
          glEnable(GL_LIGHTING);
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
          glDisable(GL_LIGHTING);
      break;
      case MODE_SOLID_SMOOTH_SHADING:
          glEnable(GL_LIGHTING);
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
          glDisable(GL_LIGHTING);
      break;
      case MODE_SOLID_TEXTURE:
          switch(Object){
          case OBJECT_BOARD:
            image = loadTexture((char *)"/home/ines/Descargas/chess.jpg");
            Board.draw_unlit_texture(image);
          break;
          case OBJECT_SPHERE:
            image = loadTexture((char *)"/home/ines/Descargas/texturas/dia_8192.jpg");
            Sphere.draw_unlit_texture(image);
          break;
          case OBJECT_CYLINDER:
            image = loadTexture((char *)"/home/ines/Descargas/texturas/dia_8192.jpg");
            Cylinder.draw_unlit_texture(image);
          break;
          default:break;
          }
      break;
      case MODE_SOLID_LIGHT_FLAT_TEXTURE:
          glEnable(GL_LIGHTING);
          Light.defineLight0();
          Light.defineLight1();
          switch(Object){
          case OBJECT_BOARD:
            image = loadTexture((char *)"/home/ines/Documentos/GitHub/IG20-21/texturas/chess.jpg");
            Board.draw_texture_flat_shading(image);
          break;
          case OBJECT_SPHERE:
            image = loadTexture((char *)"/home/ines/Documentos/GitHub/IG20-21/texturas/dia_8192.jpg");
            Sphere.draw_texture_flat_shading(image);
          break;
          }
          glDisable(GL_LIGHTING);
      break;
      case MODE_SOLID_LIGHT_SMOOTH_TEXTURE:
        glEnable(GL_LIGHTING);
        Light.defineLight0();
        Light.defineLight1();
        switch(Object){
        case OBJECT_BOARD:
            image = loadTexture((char *)"/home/ines/Documentos/GitHub/IG20-21/texturas/chess.jpg");
            Board.draw_texture_smooth_shading(image);
        break;
        case OBJECT_SPHERE:
            image = loadTexture((char *)"/home/ines/Documentos/GitHub/IG20-21/texturas/dia_8192.jpg");
            Sphere.draw_texture_smooth_shading(image);
        break;
        }
        glDisable(GL_LIGHTING);
      break;
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
  Window_height = Height1;
  Window_width = Width1;
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

  glewInit();

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);

  Window_width=width();
  Window_height=height();

  selectedTriangle = -1;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=true;
  Draw_line=false;
  Draw_fill=false;


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

  mouseX = 0;
  mouseY = 0;
  multiplier = 10;

  Object = OBJECT_TETRAHEDRON;
  Mode_solid = MODE_SOLID;
  Projection = PERSPECTIVE_PROJECTION;
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
/*************************************************************************************/
/*************************************************************************************/
void _gl_widget::pick(){
    makeCurrent();

      // Frame Buffer Object to do the off-screen rendering
      GLuint FBO;
      glGenFramebuffers(1,&FBO);
      glBindFramebuffer(GL_FRAMEBUFFER,FBO);

      // Texture for drawing
      GLuint Color_texture;
      glGenTextures(1,&Color_texture);
      glBindTexture(GL_TEXTURE_2D,Color_texture);
      // RGBA8
      glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height);
      // this implies that there is not mip mapping
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

      // Texure for computing the depth
      GLuint Depth_texture;
      glGenTextures(1,&Depth_texture);
      glBindTexture(GL_TEXTURE_2D,Depth_texture);
      // Float
      glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height);

      // Attatchment of the textures to the FBO
      glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
      glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

      // OpenGL will draw to these buffers (only one in this case)
      static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
      glDrawBuffers(1,Draw_buffers);

      /*************************/
      // dibujar escena para seleccion
      clear_window();
      change_projection();
      change_observer();

      switch (Object) {
      case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
      case OBJECT_CUBE:Cube.draw_selection();break;
      case OBJECT_CONE:Cone.draw_selection();break;
      case OBJECT_CYLINDER:Cylinder.draw_selection();break;
      case OBJECT_SPHERE:Sphere.draw_selection();break;
      case OBJECT_PLY:Ply.draw_selection();break;
      case OBJECT_PLYS:Plys.draw_selection();break;
      case OBJECT_REVOLUTIONPLY:RevolutionPly.draw_selection();break;
      case OBJECT_SEMISPHERE:Semisphere.draw_selection();break;
        default:break;
      }

      /*************************/
      // get the pixel
      int Color;
      glReadBuffer(GL_FRONT);
      glPixelStorei(GL_PACK_ALIGNMENT,1);
      glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);
      /*************************/

      // convertir de RGB a identificador
      unsigned int R = (unsigned int)Color & 0x000000FF;
      unsigned int G = (unsigned int)((Color & 0x0000FF00)>> 8);
      unsigned int B =  (unsigned int)((Color & 0x00FF0000)>> 16);
      // actualizar el identificador de la parte seleccionada en el objeto
      selectedTriangle = ( R << 16 ) + ( G << 8 ) + B ;
         if ( selectedTriangle==16777215)
             selectedTriangle = -1;

      switch (Object) {
      case OBJECT_TETRAHEDRON:Tetrahedron.selected_Triangle(selectedTriangle);break;
      case OBJECT_CUBE:Cube.selected_Triangle(selectedTriangle);break;
      case OBJECT_CONE:Cone.selected_Triangle(selectedTriangle);break;
      case OBJECT_CYLINDER:Cylinder.selected_Triangle(selectedTriangle);break;
      case OBJECT_SPHERE:Sphere.selected_Triangle(selectedTriangle);break;
      case OBJECT_PLY:Ply.selected_Triangle(selectedTriangle);break;
      case OBJECT_PLYS:Plys.selectedPly(selectedTriangle);break;
      case OBJECT_REVOLUTIONPLY:RevolutionPly.selected_Triangle(selectedTriangle);break;
      case OBJECT_SEMISPHERE:Semisphere.selected_Triangle(selectedTriangle);break;
      default:break;
      }
      /*************************/

      glDeleteTextures(1,&Color_texture);
      glDeleteTextures(1,&Depth_texture);
      glDeleteFramebuffers(1,&FBO);
      // the normal framebuffer takes the control of drawing
      glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}

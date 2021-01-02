HEADERS += \
  ../GL/freeglut.h \
  ../GL/freeglut_ext.h \
  ../GL/freeglut_std.h \
  ../GL/gl.h \
  ../GL/gl_mangle.h \
  ../GL/glew.h \
  ../GL/glext.h \
  ../GL/glu.h \
  ../GL/glu_mangle.h \
  ../GL/glut.h \
  ../GL/glx.h \
  ../GL/glx_mangle.h \
  ../GL/glxew.h \
  ../GL/glxext.h \
  ../GL/glxint.h \
  ../GL/glxmd.h \
  ../GL/glxproto.h \
  ../GL/glxtokens.h \
  ../GL/internal/dri_interface.h \
  ../GL/internal/glcore.h \
  ../GL/osmesa.h \
  ../GL/vms_x_fix.h \
  ../GL/wglew.h \
  ../GL/wglext.h \
  ../GL/wmesa.h \
  _bag.h \
  _body_legs.h \
  _cone.h \
  _cube.h \
  _cylinder.h \
  _elbow.h \
  _forearm.h \
  _forearm_elbow.h \
  _forearm_hand.h \
  _glass.h \
  _half_hand.h \
  _head.h \
  _head_glass.h \
  _leg.h \
  _leg_wheel.h \
  _light.h \
  _lower_torso.h \
  _ply.h \
  _revolution_ply.h \
  _robot.h \
  _semisphere.h \
  _shoulder.h \
  _sphere.h \
  _torso.h \
  _two_arms.h \
  _upper_body.h \
  _upper_torso.h \
  _wheel.h \
  _whole_arm.h \
  _whole_body.h \
  chess_board.h \
  colors.h \
  basic_object3d.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  revolution_object.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  _bag.cc \
  _body_legs.cc \
  _cone.cc \
  _cube.cc \
  _cylinder.cc \
  _elbow.cc \
  _forearm.cc \
  _forearm_elbow.cc \
  _forearm_hand.cc \
  _glass.cc \
  _half_hand.cc \
  _head.cc \
  _head_glass.cc \
  _leg.cc \
  _leg_wheel.cc \
  _light.cc \
  _lower_torso.cc \
  _ply.cc \
  _revolution_ply.cc \
  _robot.cc \
  _semisphere.cc \
  _shoulder.cc \
  _sphere.cc \
  _torso.cc \
  _two_arms.cc \
  _upper_body.cc \
  _upper_torso.cc \
  _wheel.cc \
  _whole_arm.cc \
  _whole_body.cc \
  basic_object3d.cc \
  chess_board.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  revolution_object.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc

LIBS += -L/usr/X11R6/lib64 -lGL -lGLEW


CONFIG += c++11
QT += widgets

DISTFILES += \
    ../GL/glext.h.old

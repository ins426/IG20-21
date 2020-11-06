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
  _arm.h \
  _arm_hand.h \
  _bag.h \
  _body_legs.h \
  _cone.h \
  _cube.h \
  _cylinder.h \
  _glass.h \
  _hand.h \
  _head.h \
  _head_glass.h \
  _hierarchical_model.h \
  _leg.h \
  _leg_wheel.h \
  _ply.h \
  _revolution_ply.h \
  _semisphere.h \
  _sphere.h \
  _torso.h \
  _upper_body.h \
  _wheel.h \
  _whole_body.h \
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
  _arm.cc \
  _arm_hand.cc \
  _bag.cc \
  _body_legs.cc \
  _cone.cc \
  _cube.cc \
  _cylinder.cc \
  _glass.cc \
  _hand.cc \
  _head.cc \
  _head_glass.cc \
  _hierarchical_model.cc \
  _leg_wheel.cc \
  _ply.cc \
  _revolution_ply.cc \
  _semisphere.cc \
  _sphere.cc \
  _torso.cc \
  _upper_body.cc \
  _wheel.cc \
  _whole_body.cc \
  basic_object3d.cc \
  file_ply_stl.cc \
  leg.cc \
  object3d.cc \
  axis.cc \
  revolution_object.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets

DISTFILES += \
    ../GL/glext.h.old

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
  _cube.h \
  _cylinder.h \
  _ply.h \
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
  _cube.cc \
  _cylinder.cc \
  _ply.cc \
  basic_object3d.cc \
  file_ply_stl.cc \
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

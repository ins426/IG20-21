/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>


class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow
{
    Q_OBJECT

public:
    _window();
    void change_state_point_widget(bool Checked);
    void change_state_line_widget(bool Checked);
    void change_state_fill_widget(bool Checked);
    void change_state_chess_widget(bool Checked);
    void change_index_object_widget(int Index);

private:
  _gl_widget *GL_widget=nullptr;

  QCheckBox *Checkbox_layout1= nullptr;
  QCheckBox *Checkbox_layout2= nullptr;
  QCheckBox *Checkbox_layout3= nullptr;
  QCheckBox *Checkbox_layout4= nullptr;
  QComboBox *Combobox_objects = nullptr;
};

#endif

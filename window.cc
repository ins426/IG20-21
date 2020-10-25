/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window()
{
    QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QWidget *Central_widget = new QWidget;

    GL_widget = new _gl_widget(this);
    GL_widget->setSizePolicy(Q);

    QTabWidget *Tab_widget = new QTabWidget; //Para incluir una página con pestañas
    Tab_widget->setMaximumWidth(300);

/***************************************************************/
    QWidget *Visualization_widget = new QWidget;
    QVBoxLayout *Visualization_layout = new QVBoxLayout;
    QGridLayout *Gridlayout_visualization = new QGridLayout;
    QGroupBox *Aux_widget=new QGroupBox("Modes");

    QLabel *Label1 = new QLabel("Points");
    QLabel *Label2 = new QLabel("Lines");
    QLabel *Label3 = new QLabel("Fill");
    QLabel *Label4 = new QLabel("Chess");

    Checkbox_layout1= new QCheckBox;
    Checkbox_layout1->setCheckState(Qt::Checked);
    connect(Checkbox_layout1,SIGNAL(stateChanged(int)),GL_widget,SLOT(mode_points_slot(int)));

    Checkbox_layout2= new QCheckBox;
    connect(Checkbox_layout2,SIGNAL(stateChanged(int)),GL_widget,SLOT(mode_lines_slot(int)));

    Checkbox_layout3= new QCheckBox;
    connect(Checkbox_layout2,SIGNAL(stateChanged(int)),GL_widget,SLOT(mode_fill_slot(int)));

    Checkbox_layout4= new QCheckBox;
    connect(Checkbox_layout2,SIGNAL(stateChanged(int)),GL_widget,SLOT(mode_chess_slot(int)));

    Gridlayout_visualization->addWidget(Label1,0,0,Qt::AlignRight);
    Gridlayout_visualization->addWidget(Checkbox_layout1,0,1);

    Gridlayout_visualization->addWidget(Label2,1,0,Qt::AlignRight);
    Gridlayout_visualization->addWidget(Checkbox_layout2,1,1);

    Gridlayout_visualization->addWidget(Label3,2,0,Qt::AlignRight);
    Gridlayout_visualization->addWidget(Checkbox_layout3,2,1);

    Gridlayout_visualization->addWidget(Label4,3,0,Qt::AlignRight);
    Gridlayout_visualization->addWidget(Checkbox_layout4,3,1);


    Aux_widget->setLayout(Gridlayout_visualization);

    Visualization_layout->addWidget(Aux_widget);
    Visualization_layout->addStretch();

    Visualization_widget->setLayout(Visualization_layout);

    Tab_widget->addTab(Visualization_widget,"Visualization");

/**************************************************************/
    QWidget *Objects_widget = new QWidget;
    QVBoxLayout *Objects_layout = new QVBoxLayout;

    Combobox_objects = new QComboBox;

    connect(Combobox_objects,SIGNAL(activated(int)),GL_widget,SLOT(mode_objects_slot(int)));

    Combobox_objects->addItem("Tetrahedron");
    Combobox_objects->addItem("Cube");
    Combobox_objects->addItem("Cone");
    Combobox_objects->addItem("Cylinder");
    Combobox_objects->addItem("Sphere");
    Combobox_objects->addItem("Ply");

    Objects_layout->addWidget(Combobox_objects);
    Objects_layout->addStretch();
    Objects_widget->setLayout(Objects_layout);

    Tab_widget->addTab(Objects_widget,"Objects");

/**************************************************************/
    //Tab_widget->addTab() Aquí iriía la de objetos

    QHBoxLayout *Horizontal_main = new QHBoxLayout;

    Horizontal_main->addWidget(GL_widget);
    Horizontal_main->addWidget(Tab_widget);

    Central_widget->setLayout(Horizontal_main);
    setCentralWidget(Central_widget);



  //  QFrame *Framed_widget= new QFrame(Central_widget);
  //  Framed_widget->setSizePolicy(Q);
  //  Framed_widget->setFrameStyle(QFrame::Panel);
  //  Framed_widget->setLineWidth(3);


  //  QHBoxLayout *Horizontal_frame = new QHBoxLayout();
  //  Horizontal_frame->setContentsMargins(1,1,1,1);

  //  Horizontal_frame->addWidget(GL_widget);
  //  Framed_widget->setLayout(Horizontal_frame);

  //  QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

  //  Horizontal_main->addWidget(Framed_widget);

  //  Central_widget->setLayout(Horizontal_main);
  //  setCentralWidget(Central_widget);

  //  // actions for file menu
      QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
      Exit->setShortcut(tr("Ctrl+Q"));
      Exit->setToolTip(tr("Exit the application"));
      connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

  //  // menus
      QMenu *File_menu=menuBar()->addMenu(tr("&File"));
      File_menu->addAction(Exit);
      File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

      setWindowTitle(tr("Práctica 1"));

      resize(800,800);

}

void _window::change_state_point_widget(bool Checked){
    Checkbox_layout1->blockSignals(true);
    if (Checked == true) Checkbox_layout1->setCheckState(Qt::Checked);
    else Checkbox_layout1->setCheckState(Qt::Unchecked);
    Checkbox_layout1->blockSignals(false);
}

void _window::change_state_line_widget(bool Checked){
    Checkbox_layout2->blockSignals(true);
    if (Checked == true) Checkbox_layout2->setCheckState(Qt::Checked);
    else Checkbox_layout2->setCheckState(Qt::Unchecked);
    Checkbox_layout2->blockSignals(false);
}

void _window::change_state_fill_widget(bool Checked){
    Checkbox_layout3->blockSignals(true);
    if (Checked == true) Checkbox_layout3->setCheckState(Qt::Checked);
    else Checkbox_layout3->setCheckState(Qt::Unchecked);
    Checkbox_layout3->blockSignals(false);
}

void _window::change_state_chess_widget(bool Checked){
    Checkbox_layout4->blockSignals(true);
    if (Checked == true) Checkbox_layout4->setCheckState(Qt::Checked);
    else Checkbox_layout4->setCheckState(Qt::Unchecked);
    Checkbox_layout4->blockSignals(false);
}

void _window::change_index_object_widget(int Index){
    Checkbox_layout4->blockSignals(true);
    Combobox_objects->setCurrentIndex(Index);
    Checkbox_layout4->blockSignals(false);
}



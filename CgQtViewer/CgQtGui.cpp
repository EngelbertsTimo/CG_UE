

#include "CgQtGLRenderWidget.h"
#include "CgQtGui.h"
#include "CgQtMainApplication.h"
#include "../CgBase/CgEnums.h"
#include "../CgEvents/CgMouseEvent.h"
#include "../CgEvents/CgKeyEvent.h"
#include "../CgEvents/CgWindowResizeEvent.h"
#include "../CgEvents/CgLoadObjFileEvent.h"
#include "../CgEvents/CgTrackballEvent.h"
#include "../CgEvents/CgColorChangeEvent.h"
#include "../CgEvents/CgButtonEvent.h"
#include "../CgEvents/CgAufgabenStatusEvent.h"
#include "../CgEvents/CgResetEvent.h"
#include "../CgEvents/CgShowNormalsEvent.h"
#include "../CgEvents/CgLRAglaetenEvent.h"
#include "../CgEvents/CgRotationEvent.h"
#include "../CgEvents/CgRenderExternObjectEvent.h"
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QMenuBar>
#include <QActionGroup>
#include <QFileDialog>
#include <iostream>
#include <QLineEdit>



CgQtGui::CgQtGui(CgQtMainApplication *mw)
  : m_mainWindow(mw)
{
  m_glRenderWidget = new CgQtGLRenderWidget;


  connect(m_glRenderWidget, SIGNAL(mouseEvent(QMouseEvent*)), this, SLOT(mouseEvent(QMouseEvent*)));
  connect(m_glRenderWidget, SIGNAL(viewportChanged(int,int)), this, SLOT(viewportChanged(int,int)));
  connect(m_glRenderWidget, SIGNAL(trackballChanged()), this, SLOT(slotTrackballChanged()));


  QVBoxLayout *mainLayout = new QVBoxLayout;
  QHBoxLayout *container = new QHBoxLayout;

  external_ObjectNames.push_back("Bishop.obj");
  external_ObjectNames.push_back("bunny.obj");
  external_ObjectNames.push_back("King.obj");
  external_ObjectNames.push_back("Knight.obj");
  external_ObjectNames.push_back("Man_sitting.obj");
  external_ObjectNames.push_back("porsche.obj");
  external_ObjectNames.push_back("Queen.obj");
  external_ObjectNames.push_back("Rook.obj");
  external_ObjectNames.push_back("tyra.obj");

  // Tabs erstellen
  // A3
  QWidget *a3_opt = new QWidget;
  createOptionPanelA3(a3_opt);

  // A4
  QWidget *a4_opt = new QWidget;
  createOptionPanelA4(a4_opt);

  // A5
  QWidget *a5_opt = new QWidget;
  createOptionPanelA5(a5_opt);

  // A6
  QWidget *a6_opt = new QWidget;
  createOptionPanelA6(a6_opt);

  // A7
  QWidget *a7_opt = new QWidget;
  createOptionPanelA7(a7_opt);

  // A8
  QWidget *a8_opt = new QWidget;
  createOptionPanelA8(a8_opt);

  QTabWidget* m_tabs = new QTabWidget();
  m_tabs->addTab(a3_opt,"Aufgabe 3");
  m_tabs->addTab(a4_opt,"Aufgabe 4");
  m_tabs->addTab(a5_opt,"Aufgabe 5");
  m_tabs->addTab(a6_opt,"Aufgabe 6");
  m_tabs->addTab(a7_opt,"Aufgabe 7");
  m_tabs->addTab(a8_opt,"Aufgabe 8");
  container->addWidget(m_tabs);

  m_tabs->setMaximumWidth(400);

  container->addWidget(m_glRenderWidget);

  QWidget *w = new QWidget;
  w->setLayout(container);
  mainLayout->addWidget(w);

  setLayout(mainLayout);
  setWindowTitle(tr("Übung Computergrafik 1 -  SoSe 2021"));


  /* create Menu Bar */
  m_menuBar = new QMenuBar;
  QMenu *file_menu = new QMenu("&File" );
  file_menu->addAction("&Open Mesh Model", this, SLOT(slotLoadMeshFile()));
  // todo: Add Quit-Action
  m_menuBar->addMenu( file_menu );
  QMenu *settings_menu = new QMenu("&Setting" );
  QMenu *polygon_mode_menu = new QMenu("&Polygon Mode" );

  QAction* m_custom_rot=settings_menu->addAction("&Custom Rotations", m_glRenderWidget, SLOT(slotCustomRotation()));
  m_custom_rot->setCheckable(true);
  m_custom_rot->setChecked(false);

  QAction* m_lighting=settings_menu->addAction("&Lighting on", m_glRenderWidget, SLOT(slotLighting()));
  m_lighting->setCheckable(true);
  m_lighting->setChecked(false);


  QActionGroup* polygonmode_group = new QActionGroup(this);
  polygonmode_group->setExclusive(true);

  QAction* points=polygon_mode_menu->addAction("&Points", m_glRenderWidget, SLOT(slotPolygonPoints()));
  points->setCheckable(true);
  points->setChecked(false);


  QAction* wireframe=polygon_mode_menu->addAction("&Wireframe", m_glRenderWidget, SLOT(slotPolygonWireframe()));
  wireframe->setCheckable(true);
  wireframe->setChecked(true);

  QAction* filled=polygon_mode_menu->addAction("&Filled", m_glRenderWidget, SLOT(slotPolygonFilled()));
  filled->setCheckable(true);
  filled->setChecked(false);



  polygonmode_group->addAction(points);
  polygonmode_group->addAction(wireframe);
  polygonmode_group->addAction(filled);



  // todo: Add Quit-Action
  m_menuBar->addMenu( file_menu );
  m_menuBar->addMenu( settings_menu );
  m_menuBar->addMenu( polygon_mode_menu );


  m_mainWindow->setMenuBar(m_menuBar);



}

QSlider *CgQtGui::createSlider()
{
  QSlider *slider = new QSlider(Qt::Vertical);
  slider->setRange(0, 360 * 16);
  slider->setSingleStep(16);
  slider->setPageStep(15 * 16);
  slider->setTickInterval(15 * 16);
  slider->setTickPosition(QSlider::TicksRight);
  return slider;
}

// A3 Tab
void CgQtGui::createOptionPanelA3(QWidget* parent)
{
  QVBoxLayout *a3_control = new QVBoxLayout();
  a3StatusCheckBox = new QCheckBox("enable Aufagbe 3 Ausgabe");
  a3StatusCheckBox->setCheckable(true);
  a3StatusCheckBox->setChecked(false);
  connect(a3StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA3StatusCheckBoxChanged()) );
  a3_control->addWidget(a3StatusCheckBox);


  a3FaceNormalStatusCheckBox = new QCheckBox("enable Aufagbe 3 Face Normales");
  a3FaceNormalStatusCheckBox->setCheckable(true);
  a3FaceNormalStatusCheckBox->setChecked(false);
  connect(a3FaceNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA3FaceNormalStatusCheckBoxChanged()) );
  a3_control->addWidget(a3FaceNormalStatusCheckBox);

  a3VertexNormalStatusCheckBox = new QCheckBox("enable Aufagbe 3 Vertex Normales");
  a3VertexNormalStatusCheckBox->setCheckable(true);
  a3VertexNormalStatusCheckBox->setChecked(false);
  connect(a3VertexNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA3VertexNormalStatusCheckBoxChanged()) );
  a3_control->addWidget(a3VertexNormalStatusCheckBox);

  /*a3StatusCheckBox = new QCheckBox("enable Aufagbe 3 Ausgabe");
  a3StatusCheckBox->setCheckable(true);
  a3StatusCheckBox->setChecked(false);
  connect(a3StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA3StatusCheckBoxChanged()) );
  a3_control->addWidget(a3StatusCheckBox);*/

  /*Example for using a label */

  QLabel *options_label = new QLabel("Options");
  a3_control->addWidget(options_label);
  options_label->setAlignment(Qt::AlignCenter);


  /*Example for using a spinbox

  mySpinBox1 = new QSpinBox();
  a3_control->addWidget(mySpinBox1);
  mySpinBox1->setMinimum(1);
  mySpinBox1->setMaximum(50);
  mySpinBox1->setValue(3);
  // mySpinBox1->setSuffix("   suffix");
  mySpinBox1->setPrefix("Prefix:  ");
  connect(mySpinBox1, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox1Changed()) );
  a3_control->addWidget(mySpinBox1);*/

  /*
  QHBoxLayout *subBox = new QHBoxLayout();
    QGroupBox* myGroupBox = new QGroupBox("Radiobutton Group Example ");

    myButtonGroup = new QButtonGroup(subBox);
    myButtonGroup->setExclusive(true);

    QRadioButton* radiobutton1 = new QRadioButton( "&Option1");
    QRadioButton* radiobutton2 = new QRadioButton( "&Option2");
    QRadioButton* radiobutton3 = new QRadioButton( "&Option3");
    QRadioButton* radiobutton4 = new QRadioButton( "&Option4");
    QRadioButton* radiobutton5 = new QRadioButton( "&Option5");

    radiobutton2->setChecked(true);

    myButtonGroup->addButton(radiobutton1,0);
    myButtonGroup->addButton(radiobutton2,1);
    myButtonGroup->addButton(radiobutton3,2);
    myButtonGroup->addButton(radiobutton4,3);
    myButtonGroup->addButton(radiobutton5,4);


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radiobutton1);
    vbox->addWidget(radiobutton2);
    vbox->addWidget(radiobutton3);
    vbox->addWidget(radiobutton4);
    vbox->addWidget(radiobutton5);
    vbox->addStretch(1);
    myGroupBox->setLayout(vbox);
    subBox->addWidget(myGroupBox);
    a3_control->addLayout(subBox);

    connect(myButtonGroup, SIGNAL( buttonClicked(int) ), this, SLOT( slotButtonGroupSelectionChanged() ) );

*/


  //Farb wahl
  QLabel *farb_label = new QLabel("Farbwahl");
  a3_control->addWidget(farb_label);

  colorSpinBoxredA3 = new QSpinBox();
  a3_control->addWidget(colorSpinBoxredA3);
  colorSpinBoxredA3->setMinimum(0);
  colorSpinBoxredA3->setMaximum(256);
  colorSpinBoxredA3->setValue(128);
  colorSpinBoxredA3->setPrefix("red: ");

  colorSpinBoxgreenA3 = new QSpinBox();
  a3_control->addWidget(colorSpinBoxgreenA3);
  colorSpinBoxgreenA3->setMinimum(0);
  colorSpinBoxgreenA3->setMaximum(256);
  colorSpinBoxgreenA3->setValue(128);
  colorSpinBoxgreenA3->setPrefix("green: ");


  colorSpinBoxblueA3 = new QSpinBox();
  a3_control->addWidget(colorSpinBoxblueA3);
  colorSpinBoxblueA3->setMinimum(0);
  colorSpinBoxblueA3->setMaximum(256);
  colorSpinBoxblueA3->setValue(128);
  colorSpinBoxblueA3->setPrefix("blue: ");

  QPushButton* colorButton = new QPushButton("change Color");
  a3_control->addWidget(colorButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA3()) );

connect(m_glRenderWidget, SIGNAL(viewportChanged(int,int)), this, SLOT(viewportChanged(int,int)));
  // reset Button
  QPushButton* resetButtonA3 = new QPushButton("Reset");
  a3_control->addWidget(resetButtonA3);
  connect(resetButtonA3, SIGNAL( clicked() ), this, SLOT(slotA3Reset()) );



  /*Example for using a checkbox

  myCheckBox1 = new QCheckBox("enable Option 1");
  myCheckBox1->setCheckable(true);
  myCheckBox1->setChecked(false);
  connect(myCheckBox1, SIGNAL( clicked() ), this, SLOT(slotMyCheckBox1Changed()) );
  a3_control->addWidget(myCheckBox1);

  Example for using a button group */

  parent->setLayout(a3_control);

}

// A4
void CgQtGui::createOptionPanelA4(QWidget* parent)
{
  QVBoxLayout *a4_control = new QVBoxLayout();

  a4StatusCheckBox = new QCheckBox("enable Aufagbe 4 Ausgabe");
  a4StatusCheckBox->setCheckable(true);
  a4StatusCheckBox->setChecked(false);
  connect(a4StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA4StatusCheckBoxChanged()) );
  a4_control->addWidget(a4StatusCheckBox);

  a4FaceNormalStatusCheckBox = new QCheckBox("enable Aufagbe 4 Face Normales");
  a4FaceNormalStatusCheckBox->setCheckable(true);
  a4FaceNormalStatusCheckBox->setChecked(false);
  connect(a4FaceNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA4FaceNormalStatusCheckBoxChanged()) );
  a4_control->addWidget(a4FaceNormalStatusCheckBox);

  a4VertexNormalStatusCheckBox = new QCheckBox("enable Aufagbe 4 Vertex Normales");
  a4VertexNormalStatusCheckBox->setCheckable(true);
  a4VertexNormalStatusCheckBox->setChecked(false);
  connect(a4VertexNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA4VertexNormalStatusCheckBoxChanged()) );
  a4_control->addWidget(a4VertexNormalStatusCheckBox);


  /*QPushButton* SmoothingButton = new QPushButton("change Color");
  a4_control->addWidget(SmoothingButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA4()) );
*/

  QLabel *LRA_label = new QLabel("Lane-Risenfeld Unterteilungsalgorthmus");
  a4_control->addWidget(LRA_label);

  a4_LRA_Mittlunsgschritte = new QSpinBox();;
  a4_LRA_Iterationen = new QSpinBox();
  a4_rotation_segmente= new QSpinBox();


  a4_control->addWidget(a4_LRA_Mittlunsgschritte);
  a4_LRA_Mittlunsgschritte->setMinimum(1);
  a4_LRA_Mittlunsgschritte->setMaximum(10);
  a4_LRA_Mittlunsgschritte->setValue(1);
  a4_LRA_Mittlunsgschritte->setPrefix("Mittlungsschritte: ");

  a4_control->addWidget(a4_LRA_Iterationen);
  a4_LRA_Iterationen->setMinimum(1);
  a4_LRA_Iterationen->setMaximum(10);
  a4_LRA_Iterationen->setValue(1);
  a4_LRA_Iterationen->setPrefix("Iterationen: ");

  QPushButton* LRAglatenButtonA4 = new QPushButton("glaeten");
  a4_control->addWidget(LRAglatenButtonA4);
  connect(LRAglatenButtonA4, SIGNAL( clicked() ), this, SLOT(soltA4LRAglaetenButton()) );

  QLabel *rotation_lable = new QLabel("Rotationskörper");
  a4_control->addWidget(rotation_lable);

  a4_control->addWidget(a4_rotation_segmente);
  a4_rotation_segmente->setMinimum(0);
  a4_rotation_segmente->setMaximum(100);
  a4_rotation_segmente->setValue(1);
  a4_rotation_segmente->setPrefix("Rotation Segmente: ");



  QPushButton* rotationButtonA4 = new QPushButton("rotieren");
  a4_control->addWidget(rotationButtonA4);
  connect(rotationButtonA4, SIGNAL( clicked() ), this, SLOT(slotA4RotationButton()) );


  //Farb wahl
  QLabel *farb_label = new QLabel("Farbwahl");
  a4_control->addWidget(farb_label);

  colorSpinBoxredA4 = new QSpinBox();
  a4_control->addWidget(colorSpinBoxredA4);
  colorSpinBoxredA4->setMinimum(0);
  colorSpinBoxredA4->setMaximum(256);
  colorSpinBoxredA4->setValue(128);
  colorSpinBoxredA4->setPrefix("red: ");

  colorSpinBoxgreenA4 = new QSpinBox();
  a4_control->addWidget(colorSpinBoxgreenA4);
  colorSpinBoxgreenA4->setMinimum(0);
  colorSpinBoxgreenA4->setMaximum(256);
  colorSpinBoxgreenA4->setValue(128);
  colorSpinBoxgreenA4->setPrefix("green: ");


  colorSpinBoxblueA4 = new QSpinBox();
  a4_control->addWidget(colorSpinBoxblueA4);
  colorSpinBoxblueA4->setMinimum(0);
  colorSpinBoxblueA4->setMaximum(256);
  colorSpinBoxblueA4->setValue(128);
  colorSpinBoxblueA4->setPrefix("blue: ");

  QPushButton* colorButton = new QPushButton("change Color");
  a4_control->addWidget(colorButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA4()) );


  // reset Button
  QPushButton* resetButtonA4 = new QPushButton("Reset");
  a4_control->addWidget(resetButtonA4);
  connect(resetButtonA4, SIGNAL( clicked() ), this, SLOT(slotA4Reset()) );

  parent->setLayout(a4_control);

}

// A5
void CgQtGui::createOptionPanelA5(QWidget* parent)
{
  QVBoxLayout *a5_control = new QVBoxLayout();
  a5StatusCheckBox = new QCheckBox("enable Aufagbe 5 Ausgabe");
  a5StatusCheckBox->setCheckable(true);
  a5StatusCheckBox->setChecked(false);
  connect(a5StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA5StatusCheckBoxChanged()) );
  a5_control->addWidget(a5StatusCheckBox);

  a5FaceNormalStatusCheckBox = new QCheckBox("enable Aufagbe 5 Face Normales");
  a5FaceNormalStatusCheckBox->setCheckable(true);
  a5FaceNormalStatusCheckBox->setChecked(false);
  connect(a5FaceNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA5FaceNormalStatusCheckBoxChanged()) );
  a5_control->addWidget(a5FaceNormalStatusCheckBox);

  a5VertexNormalStatusCheckBox = new QCheckBox("enable Aufagbe 5 Vertex Normales");
  a5VertexNormalStatusCheckBox->setCheckable(true);
  a5VertexNormalStatusCheckBox->setChecked(false);
  connect(a5VertexNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA5VertexNormalStatusCheckBoxChanged()) );
  a5_control->addWidget(a5VertexNormalStatusCheckBox);

  //Objectauswahl
  QLabel *object_label = new QLabel("Objectauswahl");
  a5_control->addWidget(object_label);

  for (int i = 0; i < external_ObjectNames.size(); ++i) {
      QString test=QString::number(i) +": "+external_ObjectNames[i];
      object_label = new QLabel(test);
        a5_control->addWidget(object_label);
    }

  a5_objectSpinnBox = new QSpinBox();
  a5_control->addWidget(a5_objectSpinnBox);
  a5_objectSpinnBox->setMinimum(0);
  a5_objectSpinnBox->setMaximum(external_ObjectNames.size());
  a5_objectSpinnBox->setValue(4);
  a5_objectSpinnBox->setPrefix("object: ");


    QPushButton* externObjectButton = new QPushButton("init Extern Object");
    a5_control->addWidget(externObjectButton);
    connect(externObjectButton, SIGNAL( clicked() ), this, SLOT(soltA5ExternObjectInit()) );

  //Farb wahl
  QLabel *farb_label = new QLabel("Farbwahl");
  a5_control->addWidget(farb_label);


  colorSpinBoxredA5 = new QSpinBox();
  a5_control->addWidget(colorSpinBoxredA5);
  colorSpinBoxredA5->setMinimum(0);
  colorSpinBoxredA5->setMaximum(256);
  colorSpinBoxredA5->setValue(128);
  colorSpinBoxredA5->setPrefix("red: ");

  colorSpinBoxgreenA5 = new QSpinBox();
  a5_control->addWidget(colorSpinBoxgreenA5);
  colorSpinBoxgreenA5->setMinimum(0);
  colorSpinBoxgreenA5->setMaximum(256);
  colorSpinBoxgreenA5->setValue(128);
  colorSpinBoxgreenA5->setPrefix("green: ");


  colorSpinBoxblueA5 = new QSpinBox();
  a5_control->addWidget(colorSpinBoxblueA5);
  colorSpinBoxblueA5->setMinimum(0);
  colorSpinBoxblueA5->setMaximum(256);
  colorSpinBoxblueA5->setValue(128);
  colorSpinBoxblueA5->setPrefix("blue: ");

  QPushButton* colorButton = new QPushButton("change Color");
  a5_control->addWidget(colorButton);
  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA5()) );


  // reset Button
  QPushButton* resetButtonA5 = new QPushButton("Reset");
  a5_control->addWidget(resetButtonA5);
  connect(resetButtonA5, SIGNAL( clicked() ), this, SLOT(slotA5Reset()) );

  parent->setLayout(a5_control);

}

// A6
void CgQtGui::createOptionPanelA6(QWidget* parent)
{
  QVBoxLayout *a6_control = new QVBoxLayout();
  a6StatusCheckBox = new QCheckBox("enable Aufagbe 6 Ausgabe");
  a6StatusCheckBox->setCheckable(true);
  a6StatusCheckBox->setChecked(false);
  connect(a6StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA6StatusCheckBoxChanged()) );
  a6_control->addWidget(a6StatusCheckBox);

  a6FaceNormalStatusCheckBox = new QCheckBox("enable Aufagbe 6 Face Normales");
  a6FaceNormalStatusCheckBox->setCheckable(true);
  a6FaceNormalStatusCheckBox->setChecked(false);
  connect(a6FaceNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA6FaceNormalStatusCheckBoxChanged()) );
  a6_control->addWidget(a6FaceNormalStatusCheckBox);

  a6VertexNormalStatusCheckBox = new QCheckBox("enable Aufagbe 6 Vertex Normales");
  a6VertexNormalStatusCheckBox->setCheckable(true);
  a6VertexNormalStatusCheckBox->setChecked(false);
  connect(a6VertexNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA6VertexNormalStatusCheckBoxChanged()) );
  a6_control->addWidget(a6VertexNormalStatusCheckBox);

  //Farb wahl
  QLabel *farb_label = new QLabel("Farbwahl");
  a6_control->addWidget(farb_label);

  colorSpinBoxredA6 = new QSpinBox();
  a6_control->addWidget(colorSpinBoxredA6);
  colorSpinBoxredA6->setMinimum(0);
  colorSpinBoxredA6->setMaximum(256);
  colorSpinBoxredA6->setValue(128);
  colorSpinBoxredA6->setPrefix("red: ");

  colorSpinBoxgreenA6 = new QSpinBox();
  a6_control->addWidget(colorSpinBoxgreenA6);
  colorSpinBoxgreenA6->setMinimum(0);
  colorSpinBoxgreenA6->setMaximum(256);
  colorSpinBoxgreenA6->setValue(128);
  colorSpinBoxgreenA6->setPrefix("green: ");


  colorSpinBoxblueA6 = new QSpinBox();
  a6_control->addWidget(colorSpinBoxblueA6);
  colorSpinBoxblueA6->setMinimum(0);
  colorSpinBoxblueA6->setMaximum(256);
  colorSpinBoxblueA6->setValue(128);
  colorSpinBoxblueA6->setPrefix("blue: ");

  QPushButton* colorButton = new QPushButton("change Color");
  a6_control->addWidget(colorButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA6()) );


  // reset Button
  QPushButton* resetButtonA6 = new QPushButton("Reset");
  a6_control->addWidget(resetButtonA6);
  connect(resetButtonA6, SIGNAL( clicked() ), this, SLOT(slotA6Reset()) );


  parent->setLayout(a6_control);

}

// A7
void CgQtGui::createOptionPanelA7(QWidget* parent)
{
  QVBoxLayout *a7_control = new QVBoxLayout();
  a7StatusCheckBox = new QCheckBox("enable Aufagbe 7 Ausgabe");
  a7StatusCheckBox->setCheckable(true);
  a7StatusCheckBox->setChecked(false);
  connect(a7StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA7StatusCheckBoxChanged()) );
  a7_control->addWidget(a7StatusCheckBox);

  a7FaceNormalStatusCheckBox = new QCheckBox("enable Aufagbe 7 Face Normales");
  a7FaceNormalStatusCheckBox->setCheckable(true);
  a7FaceNormalStatusCheckBox->setChecked(false);
  connect(a7FaceNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA7FaceNormalStatusCheckBoxChanged()) );
  a7_control->addWidget(a7FaceNormalStatusCheckBox);

  a7VertexNormalStatusCheckBox = new QCheckBox("enable Aufagbe 7 Vertex Normales");
  a7VertexNormalStatusCheckBox->setCheckable(true);
  a7VertexNormalStatusCheckBox->setChecked(false);
  connect(a7VertexNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA7VertexNormalStatusCheckBoxChanged()) );
  a7_control->addWidget(a7VertexNormalStatusCheckBox);

  //Farb wahl
  QLabel *farb_label = new QLabel("Farbwahl");
  a7_control->addWidget(farb_label);

  colorSpinBoxredA7 = new QSpinBox();
  a7_control->addWidget(colorSpinBoxredA7);
  colorSpinBoxredA7->setMinimum(0);
  colorSpinBoxredA7->setMaximum(256);
  colorSpinBoxredA7->setValue(128);
  colorSpinBoxredA7->setPrefix("red: ");

  colorSpinBoxgreenA7 = new QSpinBox();
  a7_control->addWidget(colorSpinBoxgreenA7);
  colorSpinBoxgreenA7->setMinimum(0);
  colorSpinBoxgreenA7->setMaximum(256);
  colorSpinBoxgreenA7->setValue(128);
  colorSpinBoxgreenA7->setPrefix("green: ");


  colorSpinBoxblueA7 = new QSpinBox();
  a7_control->addWidget(colorSpinBoxblueA7);
  colorSpinBoxblueA7->setMinimum(0);
  colorSpinBoxblueA7->setMaximum(256);
  colorSpinBoxblueA7->setValue(128);
  colorSpinBoxblueA7->setPrefix("blue: ");

  QPushButton* colorButton = new QPushButton("change Color");
  a7_control->addWidget(colorButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA7()) );


  // reset Button
  QPushButton* resetButtonA7 = new QPushButton("Reset");
  a7_control->addWidget(resetButtonA7);
  connect(resetButtonA7, SIGNAL( clicked() ), this, SLOT(slotA7Reset()) );


  parent->setLayout(a7_control);

}

// A8
void CgQtGui::createOptionPanelA8(QWidget* parent)
{
  QVBoxLayout *a8_control = new QVBoxLayout();
  a8StatusCheckBox = new QCheckBox("enable Aufagbe 8 Ausgabe");
  a8StatusCheckBox->setCheckable(true);
  a8StatusCheckBox->setChecked(false);
  connect(a8StatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA8StatusCheckBoxChanged()) );
  a8_control->addWidget(a8StatusCheckBox);

  a8FaceNormalStatusCheckBox = new QCheckBox("enable Aufagbe 8 Face Normales");
  a8FaceNormalStatusCheckBox->setCheckable(true);
  a8FaceNormalStatusCheckBox->setChecked(false);
  connect(a8FaceNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA8FaceNormalStatusCheckBoxChanged()) );
  a8_control->addWidget(a8FaceNormalStatusCheckBox);

  a8VertexNormalStatusCheckBox = new QCheckBox("enable Aufagbe 8 Vertex Normales");
  a8VertexNormalStatusCheckBox->setCheckable(true);
  a8VertexNormalStatusCheckBox->setChecked(false);
  connect(a8VertexNormalStatusCheckBox, SIGNAL( clicked() ), this, SLOT(slotA8VertexNormalStatusCheckBoxChanged()) );
  a8_control->addWidget(a8VertexNormalStatusCheckBox);

  //Farb wahl
  QLabel *farb_label = new QLabel("Farbwahl");
  a8_control->addWidget(farb_label);

  colorSpinBoxredA8 = new QSpinBox();
  a8_control->addWidget(colorSpinBoxredA8);
  colorSpinBoxredA8->setMinimum(0);
  colorSpinBoxredA8->setMaximum(256);
  colorSpinBoxredA8->setValue(128);
  colorSpinBoxredA8->setPrefix("red: ");

  colorSpinBoxgreenA8 = new QSpinBox();
  a8_control->addWidget(colorSpinBoxgreenA8);
  colorSpinBoxgreenA8->setMinimum(0);
  colorSpinBoxgreenA8->setMaximum(256);
  colorSpinBoxgreenA8->setValue(128);
  colorSpinBoxgreenA8->setPrefix("green: ");


  colorSpinBoxblueA8 = new QSpinBox();
  a8_control->addWidget(colorSpinBoxblueA8);
  colorSpinBoxblueA8->setMinimum(0);
  colorSpinBoxblueA8->setMaximum(256);
  colorSpinBoxblueA8->setValue(128);
  colorSpinBoxblueA8->setPrefix("blue: ");

  QPushButton* colorButton = new QPushButton("change Color");
  a8_control->addWidget(colorButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA8()) );


  // reset Button
  QPushButton* resetButtonA8 = new QPushButton("Reset");
  a8_control->addWidget(resetButtonA8);
  connect(resetButtonA8, SIGNAL( clicked() ), this, SLOT(slotA8Reset()) );


  parent->setLayout(a8_control);

}

// Slots

// A3
void CgQtGui::slotA3StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 3 Status changed to "<< a3StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,3,a3StatusCheckBox->checkState());

  notifyObserver(e);
}

void CgQtGui::slotA3FaceNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 3 Face Normal Status changed to "<< a3FaceNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,3,a3FaceNormalStatusCheckBox->checkState(),1);

  notifyObserver(e);
}

void CgQtGui::slotA3VertexNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 3 Vertex Normal Status changed to "<< a3VertexNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,3,a3VertexNormalStatusCheckBox->checkState(),2);

  notifyObserver(e);
}

void CgQtGui::slotChangeColorButtonA3()
{
  int16_t redValue = colorSpinBoxredA3->value();
  int16_t greenValue = colorSpinBoxgreenA3->value();
  int16_t blueValue = colorSpinBoxblueA3->value();
  std::cout << "CgQtGui: " << "Color Changed"<< std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,3,redValue,greenValue,blueValue);

  notifyObserver(e);
}

void CgQtGui::slotA3Reset()
{
  std::cout << "CgQtGui: " << "A3 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,3);
  notifyObserver(e);
}

// A4
void CgQtGui::slotA4StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 4 Status changed to "<< a4StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,4,a4StatusCheckBox->checkState());

  notifyObserver(e);
}

void CgQtGui::slotA4FaceNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 4 Face Normal Status changed to "<< a4FaceNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,4,a4FaceNormalStatusCheckBox->checkState(),1);

  notifyObserver(e);
}

void CgQtGui::slotA4VertexNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 4 Vertex Normal Status changed to "<< a4VertexNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,4,a4VertexNormalStatusCheckBox->checkState(),2);

  notifyObserver(e);
}

void CgQtGui::slotChangeColorButtonA4()
{
  int16_t redValue = colorSpinBoxredA4->value();
  int16_t greenValue = colorSpinBoxgreenA4->value();
  int16_t blueValue = colorSpinBoxblueA4->value();
  std::cout << "CgQtGui: " << "Color Changed"<< std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,4,redValue,greenValue,blueValue);

  notifyObserver(e);
}

void CgQtGui::slotA4Reset()
{
  std::cout << "CgQtGui: " << "A4 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,4);
  notifyObserver(e);
}

void CgQtGui::soltA4LRAglaetenButton()
{
  int iterationen = a4_LRA_Iterationen->value();
  int mittlungsschritte =a4_LRA_Mittlunsgschritte->value();
  std::cout << "CgQtGui: " << "A4 LRA glätten " << std::endl;
  CgBaseEvent* e = new CgLRAglaetenEvent(Cg::LRAglaetenEvent,4,mittlungsschritte,iterationen);
  notifyObserver(e);
}

void CgQtGui::slotA4RotationButton()
{
  int rotation_Segemente = a4_rotation_segmente->value();
  std::cout << "CgQtGui: " << "A4 Rotieren " << std::endl;
  CgBaseEvent* e = new CgRotationEvent(Cg::RotationEvent,4,1,rotation_Segemente);
  notifyObserver(e);
}

// A5
void CgQtGui::slotA5StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 5 Status changed to "<< a5StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,5,a5StatusCheckBox->checkState());

  notifyObserver(e);
}
void CgQtGui::slotA5FaceNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 5 Face Normal Status changed to "<< a5FaceNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,5,a5FaceNormalStatusCheckBox->checkState(),1);

  notifyObserver(e);
}

void CgQtGui::slotA5VertexNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 5 Vertex Normal Status changed to "<< a5VertexNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,5,a5VertexNormalStatusCheckBox->checkState(),2);

  notifyObserver(e);
}

void CgQtGui::slotChangeColorButtonA5()
{
  int16_t redValue = colorSpinBoxredA5->value();
  int16_t greenValue = colorSpinBoxgreenA5->value();
  int16_t blueValue = colorSpinBoxblueA5->value();
  std::cout << "CgQtGui: " << "Color Changed"<< std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,5,redValue,greenValue,blueValue);

  notifyObserver(e);
}

void CgQtGui::slotA5Reset()
{
  std::cout << "CgQtGui: " << "A5 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,5);
  notifyObserver(e);
}

void CgQtGui::soltA5ExternObjectInit()
{
  std::cout << "CgQtGui: " << "A5 Render Extern Object " << external_ObjectNames[a5_objectSpinnBox->value()].toStdString() <<std::endl;
  CgBaseEvent* e = new CgRenderExternObjectEvent(Cg::renderExternObjectEvent,5,external_ObjectNames[a5_objectSpinnBox->value()].toStdString());
  notifyObserver(e);
}

// A6
void CgQtGui::slotA6StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 6 Status changed to "<< a6StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,6,a6StatusCheckBox->checkState());

  notifyObserver(e);
}
void CgQtGui::slotA6FaceNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 6 Face Normal Status changed to "<< a6FaceNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,6,a6FaceNormalStatusCheckBox->checkState(),1);

  notifyObserver(e);
}

void CgQtGui::slotA6VertexNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 6 Vertex Normal Status changed to "<< a6VertexNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,6,a6VertexNormalStatusCheckBox->checkState(),2);

  notifyObserver(e);
}

void CgQtGui::slotChangeColorButtonA6()
{
  int16_t redValue = colorSpinBoxredA6->value();
  int16_t greenValue = colorSpinBoxgreenA6->value();
  int16_t blueValue = colorSpinBoxblueA6->value();
  std::cout << "CgQtGui: " << "Color Changed"<< std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,6,redValue,greenValue,blueValue);

  notifyObserver(e);
}
void CgQtGui::slotA6Reset()
{
  std::cout << "CgQtGui: " << "A6 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,6);
  notifyObserver(e);
}
// A7
void CgQtGui::slotA7StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 7 Status changed to "<< a7StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,7,a7StatusCheckBox->checkState());

  notifyObserver(e);
}
void CgQtGui::slotA7FaceNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 7 Face Normal Status changed to "<< a7FaceNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,7,a7FaceNormalStatusCheckBox->checkState(),1);

  notifyObserver(e);
}

void CgQtGui::slotA7VertexNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 7 Vertex Normal Status changed to "<< a7VertexNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,7,a7VertexNormalStatusCheckBox->checkState(),2);

  notifyObserver(e);
}

void CgQtGui::slotChangeColorButtonA7()
{
  int16_t redValue = colorSpinBoxredA7->value();
  int16_t greenValue = colorSpinBoxgreenA7->value();
  int16_t blueValue = colorSpinBoxblueA7->value();
  std::cout << "CgQtGui: " << "Color Changed"<< std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,7,redValue,greenValue,blueValue);

  notifyObserver(e);
}
void CgQtGui::slotA7Reset()
{
  std::cout << "CgQtGui: " << "A7 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,7);
  notifyObserver(e);
}
// A8
void CgQtGui::slotA8StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 8 Status changed to "<< a8StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,8,a8StatusCheckBox->checkState());

  notifyObserver(e);
}
void CgQtGui::slotA8FaceNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 8 Face Normal Status changed to "<< a8FaceNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,8,a8FaceNormalStatusCheckBox->checkState(),1);

  notifyObserver(e);
}

void CgQtGui::slotA8VertexNormalStatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 8 Vertex Normal Status changed to "<< a8VertexNormalStatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgShowNormalsEvent(Cg::ShowNormalsEvent,8,a8VertexNormalStatusCheckBox->checkState(),2);

  notifyObserver(e);
}

void CgQtGui::slotChangeColorButtonA8()
{
  int16_t redValue = colorSpinBoxredA8->value();
  int16_t greenValue = colorSpinBoxgreenA8->value();
  int16_t blueValue = colorSpinBoxblueA8->value();
  std::cout << "CgQtGui: " << "Color Changed"<< std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,8,redValue,greenValue,blueValue);

  notifyObserver(e);
}
void CgQtGui::slotA8Reset()
{
  std::cout << "CgQtGui: " << "A8 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,8);
  notifyObserver(e);
}

//  Versciedene Slots

void CgQtGui::slotButtonGroupSelectionChanged()
{

}

void CgQtGui::slotMySpinBox1Changed()
{
  /* std::cout << "CgQtGui: " << "spinnbox to " <<mySpinBox1->value() << std::endl;
    CgBaseEvent* e = new CgColorChangeEvent(mySpinBox1->value());

    notifyObserver(e);*/
}

void CgQtGui::slotMyCheckBox1Changed()
{

}



void CgQtGui::slotLoadMeshFile()
{



  QString file=  QFileDialog::getOpenFileName(this, tr("Open Obj-File"),"",tr("Model Files (*.obj)"));


  CgBaseEvent* e = new CgLoadObjFileEvent(Cg::LoadObjFileEvent, file.toStdString());

  notifyObserver(e);
}


void CgQtGui::slotTrackballChanged()
{
  CgBaseEvent* e = new CgTrackballEvent(Cg::CgTrackballEvent, m_glRenderWidget->getTrackballRotation());
  notifyObserver(e);
}

void CgQtGui::slotMyButton1Pressed()
{
  std::cout << "CgQtGui: " << "button 1 pressed " << std::endl;
  CgBaseEvent* e = new CgButtonEvent(Cg::ButtonEvent);
  notifyObserver(e);
}


void CgQtGui::mouseEvent(QMouseEvent* event)
{

  // std::cout << "CgQtGui: " << QApplication::keyboardModifiers() << std::endl;

  //  if(QApplication::keyboardModifiers().testFlag(Qt::ControlModifier)==true)
  //    std::cout << "CgQtGui: " << Cg::ControlModifier << endl;


  if(event->type()==QEvent::MouseButtonPress)
    {


      CgBaseEvent* e = new CgMouseEvent(Cg::CgMouseButtonPress,
                                        glm::vec2(event->localPos().x() ,event->localPos().y()),
                                        (Cg::MouseButtons)event->button());

      notifyObserver(e);
    }

  if(event->type()==QEvent::MouseMove)
    {
      CgBaseEvent* e= new CgMouseEvent(Cg::CgMouseMove,
                                       glm::vec2(event->localPos().x() ,event->localPos().y()),
                                       (Cg::MouseButtons)event->button());
      notifyObserver(e);
    }



}

void CgQtGui::keyPressEvent(QKeyEvent *event)
{
  CgBaseEvent* e= new CgKeyEvent(Cg::CgKeyPressEvent,(Cg::Key)event->key(),(Cg::KeyboardModifiers)event->nativeModifiers(),event->text().toStdString());
  notifyObserver(e);
}


void CgQtGui::viewportChanged(int w, int h)
{
  CgBaseEvent* e = new CgWindowResizeEvent(Cg::WindowResizeEvent,w,h);
  notifyObserver(e);
}




CgBaseRenderer* CgQtGui::getRenderer()
{
  return m_glRenderWidget;
}






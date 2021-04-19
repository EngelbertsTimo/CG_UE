

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

  /*Example for using a label */

  QLabel *options_label = new QLabel("Options");
  a3_control->addWidget(options_label);
  options_label->setAlignment(Qt::AlignCenter);


  /*Example for using a spinbox */

  mySpinBox1 = new QSpinBox();
  a3_control->addWidget(mySpinBox1);
  mySpinBox1->setMinimum(1);
  mySpinBox1->setMaximum(50);
  mySpinBox1->setValue(3);
  // mySpinBox1->setSuffix("   suffix");
  mySpinBox1->setPrefix("Prefix:  ");
  connect(mySpinBox1, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox1Changed()) );
  a3_control->addWidget(mySpinBox1);


  //Farb wahl
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


  // reset Button
  QPushButton* resetButtonA3 = new QPushButton("Reset");
  a3_control->addWidget(resetButtonA3);
  connect(resetButtonA3, SIGNAL( clicked() ), this, SLOT(slotA3Reset()) );



  /*Example for using a checkbox */

  myCheckBox1 = new QCheckBox("enable Option 1");
  myCheckBox1->setCheckable(true);
  myCheckBox1->setChecked(false);
  connect(myCheckBox1, SIGNAL( clicked() ), this, SLOT(slotMyCheckBox1Changed()) );
  a3_control->addWidget(myCheckBox1);

  /*Example for using a button group */
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


  /*QPushButton* SmoothingButton = new QPushButton("change Color");
  a4_control->addWidget(SmoothingButton);

  connect(colorButton, SIGNAL( clicked() ), this, SLOT(slotChangeColorButtonA4()) );
*/




  //Farb wahl
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

  //Farb wahl
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

  //Farb wahl
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

  //Farb wahl
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

  //Farb wahl
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

void CgQtGui::slotChangeColorButtonA3()
{
  int16_t redValue = colorSpinBoxredA3->value();
  int16_t greenValue = colorSpinBoxgreenA3->value();
  int16_t blueValue = colorSpinBoxblueA3->value();
  std::cout << "CgQtGui: " << "colorSpinBoxred value " <<redValue << std::endl;
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
void CgQtGui::slotChangeColorButtonA4()
{
  int16_t redValue = colorSpinBoxredA4->value();
  int16_t greenValue = colorSpinBoxgreenA4->value();
  int16_t blueValue = colorSpinBoxblueA4->value();
  std::cout << "CgQtGui: " << "colorSpinBoxred value " <<redValue << std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,4,redValue,greenValue,blueValue);

  notifyObserver(e);
}
void CgQtGui::slotA4Reset()
{
  std::cout << "CgQtGui: " << "A4 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,4);
  notifyObserver(e);
}
// A5
void CgQtGui::slotA5StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 5 Status changed to "<< a5StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,5,a5StatusCheckBox->checkState());

  notifyObserver(e);
}
void CgQtGui::slotChangeColorButtonA5()
{
  int16_t redValue = colorSpinBoxredA5->value();
  int16_t greenValue = colorSpinBoxgreenA5->value();
  int16_t blueValue = colorSpinBoxblueA5->value();
  std::cout << "CgQtGui: " << "colorSpinBoxred value " <<redValue << std::endl;
  CgBaseEvent* e = new CgColorChangeEvent(Cg::ColorChangeEvent,5,redValue,greenValue,blueValue);

  notifyObserver(e);
}
void CgQtGui::slotA5Reset()
{
  std::cout << "CgQtGui: " << "A5 Reset " << std::endl;
  CgBaseEvent* e = new CgResetEvent(Cg::ResetEvent,5);
  notifyObserver(e);
}
// A6
void CgQtGui::slotA6StatusCheckBoxChanged()
{
  std::cout << "CgQtGui: " << "Aufgabe 6 Status changed to "<< a6StatusCheckBox->checkState() << std::endl;
  CgBaseEvent* e = new CgAufgabenStatusEvent(Cg::AufagbenStatusEvent,6,a6StatusCheckBox->checkState());

  notifyObserver(e);
}
void CgQtGui::slotChangeColorButtonA6()
{
  int16_t redValue = colorSpinBoxredA6->value();
  int16_t greenValue = colorSpinBoxgreenA6->value();
  int16_t blueValue = colorSpinBoxblueA6->value();
  std::cout << "CgQtGui: " << "colorSpinBoxred value " <<redValue << std::endl;
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
void CgQtGui::slotChangeColorButtonA7()
{
  int16_t redValue = colorSpinBoxredA7->value();
  int16_t greenValue = colorSpinBoxgreenA7->value();
  int16_t blueValue = colorSpinBoxblueA7->value();
  std::cout << "CgQtGui: " << "colorSpinBoxred value " <<redValue << std::endl;
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
void CgQtGui::slotChangeColorButtonA8()
{
  int16_t redValue = colorSpinBoxredA8->value();
  int16_t greenValue = colorSpinBoxgreenA8->value();
  int16_t blueValue = colorSpinBoxblueA8->value();
  std::cout << "CgQtGui: " << "colorSpinBoxred value " <<redValue << std::endl;
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






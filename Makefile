#############################################################################
# Makefile for building: CgViewer
# Generated by qmake (3.1) (Qt 5.12.8)
# Project:  CG1Uebung.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile CG1Uebung.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtOpenGL -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = CgViewer1.0.0
DISTDIR = /home/timo/Dokumente/FH/Source/.tmp/CgViewer1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		CgEvents/CgButtonEvent.cpp \
		CgEvents/CgColorChangeEvent.cpp \
		CgQtViewer/CGQtGLRenderWidget.cpp \
		CgQtViewer/CgQtGui.cpp \
		CgBase/CgObservable.cpp \
		CgEvents/CgMouseEvent.cpp \
		CgQtViewer/CgQtMainApplication.cpp \
		CgSceneGraph/CgSceneControl.cpp \
		CgEvents/CgKeyEvent.cpp \
		CgSceneGraph/CgExampleTriangle.cpp \
		CgQtViewer/CgQtGlBufferObject.cpp \
		CgQtViewer/CgTrackball.cpp \
		CgEvents/CgWindowResizeEvent.cpp \
		CgEvents/CgLoadObjFileEvent.cpp \
		CgSceneGraph/cgtricube.cpp \
		CgUtils/ObjLoader.cpp \
		CgEvents/CgTrackballEvent.cpp moc_CgQtGLRenderWidget.cpp \
		moc_CgQtGui.cpp \
		moc_CgQtMainApplication.cpp
OBJECTS       = main.o \
		CgButtonEvent.o \
		CgColorChangeEvent.o \
		CGQtGLRenderWidget.o \
		CgQtGui.o \
		CgObservable.o \
		CgMouseEvent.o \
		CgQtMainApplication.o \
		CgSceneControl.o \
		CgKeyEvent.o \
		CgExampleTriangle.o \
		CgQtGlBufferObject.o \
		CgTrackball.o \
		CgWindowResizeEvent.o \
		CgLoadObjFileEvent.o \
		cgtricube.o \
		ObjLoader.o \
		CgTrackballEvent.o \
		moc_CgQtGLRenderWidget.o \
		moc_CgQtGui.o \
		moc_CgQtMainApplication.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		CG1Uebung.pro CgEvents/CgButtonEvent.h \
		CgEvents/CgColorChangeEvent.h \
		CgQtViewer/CgQtGLRenderWidget.h \
		CgQtViewer/CgQtGui.h \
		CgBase/CgObserver.h \
		CgBase/CgObservable.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h \
		CgEvents/CgMouseEvent.h \
		CgQtViewer/CgQtMainApplication.h \
		CgSceneGraph/CgSceneControl.h \
		CgEvents/CgKeyEvent.h \
		CgBase/CgBaseRenderer.h \
		CgBase/CgBaseRenderableObject.h \
		CgSceneGraph/CgExampleTriangle.h \
		CgBase/CgBasePointCloud.h \
		CgBase/CgBaseTriangleMesh.h \
		CgBase/CgBasePolygonMesh.h \
		CgBase/CgBasePolyline.h \
		CgBase/CgBaseSceneControl.h \
		CgQtViewer/CgQtGlBufferObject.h \
		CgQtViewer/CgTrackball.h \
		CgEvents/CgWindowResizeEvent.h \
		CgEvents/CgLoadObjFileEvent.h \
		CgSceneGraph/cgtricube.h \
		CgUtils/ObjLoader.h \
		CgBase/CgBaseImage.h \
		CgEvents/CgTrackballEvent.h main.cpp \
		CgEvents/CgButtonEvent.cpp \
		CgEvents/CgColorChangeEvent.cpp \
		CgQtViewer/CGQtGLRenderWidget.cpp \
		CgQtViewer/CgQtGui.cpp \
		CgBase/CgObservable.cpp \
		CgEvents/CgMouseEvent.cpp \
		CgQtViewer/CgQtMainApplication.cpp \
		CgSceneGraph/CgSceneControl.cpp \
		CgEvents/CgKeyEvent.cpp \
		CgSceneGraph/CgExampleTriangle.cpp \
		CgQtViewer/CgQtGlBufferObject.cpp \
		CgQtViewer/CgTrackball.cpp \
		CgEvents/CgWindowResizeEvent.cpp \
		CgEvents/CgLoadObjFileEvent.cpp \
		CgSceneGraph/cgtricube.cpp \
		CgUtils/ObjLoader.cpp \
		CgEvents/CgTrackballEvent.cpp
QMAKE_TARGET  = CgViewer
DESTDIR       = 
TARGET        = CgViewer


first: all
####### Build rules

CgViewer:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: CG1Uebung.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		CG1Uebung.pro
	$(QMAKE) -o Makefile CG1Uebung.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
CG1Uebung.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile CG1Uebung.pro

qmake_all: FORCE


all: Makefile CgViewer

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents CgEvents/CgButtonEvent.h CgEvents/CgColorChangeEvent.h CgQtViewer/CgQtGLRenderWidget.h CgQtViewer/CgQtGui.h CgBase/CgObserver.h CgBase/CgObservable.h CgBase/CgBaseEvent.h CgBase/CgEnums.h CgEvents/CgMouseEvent.h CgQtViewer/CgQtMainApplication.h CgSceneGraph/CgSceneControl.h CgEvents/CgKeyEvent.h CgBase/CgBaseRenderer.h CgBase/CgBaseRenderableObject.h CgSceneGraph/CgExampleTriangle.h CgBase/CgBasePointCloud.h CgBase/CgBaseTriangleMesh.h CgBase/CgBasePolygonMesh.h CgBase/CgBasePolyline.h CgBase/CgBaseSceneControl.h CgQtViewer/CgQtGlBufferObject.h CgQtViewer/CgTrackball.h CgEvents/CgWindowResizeEvent.h CgEvents/CgLoadObjFileEvent.h CgSceneGraph/cgtricube.h CgUtils/ObjLoader.h CgBase/CgBaseImage.h CgEvents/CgTrackballEvent.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp CgEvents/CgButtonEvent.cpp CgEvents/CgColorChangeEvent.cpp CgQtViewer/CGQtGLRenderWidget.cpp CgQtViewer/CgQtGui.cpp CgBase/CgObservable.cpp CgEvents/CgMouseEvent.cpp CgQtViewer/CgQtMainApplication.cpp CgSceneGraph/CgSceneControl.cpp CgEvents/CgKeyEvent.cpp CgSceneGraph/CgExampleTriangle.cpp CgQtViewer/CgQtGlBufferObject.cpp CgQtViewer/CgTrackball.cpp CgEvents/CgWindowResizeEvent.cpp CgEvents/CgLoadObjFileEvent.cpp CgSceneGraph/cgtricube.cpp CgUtils/ObjLoader.cpp CgEvents/CgTrackballEvent.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -std=c++11 -O2 -std=gnu++11 -Wall -W -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_CgQtGLRenderWidget.cpp moc_CgQtGui.cpp moc_CgQtMainApplication.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CgQtGLRenderWidget.cpp moc_CgQtGui.cpp moc_CgQtMainApplication.cpp
moc_CgQtGLRenderWidget.cpp: CgQtViewer/CgQtGLRenderWidget.h \
		CgBase/CgBaseRenderer.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/timo/Dokumente/FH/Source/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/timo/Dokumente/FH/Source -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include CgQtViewer/CgQtGLRenderWidget.h -o moc_CgQtGLRenderWidget.cpp

moc_CgQtGui.cpp: CgQtViewer/CgQtGui.h \
		CgBase/CgObservable.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/timo/Dokumente/FH/Source/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/timo/Dokumente/FH/Source -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include CgQtViewer/CgQtGui.h -o moc_CgQtGui.cpp

moc_CgQtMainApplication.cpp: CgQtViewer/CgQtMainApplication.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/timo/Dokumente/FH/Source/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/timo/Dokumente/FH/Source -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include CgQtViewer/CgQtMainApplication.h -o moc_CgQtMainApplication.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

main.o: main.cpp CgQtViewer/CgQtMainApplication.h \
		CgQtViewer/CgQtGLRenderWidget.h \
		CgBase/CgBaseRenderer.h \
		CgQtViewer/CgQtGui.h \
		CgBase/CgObservable.h \
		CgSceneGraph/CgSceneControl.h \
		CgBase/CgObserver.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h \
		CgBase/CgBaseSceneControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

CgButtonEvent.o: CgEvents/CgButtonEvent.cpp CgEvents/CgButtonEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgButtonEvent.o CgEvents/CgButtonEvent.cpp

CgColorChangeEvent.o: CgEvents/CgColorChangeEvent.cpp CgEvents/CgColorChangeEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgColorChangeEvent.o CgEvents/CgColorChangeEvent.cpp

CGQtGLRenderWidget.o: CgQtViewer/CGQtGLRenderWidget.cpp CgQtViewer/CgQtGLRenderWidget.h \
		CgBase/CgBaseRenderer.h \
		CgQtViewer/CgQtGlBufferObject.h \
		CgBase/CgBasePolyline.h \
		CgBase/CgBaseRenderableObject.h \
		CgBase/CgEnums.h \
		CgBase/CgBasePolygonMesh.h \
		CgBase/CgBaseImage.h \
		CgBase/CgBaseSceneControl.h \
		CgQtViewer/CgTrackball.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CGQtGLRenderWidget.o CgQtViewer/CGQtGLRenderWidget.cpp

CgQtGui.o: CgQtViewer/CgQtGui.cpp CgQtViewer/CgQtGLRenderWidget.h \
		CgBase/CgBaseRenderer.h \
		CgQtViewer/CgQtGui.h \
		CgBase/CgObservable.h \
		CgQtViewer/CgQtMainApplication.h \
		CgBase/CgEnums.h \
		CgEvents/CgMouseEvent.h \
		CgBase/CgBaseEvent.h \
		CgEvents/CgKeyEvent.h \
		CgEvents/CgWindowResizeEvent.h \
		CgEvents/CgLoadObjFileEvent.h \
		CgEvents/CgTrackballEvent.h \
		CgEvents/CgColorChangeEvent.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgQtGui.o CgQtViewer/CgQtGui.cpp

CgObservable.o: CgBase/CgObservable.cpp CgBase/CgObservable.h \
		CgBase/CgObserver.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgObservable.o CgBase/CgObservable.cpp

CgMouseEvent.o: CgEvents/CgMouseEvent.cpp CgEvents/CgMouseEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgMouseEvent.o CgEvents/CgMouseEvent.cpp

CgQtMainApplication.o: CgQtViewer/CgQtMainApplication.cpp CgQtViewer/CgQtMainApplication.h \
		CgQtViewer/CgQtGui.h \
		CgBase/CgObservable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgQtMainApplication.o CgQtViewer/CgQtMainApplication.cpp

CgSceneControl.o: CgSceneGraph/CgSceneControl.cpp CgSceneGraph/CgSceneControl.h \
		CgBase/CgObserver.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h \
		CgBase/CgBaseSceneControl.h \
		CgEvents/CgMouseEvent.h \
		CgEvents/CgKeyEvent.h \
		CgEvents/CgWindowResizeEvent.h \
		CgEvents/CgLoadObjFileEvent.h \
		CgEvents/CgTrackballEvent.h \
		CgEvents/CgColorChangeEvent.h \
		CgBase/CgBaseRenderer.h \
		CgSceneGraph/CgExampleTriangle.h \
		CgBase/CgBaseTriangleMesh.h \
		CgBase/CgBaseRenderableObject.h \
		CgSceneGraph/cgtricube.h \
		CgUtils/ObjLoader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgSceneControl.o CgSceneGraph/CgSceneControl.cpp

CgKeyEvent.o: CgEvents/CgKeyEvent.cpp CgEvents/CgKeyEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgKeyEvent.o CgEvents/CgKeyEvent.cpp

CgExampleTriangle.o: CgSceneGraph/CgExampleTriangle.cpp CgSceneGraph/CgExampleTriangle.h \
		CgBase/CgBaseTriangleMesh.h \
		CgBase/CgBaseRenderableObject.h \
		CgBase/CgEnums.h \
		CgUtils/ObjLoader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgExampleTriangle.o CgSceneGraph/CgExampleTriangle.cpp

CgQtGlBufferObject.o: CgQtViewer/CgQtGlBufferObject.cpp CgQtViewer/CgQtGlBufferObject.h \
		CgBase/CgBasePolyline.h \
		CgBase/CgBaseRenderableObject.h \
		CgBase/CgEnums.h \
		CgBase/CgBasePolygonMesh.h \
		CgBase/CgBaseTriangleMesh.h \
		CgBase/CgBasePointCloud.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgQtGlBufferObject.o CgQtViewer/CgQtGlBufferObject.cpp

CgTrackball.o: CgQtViewer/CgTrackball.cpp CgQtViewer/CgTrackball.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgTrackball.o CgQtViewer/CgTrackball.cpp

CgWindowResizeEvent.o: CgEvents/CgWindowResizeEvent.cpp CgEvents/CgWindowResizeEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgWindowResizeEvent.o CgEvents/CgWindowResizeEvent.cpp

CgLoadObjFileEvent.o: CgEvents/CgLoadObjFileEvent.cpp CgEvents/CgLoadObjFileEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgLoadObjFileEvent.o CgEvents/CgLoadObjFileEvent.cpp

cgtricube.o: CgSceneGraph/cgtricube.cpp CgSceneGraph/cgtricube.h \
		CgBase/CgBaseTriangleMesh.h \
		CgBase/CgBaseRenderableObject.h \
		CgBase/CgEnums.h \
		CgUtils/ObjLoader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cgtricube.o CgSceneGraph/cgtricube.cpp

ObjLoader.o: CgUtils/ObjLoader.cpp CgUtils/ObjLoader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ObjLoader.o CgUtils/ObjLoader.cpp

CgTrackballEvent.o: CgEvents/CgTrackballEvent.cpp CgEvents/CgTrackballEvent.h \
		CgBase/CgBaseEvent.h \
		CgBase/CgEnums.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CgTrackballEvent.o CgEvents/CgTrackballEvent.cpp

moc_CgQtGLRenderWidget.o: moc_CgQtGLRenderWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CgQtGLRenderWidget.o moc_CgQtGLRenderWidget.cpp

moc_CgQtGui.o: moc_CgQtGui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CgQtGui.o moc_CgQtGui.cpp

moc_CgQtMainApplication.o: moc_CgQtMainApplication.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CgQtMainApplication.o moc_CgQtMainApplication.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:


QT       += core gui opengl widgets
TEMPLATE = app
TARGET = CgViewer
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

SOURCES += main.cpp \
    CgEvents/CgAufgabenStatusEvent.cpp \
    CgEvents/CgButtonEvent.cpp \
    CgEvents/CgColorChangeEvent.cpp \
    CgEvents/CgLRAglaetenEvent.cpp \
    CgEvents/CgRenderExternObjectEvent.cpp \
    CgEvents/CgResetEvent.cpp \
    CgEvents/CgRotationEvent.cpp \
    CgEvents/CgShowNormalsEvent.cpp \
    CgQtViewer/CGQtGLRenderWidget.cpp \
    CgQtViewer/CgQtGui.cpp \
    CgBase/CgObservable.cpp \
    CgEvents/CgMouseEvent.cpp \
    CgQtViewer/CgQtMainApplication.cpp \
    CgSceneGraph/CgExternObjectBody.cpp \
    CgSceneGraph/CgPolyline.cpp \
    CgSceneGraph/CgRotationBody.cpp \
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

HEADERS += \
    CgEvents/CgAufgabenStatusEvent.h \
    CgEvents/CgButtonEvent.h \
    CgEvents/CgColorChangeEvent.h \
    CgEvents/CgLRAglaetenEvent.h \
    CgEvents/CgRenderExternObjectEvent.h \
    CgEvents/CgResetEvent.h \
    CgEvents/CgRotationEvent.h \
    CgEvents/CgShowNormalsEvent.h \
    CgQtViewer/CgQtGLRenderWidget.h \
    CgQtViewer/CgQtGui.h \
    CgBase/CgObserver.h \
    CgBase/CgObservable.h \
    CgBase/CgBaseEvent.h \
    CgBase/CgEnums.h \
    CgEvents/CgMouseEvent.h \
    CgQtViewer/CgQtMainApplication.h \
    CgSceneGraph/CgExternObjectBody.h \
    CgSceneGraph/CgPolyline.h \
    CgSceneGraph/CgRotationBody.h \
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
    CgEvents/CgTrackballEvent.h


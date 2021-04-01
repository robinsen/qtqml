TEMPLATE = app

QT += qml quick core gui network charts
CONFIG += c++11

RESOURCES += qml.qrc

INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/lib
INCLUDEPATH += $$PWD/src/views
INCLUDEPATH += $$PWD/src/control

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/qml
# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/globaldefine.h \
    src/registermetatype.h \
    src/lib/resourcemanager.h \
    src/lib/uithememanager.h \
#    src/lib/log.h \
#    src/lib/singlethread.h \
    src/iexport.h \
    src/control/equimentmanager.h \
    src/views/allview.h \
    src/views/dataview.h \
    src/views/malfunctionview.h \
    src/views/manualview.h \
    src/views/powerview.h \
    src/views/reportview.h \
    src/views/settingview.h \
    src/views/singleview.h \
    src/views/statusview.h \
    src/views/warningview.h \
    src/views/realtimeview.h \
    src/model/maintoolmodel.h

SOURCES += main.cpp \
    src/registermetatype.cpp \
    src/lib/resourcemanager.cpp \
    src/lib/uithememanager.cpp \
#    src/lib/singlethread.cpp \
#    src/lib/log.cpp \
    src/iexport.cpp \
    src/control/equimentmanager.cpp \
    src/views/allview.cpp \
    src/views/dataview.cpp \
    src/views/malfunctionview.cpp \
    src/views/manualview.cpp \
    src/views/powerview.cpp \
    src/views/reportview.cpp \
    src/views/settingview.cpp \
    src/views/singleview.cpp \
    src/views/statusview.cpp \
    src/views/warningview.cpp \
    src/views/realtimeview.cpp \
    src/model/maintoolmodel.cpp

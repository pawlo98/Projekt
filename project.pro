QT       += core gui
QT       += sql
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

BASE_DIR = $$PWD
DEFINES += ROOT_DIR="\"C:/Users/kamil/Desktop/proejkt_ice/project\""

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$BASE_DIR\curl\include\
LIBS += -L$$BASE_DIR\curl\lib\ -l:libcurl.a
LIBS += -L$$BASE_DIR\curl\lib\ -l:libcurl.dll.a

message("Include path: $$BASE_DIR")





SOURCES += \
    curlmain.cpp \
    databasemain.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbuttton.cpp \
    optionlabel.cpp

HEADERS += \
    curlmain.h \
    databasemain.h \
    json/json.hpp \
    mainwindow.h \
    mypushbutton.h \
    optionlabel.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

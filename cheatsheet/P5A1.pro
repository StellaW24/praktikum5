TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    print.cpp \
    movecontrol.cpp \
    check.cpp

HEADERS += \
    print.h \
    datatypes.h \
    movecontrol.h \
    check.h

DISTFILES += \
    a2.qmodel

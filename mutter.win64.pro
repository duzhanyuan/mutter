#-------------------------------------------------
#
# Project created by QtCreator 2015-09-14T21:58:58
#
#-------------------------------------------------

QT       += core gui
QT += webenginewidgets webchannel websockets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mutter
TEMPLATE = app


SOURCES += main.cpp\
    application.cpp

HEADERS  += \
    application.h \
    debugger.h

RESOURCES += \
    resource.qrc

DISTFILES += \
    depends.txt

copydata.commands = $(COPY_DIR) $$PWD/html $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

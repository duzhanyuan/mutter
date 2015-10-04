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
    view.h \
    application.h

# includes for the libappindicator
# /usr/lib/x86_64-linux-gnu libglib-2.0.a

INCLUDEPATH += "/usr/include/libappindicator-0.1"
INCLUDEPATH += "/usr/include/gtk-2.0"
INCLUDEPATH += "/usr/include/glib-2.0"
INCLUDEPATH += "/usr/lib/x86_64-linux-gnu/glib-2.0/include"
INCLUDEPATH += "/usr/include/cairo"
INCLUDEPATH += "/usr/include/pango-1.0"
INCLUDEPATH += "/usr/lib/x86_64-linux-gnu/gtk-2.0/include"
INCLUDEPATH += "/usr/include/gdk-pixbuf-2.0"
INCLUDEPATH += "/usr/include/atk-1.0"

#LIBS += -L/usr/lib/x86_64-linux-gnu -lgobject-2.0
#LIBS += -L/usr/lib/x86_64-linux-gnu -lappindicator
#LIBS += -L/usr/lib/x86_64-linux-gnu -lgtk-x11-2.0

#These seem to not be needed
#LIBS += -L/usr/lib/x86_64-linux-gnu -lcairo
#LIBS += -L/usr/lib/x86_64-linux-gnu -lpango-1.0
#LIBS += -L/usr/lib/x86_64-linux-gnu -lglib-2.0

# end incudes for libappindicator


#FORMS    += dialog.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    depends.txt

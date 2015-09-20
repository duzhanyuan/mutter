//#include "dialog.h"
#include "application.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
    Application app;
    app.show();
    return a.exec();
}

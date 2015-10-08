#ifndef DEBUGGER
#define DEBUGGER
#include <QString>
#include <QDateTime>
#include <stdio.h>
#include <string>

void debug(const char *message) {
#ifdef QT_DEBUG
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss:zzz");
    std::cout <<"[" << dateString.toUtf8().constData() << "] " << message << std::endl;
#endif
}

#endif // DEBUGGER


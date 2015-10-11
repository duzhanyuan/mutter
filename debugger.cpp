#include "debugger.h"

void Console::cliDebug(const char *message) {
#ifdef QT_DEBUG
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss:zzz");
    std::cout <<"[" << dateString.toUtf8().constData() << "] " << message << std::endl;
#endif
}

void Console::javaScriptDebug(QWebEnginePage::JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID) {
#ifdef QT_DEBUG
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateString = dateTime.toString("yyyy-MM-dd hh:mm:ss:zzz");
    std::cout << "[" << dateString.toUtf8().constData() << "] line: " << lineNumber << " " << message.toUtf8().data() << std::endl;
#endif
}

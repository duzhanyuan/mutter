#ifndef DEBUGGER_H
#define DEBUGGER_H
#include <QString>
#include <QDateTime>
#include <QWebEnginePage>
#include <iostream>
#include <stdio.h>
#include <string>

class Console {
public:
    static void cliDebug(const char *message);
    static void javaScriptDebug(QWebEnginePage::JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID);
};
#endif // DEBUGGER


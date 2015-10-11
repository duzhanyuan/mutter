#ifndef APPLICATION
#define APPLICATION
#include "webpage.h"
#include "debugger.h"

#include <QtWidgets>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <QtWebChannel/QtWebChannel>
#include <QtWebSockets/QtWebSockets>
#include <QtWidgets>
#include <QWebEngineView>

#include <QString>
#include <stdio.h>
#include <string>
#include <iostream>



class Application : public QMainWindow
{
    Q_OBJECT
public:
    Application();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
 void appShowTalky();
 void appShowTest();
 void appShowLocalApp();
 void titleChanged(QString);
 void windowCloseRequested();
 void appExit();
 void featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature);
 void featurePermissionRequested(QUrl,QWebEnginePage::Feature);
private:
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QWebEngineView *view;
    bool blockExit;
    WebPage *page;
};

#endif // APPLICATION


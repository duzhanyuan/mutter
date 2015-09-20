#include <QtWidgets>
#include <QWebEngineView>
#include "application.h"
Application::Application() {
    this->setWindowIcon(QIcon(":/images/mutter64.svg"));

    view = new QWebEngineView();
    view->settings()->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);
    view->load(QUrl("http://www.google.co.uk"));

    this->setCentralWidget(view);

    QAction *actionFriends = new QAction("Friends", trayMenu);
    QAction *actionExit = new QAction("Exit", trayMenu);

    trayMenu = new QMenu(this);
    trayMenu->addAction(actionFriends);
    trayMenu->addAction(actionExit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/mutter64.png"));
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    blockExit = true;

    connect(actionFriends, SIGNAL(triggered()), this, SLOT(appFriends()));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(appExit()));
}

void Application::closeEvent(QCloseEvent *event) {
    if (blockExit) {
        this->hide();
        event->ignore();
    } else {
        event->accept();
    }
}

void Application::appFriends() {
    this->show();
}

void Application::appExit() {
    blockExit = false;
    exit(0);
}

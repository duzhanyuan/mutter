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

    view->load(QUrl("https://test.webrtc.org/"));
//    view->load(QUrl("https://talky.io/under-a-rough-forest"));

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
    //
    connect(view->page(), SIGNAL(featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature)), this, SLOT(featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature)));
    connect(view->page(), SIGNAL(featurePermissionRequested(QUrl,QWebEnginePage::Feature)), this, SLOT(featurePermissionRequested(QUrl,QWebEnginePage::Feature)));
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

void Application::featurePermissionRequestCanceled(QUrl url, QWebEnginePage::Feature feature) {
    view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
}

void Application::featurePermissionRequested(QUrl url, QWebEnginePage::Feature feature) {
    view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
//    feature::setFeaturePermission()
}

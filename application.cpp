#include <QtWidgets>
#include <QWebEngineView>
#include <QString>
#include <stdio.h>
#include <string>
#include <iostream>
#include "application.h"
#include "debugger.h"
Application::Application() {
    this->setWindowIcon(QIcon(":/images/mutter64.svg"));

    view = new QWebEngineView();
    this->setCentralWidget(view);
    view->settings()->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);
    view->load(QUrl("https://test.webrtc.org/"));

    trayMenu = new QMenu(this);

    QAction *actionShowTalky = new QAction("Show Talky", trayMenu);
    QAction *actionShowTest = new QAction("Show Troubleshooter", trayMenu);
    QAction *actionShowLocalApp = new QAction("Show Local App", trayMenu);
    QAction *actionExit = new QAction("Exit", trayMenu);

    trayMenu->addAction(actionShowTalky);
    trayMenu->addAction(actionShowTest);
    trayMenu->addAction(actionShowLocalApp);
    trayMenu->addAction(actionExit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/mutter64.png"));
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    blockExit = true;

    connect(actionShowTalky, SIGNAL(triggered()), this, SLOT(appShowTalky()));
    connect(actionShowTest, SIGNAL(triggered()), this, SLOT(appShowTest()));
    connect(actionShowLocalApp, SIGNAL(triggered()), this, SLOT(appShowLocalApp()));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(appExit()));
    connect(view->page(), SIGNAL(featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature)), this, SLOT(featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature)));
    connect(view->page(), SIGNAL(featurePermissionRequested(QUrl,QWebEnginePage::Feature)), this, SLOT(featurePermissionRequested(QUrl,QWebEnginePage::Feature)));

    debug("Application::Application()");
}

void Application::closeEvent(QCloseEvent *event) {
    if (blockExit) {
        this->hide();
        event->ignore();
    } else {
        event->accept();
    }
}

void Application::appShowTalky() {
    view->load(QUrl("https://talky.io/"));
    this->show();
}

void Application::appShowTest() {
    view->load(QUrl("https://test.webrtc.org/"));
    this->show();
}

void Application::appShowLocalApp() {
    view->load(QUrl::fromLocalFile(QFileInfo("html/main-screen.html").absoluteFilePath()));
    this->show();
}

void Application::appExit() {
    blockExit = false;
    this->close();
    exit(0);
}

void Application::featurePermissionRequestCanceled(QUrl url, QWebEnginePage::Feature feature) {
    view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
}

void Application::featurePermissionRequested(QUrl url, QWebEnginePage::Feature feature) {
    switch(feature) {
    case QWebEnginePage::Geolocation:
        debug("featurePermissionRequested(url, Geolocation, PermissionDeniedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionDeniedByUser);
        break;
    case QWebEnginePage::MediaAudioCapture:
        debug("featurePermissionRequested(url, MediaAudioCapture, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::MediaAudioVideoCapture:
        debug("featurePermissionRequested(url, MediaAudioVideoCapture, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::MediaVideoCapture:
        debug("featurePermissionRequested(url, MediaVideoCapture, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::MouseLock:
        debug("featurePermissionRequested(url, MouseLock, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::Notifications:
        debug("featurePermissionRequested(url, Notifications, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    }
}

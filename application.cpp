
#include "application.h"

Application::Application() {
    this->setWindowIcon(QIcon(":/images/mutter64.svg"));

    view = new QWebEngineView();
    this->setCentralWidget(view);
    view->settings()->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);

//    page = (WebPage) view->page();
    page = new WebPage();
    view->setPage(page);

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
    connect(page, SIGNAL(featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature)), this, SLOT(featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature)));
    connect(page, SIGNAL(featurePermissionRequested(QUrl,QWebEnginePage::Feature)), this, SLOT(featurePermissionRequested(QUrl,QWebEnginePage::Feature)));
//    connect(page, SIGNAL(page->javaScriptConsoleMessage();))
    connect(page, SIGNAL(windowCloseRequested()), this, SLOT(windowCloseRequested()));
    connect(page, SIGNAL(titleChanged(QString)), this, SLOT(titleChanged(QString)));
    Console::cliDebug("Application::Application()");
    appShowLocalApp();
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

void Application::titleChanged(QString title) {
    this->setWindowTitle(title);
}

void Application::windowCloseRequested() {
    appExit();
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
        Console::cliDebug("featurePermissionRequested(url, Geolocation, PermissionDeniedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionDeniedByUser);
        break;
    case QWebEnginePage::MediaAudioCapture:
        Console::cliDebug("featurePermissionRequested(url, MediaAudioCapture, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::MediaAudioVideoCapture:
        Console::cliDebug("featurePermissionRequested(url, MediaAudioVideoCapture, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::MediaVideoCapture:
        Console::cliDebug("featurePermissionRequested(url, MediaVideoCapture, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::MouseLock:
        Console::cliDebug("featurePermissionRequested(url, MouseLock, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    case QWebEnginePage::Notifications:
        Console::cliDebug("featurePermissionRequested(url, Notifications, PermissionGrantedByUser)");
        view->page()->setFeaturePermission(url, feature, QWebEnginePage::PermissionGrantedByUser);
        break;
    }
}

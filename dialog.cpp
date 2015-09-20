#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/mutter64.svg"));

    view = new QWebEngineView(parent);
    view->settings()->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);


    trayMenu = new QMenu(this);

    QAction *actionFriends = new QAction("Friends", trayMenu);
    QAction *actionExit = new QAction("Exit", trayMenu);

    trayMenu->addAction(actionFriends);
    trayMenu->addAction(actionExit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/mutter64.png"));
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    connect(actionFriends, SIGNAL(triggered()), this, SLOT(appFriends()));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(appExit()));
//    view->load(QUrl("https://talky.io/beside-a-fragrant-waterfall"));
    view->load(QUrl("http://www.google.co.uk"));
    this->show();
    this->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::appFriends() {
    view->show();
}


void Dialog::appExit() {
    exit(0);
}

void Dialog::closeEvent(QCloseEvent *event) {
 event->ignore();
}

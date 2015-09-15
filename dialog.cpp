#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/mutter64.svg"));


    trayMenu = new QMenu(this);

    QAction *actionExit = new QAction("Exit", trayMenu);
    trayMenu->addAction(actionExit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/mutter64.png"));
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();
//    trayIcon->showMessage("Well...", "Here I should be I guess?");

    connect(actionExit, SIGNAL(triggered()), this, SLOT(appExit()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::appExit() {
//    qDebug() << "Core::appExit called";
    exit(0);
}

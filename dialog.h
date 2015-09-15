#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
//#include "ubuntu_indicator.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
private:
    Ui::Dialog *ui;
public slots:
    void appExit();

};

#endif // DIALOG_H

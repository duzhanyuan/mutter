#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QtWebEngineWidgets>
#include <QtWebChannel/QtWebChannel>
#include <QtWebSockets/QtWebSockets>

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
    QWebEngineView *view;
private:
    Ui::Dialog *ui;
public slots:
    void appFriends();
    void appExit();
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H

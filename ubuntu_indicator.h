#ifndef UBUNTU_INDICATOR_H
#define UBUNTU_INDICATOR_H
#include <QApplication>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>

// http://stackoverflow.com/questions/17193307/qt-systray-icon-appears-next-to-launcher-on-ubuntu-instead-of-on-the-panel
// requires libappindicator-dev
// sudo apt-get install libappindicator-dev
// installs the headers in: /usr/include/libappindicator-0.1/libappindicator

#undef signals
extern "C" {
  #include <libappindicator/app-indicator.h>
  #include <gtk/gtk.h>

  void quitIndicator(GtkMenu *, gpointer);

}
#define signals public

void quitIndicator(GtkMenu *menu, gpointer data) {
  Q_UNUSED(menu);
  QApplication *self = static_cast<QApplication *>(data);

  self->quit();
}

void ShowUnityAppIndicator()
{
    AppIndicator *indicator;
    GtkWidget *menu, *item;

    menu = gtk_menu_new();

    item = gtk_menu_item_new_with_label("Quit");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
    g_signal_connect(item, "activate",
                 G_CALLBACK(quitIndicator), qApp);  // We cannot connect
                 // gtk signal and qt slot so we need to create proxy
                 // function later on, we pass qApp pointer as an argument.
                 // This is useful when we need to call signals on "this"
                 //object so external function can access current object
    gtk_widget_show(item);

    indicator = app_indicator_new(
    "unique-application-name",
        "indicator-messages",
      APP_INDICATOR_CATEGORY_APPLICATION_STATUS
    );

    app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);
    app_indicator_set_menu(indicator, GTK_MENU(menu));
}



void ShowQtSysTray(QApplication* app, QDialog* dialog)
{

    Q_INIT_RESOURCE(resources);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
    }
    QApplication::setQuitOnLastWindowClosed(false);


    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(dialog);
    QAction* Action = new QAction("hello", dialog);
    QMenu* trayIconMenu = new QMenu(dialog);

    trayIconMenu->addAction("Quit", app, SLOT(quit()));

    trayIconMenu->addAction(Action);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon (":/icons/Icons/accept.png"));

    trayIcon->show();
    trayIcon->showMessage("Title","Message");
}
#endif // UBUNTU_INDICATOR_H

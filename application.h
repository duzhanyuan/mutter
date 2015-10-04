#ifndef APPLICATION
#define APPLICATION
#include <QtWidgets>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QtWebEngineWidgets>
#include <QtWebChannel/QtWebChannel>
#include <QtWebSockets/QtWebSockets>

class Application : public QMainWindow
{
    Q_OBJECT
public:
    Application();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
 void appFriends();
 void appExit();
 void featurePermissionRequestCanceled(QUrl,QWebEnginePage::Feature);
 void featurePermissionRequested(QUrl,QWebEnginePage::Feature);
private:
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QWebEngineView *view;
    bool blockExit;
};

#endif // APPLICATION


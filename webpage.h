#ifndef WEBPAGE_H
#define WEBPAGE_H
#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <QtWebChannel/QtWebChannel>
#include <QtWebSockets/QtWebSockets>


class WebPage : public QWebEnginePage
{
public:
    WebPage();

signals:

public slots:

    // QObject interface
public:
    bool event(QEvent *);
    bool eventFilter(QObject *, QEvent *);

protected:
    void timerEvent(QTimerEvent *);
    void childEvent(QChildEvent *);
    void customEvent(QEvent *);
    void connectNotify(const QMetaMethod &signal);
    void disconnectNotify(const QMetaMethod &signal);

    // QWebEnginePage interface
public:
    void triggerAction(WebAction action, bool checked);

protected:
    QWebEnginePage *createWindow(WebWindowType type);
    QStringList chooseFiles(FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes);
    void javaScriptAlert(const QUrl &securityOrigin, const QString &msg);
    bool javaScriptConfirm(const QUrl &securityOrigin, const QString &msg);
    bool javaScriptPrompt(const QUrl &securityOrigin, const QString &msg, const QString &defaultValue, QString *result);
    void javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID);
    bool certificateError(const QWebEngineCertificateError &certificateError);
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame);
};

#endif // WEBPAGE_H

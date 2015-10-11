#include "webpage.h"
#include "debugger.h"

WebPage::WebPage()
{

}

 // QObject interface
bool WebPage::event(QEvent *event) {
    return QWebEnginePage::event(event);
}

bool WebPage::eventFilter(QObject *object, QEvent *event) {
    return QWebEnginePage::eventFilter(object, event);
}

void WebPage::timerEvent(QTimerEvent *timerEvent) {
    QWebEnginePage::timerEvent(timerEvent);
}

void WebPage::childEvent(QChildEvent *timerEvent) {
    QWebEnginePage::childEvent(timerEvent);
}

void WebPage::customEvent(QEvent *event) {
    QWebEnginePage::customEvent(event);
}

void WebPage::connectNotify(const QMetaMethod &signal) {
    QWebEnginePage::connectNotify(signal);
}

void WebPage::disconnectNotify(const QMetaMethod &signal) {
    QWebEnginePage::disconnectNotify(signal);
}

// QWebEnginePage interface
void WebPage::triggerAction(WebAction action, bool checked) {
    QWebEnginePage::triggerAction(action, checked);
}

QWebEnginePage *WebPage::createWindow(WebWindowType type) {
    return QWebEnginePage::createWindow(type);
}

QStringList WebPage::chooseFiles(FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes) {
    return QWebEnginePage::chooseFiles(mode, oldFiles, acceptedMimeTypes);
}

void WebPage::javaScriptAlert(const QUrl &securityOrigin, const QString &msg) {
    return QWebEnginePage::javaScriptAlert(securityOrigin, msg);
}

bool WebPage::javaScriptConfirm(const QUrl &securityOrigin, const QString &msg) {

    return QWebEnginePage::javaScriptConfirm(securityOrigin, msg);
}

bool WebPage::javaScriptPrompt(const QUrl &securityOrigin, const QString &msg, const QString &defaultValue, QString *result) {
     return QWebEnginePage::javaScriptPrompt(securityOrigin, msg, defaultValue, result);
}

void WebPage::javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID) {
    Console::javaScriptDebug(level, message, lineNumber, sourceID);
}

bool WebPage::certificateError(const QWebEngineCertificateError &certificateError) {
    return QWebEnginePage::certificateError(certificateError);
}

bool WebPage::acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame) {
    return QWebEnginePage::acceptNavigationRequest(url, type, isMainFrame);
}

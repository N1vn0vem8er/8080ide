#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#include <QWidget>
#ifndef Q_OS_WIN
#include <qtermwidget6/qtermwidget.h>
#else
class QLabel;
#endif

namespace Ui {
class TerminalWidget;
}

class TerminalWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalWidget(QWidget *parent = nullptr);
    ~TerminalWidget();
    QStringList getThemes();
    void setTheme(const QString& theme);
    void setTerminalFont(const QFont& font);

public slots:
    void increaseFontSize();
    void decreaseFontSize();
    void resetFontSize();
    void setFontSize(int size);
    void copy();
    void paste();
    void pasteSelected();
    void scrollToEnd();
    void sigstop();
    void sigint();
    void sigterm();
    void sigkill();
    void sigquit();
    void sighup();
    void sigtstp();

private:
    Ui::TerminalWidget *ui;
#ifndef Q_OS_WIN
    QTermWidget* terminal {nullptr};
#else
    QLabel* unsupportedLabel {nullptr};
#endif

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // TERMINALWIDGET_H

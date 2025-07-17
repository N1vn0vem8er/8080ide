#ifndef TERMINALSETTINGSPAGE_H
#define TERMINALSETTINGSPAGE_H

#include <QWidget>

namespace Ui {
class TerminalSettingsPage;
}

class TerminalSettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalSettingsPage(QWidget *parent = nullptr);
    ~TerminalSettingsPage();

private:
    Ui::TerminalSettingsPage *ui;
};

#endif // TERMINALSETTINGSPAGE_H

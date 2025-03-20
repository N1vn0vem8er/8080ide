#ifndef STARTUPSETTINGSPAGE_H
#define STARTUPSETTINGSPAGE_H

#include <QWidget>

namespace Ui {
class StartupSettingsPage;
}

class StartupSettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartupSettingsPage(QWidget *parent = nullptr);
    ~StartupSettingsPage();

private:
    Ui::StartupSettingsPage *ui;
    void apply();
};

#endif // STARTUPSETTINGSPAGE_H

#ifndef SIMSETTINGSPAGE_H
#define SIMSETTINGSPAGE_H

#include <QWidget>

namespace Ui {
class SimSettingsPage;
}

class SimSettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit SimSettingsPage(QWidget *parent = nullptr);
    ~SimSettingsPage();

private:
    Ui::SimSettingsPage *ui;
    void apply();
};

#endif // SIMSETTINGSPAGE_H

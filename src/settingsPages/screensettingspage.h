#ifndef SCREENSETTINGSPAGE_H
#define SCREENSETTINGSPAGE_H

#include <QWidget>

namespace Ui {
class ScreenSettingsPage;
}

class ScreenSettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenSettingsPage(QWidget *parent = nullptr);
    ~ScreenSettingsPage();

private:
    Ui::ScreenSettingsPage *ui;

private slots:
    void apply();
};

#endif // SCREENSETTINGSPAGE_H

#ifndef HELPSETTINGS_H
#define HELPSETTINGS_H

#include <QWidget>

namespace Ui {
class HelpSettings;
}

class HelpSettings : public QWidget
{
    Q_OBJECT

public:
    explicit HelpSettings(QWidget *parent = nullptr);
    ~HelpSettings();

private:
    Ui::HelpSettings *ui;
    void apply() const;
    QList<std::pair<int, int>> resolutions = {std::make_pair(800, 600), std::make_pair(1200, 600), std::make_pair(1600, 800), std::make_pair(1920, 1080)};
};

#endif // HELPSETTINGS_H

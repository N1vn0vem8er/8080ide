#ifndef STYLESETTINGSPAGE_H
#define STYLESETTINGSPAGE_H

#include <QWidget>

namespace Ui {
class StyleSettingsPage;
}

class StyleSettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StyleSettingsPage(QWidget *parent = nullptr);
    ~StyleSettingsPage();

private:
    Ui::StyleSettingsPage *ui;
    void apply() const;
};

#endif // STYLESETTINGSPAGE_H

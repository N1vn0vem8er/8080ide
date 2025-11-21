#ifndef GUIPROJECTCONFIGWIDGET_H
#define GUIPROJECTCONFIGWIDGET_H

#include <QWidget>

namespace Ui {
class GuiProjectConfigWidget;
}

class GuiProjectConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GuiProjectConfigWidget(QWidget *parent = nullptr);
    ~GuiProjectConfigWidget();

private:
    Ui::GuiProjectConfigWidget *ui;
};

#endif // GUIPROJECTCONFIGWIDGET_H

#ifndef PROJECTCONFIGURATIONWIDGET_H
#define PROJECTCONFIGURATIONWIDGET_H

#include <QWidget>

namespace Ui {
class ProjectConfigurationWidget;
}

class ProjectConfigurationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectConfigurationWidget(QWidget *parent = nullptr);
    ~ProjectConfigurationWidget();

private:
    Ui::ProjectConfigurationWidget *ui;
};

#endif // PROJECTCONFIGURATIONWIDGET_H

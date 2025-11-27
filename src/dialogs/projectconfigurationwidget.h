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
    QString getName() const;
    int getMemorySize() const;
    int getStartAt() const;
    QList<QPair<QString, int>> getFilesInMemory() const;
    int getStackPointer() const;
    void setName(const QString& name);
    void setMemorySize(int memorySize);
    void setStartAt(int startAt);
    void setFilesInMemory(const QList<QPair<QString, int>> files);
    void setStackPointer(int stackPointer);

private:
    Ui::ProjectConfigurationWidget *ui;

private slots:
    void addFile();
    void removeFile();
};

#endif // PROJECTCONFIGURATIONWIDGET_H

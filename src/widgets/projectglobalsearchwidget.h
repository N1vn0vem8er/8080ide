#ifndef PROJECTGLOBALSEARCHWIDGET_H
#define PROJECTGLOBALSEARCHWIDGET_H

#include <QWidget>

namespace Ui {
class ProjectGlobalSearchWidget;
}

class ProjectGlobalSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectGlobalSearchWidget(QString projectPath, QWidget *parent = nullptr);
    ~ProjectGlobalSearchWidget();

private:
    Ui::ProjectGlobalSearchWidget *ui;
    QString projectPath;
    QList<QPair<QString, int>> pathsLocations;
    void search();
    void replaceAll();
    void replaceSelected();
    QMap<QString, QList<int>> found;
    QList<int> findInFile(const QString& path, const QString& text) const;
};

#endif // PROJECTGLOBALSEARCHWIDGET_H

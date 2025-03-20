#ifndef STARTTABWIDGET_H
#define STARTTABWIDGET_H

#include <QWidget>

namespace Ui {
class StartTabWidget;
}

class StartTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartTabWidget(QWidget *parent = nullptr);
    ~StartTabWidget();

private:
    Ui::StartTabWidget *ui;
    void linkClicked(const QString& link);
    void loadRecentFilesList();
    void loadRecentProjectsList();
    void openFileFromRecent();
    void openProjectFromRecent();
    void clearRecentFiles();
    void clearRecentProjects();
signals:
    void linkActivated(const QString& link);
    void openFileFromPath(const QString& path);
    void openProjectFromPath(const QString& path);
};

#endif // STARTTABWIDGET_H

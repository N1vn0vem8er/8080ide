#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include "qstandarditemmodel.h"
#include <QDialog>

namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryWindow(QWidget *parent = nullptr);
    ~MemoryWindow();
public slots:
    void updateMemory(QString memory, const int& size);
signals:
    void changedMemory(QString& memory, int size);

private:
    Ui::MemoryWindow *ui;
    int size = 0;
    QString memory;
    void userMemoryUpdate();
    QStandardItemModel* model = nullptr;
};

#endif // MEMORYWINDOW_H

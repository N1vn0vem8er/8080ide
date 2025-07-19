#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>

namespace Ui {
class SearchWidget;
}

class SearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWidget(QWidget *parent = nullptr);
    QString getSearchFieldText() const;
    QString getReplaceFiedldText() const;
    bool isCaseSensitive() const;
    ~SearchWidget();

private:
    Ui::SearchWidget *ui;
signals:
    void searchFieldChanged(const QString& text);
    void replaceFieldChanged(const QString& text);
    void searchInSelected(const QString& text);
    void replaceInSelected(const QString& text);
};

#endif // SEARCHWIDGET_H

#ifndef TABVIEW_H
#define TABVIEW_H

#include <QObject>
#include <QTabWidget>

class TabView : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabView(QWidget* parent = nullptr) : QTabWidget(parent){};
protected:
    virtual void paintEvent(QPaintEvent* e ) override;
    virtual ~TabView(){};
};

#endif // TABVIEW_H

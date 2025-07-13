#ifndef NUMBERCONVERTERWIDGET_H
#define NUMBERCONVERTERWIDGET_H

#include <QWidget>

#define DEC_IN 0
#define HEX_IN 1
#define BIN_IN 2
#define HEX_OUT 0
#define DEC_OUT 1
#define BIN_OUT 2

namespace Ui {
class NumberConverterWidget;
}

class NumberConverterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NumberConverterWidget(QWidget *parent = nullptr);
    ~NumberConverterWidget();

private:
    Ui::NumberConverterWidget *ui;
    void input() const;
    void changeMaxInLength() const;
};

#endif // NUMBERCONVERTERWIDGET_H

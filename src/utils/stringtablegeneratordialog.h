#ifndef STRINGTABLEGENERATORDIALOG_H
#define STRINGTABLEGENERATORDIALOG_H

#include <QDialog>

namespace Ui {
class StringTableGeneratorDialog;
}

class StringTableGeneratorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StringTableGeneratorDialog(QWidget *parent = nullptr);
    ~StringTableGeneratorDialog();

private:
    Ui::StringTableGeneratorDialog *ui;
    void generate();
    void copy();
    QString toHex(QChar ch);
};

#endif // STRINGTABLEGENERATORDIALOG_H

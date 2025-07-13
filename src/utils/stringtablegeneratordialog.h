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
    void generate() const;
    void copy() const;
    QString toHex(QChar ch) const;
};

#endif // STRINGTABLEGENERATORDIALOG_H

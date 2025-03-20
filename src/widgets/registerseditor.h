#ifndef REGISTERSEDITOR_H
#define REGISTERSEDITOR_H

#include <QWidget>

namespace Ui {
class RegistersEditor;
}

class RegistersEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RegistersEditor(QWidget *parent = nullptr);
    ~RegistersEditor();
public slots:
    void setRegisterValues(const QString& a, const QString& b, const QString& c, const QString& d, const QString& e, const QString& h, const QString& l, const QString& PC, const QString& SP);

signals:
    void changeRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp);

private:
    Ui::RegistersEditor *ui;
    void apply();
    void error(const QString& message);
};

#endif // REGISTERSEDITOR_H

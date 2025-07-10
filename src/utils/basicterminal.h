#ifndef BASICTERMINAL_H
#define BASICTERMINAL_H

#include <QPlainTextEdit>
#include <QProcess>

class BasicTerminal : public QPlainTextEdit
{
    Q_OBJECT
public:
    BasicTerminal(QWidget* parent = nullptr);
    ~BasicTerminal();

public slots:
    void sigint();
    void sigterm();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QProcess* process {nullptr};

private slots:
    void output();
};

#endif // BASICTERMINAL_H

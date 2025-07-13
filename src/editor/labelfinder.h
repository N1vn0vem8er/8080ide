#ifndef LABELFINDER_H
#define LABELFINDER_H

#include <QThread>

class LabelFinder : public QThread
{
    Q_OBJECT
public:
    explicit LabelFinder(QObject *parent = nullptr);
    void setProjectPath(const QString& path);
    void setFilePath(const QString& path);
    void setText(const QString& text);
    void setProjectMode(bool val);
    bool isProjectMode() const;

protected:
    void run() override;
private:
    QString projectPath = "";
    QString filePath = "";
    QString text;
    QStringList readLabelsFromFile(const QString path) const;
    QStringList readFromString(QString text) const;
    bool projectMode = false;
signals:
    void resoultsReady(const QStringList& resoults);
};

#endif // LABELFINDER_H

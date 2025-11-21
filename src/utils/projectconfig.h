#ifndef PROJECTCONFIG_H
#define PROJECTCONFIG_H

#include <QObject>

class ProjectConfig : public QObject
{
    Q_OBJECT
public:
    explicit ProjectConfig(QObject *parent = nullptr);
    void fromFile(const QString& path);
    void fromQString(const QString& text);
    void toFile(const QString& path);
    void toQString();

private:
    QString version;
    QString name;
    int memorySize;
    int startAt;
    int stackPointer;
    QList<QPair<QString, int>> filesInMemory;

signals:
};

#endif // PROJECTCONFIG_H

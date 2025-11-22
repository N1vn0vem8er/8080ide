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
    void toFile(const QString& path) const;
    QString toQString() const;
    QString getVersion() const;
    QString getName() const;
    void setName(const QString &newName);
    int getMemorySize() const;
    void setMemorySize(int newMemorySize);
    int getStartAt() const;
    void setStartAt(int newStartAt);
    int getStackPointer() const;
    void setStackPointer(int newStackPointer);
    QList<QPair<QString, int> > getFilesInMemory() const;
    void setFilesInMemory(const QList<QPair<QString, int> > &newFilesInMemory);

private:
    QString version {"1.0.0"};
    QString name;
    int memorySize;
    int startAt;
    int stackPointer;
    QList<QPair<QString, int>> filesInMemory;

signals:
};

#endif // PROJECTCONFIG_H

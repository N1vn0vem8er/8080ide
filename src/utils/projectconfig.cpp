#include "projectconfig.h"
#include "qdir.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

ProjectConfig::ProjectConfig(QObject *parent)
    : QObject{parent}
{}

void ProjectConfig::fromFile(const QString &path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QJsonParseError parseError;
        const QJsonDocument document = QJsonDocument::fromJson(file.readAll(), &parseError);
        file.close();
        if(parseError.error == QJsonParseError::NoError)
        {
            const QJsonObject object = document.object();
            if(object.contains("version"))
                version = object.value("version").toString();
            if(object.contains("name"))
                name = object.value("name").toString();
            if(object.contains("memorySize"))
                memorySize = object.value("memorySize").toInt();
            if(object.contains("startAt"))
                startAt = object.value("startAt").toInt();
            if(object.contains("stackPointer"))
                stackPointer = object.value("stackPointer").toInt();
            if(object.contains("files"))
            {
                const QJsonArray files = object.value("files").toArray();
                for(const auto& file : files)
                {
                    const QJsonObject obj = file.toObject();
                    if(obj.contains("filePath") && obj.contains("fileLocation"))
                        filesInMemory.append({obj.value("filePath").toString(), obj.value("fileLocation").toInt()});
                }
            }
        }
    }
}

void ProjectConfig::fromQString(const QString &text)
{
    if(text.isEmpty()) return;
    QJsonParseError parseError;
    const QJsonDocument document = QJsonDocument::fromJson(text.toUtf8(), &parseError);
    if(parseError.error == QJsonParseError::NoError)
    {
        const QJsonObject object = document.object();
        if(object.contains("version"))
            version = object.value("version").toString();
        if(object.contains("name"))
            name = object.value("name").toString();
        if(object.contains("memorySize"))
            memorySize = object.value("memorySize").toInt();
        if(object.contains("startAt"))
            startAt = object.value("startAt").toInt();
        if(object.contains("stackPointer"))
            stackPointer = object.value("stackPointer").toInt();
        if(object.contains("files"))
        {
            const QJsonArray files = object.value("files").toArray();
            for(const auto& file : files)
            {
                const QJsonObject obj = file.toObject();
                if(obj.contains("filePath") && obj.contains("fileLocation"))
                    filesInMemory.append({obj.value("filePath").toString(), obj.value("fileLocation").toInt()});
            }
        }
    }
}

void ProjectConfig::toFile(const QString &path) const
{
    QJsonObject object;
    object["version"] = version;
    object["name"] = name;
    object["memorySize"] = memorySize;
    object["startAt"] = startAt;
    object["stackPointer"] = stackPointer;
    QJsonArray files;
    for(const auto& i : std::as_const(filesInMemory))
    {
        QJsonObject obj;
        obj["filePath"] = i.first;
        obj["fileLocation"] = i.second;
        files.append(obj);
    }
    object["files"] = files;
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        file.write(QJsonDocument(object).toJson());
        file.close();
    }
}

QString ProjectConfig::toQString() const
{
    QJsonObject object;
    object["version"] = version;
    object["name"] = name;
    object["memorySize"] = memorySize;
    object["startAt"] = startAt;
    object["stackPointer"] = stackPointer;
    QJsonArray files;
    for(const auto& i : std::as_const(filesInMemory))
    {
        QJsonObject obj;
        obj["filePath"] = i.first;
        obj["fileLocation"] = i.second;
        files.append(obj);
    }
    object["files"] = files;
    return QJsonDocument(object).toJson();
}

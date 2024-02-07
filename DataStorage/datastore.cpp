//## DataStorage/datastore.cpp
#include "datastore.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

DataStore::DataStore()
{
}

DataStore::~DataStore()
{
}

QVariantMap DataStore::load()
{
    // Open the data file
    QFile file("data.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return QVariantMap();
    }

    // Read the data from the file
    QByteArray data = file.readAll();
    file.close();

    // Parse the data as JSON
    QJsonDocument jsonDocument = QJsonDocument::fromJson(data);
    if (jsonDocument.isNull()) {
        return QVariantMap();
    }

    // Convert the JSON object to a QVariantMap
    QVariantMap dataMap = jsonDocument.object().toVariantMap();

    // Return the data map
    return dataMap;
}

void DataStore::save(const QVariantMap &data)
{
    // Open the data file
    QFile file("data.json");
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    // Convert the QVariantMap to a JSON object
    QJsonObject jsonObject = QJsonObject::fromVariantMap(data);

    // Write the JSON object to the file
    QJsonDocument jsonDocument(jsonObject);
    file.write(jsonDocument.toJson());
    file.close();
}

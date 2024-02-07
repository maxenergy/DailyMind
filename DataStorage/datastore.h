//## DataStorage/datastore.h
#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QVariantMap>

class DataStore : public QObject
{
    Q_OBJECT

public:
    explicit DataStore(QObject *parent = nullptr);
    ~DataStore();

    QVariantMap load();
    void save(const QVariantMap &data);

signals:

private:
    QVariantMap data_;
};

#endif // DATASTORE_H

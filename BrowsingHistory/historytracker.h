//## BrowsingHistory/historytracker.h
#ifndef HISTORYTRACKER_H
#define HISTORYTRACKER_H

#include <QObject>
#include <QStringList>

class HistoryTracker : public QObject
{
    Q_OBJECT

public:
    explicit HistoryTracker(QObject *parent = nullptr);
    ~HistoryTracker();

    void trackHistory(const QString &url);
    QStringList getHistory() const;

signals:
    void historyChanged();

private:
    QStringList history_;
};

#endif // HISTORYTRACKER_H

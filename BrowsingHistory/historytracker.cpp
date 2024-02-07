//## BrowsingHistory/historytracker.cpp
#include "historytracker.h"

HistoryTracker::HistoryTracker(QObject *parent) : QObject(parent) {}

void HistoryTracker::trackHistory(const QString &url) {
  history_.push_back(url);
  emit historyChanged();
}

QStringList HistoryTracker::getHistory() const { return history_; }


#ifndef TABLETWATCHER_H
#define TABLETWATCHER_H

#include <QObject>

class TabletWatcher : public QObject {
Q_OBJECT
public:
    TabletWatcher(QObject *parent = nullptr) : QObject(parent) {};
    void startWatching();

public Q_SLOTS:
    void onChanged(const QString &output);
    void onError(const QString &output);
};

#endif //TABLETWATCHER_H

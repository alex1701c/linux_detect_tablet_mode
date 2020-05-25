#ifndef KCM_H
#define KCM_H

#include <QtGlobal>
#include <KCModule>
#include <QObject>

class KCM : public KCModule {
    Q_OBJECT
public:
    KCM(QWidget *parent, const QVariantList &args);
};

#endif //KCM_H

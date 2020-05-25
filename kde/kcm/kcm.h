#ifndef NORDVPNCONFIG_H
#define NORDVPNCONFIG_H

#include "ui_kcm.h"
#include <KCModule>
#include <KConfigCore/KConfigGroup>

class KCMConfigForm : public QWidget, public Ui::KCM {
Q_OBJECT

public:
    explicit KCMConfigForm(QWidget *parent);
};

class KCMConfig : public KCModule {
Q_OBJECT

public:
    explicit KCMConfig(QWidget *parent = nullptr, const QVariantList &args = QVariantList());

private:
    KCMConfigForm *m_ui;
};

#endif

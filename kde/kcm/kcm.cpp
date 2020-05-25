#include "kcm.h"
#include <KSharedConfig>
#include <KPluginFactory>
#include <QtDebug>
#include <QtWidgets/QGridLayout>

#include "kcmutils_version.h"

K_PLUGIN_FACTORY(NordVPNConfigFactory, registerPlugin<KCMConfig>("kcm_watch_tablet");)

KCMConfigForm::KCMConfigForm(QWidget *parent) : QWidget(parent) {
    setupUi(this);
}

KCMConfig::KCMConfig(QWidget *parent, const QVariantList &args) : KCModule(parent, args) {
    m_ui = new KCMConfigForm(this);
    auto *layout = new QGridLayout(this);
    layout->addWidget(m_ui, 0, 0);
}

#include "kcm.moc"

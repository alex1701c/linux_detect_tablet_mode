#include "kcm.h"

#include <KPluginFactory>

K_PLUGIN_FACTORY(KCMFactory, registerPlugin<KCM>("kcm_watch_tablet");)

KCM::KCM(QWidget *parent, const QVariantList &args)
    : KCModule(parent, args)
{

}

#include "kcm.moc"
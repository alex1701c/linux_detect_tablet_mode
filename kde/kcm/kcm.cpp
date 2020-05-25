#include "kcm.h"
#include <KSharedConfig>
#include <KPluginFactory>
#include <KMessageBox>
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

    config = KSharedConfig::openConfig("watch_tabletrc")->group("Config");
    modesGroup = config.group("Modes");

    const auto changedLambda = [this]() { Q_EMIT (changed(true)); };
    connect(m_ui->deviceLineEdit, &QLineEdit::textChanged, this, changedLambda);
    connect(m_ui->laptopModeScripts, &KEditListWidget::changed, this, changedLambda);
    connect(m_ui->tabletModeScripts, &KEditListWidget::changed, this, changedLambda);
}
void KCMConfig::load()
{
    KCModule::load();

    initialDevice = config.readEntry("input_device");
    m_ui->deviceLineEdit->setText(config.readEntry("input_device"));
    m_ui->laptopModeScripts->setItems(modesGroup.readEntry("laptop", QStringList()));
    m_ui->tabletModeScripts->setItems(modesGroup.readEntry("tablet", QStringList()));

    Q_EMIT changed(false);
}
void KCMConfig::save()
{
    KCModule::save();

    config.writeEntry("input_device", m_ui->deviceLineEdit->text());
    modesGroup.writeEntry("laptop", m_ui->laptopModeScripts->items());
    modesGroup.writeEntry("tablet", m_ui->tabletModeScripts->items());

    if (initialDevice != m_ui->deviceLineEdit->text()) {
        KMessageBox::information(this, "The device has been changed, for the change sto take effect the watcher has to be restarted");
    }
}

#include "kcm.moc"

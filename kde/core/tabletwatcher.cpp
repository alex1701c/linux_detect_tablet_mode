#include "tabletwatcher.h"

#include <QDebug>
#include <QProcess>
#include <QStandardPaths>
#include <QRegularExpression>
#include <KSharedConfig>
#include <KConfigGroup>

void TabletWatcher::startWatching()
{
    const QString inputDevice = KSharedConfig::openConfig("watch_tabletrc")->group("Config").readEntry("input_device");
    auto *process = new QProcess(this);
    process->start("stdbuf", QStringList({"-oL", "-eL", "libinput", "debug-events", "--device", inputDevice}));
    connect(process, &QProcess::readyReadStandardOutput, [this, process](){
        Q_EMIT onChanged(process->readAllStandardOutput());
    });
    connect(process, &QProcess::readyReadStandardError, [this, process](){
        Q_EMIT onError(process->readAllStandardError());
    });
}

void TabletWatcher::onChanged(const QString &output)
{
     const static QRegularExpression modeRegex = QRegularExpression("switch tablet-mode state (\\d+)");
     const auto match = modeRegex.match(output);
     KConfigGroup cfg = KSharedConfig::openConfig("watch_tabletrc", KConfig::SimpleConfig)->group("Config");
     KConfigGroup modesGrp = cfg.group("Modes");
     // 0 = laptop, 1 = tablet
     // If the regex does not match it is the initial process output from laptop mode
     const int mode = match.hasMatch() ? match.captured(1).toInt() : 0;
     if (mode == 0) {
        if (modesGrp.hasKey("laptop")) {
            const auto laptopCommands = modesGrp.readEntry("laptop", QStringList());
            for (const auto &command : laptopCommands) {
                system(qPrintable(command));
            }
        }
     } else if (mode == 1) {
         if (modesGrp.hasKey("tablet")) {
             const auto tabletCommands = modesGrp.readEntry("tablet", QStringList());
             for (const auto &command : tabletCommands) {
                 system(qPrintable(command));
             }
         }
     } else {
         qWarning() << "Unknown mode" << mode << "for output" << output;
     }
}

void TabletWatcher::onError(const QString &output)
{
    qWarning() << "error" << output;
}

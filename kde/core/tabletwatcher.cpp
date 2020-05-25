#include "tabletwatcher.h"

#include <QDebug>
#include <QProcess>
#include <KConfigGroup>

void TabletWatcher::startWatching()
{
    auto *process = new QProcess(this);
    process->start("stdbuf -oL -eL libinput debug-events --device /dev/input/by-path/platform-thinkpad_acpi-event");
    connect(process, &QProcess::readyReadStandardOutput, [this, process](){
        Q_EMIT onChanged(process->readAllStandardOutput());
    });
    connect(process, &QProcess::readyReadStandardError, [this, process](){
        Q_EMIT onError(process->readAllStandardError());
    });
}
void TabletWatcher::onChanged(const QString &output)
{
    qWarning() << "changed" << output;
}
void TabletWatcher::onError(const QString &output)
{
    qWarning() << "error" << output;
}

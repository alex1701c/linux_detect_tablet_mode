#include <QCommandLineParser>
#include <QDebug>
#include <QtCore/QProcess>
#include "tabletwatcher.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("watch_tablet_qt");
    QCoreApplication::setApplicationVersion("1.0");


    auto *watcher = new TabletWatcher();
    watcher->startWatching();
    QCoreApplication::exec();
}

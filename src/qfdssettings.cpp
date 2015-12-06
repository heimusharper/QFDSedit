#include "qfdssettings.h"

QFDSSettings::QFDSSettings()
{
    Settings = new Settings();
}

void QFDSSettings::loadSettings()
{
    settings->pathToFds = settingsFile.value("paths/pathToFds", "").toString();
    settings->pathToGnuplot = settingsFile.value("paths/pathToGnuplot", "").toString();
    settings->pathToSmv = settingsFile.value("paths/pathToSmv", "").toString();
    settings->useServerFds = settingsFile.value("server/useServer", "").toBool();
    settings->pathToServerFds = settingsFile.value("server/pathToServerFds", "127.0.0.1").toString();
    settings->portServerFds = settingsFile.value("server/portToServer", 9900).toInt();
    settings->useSsh = settingsFile.value("server/useSsh", true).toBool();

}

void QFDSSettings::saveSettings()
{
    settingsFile.setValue("paths/pathToFds", settings->pathToFds);
    settingsFile.setValue("paths/pathToGnuplot", settings->pathToGnuplot);
    settingsFile.setValue("paths/pathToSmv", settings->pathToSmv);
    settingsFile.setValue("server/useServer", settings->useServerFds);
    settingsFile.setValue("server/pathToServerFds", settings->pathToServerFds);
    settingsFile.setValue("server/portToServer", settings->portServerFds);
    settingsFile.setValue("server/useSsh", settings->useSsh);
}


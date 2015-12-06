#ifndef QFDSSETTINGS_H
#define QFDSSETTINGS_H
#include <QString>
#include <QSettings>


class Settings
{
public:
    QString pathToFds = "";
    QString pathToSmv = "";
    QString pathToGnuplot = "";
    bool useServerFds = false;
    QString pathToServerFds = "127.0.0.1";
    bool useSsh = true;
    int portServerFds = "9900";

};

class QFDSSettings
{
public:
    QFDSSettings();

    void loadSettings();
    void saveSettings();

    Settings *settings;

private:

    QSettings settingsFile;

};

#endif // QFDSSETTINGS_H

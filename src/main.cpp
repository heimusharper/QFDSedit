#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("Rintd");
    a.setOrganizationDomain("http://rintd.ru/");
    a.setApplicationName("QFDS");

    MainWindow w;
    w.show();

    return a.exec();
}

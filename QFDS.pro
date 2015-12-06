#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T18:41:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFDS
TEMPLATE = app


SOURCES += src\main.cpp\
        src\mainwindow.cpp \
    src\qfdshighlighter.cpp \
    src\qhighlightercolortheme.cpp \
    src/qfdssettings.cpp \
    qfdssettingsdialog.cpp

HEADERS  += src\mainwindow.h \
    src\qfdshighlighter.h \
    src\qhighlightercolortheme.h \
    src/qfdssettings.h \
    qfdssettingsdialog.h

FORMS    += src\mainwindow.ui \
    qfdssettingsdialog.ui

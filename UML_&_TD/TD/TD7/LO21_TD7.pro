#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T14:14:29
#
#-------------------------------------------------

QT       += widgets
QT       += testlib
QT       += xml

QT       -= gui

TARGET = tst_lo21_td7test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Calendar.cpp \
    main.cpp \
    tacheediteur.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    Calendar.h \
    tacheediteur.h

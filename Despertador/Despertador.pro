#----------------------------------------------------------
#
# Project created by QtCreator 2016-04-08T21:11:41
# This project is under Nintersoft Open Souce code Licence
# Developer: Mauro Mascarenhas de Araújo
# Organization: Nintersoft
#
#----------------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Despertador
TEMPLATE = app

VERSION = 1.6.0.0
QMAKE_TARGET_COMPANY = Nintersoft
QMAKE_TARGET_PRODUCT = Microcontador
QMAKE_TARGET_DESCRIPTION = Despertador de codigo aberto
QMAKE_TARGET_COPYRIGHT = Copyright (c) 2016 Nintersoft

SOURCES += main.cpp\
        jnlprincipal.cpp \
        jnlconfig.cpp \
        jnlmensagem.cpp \
    jnlsobre.cpp

HEADERS  += jnlprincipal.h \
         jnlconfig.h \
         jnlmensagem.h \
    jnlsobre.h

FORMS    += jnlprincipal.ui \
         jnlconfig.ui \
    jnlmensagem.ui \
    jnlsobre.ui

TRANSLATIONS = idiomas\Microcontador_pt.ts \
               idiomas\Microcontador_en.ts

RESOURCES += \
    estilos.qrc

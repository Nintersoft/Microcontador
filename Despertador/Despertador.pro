#-------------------------------------------------
#
# Project created by QtCreator 2016-04-08T21:11:41
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Despertador
TEMPLATE = app


SOURCES += main.cpp\
        jnlprincipal.cpp \
        jnlconfig.cpp \
        jnlmensagem.cpp

HEADERS  += jnlprincipal.h \
         jnlconfig.h \
         jnlmensagem.h

FORMS    += jnlprincipal.ui \
         jnlconfig.ui \
    jnlmensagem.ui

RESOURCES += \
    estilos.qrc

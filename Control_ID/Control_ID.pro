#-------------------------------------------------
#
# Project created by QtCreator 2018-12-18T08:40:35
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Control_ID
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        tela_inicial.cpp \
    altera_hora.cpp \
    novocadastro.cpp \
    clientes.cpp \
    valid.cpp \
    insert_bd.cpp \
    excluir.cpp \
    modific.cpp \
    sincroniza.cpp \
    cadastro_rein.cpp \
    id_aleatorio.cpp

HEADERS += \
        tela_inicial.h \
    altera_hora.h \
    novocadastro.h \
    clientes.h \
    valid.h \
    insert_bd.h \
    excluir.h \
    modific.h \
    sincroniza.h \
    cadastro_rein.h \
    id_aleatorio.h

FORMS += \
        tela_inicial.ui \
    altera_hora.ui \
    novocadastro.ui \
    clientes.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagens.qrc

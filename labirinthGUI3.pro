#-------------------------------------------------
#
# Project created by QtCreator 2017-05-28T11:05:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = labirinthGUI3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    player.cpp \
    question.cpp \
    questionabcd.cpp \
    rebus.cpp \
    room.cpp \
    report_scene.cpp \
    question_scene.cpp \
    rebus_scene.cpp

HEADERS  += mainwindow.h \
    game.h \
    player.h \
    question.h \
    questionabcd.h \
    rebus.h \
    room.h \
    report_scene.h \
    question_scene.h \
    rebus_scene.h

FORMS    += mainwindow.ui \
    report_scene.ui \
    question_scene.ui \
    rebus_scene.ui

DISTFILES += \
    1istorija1.txt \
    1igraonica1.txt \
    1igraonica2.txt \
    1igraonica3.txt \
    1istorija1.txt \
    1istorija2.txt \
    1istorija3.txt \
    1nauka1.txt \
    1nauka2.txt \
    1nauka3.txt \
    1umetnost1.txt \
    1umetnost2.txt \
    1umetnost3.txt \
    2igraonica1.txt \
    2igraonica2.txt \
    2igraonica3.txt \
    2istorija1.txt \
    2istorija2.txt \
    2istorija3.txt \
    2nauka1.txt \
    2nauka2.txt \
    2nauka3.txt \
    2umetnost1.txt \
    2umetnost2.txt \
    2umetnost3.txt \
    3igraonica1.txt \
    3igraonica2.txt \
    3igraonica3.txt \
    3istorija1.txt \
    3istorija2.txt \
    3istorija3.txt \
    3nauka1.txt \
    3nauka2.txt \
    3nauka3.txt \
    3umetnost1.txt \
    3umetnost2.txt \
    3umetnost3.txt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/custombutton.cpp \
    items/pausebutton.cpp \
    main.cpp \
    gameengine.cpp \
    core/adventure.cpp \
    core/background.cpp \
    core/block.cpp \
    core/element.cpp \
    core/enemy.cpp \
    core/level.cpp \
    core/player.cpp \
    core/projectile.cpp \
    core/unit.cpp \
    core/unitanimate.cpp \
    items/testator.cpp \
    items/wall.cpp \
    scenes/gamescene.cpp \
    scenes/menuscene.cpp \
    scenes/pausemenu.cpp

HEADERS += \
    config.h \
    core/custombutton.h \
    gameengine.h \
    core/adventure.h \
    core/background.h \
    core/block.h \
    core/element.h \
    core/enemy.h \
    core/level.h \
    core/player.h \
    core/projectile.h \
    core/unit.h \
    core/unitanimate.h \
    items/pausebutton.h \
    items/testator.h \
    items/wall.h \
    scenes/gamescene.h \
    scenes/menuscene.h \
    scenes/pausemenu.h

FORMS += \

RESOURCES += \
    ressources/images/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

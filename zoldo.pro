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
    core/healthbar.cpp \
    elements/blocks/door.cpp \
    elements/enemies/despicableboss.cpp \
    elements/projectile/airgust.cpp \
    elements/enemies/bat.cpp \
    elements/enemies/garbage.cpp \
    elements/enemies/ghost.cpp \
    elements/healthbar/basichealthbar.cpp \
    elements/healthbar/zeldahealthbar.cpp \
    elements/player/link.cpp \
    elements/player/playertest.cpp \
    elements/projectile/arrow.cpp \
    elements/projectile/dirtyball.cpp \
    elements/projectile/fireball.cpp \
    elements/projectile/stone.cpp \
    scenemanager.cpp \
    tools/elementfactory.cpp \
    main.cpp \
    core/adventure.cpp \
    core/block.cpp \
    core/element.cpp \
    core/enemy.cpp \
    core/level.cpp \
    core/player.cpp \
    core/projectile.cpp \
    core/unit.cpp \
    core/unitanimate.cpp \
    core/custombutton.cpp \
    core/background.cpp \
    elements/background/testbackground.cpp \
    elements/blocks/water.cpp \
    elements/buttons/menubutton.cpp \
    elements/buttons/playbutton.cpp \
    elements/buttons/quitbutton.cpp \
    elements/buttons/resumebutton.cpp \
    elements/buttons/settingbutton.cpp \
    elements/visual/menutitle.cpp \
    elements/enemies/testator.cpp \
    elements/blocks/wall.cpp \
    elements/projectile/testprojectile.cpp \
    elements/buttons/pausebutton.cpp \
    elements/buttons/restartbutton.cpp \
    scenes/gamescene.cpp \
    scenes/levelcreatorscene.cpp \
    scenes/menuscene.cpp \
    scenes/pausemenu.cpp \
    tools/setupdialog.cpp

HEADERS += \
    core/healthbar.h \
    elements/blocks/door.h \
    elements/enemies/despicableboss.h \
    elements/projectile/airgust.h \
    elements/enemies/bat.h \
    elements/enemies/garbage.h \
    elements/enemies/ghost.h \
    elements/healthbar/basichealthbar.h \
    elements/healthbar/zeldahealthbar.h \
    elements/player/link.h \
    elements/player/playertest.h \
    elements/projectile/arrow.h \
    elements/projectile/dirtyball.h \
    elements/projectile/fireball.h \
    elements/projectile/stone.h \
    scenemanager.h \
    tools/elementfactory.h \
    config.h \
    core/adventure.h \
    core/block.h \
    core/custombutton.h \
    core/element.h \
    core/enemy.h \
    core/level.h \
    core/player.h \
    core/projectile.h \
    core/unit.h \
    core/unitanimate.h \
    core/background.h \
    elements/background/testbackground.h \
    elements/blocks/water.h \
    elements/buttons/menubutton.h \
    elements/buttons/pausebutton.h \
    elements/buttons/playbutton.h \
    elements/buttons/quitbutton.h \
    elements/buttons/restartbutton.h \
    elements/buttons/resumebutton.h \
    elements/buttons/settingbutton.h \
    elements/enemies/testator.h \
    elements/blocks/wall.h \
    elements/visual/menutitle.h \
    elements/projectile/testprojectile.h \
    scenes/gamescene.h \
    scenes/levelcreatorscene.h \
    scenes/menuscene.h \
    scenes/pausemenu.h \
    tools/setupdialog.h

FORMS += \

RESOURCES += \
    ressources/images/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

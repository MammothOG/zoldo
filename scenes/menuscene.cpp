#include "menuscene.h"

#include <QMetaObject>
#include <QSound>

#include "config.h"
#include "elements/buttons/playbutton.h"
#include "elements/buttons/settingbutton.h"
#include "elements/buttons/quitbutton.h"
#include "elements/visual/menutitle.h"
#include "scenemanager.h"


MenuScene::MenuScene(QGraphicsView * sceneManager)
{
    this->sceneManager = sceneManager;

    setSceneRect(0, 0, WINSIZE.rwidth(), WINSIZE.rheight());
    setBackgroundBrush(Qt::white);

    menuBackground = new QGraphicsPixmapItem();
    QPixmap bgImg = QPixmap(":/ressources/images/visuals/menu_bg.png");
    bgImg = bgImg.scaled(WINSIZE.rwidth(), WINSIZE.rheight());
    menuBackground->setPixmap(bgImg);
    menuBackground->setPos(0,0);
    menuBackground->setZValue(1);
    addItem(menuBackground);

    playButton = new PlayButton();
    playButton->setPos(WINSIZE.rwidth()/2, WINSIZE.rheight()*3/4);
    addItem(playButton);

    quitButton = new QuitButton();
    quitButton->setPos(WINSIZE.rwidth() - 45, WINSIZE.rheight() - 45);
    addItem(quitButton);

    settingButton = new SettingButton();
    settingButton->setPos(WINSIZE.rwidth() - 75, 20);
    addItem(settingButton);

    title = new MenuTitle();
    title->setPos(WINSIZE.rwidth()/2, 200);
    addItem(title);

    connect(playButton, SIGNAL(onReleaseClick()), sceneManager, SLOT(setGameScene()));

    music = new QSound(":/ressources/sounds/menumusic.wav");
    music->play();
}

MenuScene::~MenuScene()
{
    music->stop();
}

void MenuScene::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_F1:
        QMetaObject::invokeMethod(sceneManager, "setLvlCreatorScene");
        break;
    }
}

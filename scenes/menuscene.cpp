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
    quitButton->setPos(WINSIZE.rwidth() - 20, 20);
    addItem(quitButton);

    settingButton = new SettingButton();
    settingButton->setPos(20, 20);
    addItem(settingButton);

    title = new MenuTitle();
    title->setPos(WINSIZE.rwidth()/2, 200);
    addItem(title);

    connect(playButton, SIGNAL(onReleaseClick()), sceneManager, SLOT(setGameScene()));

    music = new QMediaPlayer();
    music->setMedia(QUrl::fromLocalFile("../zoldo/ressources/sounds/menumusic.wav"));
    music->setVolume(50);
    music->play();
}

MenuScene::~MenuScene()
{
    music->stop();
    delete music;
}

void MenuScene::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_F1:
        QMetaObject::invokeMethod(sceneManager, "setLvlCreatorScene");
        break;
    }
}

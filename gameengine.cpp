#include "gameengine.h"

#include "config.h"
#include "scenes/gamescene.h"
#include "scenes/menuscene.h"
#include "scenes/levelcreatorscene.h"
#include "elements/buttons/playbutton.h"
#include "elements/buttons/settingbutton.h"


GameEngine::GameEngine(QMainWindow * parent)
{
    this->parent = parent;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWindowTitle(TITLE);
    parent->resize(WINSIZE);

    MenuScene * menuScene = new MenuScene();
    setScene(menuScene);

    connect(menuScene->getPlayButton(), SIGNAL(onReleaseClick()), this, SLOT(onPlay()));
    connect(menuScene->getSettingButton(), SIGNAL(onReleaseClick()), this, SLOT(onSetting()));
}

void GameEngine::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void GameEngine::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void GameEngine::onPlay()
{
    GameScene * gameScene = new GameScene();
    setScene(gameScene);
}

void GameEngine::onSetting()
{
    LevelCreatorScene * levelCreatorScene = new LevelCreatorScene(parent);
    setScene(levelCreatorScene);
}

void GameEngine::onMenu()
{
    MenuScene * menuScene = new MenuScene();
    setScene(menuScene);
}

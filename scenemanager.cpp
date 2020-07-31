#include "scenemanager.h"

#include "config.h"
#include "scenes/gamescene.h"
#include "scenes/menuscene.h"
#include "scenes/levelcreatorscene.h"
#include "elements/buttons/playbutton.h"
#include "elements/buttons/settingbutton.h"


SceneManager::SceneManager(QMainWindow * parent)
{
    this->parent = parent;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWindowTitle(TITLE);
    parent->resize(WINSIZE);

    scene = new MenuScene(this);
    setScene(scene);
}

void SceneManager::setGameScene()
{
    scene = new GameScene(this);
    setScene(scene);
}

void SceneManager::setLvlCreatorScene()
{
    scene = new LevelCreatorScene(parent, this);
    setScene(scene);
}

void SceneManager::setMenuScene()
{
    scene = new MenuScene(this);
    setScene(scene);
}

void SceneManager::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void SceneManager::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

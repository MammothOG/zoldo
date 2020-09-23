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
    parent->setFixedSize(WINSIZE);

    MenuScene * scene = new MenuScene(this);
    setScene(scene);
}

void SceneManager::setGameScene()
{
    GameScene * scene = new GameScene(this);
    if (scene->getSuccessLoaded())
    {
        delete this->scene();
        setScene(scene);
    }
}

void SceneManager::setLvlCreatorScene()
{
    delete this->scene();
    LevelCreatorScene * scene = new LevelCreatorScene(parent, this);
    setScene(scene);
}

void SceneManager::setMenuScene()
{
    delete this->scene();
    MenuScene * scene = new MenuScene(this);
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

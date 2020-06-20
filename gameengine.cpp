#include "gameengine.h"

#include "config.h"
#include "scenes/gamescene.h"
#include "scenes/menuscene.h"
#include "items/buttons/playbutton.h"


GameEngine::GameEngine()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    windowWidth = WIN_WIDTH;
    windowHeight = WIN_HEIGHT;

    setWindowTitle(TITLE);
    resize(windowWidth, windowHeight);

    menuScene = new MenuScene();
    setScene(menuScene);

    connect(menuScene->getPlayButton(), SIGNAL(onReleaseClick()), this, SLOT(onPlay()));
}

void GameEngine::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void GameEngine::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

#include <QDebug>
void GameEngine::onPlay()
{
    GameScene * gameScene = new GameScene();
    setScene(gameScene);
}

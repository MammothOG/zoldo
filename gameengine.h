#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>


class MenuScene;

class LevelCreatorScene;

class GameEngine: public QGraphicsView
{
    Q_OBJECT
private:
    int windowWidth;

    int windowHeight;

    MenuScene * menuScene;

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void onPlay();

    void onSetting();

public:
    GameEngine();

};

#endif // GAMEENGINE_H

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>


class MenuScene;

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

public:
    GameEngine();

};

#endif // GAMEENGINE_H

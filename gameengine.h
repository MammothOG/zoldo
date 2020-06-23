#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>


#include <QDebug>
class MenuScene;

class LevelCreatorScene;

class GameEngine: public QGraphicsView
{
    Q_OBJECT
private:
    int windowWidth;

    int windowHeight;

    MenuScene * menuScene;

    QMainWindow * parent;

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void onPlay();

    void onSetting();

public:
    GameEngine(QMainWindow * parent);

};

#endif // GAMEENGINE_H

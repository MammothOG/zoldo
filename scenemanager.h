#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>


class SceneManager: public QGraphicsView
{
    Q_OBJECT
private:
    int windowWidth;

    int windowHeight;

    QMainWindow * parent;

    QGraphicsScene * scene;

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void setMenuScene();

    void setGameScene();

    void setLvlCreatorScene();

public:
    SceneManager(QMainWindow * parent);
};

#endif // GAMEENGINE_H

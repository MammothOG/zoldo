#ifndef LEVELCREATORSCENE_H
#define LEVELCREATORSCENE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QGraphicsItemGroup>


class Background;

class Block;

class Unit;

class Player;

class Element;

class Level;

class LevelCreatorScene : public QGraphicsScene
{
    Q_OBJECT
private:
    int posX;

    int posY;

    Element * elementSelected;

    QGraphicsItemGroup * itemGroupSelected;

    Level * level;

    QMenuBar * menuBar;

    QMenu * backgroundMenu;

    QMenu * playerMenu;

    QMenu * blockMenu;

    QMenu * unitMenu;

    void createAction();

    QAction * newWall;

    QAction * newWater;

    QAction * newTestBackground;

    QAction * newTestator;

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent * keyEvent) override;

signals:
    void backToMenu();

public:
    LevelCreatorScene(QMainWindow * parent);

    QAction * addNewElement(QString name, Element * newElement);

};

#endif // LEVELCREATORSCENE_H

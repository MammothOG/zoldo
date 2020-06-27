#ifndef LEVELCREATORSCENE_H
#define LEVELCREATORSCENE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QGraphicsItemGroup>
#include <QList>


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

    QList<Element*> * elementList;

    QList<Unit*> * unitList;

    Background * background;

    Player * player;

    QMenuBar * menuBar;

    QMenu * menu;

    QMenu * backgroundMenu;

    QMenu * playerMenu;

    QMenu * blockMenu;

    QMenu * unitMenu;

    void createAction();

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent * keyEvent) override;

    void createLevel();

signals:
    void backToMenu();

public:
    LevelCreatorScene(QMainWindow * parent);

    QAction * addNewElement(QString name, Element * newElement);

    void appendLevelElement(Element * element);


};

#endif // LEVELCREATORSCENE_H

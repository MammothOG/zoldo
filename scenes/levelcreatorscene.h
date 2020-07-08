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
    int sceneHeight;

    int sceneWidth;

    int posX;

    int posY;

    Element * elementSelected;

    QGraphicsItemGroup * itemGroupSelected;

    Level * level;

    QMenuBar * menuBar;

    QMenu * optionMenu;

    QMenu * backgroundMenu;

    QMenu * playerMenu;

    QMenu * blockMenu;

    QMenu * unitMenu;

    void createAction();

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent * keyEvent) override;

    bool createLevel();

signals:
    void backToMenu();

public:
    LevelCreatorScene(QMainWindow * parent);

    QAction * addNewElement(QString name, Element * newElement);


};

#endif // LEVELCREATORSCENE_H

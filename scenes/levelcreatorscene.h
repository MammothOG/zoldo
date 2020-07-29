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

    int indexStyle;

    bool gridEnabled;

    bool elementCentered;

    Element * elementSelected;

    QGraphicsItemGroup * itemGroupSelected;

    Level * level;

    QMenuBar * menuBar;

    QMenu * fileMenu;

    QMenu * backgroundMenu;

    QMenu * playerMenu;

    QMenu * blockMenu;

    QMenu * unitMenu;

    QMenu * toolsMenu;

    QAction * gridAction;

    QAction * itemCenterAction;

    void createAction();

    QStringList styleList;

    void grabStyleElement(Element * element);

    void loadToolMenu(QMenu * menu);

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent * keyEvent) override;

    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    bool createLevel();

    void reset();

signals:
    void backToMenu();

public:
    LevelCreatorScene(QMainWindow * parent);

    QAction * addNewElement(QString name, Element * newElement);

};

#endif // LEVELCREATORSCENE_H

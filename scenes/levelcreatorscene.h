#ifndef LEVELCREATORSCENE_H
#define LEVELCREATORSCENE_H

#include <QGraphicsScene>


class Background;

class Block;

class Unit;

class Player;

class Element;

class LevelCreatorScene : public QGraphicsScene
{
private:
    int elementIndex;

    int elementListIndex;

    int lengthList;

    Element * elementSelected;

    QList<Element*> * elementListSelected;

    QList<QList<Element*>*> * elementList;

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

public:
    LevelCreatorScene();

    void initNewList();

};

#endif // LEVELCREATORSCENE_H

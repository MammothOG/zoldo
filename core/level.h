#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>


class Element;

class Unit;

class Background;

class Level
{
private:
    int height;

    int width;

    QString name;

    QList<Element*> * elementList;

    QList<Unit*> * unitList;

    Background * background;

    int spawnX;

    int spawnY;

public:
    Level();

    void generateTestLevel();

    void clearLevel();

    Background * getBackground() const;

    QList<Element*> * getElementList() const;

    QList<Unit*> * getUnitList() const;

    int getSpawnX() const;

    int getSpawnY() const;

    void setElementList(QList<Element *> *value);

    void setUnitList(QList<Unit *> *value);

    void setBackground(Background *value);

    void setSpawn(int X, int Y);

};

#endif // LEVEL_H

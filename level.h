#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>


class Element;

class Unit;

class Background;

class Level
{
private:
    QList<Element*> * elementList;

    QList<Unit*> * unitList;

    int difficulty;

    QString backgroundPath;

    Background * background;

    QString name;

    int height;

    int width;

    int spawnX;

    int spawnY;

public:
    Level();

    void generateTestLevel();

    void clearLevel();

    Background * getBackground() const;

    QList<Element*> * getElementList() const;

    QList<Unit*> * getUnitList() const;
};

#endif // LEVEL_H

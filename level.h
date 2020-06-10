#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

#include "element.h"
#include "unit.h"
#include "wall.h"
#include "config.h"
#include "enemy.h"

class Level
{
private:
    QList<Element*> * elementList;

    QList<Unit*> * unitList;

    int difficulty;

    QString backgroundPath;

    QImage background;

    QString name;

    int height;

    int width;

    int spawnX;

    int spawnY;

public:
    Level();

    void generateTestLevel();

    void clearLevel();

    QImage getBackground() const;

    QList<Element*> * getElementList() const;

    QList<Unit*> * getUnitList() const;
};

#endif // LEVEL_H

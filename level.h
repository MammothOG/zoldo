#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>

#import <element.h>
#import <unit.h>

class Level
{
private:
    QList<Element*> * elementList;

    QList<Unit*> * unitList;

    int difficulty;

public:
    Level();
};

#endif // LEVEL_H

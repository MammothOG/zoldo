#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QFile>


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

    void saveElement(QFile * levelFile, Element * elemen);

public:
    Level();

    void generateTestLevel();

    void clearLevel();

    Background * getBackground() const;

    QList<Element*> * getElementList() const;

    QList<Unit*> * getUnitList() const;

    int getSpawnX() const;

    int getSpawnY() const;

    void appendLevelElement(Element * element);

    void setElementList(QList<Element *> *value);

    void setUnitList(QList<Unit *> *value);

    void setBackground(Background *value);

    void setSpawn(int X, int Y);

    bool save();

    bool load(QString levelName);

    QString getName() const;

    void setName(const QString &value);
};

#endif // LEVEL_H

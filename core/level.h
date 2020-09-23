#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QFile>
#include <QSound>


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

    bool levelDone;

    float spawnX;

    float spawnY;

    void saveElement(QFile * levelFile, Element * elemen);

public:
    Level();

    ~Level();

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

    bool isLevelDone() const;

    void setLevelDone(bool value);
};

#endif // LEVEL_H

#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Element :  public QObject, public QGraphicsPixmapItem
{
protected:
    int width;

    int height;

    int spawnX;

    int spawnY;

public:
    Element();

    Element(int height,int width);

    int getWidth() const;

    void setWidth(int value);

    int getHeight() const;

    void setHeight(int value);

    void setSprite(QString ressource);

    int getSpawnX() const;

    void setSpawnX(int value);

    int getSpawnY() const;

    void setSpawnY(int value);

    void respawn();

};

#endif // ELEMENT_H

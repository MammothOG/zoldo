#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Element :  public QObject, public QGraphicsPixmapItem
{
protected:
    int width;

    int height;


public:
    Element();

    Element(int height,int width);

    int getWidth() const;

    void setWidth(int value);

    int getHeight() const;

    void setHeight(int value);

    void setSprite(QString ressource);

};

#endif // ELEMENT_H

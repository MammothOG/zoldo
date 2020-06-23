#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QGraphicsPixmapItem>


enum ElementType {
    ELEMENT,
    BACKGROUND,
    BLOCK,
    PLAYER,
    ENEMY,
    UNIT,
    UNIT_ANIMATE,
    PROJECTILE,
    CUSTOM_BUTTON,
};

class Element :  public QObject, public QGraphicsPixmapItem
{
protected:
    int type;

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

    void setCenterAsReferencial();

    int getType() const;
};

#endif // ELEMENT_H

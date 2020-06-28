#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QGraphicsPixmapItem>


enum ElementType {
    PLAYER,
    ELEMENT,
    BACKGROUND,
    BLOCK,
    ENEMY,
    UNIT,
    UNIT_ANIMATE,
    PROJECTILE,
    CUSTOM_BUTTON,
};

enum ElementName {
    WALL,
    WATER,
    TEST_BACKGROUND,
    TESTATOR,
    PLAYER_TEST,
};


class Element :  public QObject, public QGraphicsPixmapItem
{
protected:
    int type;

    int elementName;

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

    int getElementName() const;
};

#endif // ELEMENT_H

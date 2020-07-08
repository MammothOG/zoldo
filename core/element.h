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
    TEST_PROJECTILE,
    DOOR,
};


class Element :  public QObject, public QGraphicsPixmapItem
{
private:
    int type;

    int elementName;

    int width;

    int height;

    int collider;

protected:
    void setElementName(int value);

    void setType(int value);

public:
    Element();

    Element(int height,int width);

    bool isColliding(Element * element);

    virtual void onCollision(Element * element){};

    int getTop() const;

    int getBottom() const;

    int getLeft() const;

    int getRight() const;

    int getWidth() const;

    void setWidth(int value);

    int getHeight() const;

    void setHeight(int value);

    void setSprite(QString ressource);

    void setCenterAsReferencial();

    int getType() const;

    int getElementName() const;

    int getCollider() const;

    void setCollider(int value);

    bool isOutside();

    virtual void onOutside() {};
};

#endif // ELEMENT_H

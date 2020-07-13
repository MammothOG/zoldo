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
    WALL,
    WATER,
    TEST_BACKGROUND,
    TESTATOR,
    PLAYER_TEST,
    TEST_PROJECTILE,
    DOOR,
    LINK,
};

class Element :  public QObject, public QGraphicsPixmapItem
{
private:
    QList<int> type;

    int elementName;

    int width;

    int height;

    int collider;

    bool centralReferential;

    bool exit;

    bool activated;

protected:
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

    QList<int> types() const;

    bool isType(int value) const;

    int getCollider() const;

    void setCollider(int value);

    bool isInside();

    virtual void onOutside() {};

    void activate();

    virtual void onActivate() {};

    bool isExit() const;

    void setExit(bool value);

    bool isActivated() const;

    void setActivated(bool value);
};

#endif // ELEMENT_H

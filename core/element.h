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
    DOOR,
    WATER,

    TEST_BACKGROUND,

    TESTATOR,
    BAT_ENEMY,
    GARBAGE_ENEMY,
    GHOST_ENEMY,
    DESPICABLE_BOSS,

    TEST_PROJECTILE,
    DIRTY_BALL,
    ARROW,
    STONE,
    FIREBALL,
    AIR_GUST,

    PLAYER_TEST,
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

    float defaultRotation;

    QString styleDir;

    QString imageName;

protected:
    void setType(int value);

    void setStyleDir(const QString &value);

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

    void setWidth(float value);

    int getHeight() const;

    void setHeight(float value);

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

    void setOrientation(int dirX, int dirY);

    float getDefaultRotation() const;

    void setDefaultRotation(float value);

    void resetRotation();

    bool setStyle(QString imageName);

    void mirroringY();

    void mirroringX();

    QString getStyleDir() const;

    QString getImageName() const;

    void setImageName(const QString &value);
};

#endif // ELEMENT_H

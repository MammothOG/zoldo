#include "element.h"

Element::Element()
{
    height = 0;
    width = 0;
}

Element::Element(int height, int width)
{
    this->height = height;
    this->width = width;
}

void Element::setSprite(QString ressource)
{
    // set graphic
    QPixmap img = QPixmap(ressource);
    img = img.scaled(width,height);

    setPixmap(img);

}

// getter and setter
int Element::getWidth() const
{
    return width;
}

void Element::setWidth(int value)
{
    width = value;
}

int Element::getHeight() const
{
    return height;
}

void Element::setHeight(int value)
{
    height = value;
}

int Element::getSpawnX() const
{
    return spawnX;
}

void Element::setSpawnX(int value)
{
    spawnX = value;
}

int Element::getSpawnY() const
{
    return spawnY;
}

void Element::setSpawnY(int value)
{
    spawnY = value;
}

void Element::respawn()
{
    setPos(spawnX,spawnY);
}

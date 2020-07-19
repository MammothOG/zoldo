#include "element.h"

#include <math.h>

#include "config.h"


Element::Element()
{
    setType(ELEMENT);

    collider = false;

    height = 0;
    width = 0;

    centralReferential = false;

    exit = false;

    defaultRotation = 0;
}

Element::Element(int height, int width)
{
    this->height = height;
    this->width = width;
}

bool Element::isColliding(Element *element)
{
    if (this->getBottom() > element->getTop() &&
            this->getTop() < element->getBottom() &&
            this->getLeft() < element->getRight() &&
            this->getRight() > element->getLeft()) {
        onCollision(element);
        return true;
    }
    else {
        return false;
    }
}

int Element::getTop() const
{
    return this->y() + this->offset().x();
}

int Element::getBottom() const
{
    return this->y() + this->height + this->offset().y();
}

int Element::getLeft() const
{
    return this->x() + this->offset().x(); // left
}

int Element::getRight() const
{
    return this->x() + this->width + this->offset().x(); // right
}

void Element::setSprite(QString ressource)
{
    // set graphic
    QPixmap img = QPixmap(ressource);
    img = img.scaled(width, height);

    setPixmap(img);

}

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

void Element::setCenterAsReferencial()
{
    setOffset(-width/2, -height/2);
    centralReferential = true;
}

QList<int> Element::types() const
{
    return type;
}

bool Element::isType(int value) const
{
    return type.contains(value);
}

int Element::getCollider() const
{
    return collider;
}

void Element::setCollider(int value)
{
    collider = value;
}

bool Element::isInside()
{
    int leftBorder = -offset().rx();
    int topBorder = -offset().ry();
    int rightBorder = BLOCKSIZE * HORIZONTAL_BLOCK - width - offset().rx();
    int bottomBorder = BLOCKSIZE * VERTICAL_BLOCK - height - offset().ry();

    if (this->x() > leftBorder &&
            this->y() > topBorder &&
            this->x() < rightBorder &&
            this->y() < bottomBorder)
    {
        return true;
    }
    else {
        onOutside();
        return false;
    }

}

void Element::activate()
{
    activated = true;
    onActivate();
}

bool Element::isExit() const
{
    return exit;
}

void Element::setExit(bool value)
{
    exit = value;
}

bool Element::isActivated() const
{
    return activated;
}

void Element::setActivated(bool value)
{
    activated = value;
}

float Element::getDefaultRotation() const
{
    return defaultRotation;
}

void Element::setDefaultRotation(float value)
{
    defaultRotation = value;
    setRotation(defaultRotation);
}

void Element::setType(int value)
{
    type.append(value);
}

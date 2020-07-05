#include "element.h"


Element::Element()
{
    type = ELEMENT;

    collider = false;

    height = 0;
    width = 0;
}

Element::Element(int height, int width)
{
    this->height = height;
    this->width = width;
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
}

int Element::getType() const
{
    return type;
}

int Element::getElementName() const
{
    return elementName;
}

int Element::getCollider() const
{
    return collider;
}

void Element::setCollider(int value)
{
    collider = value;
}

bool Element::isInScene(int width, int height)
{
    if (this->x() > 0 &&
            this->y() > 0 &&
            this->x() < width &&
            this->y() < height)
    {
        return true;
    }
    else {
        return false;
    }

}

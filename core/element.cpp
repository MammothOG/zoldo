#include "element.h"


Element::Element()
{
    type = ELEMENT;

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
    img = img.scaled(width, height);

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

void Element::setCenterAsReferencial()
{
    setOffset(-width/2, -height/2);
}

int Element::getType() const
{
    return type;
}

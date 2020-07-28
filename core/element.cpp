#include "element.h"

#include <math.h>
#include <QTransform>
#include <QDir>

#include "config.h"


Element::Element()
{
    setType(ELEMENT);


    height = 0;
    width = 0;

    collider = false;

    centralReferential = false;
    activated = false;
    exit = false;

    defaultRotation = 0;

    styleDir = "";

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

void Element::setWidth(float value)
{
    width = value * BLOCKSIZE;
}

int Element::getHeight() const
{
    return height;
}

void Element::setHeight(float value)
{
    height = value * BLOCKSIZE;
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
    if(!activated) {
        activated = true;
        onActivate();
    }
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
    resetRotation();
}

void Element::resetRotation()
{
    setRotation(defaultRotation);
}

bool Element::setStyle(QString styleName)
{
    this->imageName = styleName;

    QDir styleDirectory(":/ressources/images/" + styleDir);
    if(!styleDirectory.exists())
        QDir().mkdir(QString(styleDir));

    QString path = QString(":/ressources/images/%1/%2.png").arg(styleDir).arg(styleName);

    QFile styleFile(path);
    if(!styleFile.exists())
    {
        qDebug() << "File does't exist :" << path;
        return false;
    }

    setSprite(path);

    return true;
}

QString Element::getStyleDir() const
{
    return styleDir;
}

void Element::setStyleDir(const QString &value)
{
    styleDir = value;
}

QString Element::getImageName() const
{
    return imageName;
}

void Element::setImageName(const QString &value)
{
    imageName = value;
}

void Element::setType(int value)
{
    type.append(value);
}

void Element::mirroringY()
{
    setTransform(QTransform().scale(-1, 1));
    setOffset(offset().rx() - width, offset().ry());
}

void Element::mirroringX()
{
    setTransform(QTransform().scale(1, -1));
    setOffset(offset().rx(), offset().ry() - height);
}

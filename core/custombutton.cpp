#include "custombutton.h"
#include "element.h"


CustomButton::CustomButton()
{
    setZValue(1);
}

QString CustomButton::getIdleImage() const
{
    return idleImage;
}

void CustomButton::setIdleImage(const QString &idleImage)
{
    this->idleImage = idleImage;
    setSprite(idleImage);
}

QString CustomButton::getClickImage() const
{
    return clickImage;
}

void CustomButton::setClickImage(const QString &clickImage)
{
    this->clickImage = clickImage;
}

void CustomButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setSprite(clickImage);
    emit onPressClick();
}

void CustomButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setSprite(idleImage);
    emit onReleaseClick();
}



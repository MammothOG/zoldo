#include "custombutton.h"
#include "element.h"


CustomButton::CustomButton()
{
    setType(CUSTOM_BUTTON);

    holdPressed = false;

    setZValue(1);
}

void CustomButton::setPressed(bool isPressed)
{
    if (isPressed)
    {
        setSprite(clickImage);
    }
    else
    {
        setSprite(idleImage);
    }
}

void CustomButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setSprite(clickImage);
    emit onPressClick();

}

void CustomButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (!holdPressed)
    {
        setSprite(idleImage);
    }
    emit onReleaseClick();

    onClick();
}

void CustomButton::onClick() {}

bool CustomButton::getHoldPressed() const
{
    return holdPressed;
}

void CustomButton::setHoldPressed(bool value)
{
    holdPressed = value;
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


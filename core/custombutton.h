#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QGraphicsItemGroup>


#include "core/element.h"

class CustomButton : public Element
{
    Q_OBJECT

private:
    QString idleImage;

    QString clickImage;

    bool holdPressed;

protected:
    virtual void onClick();

signals:
    void onPressClick();

    void onReleaseClick();

public:
    CustomButton();

    QString getIdleImage() const;

    void setIdleImage(const QString &value);

    QString getClickImage() const;

    void setClickImage(const QString &value);

    void setPressed(bool isPressed);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    bool getHoldPressed() const;

    void setHoldPressed(bool value);
};

#endif // CUSTOMBUTTON_H

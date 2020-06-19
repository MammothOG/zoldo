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

signals:
    void onPressClick();

    void onReleaseClick();

public:
    CustomButton();

    QString getIdleImage() const;

    void setIdleImage(const QString &value);

    QString getClickImage() const;

    void setClickImage(const QString &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMBUTTON_H

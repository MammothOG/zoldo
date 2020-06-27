#ifndef QUITBUTTON_H
#define QUITBUTTON_H

#include "core/custombutton.h"

class QuitButton : public CustomButton
{
public:
    QuitButton();

    void onClick() override;
};

#endif // QUITBUTTON_H

#include "settingbutton.h"

#include "config.h"


SettingButton::SettingButton()
{
    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);

    setIdleImage(":/ressources/images/buttons/setting-frame-0.png");
    setClickImage(":/ressources/images/buttons/setting-frame-1.png");
}

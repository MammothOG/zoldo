#include "settingbutton.h"

#include "config.h"


SettingButton::SettingButton()
{
    setHeight(BLOCKSIZE);
    setWidth(BLOCKSIZE);

    setIdleImage(":/ressources/images/buttons/setting-frame-0.png");
    setClickImage(":/ressources/images/buttons/setting-frame-1.png");
}

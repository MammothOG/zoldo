#include "resumebutton.h"
#include "config.h"


ResumeButton::ResumeButton()
{
    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);

    setIdleImage(":/ressources/images/buttons/resume-frame-0.png");
    setClickImage(":/ressources/images/buttons/resume-frame-1.png");

    setCenterAsReferencial();

}

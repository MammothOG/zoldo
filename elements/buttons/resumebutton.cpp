#include "resumebutton.h"
#include "config.h"


ResumeButton::ResumeButton()
{
    setHeight(1);
    setWidth(1);

    setIdleImage(":/ressources/images/buttons/resume-frame-0.png");
    setClickImage(":/ressources/images/buttons/resume-frame-1.png");

    setCenterAsReferencial();

}

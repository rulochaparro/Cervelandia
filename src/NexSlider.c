#include "NexSlider.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utilities.h"

extern char buf[12];
extern char cmd[64];

unsigned short NexSlider_getValue(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".val");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_setValue(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".val=");
    strcat(cmd, buf);

    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexSlider_Get_background_color_bco(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".bco");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_Set_background_color_bco(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".bco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, slider->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexSlider_Get_font_color_pco(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".pco");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_Set_font_color_pco(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".pco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, slider->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexSlider_Get_pointer_thickness_wid(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".wid");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_Set_pointer_thickness_wid(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".wid=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, slider->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexSlider_Get_cursor_height_hig(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".hig");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_Set_cursor_height_hig(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".hig=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, slider->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexSlider_getMaxval(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".maxval");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_setMaxval(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".maxval=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, slider->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexSlider_getMinval(struct NexObject *slider, unsigned long *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, slider->__name);
    strcat(cmd, ".minval");
    sendCommand(cmd);
    return recvRetNumber(number);
}

unsigned short NexSlider_setMinval(struct NexObject *slider, unsigned long number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, slider->__name);
    strcat(cmd, ".minval=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, slider->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

/**
 * @file NexNumber.cpp
 *
 * The implementation of class NexNumber. 
 *
 * @author  huang xianming (email:<xianming.huang@itead.cc>)
 * @date    2015/8/13
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software); you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation); either version 2 of
 * the License, or (at your option) any later version.
 */
#include "NexNumber.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utilities.h"

extern char cmd[64];
extern char buf[12];



unsigned short NexNumber_getValue(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".val");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_setValue(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".val=");
    strcat(cmd, buf);

    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_background_color_bco(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".bco");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_background_color_bco(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".bco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_font_color_pco(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".pco");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_font_color_pco(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".pco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_place_xcen(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".xcen");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_place_xcen(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".xcen=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_place_ycen(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".ycen");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_place_ycen(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".ycen=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_getFont(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".font");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_setFont(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".font=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_number_lenth(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".lenth");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_number_lenth(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".lenth=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_background_crop_picc(struct NexObject *number, unsigned long *num)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, number->__name);
    strcat(cmd, ".picc");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_background_crop_picc(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".picc=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

unsigned long NexNumber_Get_background_image_pic(struct NexObject *number, unsigned long *num)
{
    char cmd[32] = "get ";
    strcat(cmd, number->__name);
    strcat(cmd, ".pic");
    sendCommand(cmd);
    return recvRetNumber(num);
}

unsigned short NexNumber_Set_background_image_pic(struct NexObject *number, unsigned long num)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, num, 10);
    strcat(cmd, number->__name);
    strcat(cmd, ".pic=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, number->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

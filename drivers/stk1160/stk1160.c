/******************************************************************************
Copyright 2008-2009, Freie Universitaet Berlin (FUB). All rights reserved.

These sources were developed at the Freie Universitaet Berlin, Computer Systems
and Telematics group (http://cst.mi.fu-berlin.de).
-------------------------------------------------------------------------------
This file is part of RIOT.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

RIOT is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see http://www.gnu.org/licenses/ .
*******************************************************************************/

/**
 * @ingroup stk1160
 * @{
 */

/**
 * @file
 * @brief       STK1160 Video Grabber
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author      Philipp Rosenkranz <philipp.rosenkranz@fu-berlin>
 * @author      Maximilian Ferdinand Müller <m.f.mueller@fu-berlin.de>
 */

#include <debug.h>
#include <hwtimer.h>
#include <stk1160.h>
#include "stk1160-reg.h"
#include <stk1160_arch.h>
#include <usb.h>

void stk1160_init(void)
{
    DEBUG("stk1160_init");
    stk1160_arch_init();
}

int stk1160_read_reg(uint16_t reg, uint8_t* val) 
{
    int ret;

    ret = usb_control_msg(USB_ENDPOINT_IN | USB_REQUEST_TYPE_VENDOR | USB_RECIPIENT_DEVICE,
                          0x00, 0x00, reg, sizeof(uint8_t), val, 100);

    if (ret < 0)
    {
        printf("stk1160_read_reg: read failed on reg 0x%x (%d)\n", reg, ret);
        return ret;
    }

    return 0;
}
 
int stk1160_write_reg(uint16_t reg, uint16_t val) 
{
    int ret;

    ret = usb_control_msg(USB_ENDPOINT_OUT | USB_REQUEST_TYPE_VENDOR | USB_RECIPIENT_DEVICE,
                          0x01, val, reg, 0, NULL, 100);

    if (ret < 0)
    {
        printf("stk1160_write_reg: write failed on reg 0x%x (%d)\n", reg, ret);
        return ret;
    }

    return 0;
}

void stk1160_set_videosource(stk1160_video_source source)
{
    int ret = stk1160_write_reg(STK1160_GCTRL, source);
    printf("stk1160_set_videosource: stk1160_write_reg(%d, %x) returned %d\n", STK1160_GCTRL, source, ret);
}

/** @} */

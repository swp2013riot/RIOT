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

#define STK1160_I2C_TIMEOUT 100

/* copied from linux 3.9 stk1160-i2c.c */
static int stk1160_i2c_busy_wait(uint8_t wait_bit_mask)
{
    unsigned long end;
    uint8_t flag;
    
    end = hwtimer_now() + HWTIMER_TICKS(1000*1000);
    while (hwtimer_now() < end)
    {
        stk1160_read_reg(STK1160_SICTL + 1, &flag);
        
        if (flag & wait_bit_mask)
        {
            goto done;
        }
        
        hwtimer_wait(HWTIMER_TICKS(10*1000));
    }

    return -1;
    
    done:
    return 0;
}

static int stk1160_i2c_write_reg(uint8_t addr, uint8_t reg, uint8_t value)
{
    int rc;

    /* Set serial device address */
    rc = stk1160_write_reg(STK1160_SICTL_SDA, addr);
    if (rc < 0)
        return rc;

    /* Set i2c device register sub-address */
    rc = stk1160_write_reg(STK1160_SBUSW_WA, reg);
    if (rc < 0)
        return rc;

    /* Set i2c device register value */
    rc = stk1160_write_reg(STK1160_SBUSW_WD, value);
    if (rc < 0)
        return rc;

    /* Start write now */
    rc = stk1160_write_reg(STK1160_SICTL, 0x01);
    if (rc < 0)
        return rc;

    rc = stk1160_i2c_busy_wait(0x04);
    if (rc < 0)
        return rc;

    return 0;
}

static int stk1160_i2c_read_reg(uint8_t addr, uint8_t reg, uint8_t *value)
{
    int rc;

    /* Set serial device address */
    rc = stk1160_write_reg(STK1160_SICTL_SDA, addr);
    if (rc < 0)
        return rc;

    /* Set i2c device register sub-address */
    rc = stk1160_write_reg(STK1160_SBUSR_RA, reg);
    if (rc < 0)
        return rc;

    /* Start read now */
    rc = stk1160_write_reg(STK1160_SICTL, 0x20);
    if (rc < 0)
        return rc;

    rc = stk1160_i2c_busy_wait(0x01);
    if (rc < 0)
        return rc;

    stk1160_read_reg(STK1160_SBUSR_RD, value);
    if (rc < 0)
        return rc;

    return 0;
}

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

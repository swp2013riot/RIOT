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
--------------------------------------------------------------------------------
For further information and questions please use the web site
    http://scatterweb.mi.fu-berlin.de
and the mailinglist (subscription via web site)
    scatterweb@lists.spline.inf.fu-berlin.de
*******************************************************************************/

#ifndef __STK1160_ARCH_H
#define __STK1160_ARCH_H 

/**
 * @defgroup    stk1160 STK1160 
 * @ingroup     drivers
 * @{
 */

/**
 * @file
 * @brief       STK1160 
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author      Philipp Rosenkranz, Freie Universität Berlin <philipp.rosenkranz@fu-berlin.de>
 * @author      Maximilian Müller, Freie Universität Berlin <m.f.mueller@fu-berlin.de>
 */

typedef void (*stk1160_process_data_cb_handler)(uint8_t*, uint16_t);

/** board specific stk1160 initialization */
void stk1160_arch_init(void);

int usb_control_msg(uint8_t bRequestType,
                    uint8_t bRequest,
                    uint16_t wValue,
                    uint16_t wIndex,
                    uint16_t wLength,
                    void* data,
                    unsigned int timeout);

int init_iso_transfer(int num_iso_packets, int buffer_size, stk1160_process_data_cb_handler handler);

void iso_handler(struct libusb_transfer *transfer);

void libusb_event_handling_thread(void);

/** * @} */
#endif /* __STK1160_ARCH_H */

/******************************************************************************
Copyright 2013, Freie Universitaet Berlin (FUB). All rights reserved.
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

#ifndef __STK1160_ARCH_H
#define __STK1160_ARCH_H 

/**
 * @ingroup     stk1160
 * @{
 */

/**
 * @file
 * @brief       STK1160/SAA711X USB-video-grabber driver
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author      Philipp Rosenkranz, Freie Universität Berlin <philipp.rosenkranz@fu-berlin.de>
 * @author      Maximilian Müller, Freie Universität Berlin <m.f.mueller@fu-berlin.de>
 */

/** 
 * @file
 * @typedef stk1160_process_data_cb_handler
 * @brief a handler which is executed whenever video data is received.
 * The first argument is a pointer to the video data buffer. The second
 * argument is the length in bytes of the received video data.
 */
typedef void (*stk1160_process_data_cb_handler)(uint8_t*, uint16_t);

/**
 * @brief finds and reserves the usb-video-grabber for further use by this driver.
 */ 
void stk1160_arch_init(void);

/**
 * @brief Sends a synchronous usb control message
 */
int usb_control_msg(uint8_t bRequestType,
                    uint8_t bRequest,
                    uint16_t wValue,
                    uint16_t wIndex,
                    uint16_t wLength,
                    void* data,
                    unsigned int timeout);

/**
 * @brief Initializes the isochronous data transfer between host and STK1160.
 * 
 * @param num_iso_packets the number of packets to use. 
 * @param buffer_size the buffer size to be reserved for each packet
 * @param handler a handler which is called when new video data is ready for processing
 */
int init_iso_transfer(int num_iso_packets, int buffer_size, stk1160_process_data_cb_handler handler);

/**
 * @brief This function is called each time a new packet (!) arrives.
 * 
 * It extracts video data from the packet, calls the handler function 
 * with this video data and resends a new empty packet to the grabber.
 * 
 * @note This function is more or less libusb specific and should be 
 * refactored. 
 */
void iso_handler(struct libusb_transfer *transfer);

/**
 * @note This function is more or less libusb specific and should be 
 * refactored. 
 */
void libusb_event_handling_thread(void);

/** * @} */
#endif /* __STK1160_ARCH_H */

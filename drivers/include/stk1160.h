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

#ifndef __STK1160_H
#define __STK1160_H

#include <stk1160_arch.h>

/**
 * @defgroup stk1160 STK1160/SAA711X USB-video-grabber driver
 * @ingroup  driver
 * @{
 */

/**
 * @file	
 * @brief       STK1160/SAA711X USB-video-grabber driver
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author      Philipp Rosenkranz <philipp.rosenkranz@fu-berlin>
 * @author      Maximilian Ferdinand Müller <m.f.mueller@fu-berlin.de>
 */

/** 
 * @enum stk1160_video_source
 * @brief specifies valid video source values
 */
typedef enum 
{
    STK1160_VIDEO_SOURCE_COMPOSITE0 = 0x98,
    STK1160_VIDEO_SOURCE_COMPOSITE1 = 0x90,
    STK1160_VIDEO_SOURCE_COMPOSITE2 = 0x88,
    STK1160_VIDEO_SOURCE_COMPOSITE3 = 0x80
}
stk1160_video_source;

#define STK1160_REGVAL_TO_VIDEOSOURCE(x) (x+0x80)

/**
 * @brief Initializes the STK1160 driver.
 */
void stk1160_init(void);

/** 
 * @brief       Terminates the STK1160 driver
 * @todo	Implement
 */
void stk1160_terminate(void);

/**
 * @brief Reads the contents of a register reg and stores that value into val
 * 
 * @param reg a register address on the stk1160
 * @param [out] val the read value will be stored in val
 * 
 * @retval 0 on success
 * @retval !=0 failure
 */ 
int stk1160_read_reg(uint16_t reg, uint8_t* val);

/**
 * @brief Writes the contents of val into register reg 
 * 
 * @param reg a register address on the stk1160
 * @param [in] val the value to be written into reg
 * 
 * @retval 0 on success
 * @retval !=0 failure
 */ 
int stk1160_write_reg(uint16_t reg, uint16_t val);

/**
 * @brief Sets the video input to a specified source.
 * 
 * @param stk1160_video_source a valid video source.
 * 
 * @retval 0 on success
 * @retval !=0 failure
 */ 
int stk1160_set_videosource(stk1160_video_source);

/**
 * @brief Starts video data streaming.
 * 
 * This Function initializes the data transfer between the video
 * chip (saa711x), the gateway chip (stk1160) and the Host. 
 * The supplied handler function is called every time a new piece
 * of video data is received.
 *  
 * @param handler a function which processes the received video data.
 * 
 * @retval 0 on success
 * @retval !=0 failure
 */ 
int stk1160_start_streaming(stk1160_process_data_cb_handler handler);

/** @} */

#endif /* __STK1160_H */

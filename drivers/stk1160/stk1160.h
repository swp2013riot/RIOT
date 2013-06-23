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
#if 0
enum stk1160_video_source
{
    STK1160_VIDEO_SOURCE_COMPOSITE,
    STK1160_VIDEO_SOURCE_SVIDEO
};

/** 
 * @brief       Initializes the STK1160 driver
 */
void stk1160_init(void);

/** 
 * @brief       Terminates the STK1160 driver
 */
void stk1160_terminate(void);

/**
 * @brief chooses the video source
 * @return zero on success, non-zero otherwise
 */
int stk1160_set_videosource(stk1160_video_source);

/**
 * @brief starts streaming
 * @return zero on success, non-zero otherwise
 */
int stk1160_start_streaming(void);
#endif

/** @} */

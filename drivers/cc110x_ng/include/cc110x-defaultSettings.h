/******************************************************************************
Copyright 2008, Freie Universitaet Berlin (FUB). All rights reserved.

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

#ifndef CC1100_DEFAULTSETTINGS_H
#define CC1100_DEFAULTSETTINGS_H

/**
 * @ingroup		dev_cc110x
 * @{
 */

/**
 * @file
 * @brief		TI Chipcon CC110x default settings
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author		Thomas Hillebrandt <hillebra@inf.fu-berlin.de>
 * @author		Heiko Will <hwill@inf.fu-berlin.de>
 * @version     $Revision: 2139 $
 *
 * @note		$Id: cc110x-defaultSettings.h 2139 2010-05-26 08:04:04Z hillebra $
 */

#include <stdint.h>

// returns hwtimer ticks per us
#define RTIMER_TICKS(us) HWTIMER_TICKS(us)

#define TIMER_TICK_USEC_RES 	(122)

// Default PA table index (output power)
#define PATABLE 				(11)

// Watchdog cycle time in seconds, set 0 to disable watchdog
#define CC1100_WATCHDOG_PERIOD	(5)

// Number of transmission retries for unicast packets (constant RX mode)
#define TRANSMISSION_RETRIES_CRX_UC		(5)

// Number of transmission retries for unicast packets (WOR mode)
#define TRANSMISSION_RETRIES_WOR_UC		(1)

// Number of transmission retries for broadcast packets (constant RX mode)
#define TRANSMISSION_RETRIES_CRX_BC		(0)

// Number of transmission retries for broadcast packets (WOR mode)
#define TRANSMISSION_RETRIES_WOR_BC		(0)

// Time before chip goes back to RX (= stays in PWD after incoming packet)
#define WOR_TIMEOUT_1			(3200)	// ~ 32 milliseconds

// Time before chip goes back to WOR (= stays in RX after elapsed WOR_TIMEOUT_1)
#define WOR_TIMEOUT_2			(800)	// ~ 8 milliseconds

// XOSC startup + FS calibration (300 + 809 us  ~ 1.38 ms)
#define FS_CAL_TIME				RTIMER_TICKS(12 * TIMER_TICK_USEC_RES)

// Manual FS calibration (721 us)
#define MANUAL_FS_CAL_TIME 		RTIMER_TICKS(7 * TIMER_TICK_USEC_RES)

// Reset wait time (in reset procedure)
#define RESET_WAIT_TIME			RTIMER_TICKS(4 * TIMER_TICK_USEC_RES)

// Time chip needs to go to RX
#define IDLE_TO_RX_TIME			RTIMER_TICKS(1 * TIMER_TICK_USEC_RES)

// Time chip needs to go to RX and CS signal is ready
#define CS_READY_TIME			RTIMER_TICKS(3 * TIMER_TICK_USEC_RES)

// Default RX interval for WOR in milliseconds
#define T_RX_INTERVAL			(542)

// Time of packet interval in microseconds (at 400 kbps)
#define T_PACKET_INTERVAL		(3800)

// The size of the configuration array for CC1100 in bytes
#define CC1100_CONF_SIZE 		(39)

// The default channel number (0-24) for CC1100
#define CC1100_DEFAULT_CHANNR	(0)

// Burst retry to TX switch time (measured ~ 230 us)
#define BURST_RETRY_TX_SWITCH_TIME	(23)


/** @} */
#endif

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

/**
 * @ingroup stk1160
 * @{
 */

/**
 * @file
 * @brief       STK1160 Coulomb Counter
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author      Heiko Will
 * @author      Kaspar Schleiser <kaspar.schleiser@fu-berlin.de>
 */

#include <hwtimer.h>
#include "stk1160_arch.h"

void stk1160_init(void) {
    puts("stk1160_init");
    stk1160_arch_init();
}

void stk1160_start(void) {
    puts("stk1160_start");
}

void stk1160_stop(void) {
    puts("stk1160_stop");
}

/** @} */

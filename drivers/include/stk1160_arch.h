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
 * @defgroup    stk1160 STK1160 Coulomb Counter
 * @ingroup     drivers
 * @{
 */

/**
 * @file
 * @brief       STK1160 Coulomb Counter
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @author      Heiko Will
 * @version     $Revision: 1203 $
 *
 * @note        $Id: stk1160_arch.h 1203 2009-07-07 10:23:18Z baar $
 */

/** board specific stk1160 initialization */
void stk1160_arch_init(void);

/** * @} */
#endif /* __STK1160_ARCH_H */

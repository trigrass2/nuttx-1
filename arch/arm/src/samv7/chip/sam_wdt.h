/****************************************************************************************
 * arch/arm/src/samv7/chip/sam_wdt.h
 * Watchdog Timer (WDT) definitions for the SAMV71
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************/

#ifndef __ARCH_ARM_SRC_SAMV7_CHIP_SAM_WDT_H
#define __ARCH_ARM_SRC_SAMV7_CHIP_SAM_WDT_H

/****************************************************************************************
 * Included Files
 ****************************************************************************************/

#include <nuttx/config.h>
#include <arch/armv7/chip.h>

#include "chip/sam_memorymap.h"

/****************************************************************************************
 * Pre-processor Definitions
 ****************************************************************************************/

/* WDT register offsets *****************************************************************/

#define SAM_WDT_CR_OFFSET         0x00 /* Control Register */
#define SAM_WDT_MR_OFFSET         0x04 /* Mode Register */
#define SAM_WDT_SR_OFFSET         0x08 /* Status Register */

/* WDT register addresses ***************************************************************/

/* WDT0: Legacy Watchdog Timer */

#define SAM_WDT0_CR               (SAM_WDT0_BASE+SAM_WDT_CR_OFFSET)
#define SAM_WDT0_MR               (SAM_WDT0_BASE+SAM_WDT_MR_OFFSET)
#define SAM_WDT0_SR               (SAM_WDT0_BASE+SAM_WDT_SR_OFFSET)

/* WDT1: Reinforced Safety Watchdog Timer */

#define SAM_WDT1_CR               (SAM_WDT1_BASE+SAM_WDT_CR_OFFSET)
#define SAM_WDT1_MR               (SAM_WDT1_BASE+SAM_WDT_MR_OFFSET)
#define SAM_WDT1_SR               (SAM_WDT1_BASE+SAM_WDT_SR_OFFSET)

/* WDT register bit definitions *********************************************************/
/* Watchdog Timer Control Register */

#define WDT_CR_WDRSTT             (1 << 0)   /* Bit 0:  Watchdog Rest */
#define WDT_CR_KEY_SHIFT          (24)       /* Bits 24-31:  Password */
#define WDT_CR_KEY_MASK           (0xff << WDT_CR_KEY_SHIFT)
#  define WDT0_CR_KEY             (0xa5 << WDT_CR_KEY_SHIFT)
#  define WDT1_CR_KEY             (0xc4 << WDT_CR_KEY_SHIFT)

/* Watchdog Timer Mode Register */

#define WDT_MR_WDV_SHIFT          (0)       /* Bits 0-11:  Watchdog Counter Value */
#define WDT_MR_WDV_MAX            0xfff
#define WDT_MR_WDV_MASK           (WDT_MR_WDV_MAX << WDT_MR_WDV_SHIFT)
#  define WDT_MR_WDV(n)           ((uint32_t)(n) << WDT_MR_WDV_SHIFT)
#define WDT_MR_WDFIEN             (1 << 12) /* Bit 12: Watchdog Fault Interrupt Enable */
#define WDT_MR_WDRSTEN            (1 << 13) /* Bit 13: Watchdog Reset Enable */
#define WDT1_MR_WDRPROC           (1 << 14) /* Bit 14: Watchdog Reset Processor (WDT1 only) */
#define WDT_MR_WDDIS              (1 << 15) /* Bit 15: Watchdog Disable */
#define WDT_MR_WDD_SHIFT          (16)      /* Bits 16-27:  Watchdog Delta Value (WDT0 only) */
#define WDT_MR_WDD_MAX            0xfff
#define WDT_MR_WDD_MASK           (WDT_MR_WDD_MAX << WDT_MR_WDD_SHIFT)
#  define WDT0_MR_WDD(n)          ((uint32_t)(n) << WDT_MR_WDD_SHIFT)
#  define WDT1_MR_WDD_ALLONES     (0xfff << WDT_MR_WDD_SHIFT)
#define WDT_MR_WDDBGHLT           (1 << 28) /* Bit 28: Watchdog Debug Halt */
#define WDT_MR_WDIDLEHLT          (1 << 29) /* Bit 29: Watchdog Idle Halt */

/* Watchdog Timer Status Register */

#define WDT_SR_WDUNF              (1 << 0)  /* Bit 0:  Watchdog Underflow */
#define WDT0_SR_WDERR             (1 << 1)  /* Bit 1:  Watchdog Error (WDT0 only) */

/****************************************************************************************
 * Public Types
 ****************************************************************************************/

/****************************************************************************************
 * Public Data
 ****************************************************************************************/

/****************************************************************************************
 * Public Functions
 ****************************************************************************************/

#endif /* __ARCH_ARM_SRC_SAMV7_CHIP_SAM_WDT_H */
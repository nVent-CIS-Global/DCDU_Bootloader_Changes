/*******************************************************************************
  Timer/Counter(TC2) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_tc2.c

  Summary
    TC2 PLIB Implementation File.

  Description
    This file defines the interface to the TC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "plib_tc2.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: TC0 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Initialize the TC module in Timer mode */
void TC2_TimerInitialize( void )
{
    /* Reset TC */
    TC2_REGS->COUNT16.TC_CTRLA = TC_CTRLA_SWRST_Msk;

    while((TC2_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_SWRST_Msk) == TC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Write Synchronization */
    }

    /* Configure counter mode & prescaler */
    TC2_REGS->COUNT16.TC_CTRLA = TC_CTRLA_MODE_COUNT16 | TC_CTRLA_PRESCALER_DIV1 | TC_CTRLA_PRESCSYNC_PRESC ;

    /* Configure in Match Frequency Mode */
    TC2_REGS->COUNT16.TC_WAVE = TC_WAVE_WAVEGEN_MPWM;

    /* Configure timer period */
    TC2_REGS->COUNT16.TC_CC[0U] = 0;

    /* Clear all interrupt flags */
    TC2_REGS->COUNT16.TC_INTFLAG = TC_INTFLAG_Msk;



    while((TC2_REGS->COUNT16.TC_SYNCBUSY))
    {
        /* Wait for Write Synchronization */
    }
}

/* Enable the TC counter */
void TC2_TimerStart( void )
{
    TC2_REGS->COUNT16.TC_CTRLA |= TC_CTRLA_ENABLE_Msk;
    while((TC2_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk) == TC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

/* Disable the TC counter */
void TC2_TimerStop( void )
{
    TC2_REGS->COUNT16.TC_CTRLA &= ~TC_CTRLA_ENABLE_Msk;
    while((TC2_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk) == TC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

uint32_t TC2_TimerFrequencyGet( void )
{
    return (uint32_t)(48000000UL);
}

/* Get the current timer counter value */
uint16_t TC2_Timer16bitCounterGet( void )
{
    /* Write command to force COUNT register read synchronization */
    TC2_REGS->COUNT16.TC_CTRLBSET |= TC_CTRLBSET_CMD_READSYNC;

    while((TC2_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_CTRLB_Msk) == TC_SYNCBUSY_CTRLB_Msk)
    {
        /* Wait for Write Synchronization */
    }

    while((TC2_REGS->COUNT16.TC_CTRLBSET & TC_CTRLBSET_CMD_Msk) != 0)
    {
        /* Wait for CMD to become zero */
    }

    /* Read current count value */
    return (uint16_t)TC2_REGS->COUNT16.TC_COUNT;
}

/* Configure timer counter value */
void TC2_Timer16bitCounterSet( uint16_t count )
{
    TC2_REGS->COUNT16.TC_COUNT = count;

    while((TC2_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_COUNT_Msk) == TC_SYNCBUSY_COUNT_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

/* Configure timer period */
void TC2_Timer16bitPeriodSet( uint16_t period )
{
    TC2_REGS->COUNT16.TC_CC[0] = period;
    while((TC2_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_CC0_Msk) == TC_SYNCBUSY_CC0_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

/* Read the timer period value */
uint16_t TC2_Timer16bitPeriodGet( void )
{
    return (uint16_t)TC2_REGS->COUNT16.TC_CC[0];
}



/* Polling method to check if timer period interrupt flag is set */
bool TC2_TimerPeriodHasExpired( void )
{
    bool timer_status;
    timer_status = ((TC2_REGS->COUNT16.TC_INTFLAG) & TC_INTFLAG_OVF_Msk);
    TC2_REGS->COUNT16.TC_INTFLAG = timer_status;
    return timer_status;
}

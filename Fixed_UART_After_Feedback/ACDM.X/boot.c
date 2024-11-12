#include <stddef.h> 
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE

#include <xc.h>
#include "mcc_generated_files/system/interrupt.h"

typedef volatile unsigned long vu32;

////register unsigned int _msp     __asm("msp");
////register unsigned int _psp     __asm("psp");
//
//void (*jump2app)();
//
//void MSR_MSP ( unsigned int ulAddr )
//{
//	//_msp = ulAddr;
//	return;
//}
//
//
//
//void iap_load_app(unsigned int appxaddr)
//{
//
//    uint32_t app_check_address;
//    uint32_t *app_check_address_ptr;
//    /* Check if WDT is locked */
//    //if (!(WDT->CTRL.reg & WDT_CTRL_ALWAYSON)) {
//    /* Disable the Watchdog module */
//    //WDT->CTRL.reg &= ~WDT_CTRL_ENABLE;
//    //}
//    app_check_address = appxaddr;
//    app_check_address_ptr = (uint32_t *)app_check_address;
//    //board_init();
//    //if (port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
//    /* Button is pressed, run bootloader */
//    //return;
//    //}
//    if (*app_check_address_ptr == 0xFFFFFFFF) {
//    /* No application; run bootloader */
//    return;
//    }
//    /* Pointer to the Application Section */
//    void (*application_code_entry)(void);
//    /* Rebase the Stack Pointer */
//    __set_MSP(*(uint32_t *)APP_START_ADDRESS);
//    /* Rebase the vector table base address TODO: use RAM */
//    SCB->VTOR = ((uint32_t)APP_START_ADDRESS & SCB_VTOR_TBLOFF_Msk);
//    /* Load the Reset Handler address of the application */
//    application_code_entry = (void (*)(void))(unsigned *)(*(unsigned *)
//    (appxaddr + 4));
//    /* Jump to user Reset Handler in the application */
//    application_code_entry();
//}

void iap_load_app(unsigned int appxaddr)
{

    // Disable the Global High Interrupts 
    INTERRUPT_GlobalInterruptHighDisable(); 

    // Disable the Global Low Interrupts 
    INTERRUPT_GlobalInterruptLowDisable(); 
    ((void (*)(void))appxaddr)();
}

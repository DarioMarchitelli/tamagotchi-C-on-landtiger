/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD_advanced/GLCD.h" 
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "joystick/joystick.h"
#include "RIT/RIT.h"
#include "graphics/graphics.h"
#include "adc/adc.h"

#define SIMULATOR 1

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

volatile int x=160,y=120;

int main(void)

{
  SystemInit();  												/* System Initialization (i.e., PLL)              */
	
	
  LCD_Initialization();
	
	
	TP_Init();
	TouchPanel_Calibrate();
	
	init_timer(0, 0, 0, 3, 0x17D7840);    // 1 sec
	
	init_timer(1, 0, 0, 3, 0xBEBC20);    // 0,5 sec
	enable_timer(0);
	enable_timer(1);
	
	joystick_init();											/* Joystick Initialization            */
	init_RIT(0x2625A0);									/* RIT Initialization 25 msec       	25msec * 100MHz = 0x2625A0*/
	enable_RIT();													/* RIT enabled				  */
	ADC_init();
	
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	
	LPC_SC->PCONP |= (1<<22);        /* Abilito il timer 2      */
	LPC_SC->PCONP |= (1<<23);        /* Abilito il timer 3      */
	
  while (1)	
  {
		__ASM("wfi");
  }
}


/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

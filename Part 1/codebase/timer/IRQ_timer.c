/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../graphics/graphics.h"
#include "../GLCD_advanced/GLCD.h" 
#include "../RIT/RIT.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
volatile int age=0;
volatile int first_basic_shown=0;
volatile int first_escaped=0;
volatile int satiety=5,happiness=5;
volatile int decrease_happiness=0,decrease_satiety=0;
volatile int is_escaped = 0;
volatile int is_meal = 0;
volatile int is_snow = 0;
volatile int meal_count = 0;
volatile int snow_count = 0;
volatile int escape_count = 0;
volatile int dead_count = 0;
volatile int frame_basic_animation = 0;
extern int selected_item;

void incr_show_age(void){
	age++;
	show_age(age);
}

void decrease_show_satiety(void){
		if(decrease_satiety>=4){
			decrease_satiety=0;
			satiety--;
		}else{
			decrease_satiety++;
		}
		draw_satiety(satiety);
}

void decrease_show_happiness(void){
		if(decrease_happiness>=4){
			decrease_happiness=0;
			happiness--;
		}else{
			decrease_happiness++;
		}
		draw_happiness(happiness);
}


void TIMER0_IRQHandler (void){
	if(satiety == 0 || happiness == 0){
		disable_timer(0);
		is_escaped=1;
		dead_count++;
	}
	first_basic_shown++;
	if(first_basic_shown==1){
		basic_layout();
		show_age(age);
		enable_RIT();
	}
	
	/* Match register 0 interrupt service routine */
	if (LPC_TIM0->IR & 01)
	{
		draw_pou(frame_basic_animation,0,1);
		frame_basic_animation = !frame_basic_animation;
		if(is_escaped == 0){
			incr_show_age();
		}
		decrease_show_satiety();
		decrease_show_happiness();
		LPC_TIM0->IR = 1;			/* clear interrupt flag */
	}
	
	/* Match register 1 interrupt service routine */
	else if(LPC_TIM0->IR & 02)
	{
		LPC_TIM0->IR =  2 ;			/* clear interrupt flag */	
	}
	
	/* Match register 2 interrupt service routine */
	else if(LPC_TIM0->IR & 4){
		LPC_TIM0->IR =  4 ;			/* clear interrupt flag */	
	}
		/* Match register 3 interrupt service routine */
	else if(LPC_TIM0->IR & 8){
		LPC_TIM0->IR =  8 ;			/* clear interrupt flag */	
	}
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	if (LPC_TIM1->IR & 01){
		if(is_meal==1){
			disable_RIT();
			//meal!!
			meal(meal_count);
			meal_count++;
			if(meal_count == 5){
				selected_item = 0;
				is_meal=0;
				meal_count=0;
				first_basic_shown=0;
				//decrease_satiety = 0;
				if(satiety < 5){
					satiety++;
				}
				enable_timer(0);
			}
		}
		if(is_snow==1){
			disable_RIT();
			//snow!!
			snow(snow_count);
			snow_count++;
			if(snow_count == 5){
				selected_item = 0;
				is_snow=0;
				snow_count=0;
				first_basic_shown=0;
				//decrease_happiness = 0;
				if(happiness < 5){
					happiness++;
				}
				enable_timer(0);
			}
		}
		if(is_escaped==1){
			selected_item = 3;
			first_basic_shown=0;
			if(escape_count < 6){
				//escape!!
				escaped_layout(escape_count,age);
				escape_count++;
			}else{
				show_dead_count(dead_count);
			}
			if(satiety == 0){
				draw_satiety(0);
			}
			if(happiness == 0){
				draw_happiness(0);
			}
		}
	}
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER2_IRQHandler (void)
{
	LPC_TIM1->IR = 1;
  return;
}





/******************************************************************************
**                            End Of File
******************************************************************************/

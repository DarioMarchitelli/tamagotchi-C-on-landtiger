/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../TouchPanel/TouchPanel.h"
#include "../GLCD_advanced/GLCD.h" 
#include "../graphics/graphics.h"
#include "../timer/timer.h"
#include "../adc/adc.h"
#include "../music/music.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

volatile int down=0;
extern char led_value;
extern int x,y;
extern int first_basic_shown;
extern int satiety,happiness;
extern int first_escaped;
extern int is_escaped;
extern int age;
extern int decrease_happiness,decrease_satiety;

extern int is_meal;
extern int is_snow;
extern int is_cuddle;
extern int meal_count;
extern int snow_count;
extern int escape_count;

volatile int selected_item; //0 nothing, 1 meal, 2 snow, 3 reset


	extern NOTE songMeal[12];
	extern int currentNoteMeal;
	extern NOTE songDeath[12];
	extern int currentNoteDeath;
	extern NOTE songCuddle[12];
	extern int currentNoteCuddle;
	extern NOTE songSnow[12];
	extern int currentNoteSnow;
	
	extern int volume;




//SHORTENING UNDERTALE: TOO MANY REPETITIONS

void RIT_IRQHandler (void)
{					
	static int J_left = 0;
	static int J_right = 0;
	static int J_selected = 0;
	
	
	//LCD_DrawLine(70,0,0,70,Black);

	show_speaker(volume);
	/* ADC management */
	ADC_start_conversion();
	
	if(getDisplayPoint(&display, Read_Ads7846(), &matrix )){
		if(display.y >= 30 && display.y <=270 && display.x >=70 && display.x <=170){
			if(is_escaped == 0){
				disable_timer(0);
				is_cuddle=1;
				if(happiness < 5){
					happiness++;
				}
				currentNoteCuddle=0;
				playNote(songCuddle[currentNoteCuddle++]);
			}
		}
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
		/* Joytick Select pressed p1.25*/
		/* Joytick Down pressed p1.26 --> using J_DOWN due to emulator issues*/
		
		J_selected++;
		switch(J_selected){
			case 1:
				switch(selected_item){
					case 1:
						if(is_escaped == 0){
							disable_timer(0);
							is_meal=1;
							currentNoteMeal=0;
							playNote(songMeal[currentNoteMeal++]);
			
						}
						break;
					case 2:
						if(is_escaped == 0){
							disable_timer(0);
							is_snow=1;
							currentNoteSnow=0;
							playNote(songSnow[currentNoteSnow++]);
						}
						break;
					case 3:
						is_escaped=0;
						age=0;
						escape_count = 0;
						happiness=5;
						satiety=5;
						first_escaped=0;
						first_basic_shown=0;
						decrease_happiness=0;
						decrease_satiety=0;
						enable_timer(0);
						break;
				}
				break;
			default:
				break;
		}
	}
	else{
			J_selected=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick Select pressed p1.25*/
		/* Joytick Down pressed p1.26 --> using J_DOWN due to emulator issues*/
		
		J_left++;
		switch(J_left){
			case 1:
				if(is_escaped == 0 && first_basic_shown > 0){
					selected_item=1;
					//deselect snow
					LCD_DrawLine(120,280,240,280, Black);
					LCD_DrawLine(120,280,120,320,Black);
					GUI_Text(158, 292, (uint8_t *) "Snow", Black, White);
					//select meal
					LCD_DrawLine(0,280,120,280, Red);
					LCD_DrawLine(120,280,120,320,Red);
					GUI_Text(43, 292, (uint8_t *) "Meal", Red, White);
				}
				break;
			default:
				break;
		}
	}
	else{
			J_left=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick Select pressed p1.25*/
		/* Joytick Down pressed p1.26 --> using J_DOWN due to emulator issues*/
		J_right++;
		switch(J_right){
			case 1:
				if(is_escaped == 0 && first_basic_shown > 0){
					selected_item = 2;
					//deselect meal
					LCD_DrawLine(0,280,120,280, Black);
					LCD_DrawLine(120,280,120,320,Black);
					GUI_Text(43, 292, (uint8_t *) "Meal", Black, White);
					//select snow
					LCD_DrawLine(120,280,240,280, Red);
					LCD_DrawLine(120,280,120,320,Red);
					GUI_Text(158, 292, (uint8_t *) "Snow", Red, White);
				}
				break;
			default:
				break;
		}
	}
	else{
			J_right=0;
	}
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

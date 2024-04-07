
#include "lpc17xx.h"
#include "../GLCD_advanced/GLCD.h" 
#include <stdio.h>


/*----------------------------------------------------------------------------
  Function for graphics
 *----------------------------------------------------------------------------*/

void draw_pou_conf0(color0,move_x){
	//left arm
	LCD_DrawLine(80+move_x,129,120+move_x,159,color0);
	LCD_DrawLine(80+move_x,130,120+move_x,160,color0);
	LCD_DrawLine(80+move_x,131,120+move_x,161,color0);
	
	//right arm
	LCD_DrawLine(160+move_x,129,200+move_x,159,color0);
	LCD_DrawLine(160+move_x,130,200+move_x,160,color0);
	LCD_DrawLine(160+move_x,131,200+move_x,161,color0);
	
	//left eye
	LCD_DrawCircle(110+move_x,48,6,color0);
	LCD_DrawCircle(112+move_x,48,2,color0);
	
	//right eye
	LCD_DrawCircle(130+move_x,48,6,color0);
	LCD_DrawCircle(132+move_x,48,2,color0);
	
	//nose
	LCD_DrawRectangle(120+move_x,58,20,5,color0);
}
void draw_pou_conf1(color1,move_x){
	//conf 1
	
	//left arm
	LCD_DrawLine(80+move_x,129,120+move_x,169,color1);
	LCD_DrawLine(80+move_x,130,120+move_x,170,color1);
	LCD_DrawLine(80+move_x,131,120+move_x,171,color1);
	
	//right arm
	LCD_DrawLine(160+move_x,129,200+move_x,169,color1);
	LCD_DrawLine(160+move_x,130,200+move_x,170,color1);
	LCD_DrawLine(160+move_x,131,200+move_x,171,color1);
	
	//left eye
	LCD_DrawCircle(110+move_x,48,6,color1);
	LCD_DrawCircle(108+move_x,48,2,color1);
	
	//right eye
	LCD_DrawCircle(130+move_x,48,6,color1);
	LCD_DrawCircle(128+move_x,48,2,color1);
	
	//nose
	LCD_DrawRectangle(100+move_x,58,20,5,color1);
}

void draw_pou(int config,int move_x,int is_happy){
	switch(config){
		case 0:
			draw_pou_conf1(White,move_x);
			break;
		case 1:
			draw_pou_conf0(White,move_x);
			break;
	}
	
	//high ball
	LCD_DrawCircle(120+move_x,60,28,Black);
	LCD_DrawCircle(120+move_x,60,29,Black);
	LCD_DrawCircle(120+move_x,60,30,Black);
	//medium ball
	LCD_DrawCircle(120+move_x,130,38,Black);
	LCD_DrawCircle(120+move_x,130,39,Black);
	LCD_DrawCircle(120+move_x,130,40,Black);
	//low ball
	LCD_DrawCircle(120+move_x,220,48,Black);
	LCD_DrawCircle(120+move_x,220,49,Black);
	LCD_DrawCircle(120+move_x,220,50,Black);
	
	//mouth
	if(is_happy==1){
		//horizontal
		LCD_DrawLine(105+move_x,71,110+move_x,71,Black);
		LCD_DrawLine(130+move_x,71,135+move_x,71,Black);
		LCD_DrawLine(105+move_x,74,135+move_x,74,Black);
		LCD_DrawLine(105+move_x,77,135+move_x,77,Black);
		LCD_DrawLine(110+move_x,80,130+move_x,80,Black);
		//vertical
		LCD_DrawLine(105+move_x,71,105+move_x,77,Black);
		LCD_DrawLine(110+move_x,71,110+move_x,80,Black);
		LCD_DrawLine(115+move_x,74,115+move_x,80,Black);
		LCD_DrawLine(120+move_x,74,120+move_x,80,Black);
		LCD_DrawLine(125+move_x,74,125+move_x,80,Black);
		LCD_DrawLine(130+move_x,71,130+move_x,80,Black);
		LCD_DrawLine(135+move_x,71,135+move_x,77,Black);
	}else if(is_happy == 0){
		LCD_DrawCircle(120+move_x,76,10,Black);
		LCD_DrawCircle(120+move_x,76,9,Black);
	}
	
	switch(config){
		case 0:
			draw_pou_conf0(Black,move_x);
			break;
		case 1:
			draw_pou_conf1(Black,move_x);
			break;
	}
	
}




void draw_satiety(int level){
	int color = Green;
	//satiety indicator
	//clear
	LCD_DrawRectangle(42,44,12,5,White);
	LCD_DrawRectangle(42,38,12,5,White);
	LCD_DrawRectangle(42,32,12,5,White);
	LCD_DrawRectangle(42,26,12,5,White);
	LCD_DrawRectangle(42,20,12,5,White);
	
	//rectangle
	LCD_DrawLine(40,18,55,18,Black);
	LCD_DrawLine(40,18,40,50,Black);
	LCD_DrawLine(40,50,55,50,Black);
	LCD_DrawLine(55,18,55,50,Black);
	
	//set level
	if(level <=3 ) color=Yellow;
	if(level <=1 ) color=Red;

	if(level>=1){
		LCD_DrawRectangle(42,44,12,5,color);
	}
	if(level>=2){
		LCD_DrawRectangle(42,38,12,5,color);
	}
	if(level>=3){
		LCD_DrawRectangle(42,32,12,5,color);
	}
	if(level>=4){
		LCD_DrawRectangle(42,26,12,5,color);
	}
	if(level>=5){
		LCD_DrawRectangle(42,20,12,5,color);
	}
	GUI_Text(18, 55, (uint8_t *) "Satiety", Black, White);
}


void draw_happiness(int level){
	//Happiness indicator
	int color = Green;
	
	//clear
	LCD_DrawRectangle(187,44,12,5,White);
	LCD_DrawRectangle(187,38,12,5,White);
	LCD_DrawRectangle(187,32,12,5,White);
	LCD_DrawRectangle(187,26,12,5,White);
	LCD_DrawRectangle(187,20,12,5,White);
	
	//rectangle
	LCD_DrawLine(185,18,200,18,Black);
	LCD_DrawLine(185,18,185,50,Black);
	LCD_DrawLine(185,50,200,50,Black);
	LCD_DrawLine(200,18,200,50,Black);
	
	//set level
	if(level <=3 ) color=Yellow;
	if(level <=1 ) color=Red;
	
	if(level>=1){
		LCD_DrawRectangle(187,44,12,5,color);
	}
	if(level>=2){
		LCD_DrawRectangle(187,38,12,5,color);
	}
	if(level>=3){
		LCD_DrawRectangle(187,32,12,5,color);
	}
	if(level>=4){
		LCD_DrawRectangle(187,26,12,5,color);
	}
	if(level>=5){
		LCD_DrawRectangle(187,20,12,5,color);
	}
	GUI_Text(161, 55, (uint8_t *) "Happiness", Black, White);
}

void meal(int config){
	switch(config){
		case 0:
			LCD_Clear(White);
			GUI_Text(100, 280, (uint8_t *) "Meal!", Black, White);
			LCD_DrawCircle(195,76,7,Black);
			LCD_DrawCircle(195,76,6,Black);
			LCD_DrawCircle(195,76,5,Black);
			LCD_DrawCircle(195,76,4,Black);
			LCD_DrawCircle(195,76,3,Black);
			LCD_DrawCircle(195,76,2,Black);
			LCD_DrawCircle(195,76,1,Black);
			draw_pou(0,0,1);
			break;
		case 1:
			LCD_Clear(White);
			GUI_Text(100, 280, (uint8_t *) "Meal!", Black, White);
			LCD_DrawCircle(195,76,7,Black);
			LCD_DrawCircle(195,76,6,Black);
			LCD_DrawCircle(195,76,5,Black);
			LCD_DrawCircle(195,76,4,Black);
			LCD_DrawCircle(195,76,3,Black);
			LCD_DrawCircle(195,76,2,Black);
			LCD_DrawCircle(195,76,1,Black);
			draw_pou(0,20,0);
			break;
		case 2:
			LCD_Clear(White);
			GUI_Text(100, 280, (uint8_t *) "Meal!", Black, White);
			LCD_DrawCircle(195,76,7,Black);
			LCD_DrawCircle(195,76,6,Black);
			LCD_DrawCircle(195,76,5,Black);
			LCD_DrawCircle(195,76,4,Black);
			LCD_DrawCircle(195,76,3,Black);
			LCD_DrawCircle(195,76,2,Black);
			LCD_DrawCircle(195,76,1,Black);
			draw_pou(0,40,0);
			break;
		case 3:
			LCD_Clear(White);
			GUI_Text(100, 280, (uint8_t *) "Meal!", Black, White);
			LCD_DrawCircle(195,76,7,Black);
			LCD_DrawCircle(195,76,6,Black);
			LCD_DrawCircle(195,76,5,Black);
			LCD_DrawCircle(195,76,4,Black);
			LCD_DrawCircle(195,76,3,Black);
			LCD_DrawCircle(195,76,2,Black);
			LCD_DrawCircle(195,76,1,Black);
			draw_pou(0,60,0);
			break;
		case 4:
			LCD_Clear(White);
			GUI_Text(100, 280, (uint8_t *) "Meal!", Black, White);
			draw_pou(0,60,1);
			break;
	}
}

void snow_frame(int frame){
	
	LCD_Clear(White);
	
	//upper line
	LCD_DrawCircle(20,20+frame*2,5,Black);
	LCD_DrawCircle(60,20+frame*2,3,Black);
	LCD_DrawCircle(100,20+frame*2,4,Black);
	LCD_DrawCircle(140,20+frame*2,5,Black);
	LCD_DrawCircle(180,20+frame*2,3,Black);
	LCD_DrawCircle(220,20+frame*2,4,Black);
	
	LCD_DrawCircle(30,50+frame*2,4,Black);
	LCD_DrawCircle(70,50+frame*2,5,Black);
	LCD_DrawCircle(190,50+frame*2,5,Black);
	LCD_DrawCircle(230,50+frame*2,3,Black);
	
	LCD_DrawCircle(25,80+frame*2,3,Black);
	LCD_DrawCircle(65,80+frame*2,4,Black);
	LCD_DrawCircle(185,80+frame*2,4,Black);
	LCD_DrawCircle(225,80+frame*2,5,Black);
	
	LCD_DrawCircle(20,110+frame*2,5,Black);
	LCD_DrawCircle(60,110+frame*2,3,Black);
	LCD_DrawCircle(180,110+frame*2,3,Black);
	LCD_DrawCircle(220,110+frame*2,4,Black);
	
	LCD_DrawCircle(30,140+frame*2,4,Black);
	LCD_DrawCircle(70,140+frame*2,5,Black);
	LCD_DrawCircle(190,140+frame*2,5,Black);
	LCD_DrawCircle(230,140+frame*2,3,Black);
	
	LCD_DrawCircle(25,170+frame*2,3,Black);
	LCD_DrawCircle(65,170+frame*2,4,Black);
	LCD_DrawCircle(185,170+frame*2,4,Black);
	LCD_DrawCircle(225,170+frame*2,5,Black);
	
	LCD_DrawCircle(20,200+frame*2,5,Black);
	LCD_DrawCircle(220,200+frame*2,4,Black);
	
	LCD_DrawCircle(30,230+frame*2,4,Black);
	LCD_DrawCircle(230,230+frame*2,3,Black);
	
	//bottom line
	LCD_DrawCircle(25,270+frame*2,3,Black);
	LCD_DrawCircle(225,270+frame*2,5,Black);
	
	draw_pou(frame%2,0,1);
	
	GUI_Text(100, 280, (uint8_t *) "Snow!", Black, White);
}

void snow(int config){
	snow_frame(config);
}

void basic_layout(){
	LCD_Clear(White);
	LCD_DrawLine(0,280,240,280,Black);
	LCD_DrawLine(120,280,120,320,Black);
	GUI_Text(43, 292, (uint8_t *) "Meal", Black, White);
	GUI_Text(158, 292, (uint8_t *) "Snow", Black, White);
}

void show_age(int age){
	int hours,minutes,seconds;
	char s_age[100];
	hours=age/(60*60);
	minutes = (age-hours*(60*60))/60;
	seconds = age-(hours*(60*60))- (minutes * 60);
	sprintf(s_age,"Age: %02d:%02d:%02d",hours,minutes,seconds);
	GUI_Text(69, 5, (uint8_t *) s_age, Black, White);
}


void melt_pou(int config, int age){
	LCD_Clear(White);
	show_age(age);
	LCD_DrawLine(0,280,240,280, Red);
	GUI_Text(100, 292, (uint8_t *) "Reset", Red, White);
	
	switch(config){
		case 0:
			//high ball
			LCD_DrawCircle(120,60,28,Black);
			LCD_DrawCircle(120,60,29,Black);
			LCD_DrawCircle(120,60,30,Black);
			//medium ball
			LCD_DrawCircle(120,130,38,Black);
			LCD_DrawCircle(120,130,39,Black);
			LCD_DrawCircle(120,130,40,Black);
			//low ball
			LCD_DrawCircle(120,220,48,Black);
			LCD_DrawCircle(120,220,49,Black);
			LCD_DrawCircle(120,220,50,Black);
		
			//mouth
			//horizontal
			LCD_DrawLine(110,71,130,71,Black);
			LCD_DrawLine(105,74,135,74,Black);
			LCD_DrawLine(105,77,135,77,Black);
			LCD_DrawLine(105,80,110,80,Black);
			LCD_DrawLine(130,80,135,80,Black);
			//vertical
			LCD_DrawLine(105,74,105,80,Black);
			LCD_DrawLine(110,71,110,80,Black);
			LCD_DrawLine(115,71,115,77,Black);
			LCD_DrawLine(120,71,120,77,Black);
			LCD_DrawLine(125,71,125,77,Black);
			LCD_DrawLine(130,71,130,80,Black);
			LCD_DrawLine(135,74,135,80,Black);
		
			//left arm
			LCD_DrawLine(80,129,120,159,Black);
			LCD_DrawLine(80,130,120,160,Black);
			LCD_DrawLine(80,131,120,161,Black);
			
			//right arm
			LCD_DrawLine(160,129,200,159,Black);
			LCD_DrawLine(160,130,200,160,Black);
			LCD_DrawLine(160,131,200,161,Black);
			
			//left eye
			LCD_DrawCircle(110,48,6,Black);
			LCD_DrawCircle(110,48,2,Black);
			
			//right eye
			LCD_DrawCircle(130,48,6,Black);
			LCD_DrawCircle(130,48,2,Black);
			
			//nose
			LCD_DrawRectangle(120,58,20,5,Black);
			break;
		case 1:
			//high ball
			LCD_DrawCircle(120,110,28,Black);
			LCD_DrawCircle(120,110,29,Black);
			LCD_DrawCircle(120,110,30,Black);
			//medium ball
			LCD_DrawCircle(120,180,38,Black);
			LCD_DrawCircle(120,180,39,Black);
			LCD_DrawCircle(120,180,40,Black);
			//low ball
			LCD_DrawCircle(120,245,23,Black);
			LCD_DrawCircle(120,245,24,Black);
			LCD_DrawCircle(120,245,25,Black);
		
			//mouth
			//horizontal
			LCD_DrawLine(110,121,130,121,Black);
			LCD_DrawLine(105,124,135,124,Black);
			LCD_DrawLine(105,127,135,127,Black);
			LCD_DrawLine(105,130,110,130,Black);
			LCD_DrawLine(130,130,135,130,Black);
			//vertical
			LCD_DrawLine(105,124,105,130,Black);
			LCD_DrawLine(110,121,110,130,Black);
			LCD_DrawLine(115,121,115,127,Black);
			LCD_DrawLine(120,121,120,127,Black);
			LCD_DrawLine(125,121,125,127,Black);
			LCD_DrawLine(130,121,130,130,Black);
			LCD_DrawLine(135,124,135,130,Black);
		
			//left arm
			LCD_DrawLine(80,179,120,209,Black);
			LCD_DrawLine(80,180,120,210,Black);
			LCD_DrawLine(80,181,120,211,Black);
			
			//right arm
			LCD_DrawLine(160,179,200,209,Black);
			LCD_DrawLine(160,180,200,210,Black);
			LCD_DrawLine(160,181,200,211,Black);
			
			//left eye
			LCD_DrawCircle(110,98,6,Black);
			LCD_DrawCircle(110,98,2,Black);
			
			//right eye
			LCD_DrawCircle(130,98,6,Black);
			LCD_DrawCircle(130,98,2,Black);
			
			//nose
			LCD_DrawRectangle(120,108,20,5,Black);
			break;
		case 2:
			//high ball
			LCD_DrawCircle(120,160,28,Black);
			LCD_DrawCircle(120,160,29,Black);
			LCD_DrawCircle(120,160,30,Black);
			//medium ball
			LCD_DrawCircle(120,230,38,Black);
			LCD_DrawCircle(120,230,39,Black);
			LCD_DrawCircle(120,230,40,Black);
		
			//mouth
			//horizontal
			LCD_DrawLine(110,171,130,171,Black);
			LCD_DrawLine(105,174,135,174,Black);
			LCD_DrawLine(105,177,135,177,Black);
			LCD_DrawLine(105,180,110,180,Black);
			LCD_DrawLine(130,180,135,180,Black);
			//vertical
			LCD_DrawLine(105,174,105,180,Black);
			LCD_DrawLine(110,171,110,180,Black);
			LCD_DrawLine(115,171,115,177,Black);
			LCD_DrawLine(120,171,120,177,Black);
			LCD_DrawLine(125,171,125,177,Black);
			LCD_DrawLine(130,171,130,180,Black);
			LCD_DrawLine(135,174,135,180,Black);
		
			//left arm
			LCD_DrawLine(80,229,120,259,Black);
			LCD_DrawLine(80,230,120,260,Black);
			LCD_DrawLine(80,231,120,261,Black);
			
			//right arm
			LCD_DrawLine(160,229,200,259,Black);
			LCD_DrawLine(160,230,200,260,Black);
			LCD_DrawLine(160,231,200,261,Black);
			
			//left eye
			LCD_DrawCircle(110,148,6,Black);
			LCD_DrawCircle(110,148,2,Black);
			
			//right eye
			LCD_DrawCircle(130,148,6,Black);
			LCD_DrawCircle(130,148,2,Black);
			
			//nose
			LCD_DrawRectangle(120,158,20,5,Black);
			break;
		case 3:
			//high ball
			LCD_DrawCircle(120,200,28,Black);
			LCD_DrawCircle(120,200,29,Black);
			LCD_DrawCircle(120,200,30,Black);
			//medium ball
			LCD_DrawCircle(120,250,18,Black);
			LCD_DrawCircle(120,250,19,Black);
			LCD_DrawCircle(120,250,20,Black);
		
			//mouth
			//horizontal
			LCD_DrawLine(110,211,130,211,Black);
			LCD_DrawLine(105,214,135,214,Black);
			LCD_DrawLine(105,217,135,217,Black);
			LCD_DrawLine(105,220,110,220,Black);
			LCD_DrawLine(130,220,135,220,Black);
			//vertical
			LCD_DrawLine(105,214,105,220,Black);
			LCD_DrawLine(110,211,110,220,Black);
			LCD_DrawLine(115,211,115,217,Black);
			LCD_DrawLine(120,211,120,217,Black);
			LCD_DrawLine(125,211,125,217,Black);
			LCD_DrawLine(130,211,130,220,Black);
			LCD_DrawLine(135,214,135,220,Black);
			
			//left eye
			LCD_DrawCircle(110,188,6,Black);
			LCD_DrawCircle(110,188,2,Black);
			
			//right eye
			LCD_DrawCircle(130,188,6,Black);
			LCD_DrawCircle(130,188,2,Black);
			
			//nose
			LCD_DrawRectangle(120,198,20,5,Black);
			break;
		case 4:
			//high ball
			LCD_DrawCircle(120,240,28,Black);
			LCD_DrawCircle(120,240,29,Black);
			LCD_DrawCircle(120,240,30,Black);
		
			//mouth
			//horizontal
			LCD_DrawLine(110,251,130,251,Black);
			LCD_DrawLine(105,254,135,254,Black);
			LCD_DrawLine(105,257,135,257,Black);
			LCD_DrawLine(105,260,110,260,Black);
			LCD_DrawLine(130,260,135,260,Black);
			//vertical
			LCD_DrawLine(105,254,105,260,Black);
			LCD_DrawLine(110,251,110,260,Black);
			LCD_DrawLine(115,251,115,257,Black);
			LCD_DrawLine(120,251,120,257,Black);
			LCD_DrawLine(125,251,125,257,Black);
			LCD_DrawLine(130,251,130,260,Black);
			LCD_DrawLine(135,254,135,260,Black);
			
			//left eye
			LCD_DrawCircle(110,228,6,Black);
			LCD_DrawCircle(110,228,2,Black);
			
			//right eye
			LCD_DrawCircle(130,228,6,Black);
			LCD_DrawCircle(130,228,2,Black);
			
			//nose
			LCD_DrawRectangle(120,238,20,5,Black);
			break;
		case 5:
			//mouth
			//horizontal
			LCD_DrawLine(110,261,130,261,Black);
			LCD_DrawLine(105,264,135,264,Black);
			LCD_DrawLine(105,267,135,267,Black);
			LCD_DrawLine(105,270,110,270,Black);
			LCD_DrawLine(130,270,135,270,Black);
			//vertical
			LCD_DrawLine(105,264,105,270,Black);
			LCD_DrawLine(110,261,110,270,Black);
			LCD_DrawLine(115,261,115,267,Black);
			LCD_DrawLine(120,261,120,267,Black);
			LCD_DrawLine(125,261,125,267,Black);
			LCD_DrawLine(130,261,130,270,Black);
			LCD_DrawLine(135,264,135,270,Black);
			
			//left eye
			LCD_DrawCircle(110,255,6,Black);
			LCD_DrawCircle(110,255,2,Black);
			
			//right eye
			LCD_DrawCircle(130,250,6,Black);
			LCD_DrawCircle(130,250,2,Black);
			
			//nose
			LCD_DrawRectangle(120,256,20,5,Black);
			
			
			GUI_Text(42, 135, (uint8_t *) "You made me melt!!!", Black, White);
			break;
	}
	
}
void escaped_layout(int config, int age){
	melt_pou(config,age);
	//melt_pou(0,age); //only sad
	//melt_pou(1,age); //first melt
	//melt_pou(2,age); //first disappear
	//melt_pou(3,age); //second melt
	//melt_pou(4,age); //second disappear
	//melt_pou(5,age); //third disappear
}

void show_dead_count(int dead_count){
	
	char s_dead[100];
	sprintf(s_dead,"Snowmans killed: %d",dead_count);
	GUI_Text(45, 175, (uint8_t *) s_dead, Black, White);
}

void show_speaker(int level){
	int speakerX[38]={0,0,0,0,0,0,1,1,1,1,2,2,3,3,3, 3,4,4,4, 4,5,5, 5, 5,6, 6,7,7,7,7,7,7,7,7,7,7, 7, 7,};
	int speakerY[38]={3,4,5,6,7,8,2,3,8,9,2,9,1,2,9,10,1,2,9,10,0,1,10,11,0,11,0,1,2,3,4,5,6,7,8,9,10,11,};
	int level1X[9]={9, 9,10,10,10,10,10,10,10};
	int level1Y[9]={2,10, 3, 4, 5, 6, 7, 8, 9};
	int level2X[12]={11,11,12,12,12,12,13,13,13,13,13,13};
	int level2Y[12]={ 0,11, 1, 2, 9,10, 3, 4, 5, 6, 7, 8};
	int i;
	
	
	for(i = 0; i<38; i++){
			LCD_SetPoint(speakerX[i]+5,speakerY[i]+5,White);
	}
	LCD_DrawLine(5,5,12,16,White);
	for(i = 0; i<9; i++){
		LCD_SetPoint(level1X[i]+5,level1Y[i]+5,White);
	}
	
	for(i = 0; i<12; i++){
		LCD_SetPoint(level2X[i]+5,level2Y[i]+5,White);
	}
	
	for(i = 0; i<38; i++){
		LCD_SetPoint(speakerX[i]+5,speakerY[i]+5,Black);
	}
	if(level == 0){
	LCD_DrawLine(5,5,12,16,Red);
	}
	if(level>1){
		for(i = 0; i<9; i++){
			LCD_SetPoint(level1X[i]+5,level1Y[i]+5,Black);
		}
	}
	if(level>5){
		for(i = 0; i<12; i++){
			LCD_SetPoint(level2X[i]+5,level2Y[i]+5,Black);
		}
	}
}

void draw_heart(x,y){
int pixelsX[28]={1,2,3,4,7,8,9,10,0,5,6,11,0,11,0,11,0,11,1,10,2,9,3,8,4,7,5,6};
int pixelsY[28]={0,0,0,0,0,0,0,0,1,1,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
int i;

	for(i = 0; i<28; i++){
      LCD_SetPoint(x + pixelsX[i],y + pixelsY[i],Red);
  }
}

void cuddle(int config){
	LCD_Clear(White);
	GUI_Text(100, 280, (uint8_t *) "Cuddle!", Black, White);
	switch(config){
		case 0:
			draw_pou(0,0,1);
			draw_heart(114,20);//N
			draw_heart(75,60);//O
			draw_heart(155,60);//E
			draw_heart(85,30);//NO
			draw_heart(145,30);//NE
			break;
		case 1:
			draw_pou(1,0,1);
			draw_heart(114,15);//N
			draw_heart(70,60);//O
			draw_heart(160,60);//E
			draw_heart(80,25);//NO
			draw_heart(150,25);//NE
			break;
		case 2:
			draw_pou(0,0,1);
			draw_heart(114,10);//N
			draw_heart(65,60);//O
			draw_heart(165,60);//E
			draw_heart(75,20);//NO
			draw_heart(155,20);//NE
			break;
		case 3:
			draw_pou(1,0,1);
			draw_heart(114,5);//N
			draw_heart(60,60);//O
			draw_heart(170,60);//E
			draw_heart(70,15);//NO
			draw_heart(160,15);//NE
			break;
		case 4:
			draw_pou(0,0,1);
			draw_heart(114,0);//N
			draw_heart(55,60);//O
			draw_heart(175,60);//E
			draw_heart(65,10);//NO
			draw_heart(165,10);//NE
			break;
	}
}

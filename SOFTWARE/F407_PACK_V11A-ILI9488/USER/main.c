#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"

//ALIENTEK 探索者STM32F407开发板 实验13
//LCD显示实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

int main(void)
{ 
 	u8 x=0;
	u8 lcd_id[12];				//存放LCD ID字符串
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	
	LED_Init();					  //初始化LED
 	LCD_Init();           //初始化LCD FSMC接口
	POINT_COLOR=CL_RED;      //画笔颜色：红色
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。				 	
  	while(1) 
	{		 
		switch(x)
		{
			case 0:LCD_Clear(CL_WHITE);break;
			case 1:LCD_Clear(CL_BLACK);break;
			case 2:LCD_Clear(CL_BLUE);break;
			case 3:LCD_Clear(CL_RED);break;
			case 4:LCD_Clear(CL_YELLOW);break;
			case 5:LCD_Clear(CL_GREEN);break;
			case 6:LCD_Clear(CYAN);break; 
			case 7:LCD_Clear(CL_YELLOW);break;
			case 8:LCD_Clear(BRRED);break;
			case 9:LCD_Clear(GRAY);break;
			case 10:LCD_Clear(LGRAY);break;
			case 11:LCD_Clear(BROWN);break;
		}
		POINT_COLOR=CL_RED;	  
		LCD_ShowString(30,40,210,24,24,"ILI9488 TEST");	
		LCD_ShowString(30,70,200,16,16,"");
		LCD_ShowString(30,90,200,16,16,"CUIT_BIKE");
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 
		LCD_ShowString(30,130,200,12,12,"2018/2/12");	      					 
		x++;
		if(x==5)x=0;
		LED0=!LED0;	 
		delay_ms(1000);	
	} 
}

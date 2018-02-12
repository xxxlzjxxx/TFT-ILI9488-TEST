#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"

//ALIENTEK ̽����STM32F407������ ʵ��13
//LCD��ʾʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{ 
 	u8 x=0;
	u8 lcd_id[12];				//���LCD ID�ַ���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	
	LED_Init();					  //��ʼ��LED
 	LCD_Init();           //��ʼ��LCD FSMC�ӿ�
	POINT_COLOR=CL_RED;      //������ɫ����ɫ
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣				 	
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
 		LCD_ShowString(30,110,200,16,16,lcd_id);		//��ʾLCD ID	      					 
		LCD_ShowString(30,130,200,12,12,"2018/2/12");	      					 
		x++;
		if(x==5)x=0;
		LED0=!LED0;	 
		delay_ms(1000);	
	} 
}

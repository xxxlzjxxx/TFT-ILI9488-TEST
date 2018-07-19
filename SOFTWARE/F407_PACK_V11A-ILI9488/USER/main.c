#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "ili9488.h"
#include "key.h"
#include "touch.h"

//ALIENTEK ̽����STM32F407������ ʵ��13
//LCD��ʾʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

void GarminUI(void);

int main(void)
{ 
// 	u8 x=0;
//	u8 lcd_id[12];				//���LCD ID�ַ���
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	
	LED_Init();					  //��ʼ��LED
 	ILI9488_Init();           //��ʼ��LCD FSMC�ӿ�
	KEY_Init();				//��ʼ������
//	tp_dev.init();				//��������ʼ��
	while(1){
		GarminUI();
	}

}


void GarminUI(void){
//�Ȼ��ø����߽���
	POINT_COLOR=BLUE;	
	LCD_ShowxNum(0,40,10086,40,24,1);
	LCD_Fill(0,88,320,98,BLACK);
	LCD_DrawRectangle(0,186,320,196);
	LCD_DrawRectangle(0,284,320,294);
	LCD_DrawRectangle(0,382,320,392);
	LCD_DrawRectangle(155,0,165,480);
//��ʾ��Ϣ
}




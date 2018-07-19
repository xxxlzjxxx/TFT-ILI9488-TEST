#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "ili9488.h"
#include "key.h"
#include "touch.h"

//ALIENTEK 探索者STM32F407开发板 实验13
//LCD显示实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

void GarminUI(void);

int main(void)
{ 
// 	u8 x=0;
//	u8 lcd_id[12];				//存放LCD ID字符串
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	
	LED_Init();					  //初始化LED
 	ILI9488_Init();           //初始化LCD FSMC接口
	KEY_Init();				//初始化按键
//	tp_dev.init();				//触摸屏初始化
	while(1){
		GarminUI();
	}

}


void GarminUI(void){
//先画好各个边界线
	POINT_COLOR=BLUE;	
	LCD_ShowxNum(0,40,10086,40,24,1);
	LCD_Fill(0,88,320,98,BLACK);
	LCD_DrawRectangle(0,186,320,196);
	LCD_DrawRectangle(0,284,320,294);
	LCD_DrawRectangle(0,382,320,392);
	LCD_DrawRectangle(155,0,165,480);
//显示信息
}




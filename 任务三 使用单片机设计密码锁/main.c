#include <STC89C5xRC.H>
#include "Delay.h"
#include "lcd1602.h"  //提示：记得要声明函数，不然无法引用函数
#include "Buzzer.h"
#include "matrix.h"
void main ()
{	unsigned int keynum=0,keynumber;
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while (1)
	{
		
		keynumber=matrixkey();
	if(keynumber!=0)
	{
		if(keynumber<=10)//输入密码
		 {
			 keynum=keynum*10+keynumber%10;
			 LCD_ShowNum(2,1,keynum,4);
		 }
		else if (keynumber==11)//后退为前一次输入的密码
			{
			keynum=keynum/10;
			LCD_ShowNum(2,1,keynum,4);
			}
		else if (keynumber==12)	//取消密码
			{
			keynum=0;
			LCD_ShowNum(2,1,keynum,4);
			}
		else if(keynumber==16)//判断密码对错
			{if(keynum==5678)//密码正确，显示ture，并重置密码
				{
					LCD_ShowString(1,12,"Ture");
					Buzzer_Time2(100);
					Delay(20);
					Buzzer_Time2(100);
					Delay(20);
					Buzzer_Time2(100);
					Delay(500);
					keynum=0;
					LCD_Init();
					LCD_ShowString(1,1,"Password:");
					LCD_ShowNum(2,1,keynum,4);
				}
			 else 			//密码错误，显示err，并重置密码		
				{
				LCD_ShowString(1,13,"Err");	
				Buzzer_Time1(250);
				LCD_ShowString(2,1,"Plesea rewrite!");
				Delay(1000);
				keynum=0;
				LCD_Init();
				LCD_ShowString(1,1,"Password:");	
				LCD_ShowNum(2,1,keynum,4);					
				}
			
			}
		 
		
	}
	
	}
}

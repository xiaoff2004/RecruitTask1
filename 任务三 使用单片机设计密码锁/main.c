#include <STC89C5xRC.H>
#include "Delay.h"
#include "lcd1602.h"  //��ʾ���ǵ�Ҫ������������Ȼ�޷����ú���
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
		if(keynumber<=10)//��������
		 {
			 keynum=keynum*10+keynumber%10;
			 LCD_ShowNum(2,1,keynum,4);
		 }
		else if (keynumber==11)//����Ϊǰһ�����������
			{
			keynum=keynum/10;
			LCD_ShowNum(2,1,keynum,4);
			}
		else if (keynumber==12)	//ȡ������
			{
			keynum=0;
			LCD_ShowNum(2,1,keynum,4);
			}
		else if(keynumber==16)//�ж�����Դ�
			{if(keynum==5678)//������ȷ����ʾture������������
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
			 else 			//���������ʾerr������������		
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

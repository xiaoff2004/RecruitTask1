#include <STC89C5xRC.H>
#include "timer0.h"
#include "Nixie.h"
#include "Key.h"
#include "DELAY.h"
unsigned char num=0,counter,speed;
void main()
{
	Timer0Init();
	
	while(1)
	{
		if(Key()==1)         //设置占空比
			num++;
		if(num==0)
			speed=0;
		else if(num==1)
			speed=50;
		else if(num==2)
			speed=75;
		else if(num==3)
			speed=100;
		else if(num==4)
			num=0;	
		Nixie(1,num);
	}
}

void timer0() interrupt 1
{
	
	TL0 = 0x66;		
	TH0 = 0xFC;		
	counter++;
	if(counter<=speed)//电机转动
		P10=1;
	else if(counter>speed)//电机不转
		P10=0;
  else if(counter>100)
		counter=0;	
}
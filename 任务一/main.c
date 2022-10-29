#include <STC89C5xRC.H>
#include "timer0.h"

unsigned int count=0;

void main()
{
	Ex0init();
  Timer0Init();
	P20=0;
  while(1)
  {

   }
}

void timer0() interrupt 1
{
	static unsigned int count=0;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count++;
	if(count==1000)
	{
		count=0;
		P20=~P20;
		
	}


}


void Ex0() interrupt 0
{
	
	ET0=1;//让定时器中断开启

}
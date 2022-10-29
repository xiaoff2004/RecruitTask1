#include <STC89C5xRC.H>
#include "DELAY.h"

/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(P31==0){delay(20);while(P31==0);delay(20);KeyNumber=1;}
	if(P30==0){delay(20);while(P30==0);delay(20);KeyNumber=2;}
	if(P32==0){delay(20);while(P32==0);delay(20);KeyNumber=3;}
	if(P33==0){delay(20);while(P33==0);delay(20);KeyNumber=4;}
	
	return KeyNumber;
}

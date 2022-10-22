#include <STC89C5xRC.H>
#include "Delay.h"

unsigned char matrixkey()
{
	unsigned char keynumber=0;
	
	P1=0xFF;
	P13=0;
	if (P17==0){Delay(20);if(P17==0){Delay(200);keynumber=1;}}
	if (P16==0){Delay(20);if(P16==0){Delay(200);keynumber=5;}}
	if (P15==0){Delay(20);if(P15==0){Delay(200);keynumber=9;}}
	if (P14==0){Delay(20);if(P14==0){Delay(200);keynumber=13;}}
	
	P1=0xFF;
	P12=0;
	if (P17==0){Delay(20);if(P17==0){Delay(200);keynumber=2;}}
	if (P16==0){Delay(20);if(P16==0){Delay(200);keynumber=6;}}
	if (P15==0){Delay(20);if(P15==0){Delay(200);keynumber=10;}}
	if (P14==0){Delay(20);if(P14==0){Delay(200);keynumber=14;}}
	
	P1=0xFF;
	P11=0;
	if (P17==0){Delay(20);if(P17==0){Delay(200);keynumber=3;}}
	if (P16==0){Delay(20);if(P16==0){Delay(200);keynumber=7;}}
	if (P15==0){Delay(20);if(P15==0){Delay(200);keynumber=11;}}
	if (P14==0){Delay(20);if(P14==0){Delay(200);keynumber=15;}}
	
	P1=0xFF;
	P10=0;
	if (P17==0){Delay(20);if(P17==0){Delay(200);keynumber=4;}}
	if (P16==0){Delay(20);if(P16==0){Delay(200);keynumber=8;}}
	if (P15==0){Delay(20);if(P15==0){Delay(200);keynumber=12;}}
	if (P14==0){Delay(20);if(P14==0){Delay(200);keynumber=16;}}

	return keynumber;
}


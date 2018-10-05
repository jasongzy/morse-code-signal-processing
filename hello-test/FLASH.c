#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit p10 = P1 ^ 0;

void delay(uint n)
{
	uint i = 0, j = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < 123; j++);
}

void dot()
{
	p10 = 0;
	delay(500);
	p10 = 1;
}

void line()
{
	p10 = 0;
	delay(1500);
	p10 = 1;
}

void main()
{
	uchar a;
	while (1)
	{
// H
		for (a = 4; a > 0; a--)
		{
			dot(); delay(500);
		}
		delay(1000);
// E
		dot();
		delay(1500);
// double L
		for (a = 2; a > 0; a--)
		{
			dot(); delay(500);
			line(); delay(500);
			dot(); delay(500);
			dot();
			delay(1500);
		}
// O
		for (a = 3; a > 0; a--)
		{
			line(); delay(500);
		}
		delay(2000);	// next word
	}
}
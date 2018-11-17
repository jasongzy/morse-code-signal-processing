#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
#define led P2 

void delay(uint n)
{	uint i = 0, j = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < 123; j++);
}

void dot()
{
led=0x00;
	delay(1000);
led=0xff;
}

void line()
{
led=0x00 ;
	delay(3000);
led=0xff;
}

void main()
{

    delay(5000);
	dot(); delay(1000);
	line(); delay(1000);
	delay(2000);

	line(); delay(1000);
	dot(); delay(1000);
	dot(); delay(1000);
	dot(); delay(1000);
	delay(2000);

	line(); delay(1000);
	dot(); delay(1000);
	line(); delay(1000);
	dot(); delay(1000);
	delay(2000);

	line(); delay(1000);
	dot(); delay(1000);
	dot(); delay(1000);
	delay(2000);

	dot();  delay(1000);
	delay(2000);

	dot(); delay(1000);
	dot(); delay(1000);
	line(); delay(1000);
	dot(); delay(1000);
	delay(6000);


	while(1);
}
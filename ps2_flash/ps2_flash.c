// http://www.doczj.com/list_31/150
#include<reg51.h>
#include "pscodes.h"
#define uint unsigned int
#define uchar unsigned char
#define Keydata P3_4 // 定义 Keyboard 引脚
#define kclock P3_3 // 定义 clock 引脚

sbit p10 = P1 ^ 0;
static uchar IntNum = 0; // 中断计数
static uchar keyCode; // 键值
static uchar BF = 0; // 标识是否有字符被收到

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

void Keyboard_out() interrupt 2
{
	if ((IntNum > 0) && (IntNum < 9))
	{
		keyCode = keyCode >> 1; // 因键盘数据是低 >> 高, 结合上一句所以右移一位
		if (Keydata)
			keyCode = keyCode | 0x80; // 当键盘数据线为 1 时最高位为 1
	}
	IntNum++;
	while (!kclock); // 等待时钟信号从低变高
	if (IntNum > 10) // 判断一个完整的键码是否接收完毕, 如果接收完毕, 则重置 IntNum, 设置键码
					// 有效标志 BF=1, 并关闭中断
	{
		IntNum = 0;
		BF = 1;
		EA = 0;
	}
}

uchar decode(uchar Skeycode)
{
	uchar TempCyc;
	for (TempCyc = 0; TempCyc < 46; TempCyc++);
	if (ps2KeyCode[TempCyc][0] == Skeycode)
		return ps2KeyCode[TempCyc][1];
}

void flash(uchar a)
{
	switch (a)
	{
	case 'A' :
		dot(); delay(500);
		line();
		delay(1500);
		break;
	case 'B' :
		line(); delay(500);
		for (a = 3; a > 0; a--)
		{
			dot(); delay(500);
		}
		delay(1000);
		break;
	case 'C' :
		line(); delay(500);
		dot(); delay(500);
		line(); delay(500);
		dot(); delay(1500);
		break;
	case 'D' :
		line(); delay(500);
		dot(); delay(500);
		dot(); delay(1500);
		break;
	case 'E' :
		dot();
		delay(1500);
		break;
	case 'F' :
		dot(); delay(500);
		dot(); delay(500);
		line(); delay(500);
		dot(); delay(1500);
		break;
	case 'G' :
		line(); delay(500);
		line(); delay(500);
		dot(); delay(1500);
		break;
	case 'H' :
		for (a = 4; a > 0; a--)
		{
			dot(); delay(500);
		}
		delay(1000);
	case 'I' :
		for (a = 2; a > 0; a--)
		{
			dot(); delay(500);
		}
		delay(1000);
		break;
	case 'J' :
		dot(); delay(500);
		for (a = 3; a > 0; a--)
		{
			line(); delay(500);
		}
		delay(1000);
		break;
	case 'K' :
		line(); delay(500);
		dot(); delay(500);
		line(); delay(1500);
		break;
	case 'L' :
		dot(); delay(500);
		line(); delay(500);
		dot(); delay(500);
		dot(); delay(1500);
		break;
	case 'M' :
		line(); delay(500);
		line(); delay(1500);
		break;
	case 'N' :
		line(); delay(500);
		dot(); delay(1500);
		break;
	case 'O' :
		for (a = 3; a > 0; a--)
		{
			line(); delay(500);
		}
		delay(1000);
		break;
	case 'P' :
		dot(); delay(500);
		line(); delay(500);
		line(); delay(500);
		dot(); delay(1500);
		break;
	case 'Q' :
		line(); delay(500);
		line(); delay(500);
		dot(); delay(500);
		line(); delay(1500);
		break;
	case 'R' :
		dot(); delay(500);
		line(); delay(500);
		dot(); delay(1500);
		break;
	case 'S' :
		for (a = 3; a > 0; a--)
		{
			dot(); delay(500);
		}
		delay(1000);
		break;
	case 'T' :
		line(); delay(1500);
		break;
	case 'U' :
		dot(); delay(500);
		dot(); delay(500);
		line(); delay(1500);
		break;
	case 'V' :
		for (a = 3; a > 0; a--)
		{
			dot(); delay(500);
		}
		line(); delay(1500);
	case 'W' :
		dot(); delay(500);
		line(); delay(500);
		line(); delay(1500);
		break;
	case 'X' :
		line(); delay(500);
		dot(); delay(500);
		dot(); delay(500);
		line(); delay(1500);
		break;
	case 'Y' :
		line(); delay(500);
		dot(); delay(500);
		line(); delay(500);
		line(); delay(1500);
		break;
	case 'Z' :
		line(); delay(500);
		line(); delay(500);
		dot(); delay(500);
		dot(); delay(1500);
		break;
	default :	// blank or anything else
		p10 = 1;
		delay(1000);
	}
}

void main()
{
	uchar a;
	uchar key;
	delay(400); // 启动等待
	IT1 = 0; // 设外部中断 1 为低电平触发
	EA = 1;
	EX1 = 1; // 开中断
	while (1)
	{
		if (BF)
		{
			key = decode(keyCode);
			flash(key);
		}
		else
			EA = 1; // 开中断
	}
}
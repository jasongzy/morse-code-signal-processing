#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include"XPT2046.h"
#include "lcd.h"
#include<string.h>

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

u8 digplay[20] = "\0";
u8 testindex[20][28] = {0};		//一行存放一个字母，存放满清0
u8 morseIndex[36][28] = {"10111000", "111010101000", "11101011101000", "1110101000", "1000", "101011101000", "111011101000", "1010101000", "101000", "1011101110111000", "111010111000", "101110101000", "1110111000", "11101000", "11101110111000", "10111011101000", "1110111010111000", "1011101000", "10101000", "111000",
                         "1010111000", "101010111000", "101110111000", "11101010111000", "1110101110111000", "11101110101000", "1110111011101110111000", "10111011101110111000", "101011101110111000", "1010101110111000", "10101010111000", "101010101000", "11101010101000", "1110111010101000", "111011101110101000", "11101110111011101000"
                        };	// 10 for dot, 1110 for line
u8 readstore[100] = "0";			//用来存储读取AD时判断灯泡亮灭,亮为1，灭为0

void read_and_store()
{	u16 temp, i = 0, j = 0;
	Lcd1602_Delay1ms(500)
	for (i = 0; i < 45; i++)
	{
		temp = Read_AD_Data(0xA4);
		if (temp > 12)
			readstore[j++] = '1';
		if (temp < 10)
			readstore[j++] = '0';
		Lcd1602_Delay1ms(1000);
	}
}

void analysis


void judge()
{
	u16 temp, i = 0, j = 0;
	Lcd1602_Delay1ms(500);
	do
	{
		temp = Read_AD_Data(0xA4);		//读取光敏电阻的AD值
		if (temp > 12)			 //AD值改变，LED为亮
		{
			testindex[i][j++] = '1';
		}

		if (temp < 10)			 //灯泡不亮
		{
			testindex[i][j++] = '0';
		}
		if (j >= 3 && testindex[i][j - 1] == '0' && testindex[i][j - 2] == '0')	// next letter or word
		{
			testindex[i][j] = '\0';
			i++;
			j = 0;
		}
		Lcd1602_Delay1ms(1000);
	} while (i < 20);
}


void interpret(u8 str[][6])
{
	u8 i, j;
	for (j = 0; j < 20; j++)
	{
		for (i = 0; i < 37; i++)
			if (strcmp(str[j], morseIndex[i]) == 0)
			{
				if (i < 26)
					digplay[j] = ((u8)(i + 65));
				else  if (26 <= i < 36)
					digplay[j] = ((u8)(i + 48 - 26));
				else
					digplay[j] = ' ';
			}
	}
}


void main()
{
	u8 i;
	judge();
	interpret(testindex);
	LcdInit();
	for (i = 0; i < 16; i++)
	{
		LcdWriteData(digplay[i]);
	}
	LcdWriteCom(0xc0);
	for (i = 16; i < 20; i++)
		LcdWriteData(digplay[i]);
	while (1);
}


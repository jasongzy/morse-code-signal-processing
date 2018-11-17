#include<judge.h>

uchar digplay[6] = "\0";
uchar testindex[6][17] = {0};		//一行存放一个字母，存放满清0
uchar code morseIndex[27][17] = {
	"10111000", "111010101000", "11101011101000", "1110101000", "1000",
	"101011101000", "111011101000", "1010101000", "101000", "1011101110111000",
	"111010111000", "101110101000", "1110111000", "11101000", "11101110111000",
	"10111011101000", "1110111010111000", "1011101000", "10101000", "111000",
	"1010111000", "101010111000", "101110111000", "11101010111000", "1110101110111000",
	"11101110101000", "0000"
};	// 10 for dot, 1110 for line

void delay(uint c)
{
	uchar a, b;
	for (; c > 0; c--)
	{
		for (b = 199; b > 0; b--)
		{
			for (a = 1; a > 0; a--);
		}
	}

}
void judge()
{
	uint temp, i = 0, j = 0;
	delay(500);
	do
	{
		temp = Read_AD_Data(0xA4);		//读取光敏电阻的AD值
		if (temp > 250)			 //AD值改变，LED为亮
		{
			testindex[i][j++] = '1';
		}

		if (temp <= 250)			 //灯泡不亮
		{
			testindex[i][j++] = '0';
		}
		if (j > 3 && testindex[i][j - 2] == '0' && testindex[i][j - 3] == '0')	// next letter or word
		{
			testindex[i][j] = '\0';
			i++;
			j = 0;
		}
		if (j > 16)	break;	// 灯一直亮，即将溢出
		delay(1000);
	} while (i < 6);
}


void interpret(uchar str[][17])
{
	uchar i, j;
	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < 27; i++)
		{
			digplay[j] = 'e';	// 若未匹配morseIndex，则最后该位是e(rror)
			if (strcmp(str[j], morseIndex[i]) == 0)
			{
				if (i < 26)
					digplay[j] = ((uchar)(i + 65));
				else
					digplay[j] = ' ';
				break;
			}
		}
	}
}
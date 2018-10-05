#include<reg51.h>
#include<string.h>
#define uint unsigned int
#define uchar unsigned char
sbit p10 = P1 ^ 0;

// A to Z, 0 to 9;
uchar morseIndex[36][6] = {"10", "0111", "0101", "011", "1", "1101", "001", "1111", "11", "1000", "010", "1011", "00", "01", "000", "1001", "0010", "101", "111", "0",
                           "110", "1110", "100", "0110", "0100", "0011", "00000", "10000", "11000", "11100", "11110", "11111", "01111", "00111", "00011", "00001"
                          };	// 1 for dot, 0 for line

uchar interpret(uchar *str)
{
	for (uint i = 0; i < 36; i++)
		if (strcmp(str, morseIndex[i]) == 0)
		{
			if (i < 26)
				return ((uchar)(i + 65));
			else
				return ((uchar)(i + 48 - 26));
			break;
		}
}

void main()
{
	uchar code[] = "1001";	// "P"
	// output interpret(code)
}
/**************************************************************************************
*		              LCD1602Һ����ʾʵ��												  *
ʵ���������س�������LCD1602Һ���ڿ������ϣ�������ʾ
ע�������������õ���ģ����ʾ�����Խ�74HC595ģ���ϵ�JP595�̽�Ƭ�ε���
***************************************************************************************/

#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include "lcd.h"
#include"XPT2046.h"
#include"judge.h"

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;


u8 digplay1[] = "hello 674 ";

void main(void)
{
	u8 i;
	judge();
	interpret(testindex);
	LcdInit();
	for (i = 0; i < 6; i++)
	{
		LcdWriteData(digplay[i]);
	}
	while (1);
}
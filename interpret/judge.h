#ifndef _JUDGE_H_
#define _JUDGE_H_

#include <reg52.h>
#include<string.h>
#include<XPT2046.h>


#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif


void judge();
void interpret( unsigned char str[][17]);
extern uchar digplay[] ;
extern uchar testindex[][17];
extern uchar code morseIndex[][17];
#endif
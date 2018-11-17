#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit p10=P1^0;

void delay(uint n)
{	 uint i=0,j=0;
     for(i=0;i<n;i++)
	   for(j=0;j<123;j++);
}	  //延迟函数，延迟n毫秒

void dot()	  
{
   p10=0;   
   delay(1000);
   p10=1;
   delay(1000);
}

void line()
{
   p10=0;
   delay(3000);
   p10=1;
   delay(1000);
   }

void cut1()
{
  p10=0;
  delay(1000);
}

void cut2()
{
  p10=0;
  delay(3000);
}

void delay3()
{
  p10=1;
  delay(1000);
}
     
void main()	   //主函数，调用延迟函数完成 HELLO
{    
	uchar a;
    while(1)
    {
	  for(a=3;a>0;a--)
	  {
	    dot();
	   }
	  cut1();  // H-MORSE
	  delay3(); 

	  cut1();  //E
	  delay3();
	  delay(1000);

	  for(a=2;a>0;a--)
	  {  
	    dot();
		line();
		dot();
		cut1();
		delay3();
      }		//  L L 
	  
	  for(a=2;a>0;a--)
	  {
	    line();
	  }	
	  cut2();
	  delay3();	// O 
      delay(2500);
	}
}
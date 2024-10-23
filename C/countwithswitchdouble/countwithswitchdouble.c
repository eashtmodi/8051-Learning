#include<REG51.h>

void delay(unsigned int d);

sbit t1= P3^7;
sbit t2= P3^6;

sbit s1=P3^5;


char array[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0Xf8,0X80,0X98};


void main(){
	int a,b,c;

	t1=1;
	t2=1;
	s1=1;
	while(1)
		{
				
			while(s1==0){
	for(a=0;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			for(c=0;c<10;c++)
			{
				HERE:
				t1=0;
				t2=1;
				P0=array[a];
				delay(1000);
				t1=1;
				t2=0;
				P0=array[b];
				delay(1000);
				if(s1!=0){
				goto HERE;
				}
			}
		}
	}
}
			}
}
void delay(unsigned int d){
	while(d!=0)
		{
		d--;
	}
}
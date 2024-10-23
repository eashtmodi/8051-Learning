#include<reg51.h>

sbit rs =P3^5;
sbit en =P3^3;

sbit intr=P0^6;
sbit wtr=P0^7;


void delay(unsigned int a);
void command(unsigned int b);
void display(unsigned int c);
void string(char *e);
void ascii(unsigned int tempp);
void start();

void main(){
	unsigned int x;
	P2=0Xff;
	start();
	wtr=1;
	command(0X80);
	display('A');
	while(1){
		intr=1;
		wtr=0;
		delay(100);
		wtr=1;
		while(intr==1);
		x=P2;
		command(0XC0);
		delay(10);
		ascii(x);
	}
}

void delay(unsigned int a){
	while(a!=0){
		a--;
	}
}

void command(unsigned int b){
	rs=0;
	P1=b;
	en=1;
	delay(300);
	en=0;
}

void display(unsigned int c){
	rs=1;
	P1=c;
	en=1;
	delay(300);
	en=0;
}

void start(){
	command(0X01);
	command(0X0C);
	command(0X3C);
	command(0X38);

}

void string(char *e){
	while(*e){
		display(*e++);
		}
}

void ascii(unsigned int tempp){
	char array[]={'0','1','2','3','4','5','6','7','8','9'};
	int a,b,c;
	a=tempp/100;
	display(array[a]);
	b=tempp%10;
	display(array[b]);
	c=tempp%10;
	display(array[c]);
}
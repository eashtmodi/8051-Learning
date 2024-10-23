#include<reg51.h>

sbit rs =P3^5;
sbit en =P3^3;
unsigned int adrress;

void delay(unsigned int a);
void command(unsigned int b);
void display(unsigned int c);
void string(char *e);
void start();


void main(){
	start();
	while(1){
	for(adrress=0XC0;adrress<=0XCF;adrress++){
		command(0X01);
		command(adrress);
		delay(6500);
		string("NUMITECH");
		delay(6500);
		
	}
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


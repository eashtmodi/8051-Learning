#include<reg51.h>

sbit rs =P3^5;
sbit en =P3^3;

sbit ir =P3^7;

void delay(unsigned int a);
void command(unsigned int b);
void display(unsigned int c);
void string(char *e);
void ascii(unsigned int q);
void start();

int count=0;

void main(){
	start();
	command(0x80);
	display('a');
	while(1){
	if(ir==1){
		count++;
		command(0x81);
		ascii(count);
		P0=0xff;
		while(ir==1){
			delay(65000);
		}
		
	}
	
	if(ir==0){
		P0=0x00;
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

void ascii(unsigned int q){
	char array[]={'0','1','2','3','4','5','6','7','8','9'};
	int a,b;
	a=q/10;
	display(array[a]);
	b=q%10;
	display(array[b]);
}

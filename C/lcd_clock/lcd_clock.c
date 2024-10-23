#include<reg51.h>

sbit rs =P3^5;
sbit en =P3^3;
int d,e,f;

void delay(unsigned int a);
void command(unsigned int b);
void display(unsigned int c);
void ascii(unsigned int g);
void start();
void main(){
	start();
	while(1){
	for(d=0;d<24;d++){
		for(e=0;e<60;e++){
			for(f=0;f<60;f++){
			command(0X81);
			ascii(d);
			display(':');
			ascii(e);
			display(':');
			ascii(f);
			delay(65000);
		}
	}
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

void ascii(unsigned int g){
	char array[]={'0','1','2','3','4','5','6','7','8','9'};
  int a,b;
	a=g/10;
	display(array[a]);
	b=g%10;
	display(array[b]);
}



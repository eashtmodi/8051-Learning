#include<reg51.h>

#define switches P0

sbit rs =P3^5;
sbit en =P3^3;


void delay(unsigned int z);
void command(unsigned int b);
void display(unsigned int c);
void string(char *e);
void start();


unsigned int a;

void main(){
	
	P3=0;
	P0=0Xff;
	
	
	start();
	command(0X01);
	
	
	
	while(1){
		main:switches=0X0F;
	
		if(switches==0X0F){
			goto main;
		}
		
		switches=0XEF;
				a=switches;

		if(a!=0XEF){
			if(a==0XE7){
				//P3=1;
				command(0X01);
				display('A');

			}
			
			if(a==0XEB){
				//P3=2;
				command(0X01);
				display('B');
			}
			
			if(a==0XED){
				P3=3;
				command(0X01);
				display('C');
			}
			
			if(a==0XEE){
				//P3=4;
				command(0X01);
				display('D');
			}
			
		}
		
		switches=0XDF;
				a=switches;

		if(a!=0XDF){
			if(a==0XD7){
				//P3=5;
				command(0X01);
				display('E');
			}
			
			if(a==0XDB){
				//P3=6;
				command(0X01);
				display('F');
			}
			
			if(a==0XDD){
				//P3=7;
				command(0X01);
				display('G');
			}
			
			if(a==0XDE){
				//P3=8;
				command(0X01);
				display('H');
			}
		}
		
		switches=0XBF;
				a=switches;

		if(a!=0XBF){
			if(a==0XB7){
				//P3=9;
				command(0X01);
				display('I');
			}
			
			if(a==0XBB){
				//P3=10;
				command(0X01);
				display('J');
			}
			
			if(a==0XBD){
				//P3=11;
				command(0X01);
				display('K');
			}
			
			if(a==0XBE){
				//P3=12;
				command(0X01);
				display('L');
			}
		}
		
		switches=0X7F;
		a=switches;
		
		if(a!=0X7F){
			if(a==0X77){
				//P3=13;
				command(0X01);
				display('M');
			}
			
			if(a==0X7B){
				//P3=14;
				command(0X01);
				display('N');
			}
			
			if(a==0X7D){
				//P3=15;
				command(0X01);
				display('O');
			}
			
			if(a==0X7E){
				//P3=16;
				command(0X01);
				display('P');
			}
		}
		
	}
}


void delay(unsigned int z){
	while(z!=0){
		z--;
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
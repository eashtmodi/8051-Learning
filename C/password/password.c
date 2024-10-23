#include<reg51.h>

#define switches P0

sbit rs =P3^5;
sbit en =P3^3;

unsigned int password[]={1,2,3,4};

unsigned int array[4];


void delay(unsigned int z);
void command(unsigned int b);
void display(unsigned int c);
void string(char *e);
void start();

int index=-1;


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
				index=index+1;
				array[index]=1;
				display('*');
				delay(65000);

			}
			
			if(a==0XEB){
				//P3=2;
				index=index+1;
				array[index]=2;
				display('*');
				delay(65000);

			}
			
			if(a==0XED){
				P3=3;
				index=index+1;
				array[index]=3;
				display('*');
				delay(65000);

			}
			
			if(a==0XEE){
				//P3=4;
				index=index+1;
				array[index]=4;
				display('*');
				delay(65000);
			}
			
		}
		
		switches=0XDF;
				a=switches;

		if(a!=0XDF){
			if(a==0XD7){
				//P3=5;
				index=index+1;
				array[index]=5;
				display('*');
				delay(65000);
			}
			
			if(a==0XDB){
				//P3=6;
				index=index+1;
				array[index]=6;
				display('*');
				delay(65000);
			}
			
			if(a==0XDD){
				//P3=7;
				index=index+1;
				array[index]=7;
				display('*');
				delay(65000);
			}
			
			if(a==0XDE){
				//P3=8;
				index=index+1;
				array[index]=8;
				display('*');
				delay(65000);
			}
		}
		
		switches=0XBF;
				a=switches;

		if(a!=0XBF){
			if(a==0XB7){
				//P3=9;
				index=index+1;
				array[index]=9;
				display('*');
				delay(65000);
			}
			
			if(a==0XBB){
				//P3=10;
				index=index+1;
				array[index]=10;
			display('*');
				delay(65000);
			}
			
			if(a==0XBD){
				//P3=11;
				index=index+1;
				array[index]=11;
				display('*');
				delay(65000);
			}
			
			if(a==0XBE){
				//P3=12;
				index=index+1;
				array[index]=12;
				display('*');
				delay(65000);
			}
		}
		
		switches=0X7F;
		a=switches;
		
		if(a!=0X7F){
			if(a==0X77){
				//P3=13;
				index=index+1;
				array[index]=13;
				display('*');
				delay(65000);
			}
			
			if(a==0X7B){
				//P3=14;
				index=index+1;
				array[index]=14;
				display('*');
				delay(65000);
			}
			
			if(a==0X7D){
				//P3=15;
				index=index+1;
				array[index]=15;
				display('*');
				delay(65000);
			}
			
			if(a==0X7E){
				//P3=16;
				index=index+1;
				array[index]=16;
				display('*');
				delay(65000);
			}
		}
		if(password[0]==array[0] && password[1]==array[1] && password[2]==array[2] && password[3]==array[3]){
			command(0XC3);
			display('D');
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
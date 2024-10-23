#include<reg51.h>

#define switches P0

void delay(unsigned int a);

int a;


void main(){
	
	P3=0;
	P0=0Xff;
	
	while(1){
		main:switches=0X0F;
	
		if(switches==0X0F){
			goto main;
		}
		
		switches=0XEF;
				a=switches;

		if(a!=0XEF){
			if(a==0XE7){
				P3=1;
			}
			
			if(a==0XEB){
				P3=2;
			}
			
			if(a==0XED){
				P3=3;
			}
			
			if(a==0XEE){
				P3=4;
			}
			
		}
		
		switches=0XDF;
				a=switches;

		if(a!=0XDF){
			if(a==0XD7){
				P3=5;
			}
			
			if(a==0XDB){
				P3=6;
			}
			
			if(a==0XDD){
				P3=7;
			}
			
			if(a==0XDE){
				P3=8;
			}
		}
		
		switches=0XBF;
				a=switches;

		if(a!=0XBF){
			if(a==0XB7){
				P3=9;
			}
			
			if(a==0XBB){
				P3=10;
			}
			
			if(a==0XBD){
				P3=11;
			}
			
			if(a==0XBE){
				P3=12;
			}
		}
		
		switches=0X7F;
		a=switches;
		
		if(a!=0X7F){
			if(a==0X77){
				P3=13;
			}
			
			if(a==0X7B){
				P3=14;
			}
			
			if(a==0X7D){
				P3=15;
			}
			
			if(a==0X7E){
				P3=16;
			}
		}
		
	}
}
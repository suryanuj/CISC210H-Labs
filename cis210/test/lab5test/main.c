//Name of file: main.c
//Name of author: Shaun Gupta
//Date: April 13, 2020
//Description of file: In this file is my work for Lab 5. Lab 5 asked us the use the pi to represent 4 dice being shaken.

#include <stdio.h>
#include <sense/sense.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <linux/input.h>
#define _GNU_SOURCE

//Below are functions that tell me what the colors are. I did this so that I can call the colors in different functions

//Declaration of Variables
int g;
pi_framebuffer_t* fb;
int run=1;
float x=0;
float y=0;
uint16_t color;
pi_framebuffer_t* fb;
pi_i2c_t* device;

//Position of the Pi: Sideways with the USD ports facing right.

//interruptHandler will be called when a SIGINT event occurs (i.e. ctrl-c)
void interruptHandler(int sig){
	run=0;
}

//The functions that draw the numbers on the screen
void dice1num1(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,g);
}

void dice1num2(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,g);
        setPixel(fb->bitmap,0,6,g);
}

void dice1num3(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,g);
        setPixel(fb->bitmap,1,6,g);
        setPixel(fb->bitmap,2,5,g);
}

void dice1num4(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,g);
        setPixel(fb->bitmap,0,5,g);
        setPixel(fb->bitmap,2,7,g);
        setPixel(fb->bitmap,2,5,g);
}

void dice1num5(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,g);
        setPixel(fb->bitmap,0,5,g);
        setPixel(fb->bitmap,2,7,g);
        setPixel(fb->bitmap,2,5,g);
        setPixel(fb->bitmap,1,6,g);
}

void dice1num6(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,g);
        setPixel(fb->bitmap,1,7,g);
        setPixel(fb->bitmap,0,6,g);
        setPixel(fb->bitmap,1,6,g);
        setPixel(fb->bitmap,0,5,g);
        setPixel(fb->bitmap,1,5,g);
}

void dice2num1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,g);
}

void dice2num2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,g);
	setPixel(fb->bitmap,5,6,g);
}

void dice2num3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,g);
	setPixel(fb->bitmap,6,6,g);
	setPixel(fb->bitmap,7,5,g);
}

void dice2num4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,g);
	setPixel(fb->bitmap,5,5,g);
	setPixel(fb->bitmap,7,7,g);
	setPixel(fb->bitmap,7,5,g);
}

void dice2num5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,g);
	setPixel(fb->bitmap,5,5,g);
	setPixel(fb->bitmap,7,7,g);
	setPixel(fb->bitmap,7,5,g);
	setPixel(fb->bitmap,6,6,g);
}

void dice2num6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,g);
	setPixel(fb->bitmap,6,7,g);
	setPixel(fb->bitmap,5,6,g);
	setPixel(fb->bitmap,6,6,g);
	setPixel(fb->bitmap,5,5,g);
	setPixel(fb->bitmap,6,5,g);
}

//Dice 3 (Lower Left Section) Values Red
void dice3num1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,g);
}

void dice3num2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,g);
	setPixel(fb->bitmap,0,1,g);
}

void dice3num3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,g);
	setPixel(fb->bitmap,1,1,g);
	setPixel(fb->bitmap,2,0,g);
}

void dice3num4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,g);
	setPixel(fb->bitmap,0,0,g);
	setPixel(fb->bitmap,2,0,g);
	setPixel(fb->bitmap,2,2,g);
}

void dice3num5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,g);
	setPixel(fb->bitmap,0,0,g);
	setPixel(fb->bitmap,2,0,g);
	setPixel(fb->bitmap,2,2,g);
	setPixel(fb->bitmap,1,1,g);
}

void dice3num6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,g);
	setPixel(fb->bitmap,0,1,g);
	setPixel(fb->bitmap,0,0,g);
	setPixel(fb->bitmap,1,0,g);
	setPixel(fb->bitmap,1,1,g);
	setPixel(fb->bitmap,1,2,g);
}

//Dice 4 (Lower Right Section) Values Red
void dice4num1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,g);
}

void dice4num2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,g);
	setPixel(fb->bitmap,5,1,g);
}

void dice4num3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,g);
	setPixel(fb->bitmap,6,1,g);
	setPixel(fb->bitmap,7,0,g);
}

void dice4num4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,g);
	setPixel(fb->bitmap,5,0,g);
	setPixel(fb->bitmap,7,0,g);
	setPixel(fb->bitmap,7,2,g);
}

void dice4num5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,g);
	setPixel(fb->bitmap,5,0,g);
	setPixel(fb->bitmap,7,0,g);
	setPixel(fb->bitmap,7,2,g);
	setPixel(fb->bitmap,6,1,g);
}

void dice4num6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,g);
	setPixel(fb->bitmap,5,1,g);
	setPixel(fb->bitmap,5,0,g);
	setPixel(fb->bitmap,6,0,g);
	setPixel(fb->bitmap,6,1,g);
	setPixel(fb->bitmap,6,2,g);
}

//Main function for the program.
int main(){
	int red=getColor(255,0,0);
	int green=getColor(0,255,0);
	int blue=getColor(0,0,255);
	int yellow=getColor(255,255,0);
	int blank=getColor(0,0,0);

	srand(time(0));

	int cnt=0;
	pi_i2c_t* device=geti2cDevice();
	coordinate_t data;
	signal(SIGINT, interruptHandler);
	device=geti2cDevice();

	pi_joystick_t* joystick=getJoystickDevice();
	pi_framebuffer_t* fb=getFBDevice();
	clearBitmap(fb->bitmap,blank);

	if (device){
		configureAccelGyro(device);
		while (run){
			usleep(2000);
			while (run && getGyroPosition(device,&data)){
				if (data.x>6){
						pi_framebuffer_t* fb=getFBDevice();
						clearBitmap(fb->bitmap,0);
	//Dice 1 Possibilities
	int a=(rand() %(6+1-1))+1;
	
	if (a==1)
		{g=red;dice1num1(fb);}
	else if (a==2)
		{g=red;dice1num2(fb);}
	else if (a==3)
		{g=red;dice1num3(fb);}
	else if (a==4)
		{g=red;dice1num4(fb);}
	else if (a==5)
		{g=red;dice1num5(fb);}
	else if (a==6)
		{g=red;dice1num6(fb);}

	//Dice 2 Possibilities
	int b=(rand() %(12+1-7))+7;
	if (b==7)
		{g=blue;dice2num1(fb);}
        else if (b==8)
		{g=blue;dice2num2(fb);}
        else if (b==9)
        	{g=blue;dice2num3(fb);}
        else if (b==10)
        	{g=blue;dice2num4(fb);}
        else if (b==11)
        	{g=blue;dice2num5(fb);}
        else if (b==12)
        	{g=blue;dice2num6(fb);}

	//Dice 3 Possibilities
	int c=(rand() %(18+1-13))+13;
	if (c==13)
		{g=green;dice3num1(fb);}
        else if (c==14)
        	{g=green;dice3num2(fb);}
        else if (c==15)
        	{g=green;dice3num3(fb);}
       	else if (c==16)
       		{g=green;dice3num4(fb);}
       	else if (c==17)
       		{g=green;dice3num5(fb);}
	else if (c==18)
		{g=green;dice3num6(fb);}

	//Dice 4 Possibilities
	int d=(rand() %(24+1-19))+19;
	if (d==19)
		{g=yellow;dice4num1(fb);}
        else if (d==20)
        	{g=yellow;dice4num2(fb);}
        else if (d==21)
        	{g=yellow;dice4num3(fb);}
        else if (d==22)
        	{g=yellow;dice4num4(fb);}
        else if (d==23)
        	{g=yellow;dice4num5(fb);}
        else if (d==24)
        	{g=yellow;dice4num6(fb);}

		cnt=0;
 				printf("Gyro: %f %f %f\n",data.x,data.y,data.z);
					}
				cnt++;		
			}
		}
		printf("\nExiting...\n");
		clearBitmap(fb->bitmap,0);
		freeFrameBuffer(fb);
		freei2cDevice(device);
		freeJoystick(joystick);
	}
	return 0;
}

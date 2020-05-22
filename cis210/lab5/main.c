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
int red(){return getColor(255,0,0);}
int blank(){return getColor(0,0,0);}
int blue(){return getColor(0,0,255);}
int green(){return getColor(0,255,0);}
int yellow(){return getColor(255,255,0);}

//Declaration of Variables
int a,b,c,d;
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

//Dice 1 (Upper Left Section) Values Red
void dice1num1r(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,red());
}

void dice1num2r(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,red());
        setPixel(fb->bitmap,0,6,red());
}

void dice1num3r(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,red());
        setPixel(fb->bitmap,1,6,red());
        setPixel(fb->bitmap,2,5,red());
}

void dice1num4r(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,red());
        setPixel(fb->bitmap,0,5,red());
        setPixel(fb->bitmap,2,7,red());
        setPixel(fb->bitmap,2,5,red());
}

void dice1num5r(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,red());
        setPixel(fb->bitmap,0,5,red());
        setPixel(fb->bitmap,2,7,red());
        setPixel(fb->bitmap,2,5,red());
        setPixel(fb->bitmap,1,6,red());
}

void dice1num6r(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,red());
        setPixel(fb->bitmap,1,7,red());
        setPixel(fb->bitmap,0,6,red());
        setPixel(fb->bitmap,1,6,red());
        setPixel(fb->bitmap,0,5,red());
        setPixel(fb->bitmap,1,5,red());
}

//Dice 2 (Upper Right Section) Values Red
void dice2num1r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,red());
}

void dice2num2r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,red());
	setPixel(fb->bitmap,5,6,red());
}

void dice2num3r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,red());
	setPixel(fb->bitmap,6,6,red());
	setPixel(fb->bitmap,7,5,red());
}

void dice2num4r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,7,red());
	setPixel(fb->bitmap,7,5,red());
}

void dice2num5r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,7,red());
	setPixel(fb->bitmap,7,5,red());
	setPixel(fb->bitmap,6,6,red());
}

void dice2num6r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,red());
	setPixel(fb->bitmap,6,7,red());
	setPixel(fb->bitmap,5,6,red());
	setPixel(fb->bitmap,6,6,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

//Dice 3 (Lower Left Section) Values Red
void dice3num1r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,red());
}

void dice3num2r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,red());
	setPixel(fb->bitmap,0,1,red());
}

void dice3num3r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,red());
	setPixel(fb->bitmap,1,1,red());
	setPixel(fb->bitmap,2,0,red());
}

void dice3num4r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,red());
	setPixel(fb->bitmap,0,0,red());
	setPixel(fb->bitmap,2,0,red());
	setPixel(fb->bitmap,2,2,red());
}

void dice3num5r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,red());
	setPixel(fb->bitmap,0,0,red());
	setPixel(fb->bitmap,2,0,red());
	setPixel(fb->bitmap,2,2,red());
	setPixel(fb->bitmap,1,1,red());
}

void dice3num6r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,red());
	setPixel(fb->bitmap,0,1,red());
	setPixel(fb->bitmap,0,0,red());
	setPixel(fb->bitmap,1,0,red());
	setPixel(fb->bitmap,1,1,red());
	setPixel(fb->bitmap,1,2,red());
}

//Dice 4 (Lower Right Section) Values Red
void dice4num1r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,red());
}

void dice4num2r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,red());
	setPixel(fb->bitmap,5,1,red());
}

void dice4num3r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,red());
	setPixel(fb->bitmap,6,1,red());
	setPixel(fb->bitmap,7,0,red());
}

void dice4num4r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,red());
	setPixel(fb->bitmap,5,0,red());
	setPixel(fb->bitmap,7,0,red());
	setPixel(fb->bitmap,7,2,red());
}

void dice4num5r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,red());
	setPixel(fb->bitmap,5,0,red());
	setPixel(fb->bitmap,7,0,red());
	setPixel(fb->bitmap,7,2,red());
	setPixel(fb->bitmap,6,1,red());
}

void dice4num6r(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,red());
	setPixel(fb->bitmap,5,1,red());
	setPixel(fb->bitmap,5,0,red());
	setPixel(fb->bitmap,6,0,red());
	setPixel(fb->bitmap,6,1,red());
	setPixel(fb->bitmap,6,2,red());
}


//Dice 1 (Upper Left Section) Values Blue
void dice1num1b(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,blue());
}

void dice1num2b(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,blue());
        setPixel(fb->bitmap,0,6,blue());
}

void dice1num3b(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,blue());
        setPixel(fb->bitmap,1,6,blue());
        setPixel(fb->bitmap,2,5,blue());
}

void dice1num4b(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,blue());
        setPixel(fb->bitmap,0,5,blue());
        setPixel(fb->bitmap,2,7,blue());
        setPixel(fb->bitmap,2,5,blue());
}

void dice1num5b(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,blue());
        setPixel(fb->bitmap,0,5,blue());
        setPixel(fb->bitmap,2,7,blue());
        setPixel(fb->bitmap,2,5,blue());
        setPixel(fb->bitmap,1,6,blue());
}

void dice1num6b(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,blue());
        setPixel(fb->bitmap,1,7,blue());
        setPixel(fb->bitmap,0,6,blue());
        setPixel(fb->bitmap,1,6,blue());
        setPixel(fb->bitmap,0,5,blue());
        setPixel(fb->bitmap,1,5,blue());
}

//Dice 2 (Upper Right Section) Values Blue
void dice2num1b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,blue());
}

void dice2num2b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,blue());
	setPixel(fb->bitmap,5,6,blue());
}

void dice2num3b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,blue());
	setPixel(fb->bitmap,6,6,blue());
	setPixel(fb->bitmap,7,5,blue());
}

void dice2num4b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,blue());
	setPixel(fb->bitmap,5,5,blue());
	setPixel(fb->bitmap,7,7,blue());
	setPixel(fb->bitmap,7,5,blue());
}

void dice2num5b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,blue());
	setPixel(fb->bitmap,5,5,blue());
	setPixel(fb->bitmap,7,7,blue());
	setPixel(fb->bitmap,7,5,blue());
	setPixel(fb->bitmap,6,6,blue());
}

void dice2num6b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,blue());
	setPixel(fb->bitmap,6,7,blue());
	setPixel(fb->bitmap,5,6,blue());
	setPixel(fb->bitmap,6,6,blue());
	setPixel(fb->bitmap,5,5,blue());
	setPixel(fb->bitmap,6,5,blue());
}

//Dice 3 (Lower Left Section) Values Blue
void dice3num1b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,blue());
}

void dice3num2b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,blue());
	setPixel(fb->bitmap,0,1,blue());
}

void dice3num3b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,blue());
	setPixel(fb->bitmap,1,1,blue());
	setPixel(fb->bitmap,2,0,blue());
}

void dice3num4b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,blue());
	setPixel(fb->bitmap,0,0,blue());
	setPixel(fb->bitmap,2,0,blue());
	setPixel(fb->bitmap,2,2,blue());
}

void dice3num5b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,blue());
	setPixel(fb->bitmap,0,0,blue());
	setPixel(fb->bitmap,2,0,blue());
	setPixel(fb->bitmap,2,2,blue());
	setPixel(fb->bitmap,1,1,blue());
}

void dice3num6b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,blue());
	setPixel(fb->bitmap,0,1,blue());
	setPixel(fb->bitmap,0,0,blue());
	setPixel(fb->bitmap,1,0,blue());
	setPixel(fb->bitmap,1,1,blue());
	setPixel(fb->bitmap,1,2,blue());
}

//Dice 4 (Lower Right Section) Values Blue
void dice4num1b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,blue());
}

void dice4num2b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,5,1,blue());
}

void dice4num3b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,7,0,blue());
}

void dice4num4b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,blue());
	setPixel(fb->bitmap,5,0,blue());
	setPixel(fb->bitmap,7,0,blue());
	setPixel(fb->bitmap,7,2,blue());
}

void dice4num5b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,blue());
	setPixel(fb->bitmap,5,0,blue());
	setPixel(fb->bitmap,7,0,blue());
	setPixel(fb->bitmap,7,2,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void dice4num6b(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,5,0,blue());
	setPixel(fb->bitmap,6,0,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,6,2,blue());
}


//Dice 1 (Upper Left Section) Values Green
void dice1num1g(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,green());
}

void dice1num2g(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,green());
        setPixel(fb->bitmap,0,6,green());
}

void dice1num3g(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,green());
        setPixel(fb->bitmap,1,6,green());
        setPixel(fb->bitmap,2,5,green());
}

void dice1num4g(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,green());
        setPixel(fb->bitmap,0,5,green());
        setPixel(fb->bitmap,2,7,green());
        setPixel(fb->bitmap,2,5,green());
}

void dice1num5g(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,green());
        setPixel(fb->bitmap,0,5,green());
        setPixel(fb->bitmap,2,7,green());
        setPixel(fb->bitmap,2,5,green());
        setPixel(fb->bitmap,1,6,green());
}

void dice1num6g(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,green());
        setPixel(fb->bitmap,1,7,green());
        setPixel(fb->bitmap,0,6,green());
        setPixel(fb->bitmap,1,6,green());
        setPixel(fb->bitmap,0,5,green());
        setPixel(fb->bitmap,1,5,green());
}

//Dice 2 (Upper Right Section) Values Green
void dice2num1g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,green());
}

void dice2num2g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,green());
	setPixel(fb->bitmap,5,6,green());
}

void dice2num3g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,green());
	setPixel(fb->bitmap,6,6,green());
	setPixel(fb->bitmap,7,5,green());
}

void dice2num4g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,green());
	setPixel(fb->bitmap,5,5,green());
	setPixel(fb->bitmap,7,7,green());
	setPixel(fb->bitmap,7,5,green());
}

void dice2num5g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,green());
	setPixel(fb->bitmap,5,5,green());
	setPixel(fb->bitmap,7,7,green());
	setPixel(fb->bitmap,7,5,green());
	setPixel(fb->bitmap,6,6,green());
}

void dice2num6g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,green());
	setPixel(fb->bitmap,6,7,green());
	setPixel(fb->bitmap,5,6,green());
	setPixel(fb->bitmap,6,6,green());
	setPixel(fb->bitmap,5,5,green());
	setPixel(fb->bitmap,6,5,green());
}

//Dice 3 (Lower Left Section) Values Green
void dice3num1g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,green());
}

void dice3num2g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,green());
	setPixel(fb->bitmap,0,1,green());
}

void dice3num3g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,green());
	setPixel(fb->bitmap,1,1,green());
	setPixel(fb->bitmap,2,0,green());
}

void dice3num4g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,green());
	setPixel(fb->bitmap,0,0,green());
	setPixel(fb->bitmap,2,0,green());
	setPixel(fb->bitmap,2,2,green());
}

void dice3num5g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,green());
	setPixel(fb->bitmap,0,0,green());
	setPixel(fb->bitmap,2,0,green());
	setPixel(fb->bitmap,2,2,green());
	setPixel(fb->bitmap,1,1,green());
}

void dice3num6g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,green());
	setPixel(fb->bitmap,0,1,green());
	setPixel(fb->bitmap,0,0,green());
	setPixel(fb->bitmap,1,0,green());
	setPixel(fb->bitmap,1,1,green());
	setPixel(fb->bitmap,1,2,green());
}

//Dice 4 (Lower Right Section) Values Green
void dice4num1g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,green());
}

void dice4num2g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,green());
	setPixel(fb->bitmap,5,1,green());
}

void dice4num3g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,green());
	setPixel(fb->bitmap,6,1,green());
	setPixel(fb->bitmap,7,0,green());
}

void dice4num4g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,green());
	setPixel(fb->bitmap,5,0,green());
	setPixel(fb->bitmap,7,0,green());
	setPixel(fb->bitmap,7,2,green());
}

void dice4num5g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,green());
	setPixel(fb->bitmap,5,0,green());
	setPixel(fb->bitmap,7,0,green());
	setPixel(fb->bitmap,7,2,green());
	setPixel(fb->bitmap,6,1,green());
}

void dice4num6g(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,green());
	setPixel(fb->bitmap,5,1,green());
	setPixel(fb->bitmap,5,0,green());
	setPixel(fb->bitmap,6,0,green());
	setPixel(fb->bitmap,6,1,green());
	setPixel(fb->bitmap,6,2,green());
}

//Dice 1 (Upper Left Section) Values Yellow
void dice1num1y(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,yellow());
}

void dice1num2y(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,1,6,yellow());
        setPixel(fb->bitmap,0,6,yellow());
}

void dice1num3y(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,yellow());
        setPixel(fb->bitmap,1,6,yellow());
        setPixel(fb->bitmap,2,5,yellow());
}

void dice1num4y(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,yellow());
        setPixel(fb->bitmap,0,5,yellow());
        setPixel(fb->bitmap,2,7,yellow());
        setPixel(fb->bitmap,2,5,yellow());
}

void dice1num5y(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,yellow());
        setPixel(fb->bitmap,0,5,yellow());
        setPixel(fb->bitmap,2,7,yellow());
        setPixel(fb->bitmap,2,5,yellow());
        setPixel(fb->bitmap,1,6,yellow());
}

void dice1num6y(pi_framebuffer_t* fb){
        setPixel(fb->bitmap,0,7,yellow());
        setPixel(fb->bitmap,1,7,yellow());
        setPixel(fb->bitmap,0,6,yellow());
        setPixel(fb->bitmap,1,6,yellow());
        setPixel(fb->bitmap,0,5,yellow());
        setPixel(fb->bitmap,1,5,yellow());
}

//Dice 2 (Upper Right Section) Values Yellow
void dice2num1y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,yellow());
}

void dice2num2y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,6,yellow());
	setPixel(fb->bitmap,5,6,yellow());
}

void dice2num3y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,yellow());
	setPixel(fb->bitmap,6,6,yellow());
	setPixel(fb->bitmap,7,5,yellow());
}

void dice2num4y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,yellow());
	setPixel(fb->bitmap,5,5,yellow());
	setPixel(fb->bitmap,7,7,yellow());
	setPixel(fb->bitmap,7,5,yellow());
}

void dice2num5y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,yellow());
	setPixel(fb->bitmap,5,5,yellow());
	setPixel(fb->bitmap,7,7,yellow());
	setPixel(fb->bitmap,7,5,yellow());
	setPixel(fb->bitmap,6,6,yellow());
}

void dice2num6y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,7,yellow());
	setPixel(fb->bitmap,6,7,yellow());
	setPixel(fb->bitmap,5,6,yellow());
	setPixel(fb->bitmap,6,6,yellow());
	setPixel(fb->bitmap,5,5,yellow());
	setPixel(fb->bitmap,6,5,yellow());
}

//Dice 3 (Lower Left Section) Values Yellow
void dice3num1y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,yellow());
}

void dice3num2y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,1,yellow());
	setPixel(fb->bitmap,0,1,yellow());
}

void dice3num3y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,yellow());
	setPixel(fb->bitmap,1,1,yellow());
	setPixel(fb->bitmap,2,0,yellow());
}

void dice3num4y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,yellow());
	setPixel(fb->bitmap,0,0,yellow());
	setPixel(fb->bitmap,2,0,yellow());
	setPixel(fb->bitmap,2,2,yellow());
}

void dice3num5y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,yellow());
	setPixel(fb->bitmap,0,0,yellow());
	setPixel(fb->bitmap,2,0,yellow());
	setPixel(fb->bitmap,2,2,yellow());
	setPixel(fb->bitmap,1,1,yellow());
}

void dice3num6y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,0,2,yellow());
	setPixel(fb->bitmap,0,1,yellow());
	setPixel(fb->bitmap,0,0,yellow());
	setPixel(fb->bitmap,1,0,yellow());
	setPixel(fb->bitmap,1,1,yellow());
	setPixel(fb->bitmap,1,2,yellow());
}

//Dice 4 (Lower Right Section) Values Yellow
void dice4num1y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,yellow());
}

void dice4num2y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,yellow());
	setPixel(fb->bitmap,5,1,yellow());
}

void dice4num3y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,yellow());
	setPixel(fb->bitmap,6,1,yellow());
	setPixel(fb->bitmap,7,0,yellow());
}

void dice4num4y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,yellow());
	setPixel(fb->bitmap,5,0,yellow());
	setPixel(fb->bitmap,7,0,yellow());
	setPixel(fb->bitmap,7,2,yellow());
}

void dice4num5y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,yellow());
	setPixel(fb->bitmap,5,0,yellow());
	setPixel(fb->bitmap,7,0,yellow());
	setPixel(fb->bitmap,7,2,yellow());
	setPixel(fb->bitmap,6,1,yellow());
}

void dice4num6y(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,2,yellow());
	setPixel(fb->bitmap,5,1,yellow());
	setPixel(fb->bitmap,5,0,yellow());
	setPixel(fb->bitmap,6,0,yellow());
	setPixel(fb->bitmap,6,1,yellow());
	setPixel(fb->bitmap,6,2,yellow());
}


//Function for the joystick. When you do something with the joystick, it changes the color. 
void callbackFn(unsigned int code){
	setPixel(fb->bitmap,x,y,0);

	switch(code){
		case KEY_UP:
			//Red Options
			clearBitmap(fb->bitmap,0);
			setPixel(fb->bitmap,x,y,red());
			//Dice 1 Possibilities
		
				if (a==1)
					{dice1num1r(fb);}
				else if (a==2)
					{dice1num2r(fb);}
				else if (a==3)
					{dice1num3r(fb);}
				else if (a==4)
					{dice1num4r(fb);}
				else if (a==5)
					{dice1num5r(fb);}
				else if (a==6)
					{dice1num6r(fb);}
	
			//Dice 2 Possibilities
    				
				clearBitmap(fb->bitmap,0);
				if (b==7)
     					{dice2num1r(fb);}
        			else if (b==8)
					{dice2num2r(fb);}
        			else if (b==9)
        				{dice2num3r(fb);}
        			else if (b==10)
        				{dice2num4r(fb);}
        			else if (b==11)
        				{dice2num5r(fb);}
        			else if (b==12)
        				{dice2num6r(fb);}

			//Dice 3 Possibilities
        
				clearBitmap(fb->bitmap,0);
        			if (c==13)
        				{dice3num1r(fb);}
        			else if (c==14)
        				{dice3num2r(fb);}
        			else if (c==15)
        				{dice3num3r(fb);}
        			else if (c==16)
        				{dice3num4r(fb);}
       				else if (c==17)
        				{dice3num5r(fb);}
        			else if (c==18)
        				{dice3num6r(fb);}
        
			//Dice 4 Possibilities
        	
				clearBitmap(fb->bitmap,0);
        			if (d==19)
        				{dice4num1r(fb);}
        			else if (d==20)
        				{dice4num2r(fb);}
        			else if (d==21)
        				{dice4num3r(fb);}
        			else if (d==22)
        				{dice4num4r(fb);}
        			else if (d==23)
        				{dice4num5r(fb);}
        			else if (d==24)
        				{dice4num6r(fb);}			
			
				break;
		case KEY_DOWN:
			//Blue Options
			clearBitmap(fb->bitmap,0);
			setPixel(fb->bitmap,x,y,blue());
			//Dice 1 Possibilities
	
				if (a==1)
					{dice1num1b(fb);}
				else if (a==2)
					{dice1num2b(fb);}
				else if (a==3)
					{dice1num3b(fb);}
				else if (a==4)
					{dice1num4b(fb);}
				else if (a==5)
					{dice1num5b(fb);}
				else if (a==6)
					{dice1num6b(fb);}
	
			//Dice 2 Possibilities

     				if (b==7)
        				{dice2num1b(fb);}
        			else if (b==8)
					{dice2num2b(fb);}
        			else if (b==9)
        				{dice2num3b(fb);}
        			else if (b==10)
        				{dice2num4b(fb);}
        			else if (b==11)
        				{dice2num5b(fb);}
        			else if (b==12)
        				{dice2num6b(fb);}

			//Dice 3 Possibilities

        			if (c==13)
        				{dice3num1b(fb);}
        			else if (c==14)
        				{dice3num2b(fb);}
        			else if (c==15)
        				{dice3num3b(fb);}
        			else if (c==16)
        				{dice3num4b(fb);}
       				else if (c==17)
        				{dice3num5b(fb);}
        			else if (c==18)
        				{dice3num6b(fb);}
        
			//Dice 4 Possibilities

				if (d==19)
    					{dice4num1b(fb);}
        			else if (d==20)
        				{dice4num2b(fb);}
        			else if (d==21)
        				{dice4num3b(fb);}
        			else if (d==22)
        				{dice4num4b(fb);}
        			else if (d==23)
        				{dice4num5b(fb);}
        			else if (d==24)
        				{dice4num6b(fb);}
				
				break;
		case KEY_RIGHT:
			//Green Options
			clearBitmap(fb->bitmap,0);
			setPixel(fb->bitmap,x,y,green());
			//Dice 1 Possibilities
	
				if (a==1)
					{dice1num1g(fb);}
				else if (a==2)
					{dice1num2g(fb);}
				else if (a==3)
					{dice1num3g(fb);}
				else if (a==4)
					{dice1num4g(fb);}
				else if (a==5)
					{dice1num5g(fb);}
				else if (a==6)
					{dice1num6g(fb);}
	
			//Dice 2 Possibilities

				if (b==7)
     					{dice2num1g(fb);}
        			else if (b==8)
					{dice2num2g(fb);}
        			else if (b==9)
        				{dice2num3g(fb);}
        			else if (b==10)
        				{dice2num4g(fb);}
        			else if (b==11)
        				{dice2num5g(fb);}
        			else if (b==12)
        				{dice2num6g(fb);}

			//Dice 3 Possibilities

				if (c==13)
    					{dice3num1g(fb);}
        			else if (c==14)
        				{dice3num2g(fb);}
        			else if (c==15)
        				{dice3num3g(fb);}
        			else if (c==16)
        				{dice3num4g(fb);}
       				else if (c==17)
        				{dice3num5g(fb);}
        			else if (c==18)
        				{dice3num6g(fb);}
        
			//Dice 4 Possibilities

        			if (d=19)
        				{dice4num1g(fb);}
        			else if (d==20)
        				{dice4num2g(fb);}
        			else if (d==21)
        				{dice4num3g(fb);}
        			else if (d==22)
        				{dice4num4g(fb);}
        			else if (d==23)
        				{dice4num5g(fb);}
        			else if (d==24)
        				{dice4num6g(fb);}
			
				break;

		default:
			//Yellow Options
			clearBitmap(fb->bitmap,0);
			setPixel(fb->bitmap,x,y,yellow());
			//Dice 1 Possibilities

				if (a==1)
					{dice1num1y(fb);}
				else if (a==2)
					{dice1num2y(fb);}
				else if (a==3)
					{dice1num3y(fb);}
				else if (a==4)
					{dice1num4y(fb);}
				else if (a==5)
					{dice1num5y(fb);}
				else if (a==6)
					{dice1num6y(fb);}

			//Dice 2 Possibilities

				if (b==7)
     					{dice2num1y(fb);}
        			else if (b==8)
					{dice2num2y(fb);}
        			else if (b==9)
        				{dice2num3y(fb);}
        			else if (b==10)
        				{dice2num4y(fb);}
        			else if (b==11)
        				{dice2num5y(fb);}
        			else if (b==12)
        				{dice2num6y(fb);}

			//Dice 3 Possibilities

        			if (c==13)
        				{dice3num1y(fb);}
        			else if (c==14)
        				{dice3num2y(fb);}
        			else if (c==15)
        				{dice3num3y(fb);}
        			else if (c==16)
        				{dice3num4y(fb);}
       				else if (c==17)
        				{dice3num5y(fb);}
        			else if (c==18)
        				{dice3num6y(fb);}

			//Dice 4 Possibilities

        			if (d==19)
        				{dice4num1y(fb);}
        			else if (d==20)
        				{dice4num2y(fb);}
        			else if (d==21)
        				{dice4num3y(fb);}
        			else if (d==22)
        				{dice4num4y(fb);}
        			else if (d==23)
        				{dice4num5y(fb);}
        			else if (d==24)
        				{dice4num6y(fb);}

				break;
			}
	}

//Main function for the program. 
int main(){
	srand(time(0));

	int cnt=0;
	pi_i2c_t* device=geti2cDevice();
	coordinate_t data;
	signal(SIGINT, interruptHandler);
	device=geti2cDevice();

	pi_joystick_t* joystick=getJoystickDevice();
	fb=getFBDevice();
	clearBitmap(fb->bitmap,0);

	//Generates a random # for each dice. 
	int a=(rand() %(6+1-1))+1;
	int b=(rand() %(12+1-7))+7;
	int c=(rand() %(18+1-13))+13;
	int d=(rand() %(24+1-19))+19;


//	color=getColor(255,0,0);
//	setPixel(fb->bitmap,0,0,green());
//	setPixel(fb->bitmap,0,0,blue());
//	setPixel(fb->bitmap,0,0,red());
//	setPixel(fb->bitmap,0,0,yellow());
	if (device){
		configureAccelGyro(device);
		while (run){
			usleep(2000);
			while (run && getGyroPosition(device,&data)){
				if (data.x>6){
						pi_framebuffer_t* fb=getFBDevice();	
						clearBitmap(fb->bitmap,0);

						//	while(run){
						//		pollJoystick(joystick,callbackFn,1000);}

						//Dice 1 Possibilities
						int a=(rand() %(6+1-1))+1;
						if (a==1)
							{dice1num1r(fb);}
						else if (a==2)
							{dice1num2r(fb);}
						else if (a==3)
							{dice1num3r(fb);}
						else if (a==4)
							{dice1num4r(fb);}
						else if (a==5)
							{dice1num5r(fb);}
						else if (a==6)
							{dice1num6r(fb);}
		
						//Dice 2 Possibilities
  						int b=(rand() %(12+1-7))+7;
		     				if (b==7)
        						{dice2num1b(fb);}
        					else if (b==8)
							{dice2num2b(fb);}
        					else if (b==9)
        						{dice2num3b(fb);}
        					else if (b==10)
        						{dice2num4b(fb);}
        					else if (b==11)
        						{dice2num5b(fb);}
        					else if (b==12)
        						{dice2num6b(fb);}
		
						//Dice 3 Possibilities
						int c=(rand() %(18+1-13))+13;

        					if (c==13)
        						{dice3num1g(fb);}
        					else if (c==14)
        						{dice3num2g(fb);}
        					else if (c==15)
        						{dice3num3g(fb);}
        					else if (c==16)
        						{dice3num4g(fb);}
       						else if (c==17)
        						{dice3num5g(fb);}
        					else if (c==18)
        						{dice3num6g(fb);}

						//Dice 4 Possibilities
        					int d=(rand() %(24+1-19))+19;

						if (d==19)
    							{dice4num1y(fb);}
        					else if (d==20)
        						{dice4num2y(fb);}
        					else if (d==21)
        						{dice4num3y(fb);}
        					else if (d==22)
        						{dice4num4y(fb);}
        					else if (d==23)
        						{dice4num5y(fb);}
        					else if (d==24)
        						{dice4num6y(fb);}

						cnt=0;
 						printf("Gyro: %f %f %f\n",data.x,data.y,data.z);
					}
				cnt++;		
			}
		}
		printf("\nExiting...\n");
		freeFrameBuffer(fb);
		freei2cDevice(device);
		freeJoystick(joystick);
	}
	return 0;
}

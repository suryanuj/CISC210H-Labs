//Name of file: main.c
//Name of author: Shaun Gupta
//Date: April 20, 2020
//Description of file: In this file is my work for Lab 6. Lab 6 asked us the use the pi to make a binary clock.

#include <stdio.h>
#include <sense/sense.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

//Below are functions that tell me what the colors are. I did this so that I can call the colors in different functions
int red(){return getColor(255,0,0);}
int blank(){return getColor(0,0,0);}
int blue(){return getColor(0,0,255);}
int green(){return getColor(0,255,0);}

//Postion of the Pi: USB Ports Facing Left.

//Declaration of Variables
pi_framebuffer_t* fb;
volatile sig_atomic_t stop;

//inthand will be called when a SIGNUM event occurs (i.e. ctrl-c)
void inthand(int signum) {
    stop = 1;
}

//Hours (in Blue)
void hour0(pi_framebuffer_t* fb){
}

void hour1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,1,blue());
}

void hour2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,1,blue());
}

void hour3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,1,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void hour4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,1,blue());
}

void hour5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void hour7(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour8(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
}

void hour9(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour10(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void hour11(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour12(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,5,1,blue());
}

void hour13(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour14(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void hour15(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,1,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour16(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
}

void hour17(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour18(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void hour19(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour20(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,5,1,blue());
}

void hour21(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

void hour22(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,6,1,blue());
}

void hour23(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,1,blue());
	setPixel(fb->bitmap,5,1,blue());
	setPixel(fb->bitmap,6,1,blue());
	setPixel(fb->bitmap,7,1,blue());
}

//Minutes (in Green)
void min0(pi_framebuffer_t* fb){
}

void min1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,3,green());
}

void min2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,3,green());
}

void min3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,3,green());
}

void min5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min7(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min8(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
}

void min9(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min10(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min11(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min12(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
}

void min13(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min14(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min15(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min16(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
}

void min17(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min18(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min19(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min20(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
}

void min21(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min22(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min23(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min24(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
}

void min25(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min26(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min27(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min28(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
}

void min29(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min30(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min31(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min32(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
}

void min33(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min34(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min35(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min36(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,5,3,green());
}

void min37(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min38(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min39(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min40(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
}

void min41(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min42(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min43(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min44(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
}

void min45(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min46(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min47(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min48(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
}

void min49(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min50(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min51(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min52(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
}

void min53(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min54(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min55(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,5,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min56(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
}

void min57(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,7,3,green());
}

void min58(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
}

void min59(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,3,green());
	setPixel(fb->bitmap,3,3,green());
	setPixel(fb->bitmap,4,3,green());
	setPixel(fb->bitmap,6,3,green());
	setPixel(fb->bitmap,7,3,green());
}

//Seconds (in Red)
void sec0(pi_framebuffer_t* fb){
}

void sec1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,5,red());
}

void sec2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,5,red());
}

void sec3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,5,red());
}

void sec5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec7(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec8(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
}

void sec9(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec10(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec11(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec12(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
}

void sec13(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec14(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec15(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec16(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
}

void sec17(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec18(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec19(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec20(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
}

void sec21(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec22(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec23(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec24(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
}

void sec25(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec26(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec27(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec28(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
}

void sec29(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec30(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec31(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec32(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
}

void sec33(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec34(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec35(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec36(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,5,5,red());
}

void sec37(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec38(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec39(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec40(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
}

void sec41(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec42(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec43(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec44(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
}

void sec45(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec46(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec47(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec48(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
}

void sec49(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec50(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec51(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec52(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
}

void sec53(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec54(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec55(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,5,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec56(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
}

void sec57(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec58(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
}

void sec59(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,6,5,red());
	setPixel(fb->bitmap,7,5,red());
}

void sec60(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,5,red());
	setPixel(fb->bitmap,3,5,red());
	setPixel(fb->bitmap,4,5,red());
	setPixel(fb->bitmap,5,5,red());
}


int main(int argc, char **argv) {
	time_t now;
	struct tm *tm;
	
	signal(SIGINT, inthand);


	pi_framebuffer_t* fb=getFBDevice();
	clearBitmap(fb->bitmap,blank());

   	now = time(0);
 	if ((tm = localtime (&now)) == NULL) {
   		printf ("Error extracting time stuff\n");
	return 1;
    	}

	while(!stop){

	//Hours Display
	if (tm->tm_hour == 0)
		hour0(fb);
	else if (tm->tm_hour == 1)
		hour1(fb);
	else if (tm->tm_hour == 2)
		hour2(fb);
	else if (tm->tm_hour == 3)
		hour3(fb);
	else if (tm->tm_hour == 4)
		hour4(fb);
	else if (tm->tm_hour == 5)
		hour5(fb);
	else if (tm->tm_hour == 6)
		hour6(fb);
	else if (tm->tm_hour == 7)
		hour7(fb);
	else if (tm->tm_hour == 8)
		hour8(fb);
	else if (tm->tm_hour == 9)
		hour9(fb);
	else if (tm->tm_hour == 10)
		hour10(fb);
	else if (tm->tm_hour == 11)
		hour11(fb);
	else if (tm->tm_hour == 12)
		hour12(fb);
	else if (tm->tm_hour == 13)
		hour13(fb);
	else if (tm->tm_hour == 14)
		hour14(fb);
	else if (tm->tm_hour == 15)
		hour15(fb);
	else if (tm->tm_hour == 16)
		hour16(fb);
	else if (tm->tm_hour == 17)
		hour17(fb);
	else if (tm->tm_hour == 18)
		hour18(fb);
	else if (tm->tm_hour == 19)
		hour19(fb);
	else if (tm->tm_hour == 20)
		hour20(fb);
	else if (tm->tm_hour == 21)
		hour21(fb);
	else if (tm->tm_hour == 22)
		hour22(fb);
	else if (tm->tm_hour == 23)
		hour23(fb);

	//Minutes Display
	if (tm->tm_min == 0)
		min0(fb);
	else if (tm->tm_min == 1)
		min1(fb);
	else if (tm->tm_min == 2)
		min2(fb);
	else if (tm->tm_min == 3)
		min3(fb);
	else if (tm->tm_min == 4)
		min4(fb);
	else if (tm->tm_min == 5)
		min5(fb);
	else if (tm->tm_min == 6)
		min6(fb);
	else if (tm->tm_min == 7)
		min7(fb);
	else if (tm->tm_min == 8)
		min8(fb);
	else if (tm->tm_min == 9)
		min9(fb);
	else if (tm->tm_min == 10)
		min10(fb);
	else if (tm->tm_min == 11)
		min11(fb);
	else if (tm->tm_min == 12)
		min12(fb);
	else if (tm->tm_min == 13)
		min13(fb);
	else if (tm->tm_min == 14)
		min14(fb);
	else if (tm->tm_min == 15)
		min15(fb);
	else if (tm->tm_min == 16)
		min16(fb);
	else if (tm->tm_min == 17)
		min17(fb);
	else if (tm->tm_min == 18)
		min18(fb);
	else if (tm->tm_min == 19)
		min19(fb);
	else if (tm->tm_min == 20)
		min20(fb);
	else if (tm->tm_min == 21)
		min21(fb);
	else if (tm->tm_min == 22)
		min22(fb);
	else if (tm->tm_min == 23)
		min23(fb);
	else if (tm->tm_min == 24)
		min24(fb);
	else if (tm->tm_min == 25)
		min25(fb);
	else if (tm->tm_min == 26)
		min26(fb);
	else if (tm->tm_min == 27)
		min27(fb);
	else if (tm->tm_min == 28)
		min28(fb);
	else if (tm->tm_min == 29)
		min29(fb);
	else if (tm->tm_min == 30)
		min30(fb);
	else if (tm->tm_min == 31)
		min31(fb);
	else if (tm->tm_min == 32)
		min32(fb);
	else if (tm->tm_min == 33)
		min33(fb);
	else if (tm->tm_min == 34)
		min34(fb);
	else if (tm->tm_min == 35)
		min35(fb);
	else if (tm->tm_min == 36)
		min36(fb);
	else if (tm->tm_min == 37)
		min37(fb);
	else if (tm->tm_min == 38)
		min38(fb);
	else if (tm->tm_min == 39)
		min39(fb);
	else if (tm->tm_min == 40)
		min40(fb);
	else if (tm->tm_min == 41)
		min41(fb);
	else if (tm->tm_min == 42)
		min42(fb);
	else if (tm->tm_min == 43)
		min43(fb);
	else if (tm->tm_min == 44)
		min44(fb);
	else if (tm->tm_min == 45)
		min45(fb);
	else if (tm->tm_min == 46)
		min46(fb);
	else if (tm->tm_min == 47)
		min47(fb);
	else if (tm->tm_min == 48)
		min48(fb);
	else if (tm->tm_min == 49)
		min49(fb);
	else if (tm->tm_min == 50)
		min50(fb);
	else if (tm->tm_min == 51)
		min51(fb);
	else if (tm->tm_min == 52)
		min52(fb);
	else if (tm->tm_min == 53)
		min53(fb);
	else if (tm->tm_min == 54)
		min54(fb);
	else if (tm->tm_min == 55)
		min55(fb);
	else if (tm->tm_min == 56)
		min56(fb);
	else if (tm->tm_min == 57)
		min57(fb);
	else if (tm->tm_min == 58)
		min58(fb);
	else if (tm->tm_min == 59)
		min59(fb);

	//Seconds Display
	if (tm->tm_sec == 0)
		sec0(fb);
	else if (tm->tm_sec == 1)
		sec1(fb);
	else if (tm->tm_sec == 2)
		sec2(fb);
	else if (tm->tm_sec == 3)
		sec3(fb);
	else if (tm->tm_sec == 4)
		sec4(fb);
	else if (tm->tm_sec == 5)
		sec5(fb);
	else if (tm->tm_sec == 6)
		sec6(fb);
	else if (tm->tm_sec == 7)
		sec7(fb);
	else if (tm->tm_sec == 8)
		sec8(fb);
	else if (tm->tm_sec == 9)
		sec9(fb);
	else if (tm->tm_sec == 10)
		sec10(fb);
	else if (tm->tm_sec == 11)
		sec11(fb);
	else if (tm->tm_sec == 12)
		sec12(fb);
	else if (tm->tm_sec == 13)
		sec13(fb);
	else if (tm->tm_sec == 14)
		sec14(fb);
	else if (tm->tm_sec == 15)
		sec15(fb);
	else if (tm->tm_sec == 16)
		sec16(fb);
	else if (tm->tm_sec == 17)
		sec17(fb);
	else if (tm->tm_sec == 18)
		sec18(fb);
	else if (tm->tm_sec == 19)
		sec19(fb);
	else if (tm->tm_sec == 20)
		sec20(fb);
	else if (tm->tm_sec == 21)
		sec21(fb);
	else if (tm->tm_sec == 22)
		sec22(fb);
	else if (tm->tm_sec == 23)
		sec23(fb);
	else if (tm->tm_sec == 24)
		sec24(fb);
	else if (tm->tm_sec == 25)
		sec25(fb);
	else if (tm->tm_sec == 26)
		sec26(fb);
	else if (tm->tm_sec == 27)
		sec27(fb);
	else if (tm->tm_sec == 28)
		sec28(fb);
	else if (tm->tm_sec == 29)
		sec29(fb);
	else if (tm->tm_sec == 30)
		sec30(fb);
	else if (tm->tm_sec == 31)
		sec31(fb);
	else if (tm->tm_sec == 32)
		sec32(fb);
	else if (tm->tm_sec == 33)
		sec33(fb);
	else if (tm->tm_sec == 34)
		sec34(fb);
	else if (tm->tm_sec == 35)
		sec35(fb);
	else if (tm->tm_sec == 36)
		sec36(fb);
	else if (tm->tm_sec == 37)
		sec37(fb);
	else if (tm->tm_sec == 38)
		sec38(fb);
	else if (tm->tm_sec == 39)
		sec39(fb);
	else if (tm->tm_sec == 40)
		sec40(fb);
	else if (tm->tm_sec == 41)
		sec41(fb);
	else if (tm->tm_sec == 42)
		sec42(fb);
	else if (tm->tm_sec == 43)
		sec43(fb);
	else if (tm->tm_sec == 44)
		sec44(fb);
	else if (tm->tm_sec == 45)
		sec45(fb);
	else if (tm->tm_sec == 46)
		sec46(fb);
	else if (tm->tm_sec == 47)
		sec47(fb);
	else if (tm->tm_sec == 48)
		sec48(fb);
	else if (tm->tm_sec == 49)
		sec49(fb);
	else if (tm->tm_sec == 50)
		sec50(fb);
	else if (tm->tm_sec == 51)
		sec51(fb);
	else if (tm->tm_sec == 52)
		sec52(fb);
	else if (tm->tm_sec == 53)
		sec53(fb);
	else if (tm->tm_sec == 54)
		sec54(fb);
	else if (tm->tm_sec == 55)
		sec55(fb);
	else if (tm->tm_sec == 56)
		sec56(fb);
	else if (tm->tm_sec == 57)
		sec57(fb);
	else if (tm->tm_sec == 58)
		sec58(fb);
	else if (tm->tm_sec == 59)
		sec59(fb);

	printf("Current Time: %02d:%02d:%02d\n",tm->tm_hour, tm->tm_min, tm->tm_sec);

	sleep(1);

	time_t now;
	struct tm *tm;

	pi_framebuffer_t* fb=getFBDevice();
	clearBitmap(fb->bitmap,blank());

   	now = time(0);
 	if ((tm = localtime (&now)) == NULL) {
   		printf ("Error extracting time stuff\n");
	return 1;
    		}

	}
	freeFrameBuffer(fb);
	return (0);
}

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

//Postion of the Pi: USB Ports Facing Left.

//Below are functions that tell me what the colors are. I did this so that I can call the colors in different functions
int red(){return getColor(255,0,0);}
int blank(){return getColor(0,0,0);}
int blue(){return getColor(0,0,255);}
int green(){return getColor(0,255,0);}

//Declaration of Variables
int x, color;
pi_framebuffer_t* fb;
volatile sig_atomic_t stop;

//inthand will be called when a SIGNUM event occurs (i.e. ctrl-c)
void inthand(int signum) {
    stop = 1;
}

//Functions for the 60 different numbers, in Binary
void num0(pi_framebuffer_t* fb){
}

void num1(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,x,color);
}

void num2(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,6,x,color);
}

void num3(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,7,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num4(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,x,color);
}

void num5(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num6(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num7(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num8(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
}

void num9(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num10(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num11(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num12(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
}

void num13(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num14(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num15(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num16(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
}

void num17(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num18(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num19(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num20(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
}

void num21(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num22(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num23(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num24(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
}

void num25(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num26(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num27(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num28(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
}

void num29(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num30(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num31(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num32(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
}

void num33(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num34(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num35(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num36(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,5,x,color);
}

void num37(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num38(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num39(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num40(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
}

void num41(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num42(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num43(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num44(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
}

void num45(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num46(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num47(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num48(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
}

void num49(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num50(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num51(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num52(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
}

void num53(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num54(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num55(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,5,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num56(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
}

void num57(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,7,x,color);
}

void num58(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
}

void num59(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,2,x,color);
	setPixel(fb->bitmap,3,x,color);
	setPixel(fb->bitmap,4,x,color);
	setPixel(fb->bitmap,6,x,color);
	setPixel(fb->bitmap,7,x,color);
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
	x=1;
	color=blue();
	//Hours Display (in Blue)
	if (tm->tm_hour == 0)
		num0(fb);
	else if (tm->tm_hour == 1)
		num1(fb);
	else if (tm->tm_hour == 2)
		num2(fb);
	else if (tm->tm_hour == 3)
		num3(fb);
	else if (tm->tm_hour == 4)
		num4(fb);
	else if (tm->tm_hour == 5)
		num5(fb);
	else if (tm->tm_hour == 6)
		num6(fb);
	else if (tm->tm_hour == 7)
		num7(fb);
	else if (tm->tm_hour == 8)
		num8(fb);
	else if (tm->tm_hour == 9)
		num9(fb);
	else if (tm->tm_hour == 10)
		num10(fb);
	else if (tm->tm_hour == 11)
		num11(fb);
	else if (tm->tm_hour == 12)
		num12(fb);
	else if (tm->tm_hour == 13)
		num13(fb);
	else if (tm->tm_hour == 14)
		num14(fb);
	else if (tm->tm_hour == 15)
		num15(fb);
	else if (tm->tm_hour == 16)
		num16(fb);
	else if (tm->tm_hour == 17)
		num17(fb);
	else if (tm->tm_hour == 18)
		num18(fb);
	else if (tm->tm_hour == 19)
		num19(fb);
	else if (tm->tm_hour == 20)
		num20(fb);
	else if (tm->tm_hour == 21)
		num21(fb);
	else if (tm->tm_hour == 22)
		num22(fb);
	else if (tm->tm_hour == 23)
		num23(fb);

	x=3;
	color=green();
	//Minutes Display (in Green)
	if (tm->tm_min == 0)
		num0(fb);
	else if (tm->tm_min == 1)
		num1(fb);
	else if (tm->tm_min == 2)
		num2(fb);
	else if (tm->tm_min == 3)
		num3(fb);
	else if (tm->tm_min == 4)
		num4(fb);
	else if (tm->tm_min == 5)
		num5(fb);
	else if (tm->tm_min == 6)
		num6(fb);
	else if (tm->tm_min == 7)
		num7(fb);
	else if (tm->tm_min == 8)
		num8(fb);
	else if (tm->tm_min == 9)
		num9(fb);
	else if (tm->tm_min == 10)
		num10(fb);
	else if (tm->tm_min == 11)
		num11(fb);
	else if (tm->tm_min == 12)
		num12(fb);
	else if (tm->tm_min == 13)
		num13(fb);
	else if (tm->tm_min == 14)
		num14(fb);
	else if (tm->tm_min == 15)
		num15(fb);
	else if (tm->tm_min == 16)
		num16(fb);
	else if (tm->tm_min == 17)
		num17(fb);
	else if (tm->tm_min == 18)
		num18(fb);
	else if (tm->tm_min == 19)
		num19(fb);
	else if (tm->tm_min == 20)
		num20(fb);
	else if (tm->tm_min == 21)
		num21(fb);
	else if (tm->tm_min == 22)
		num22(fb);
	else if (tm->tm_min == 23)
		num23(fb);
	else if (tm->tm_min == 24)
		num24(fb);
	else if (tm->tm_min == 25)
		num25(fb);
	else if (tm->tm_min == 26)
		num26(fb);
	else if (tm->tm_min == 27)
		num27(fb);
	else if (tm->tm_min == 28)
		num28(fb);
	else if (tm->tm_min == 29)
		num29(fb);
	else if (tm->tm_min == 30)
		num30(fb);
	else if (tm->tm_min == 31)
		num31(fb);
	else if (tm->tm_min == 32)
		num32(fb);
	else if (tm->tm_min == 33)
		num33(fb);
	else if (tm->tm_min == 34)
		num34(fb);
	else if (tm->tm_min == 35)
		num35(fb);
	else if (tm->tm_min == 36)
		num36(fb);
	else if (tm->tm_min == 37)
		num37(fb);
	else if (tm->tm_min == 38)
		num38(fb);
	else if (tm->tm_min == 39)
		num39(fb);
	else if (tm->tm_min == 40)
		num40(fb);
	else if (tm->tm_min == 41)
		num41(fb);
	else if (tm->tm_min == 42)
		num42(fb);
	else if (tm->tm_min == 43)
		num43(fb);
	else if (tm->tm_min == 44)
		num44(fb);
	else if (tm->tm_min == 45)
		num45(fb);
	else if (tm->tm_min == 46)
		num46(fb);
	else if (tm->tm_min == 47)
		num47(fb);
	else if (tm->tm_min == 48)
		num48(fb);
	else if (tm->tm_min == 49)
		num49(fb);
	else if (tm->tm_min == 50)
		num50(fb);
	else if (tm->tm_min == 51)
		num51(fb);
	else if (tm->tm_min == 52)
		num52(fb);
	else if (tm->tm_min == 53)
		num53(fb);
	else if (tm->tm_min == 54)
		num54(fb);
	else if (tm->tm_min == 55)
		num55(fb);
	else if (tm->tm_min == 56)
		num56(fb);
	else if (tm->tm_min == 57)
		num57(fb);
	else if (tm->tm_min == 58)
		num58(fb);
	else if (tm->tm_min == 59)
		num59(fb);

	x=5;
	color=red();
	//Seconds Display (in Red)
	if (tm->tm_sec == 0)
		num0(fb);
	else if (tm->tm_sec == 1)
		num1(fb);
	else if (tm->tm_sec == 2)
		num2(fb);
	else if (tm->tm_sec == 3)
		num3(fb);
	else if (tm->tm_sec == 4)
		num4(fb);
	else if (tm->tm_sec == 5)
		num5(fb);
	else if (tm->tm_sec == 6)
		num6(fb);
	else if (tm->tm_sec == 7)
		num7(fb);
	else if (tm->tm_sec == 8)
		num8(fb);
	else if (tm->tm_sec == 9)
		num9(fb);
	else if (tm->tm_sec == 10)
		num10(fb);
	else if (tm->tm_sec == 11)
		num11(fb);
	else if (tm->tm_sec == 12)
		num12(fb);
	else if (tm->tm_sec == 13)
		num13(fb);
	else if (tm->tm_sec == 14)
		num14(fb);
	else if (tm->tm_sec == 15)
		num15(fb);
	else if (tm->tm_sec == 16)
		num16(fb);
	else if (tm->tm_sec == 17)
		num17(fb);
	else if (tm->tm_sec == 18)
		num18(fb);
	else if (tm->tm_sec == 19)
		num19(fb);
	else if (tm->tm_sec == 20)
		num20(fb);
	else if (tm->tm_sec == 21)
		num21(fb);
	else if (tm->tm_sec == 22)
		num22(fb);
	else if (tm->tm_sec == 23)
		num23(fb);
	else if (tm->tm_sec == 24)
		num24(fb);
	else if (tm->tm_sec == 25)
		num25(fb);
	else if (tm->tm_sec == 26)
		num26(fb);
	else if (tm->tm_sec == 27)
		num27(fb);
	else if (tm->tm_sec == 28)
		num28(fb);
	else if (tm->tm_sec == 29)
		num29(fb);
	else if (tm->tm_sec == 30)
		num30(fb);
	else if (tm->tm_sec == 31)
		num31(fb);
	else if (tm->tm_sec == 32)
		num32(fb);
	else if (tm->tm_sec == 33)
		num33(fb);
	else if (tm->tm_sec == 34)
		num34(fb);
	else if (tm->tm_sec == 35)
		num35(fb);
	else if (tm->tm_sec == 36)
		num36(fb);
	else if (tm->tm_sec == 37)
		num37(fb);
	else if (tm->tm_sec == 38)
		num38(fb);
	else if (tm->tm_sec == 39)
		num39(fb);
	else if (tm->tm_sec == 40)
		num40(fb);
	else if (tm->tm_sec == 41)
		num41(fb);
	else if (tm->tm_sec == 42)
		num42(fb);
	else if (tm->tm_sec == 43)
		num43(fb);
	else if (tm->tm_sec == 44)
		num44(fb);
	else if (tm->tm_sec == 45)
		num45(fb);
	else if (tm->tm_sec == 46)
		num46(fb);
	else if (tm->tm_sec == 47)
		num47(fb);
	else if (tm->tm_sec == 48)
		num48(fb);
	else if (tm->tm_sec == 49)
		num49(fb);
	else if (tm->tm_sec == 50)
		num50(fb);
	else if (tm->tm_sec == 51)
		num51(fb);
	else if (tm->tm_sec == 52)
		num52(fb);
	else if (tm->tm_sec == 53)
		num53(fb);
	else if (tm->tm_sec == 54)
		num54(fb);
	else if (tm->tm_sec == 55)
		num55(fb);
	else if (tm->tm_sec == 56)
		num56(fb);
	else if (tm->tm_sec == 57)
		num57(fb);
	else if (tm->tm_sec == 58)
		num58(fb);
	else if (tm->tm_sec == 59)
		num59(fb);

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

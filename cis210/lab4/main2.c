/* Name of the file: main2.c
 * Name: Suryanuj Gupta
 * Date: 04/01/20
 * Description of the file: This file contains the work for Lab 4, Part 1. 
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sense/sense.h>
#define MAX_STRING 1024
/*Below is the main function used to do Part 1 of this lab. */
int main(){
	/*Below are the definitions of the different variables in the function, 
	four integers that represent colors and 1 character string that represents the color the user inputs*/
	int red=getColor(255,0,0);
	int green=getColor(0,255,0);
	int blue=getColor(0,0,255);
	int blank=getColor(0,0,0);
	char colorofx[MAX_STRING];
	/*Below asks the user what color they want to be shown on the raspberry pi*/
	printf("What color do you want to make the X (Red, Green, or Blue)? \n");
	scanf("%s", colorofx);
	/*Below is code that, depending on what the user inputted, will change the color of the X on the pi. If they 
	inputted red, then the x on the pi will be red. If they inputted green, then the x on the pi will be green. If 
	they inputted blue, then the x on the pi will be blue. If the user inputted a color that is not one of those three colors,
	then the x on the pi will be blank and it asks the user to try again.*/
	if (strcmp(colorofx,"red") == 0 || strcmp(colorofx, "Red")==0)
	{
		pi_framebuffer_t* fb=getFBDevice();
		clearBitmap(fb->bitmap,blank);
		for (int i=0;i<8;i++){
			setPixel(fb->bitmap,i,i,red);
			setPixel(fb->bitmap,i,7-i,red);
			}
		freeFrameBuffer(fb);
	}
	else
	{	if (strcmp(colorofx,"blue")==0 || strcmp(colorofx, "Blue")==0)
		{
			pi_framebuffer_t* fb=getFBDevice();
			clearBitmap(fb->bitmap,blank);
			for (int i=0;i<8;i++){
				setPixel(fb->bitmap,i,i,blue);
				setPixel(fb->bitmap,i,7-i,blue);
				}
			freeFrameBuffer(fb);
		}

		else{
			if (strcmp(colorofx, "green")==0 || strcmp(colorofx, "Green")==0)
			{
				pi_framebuffer_t* fb=getFBDevice();
				clearBitmap(fb->bitmap,blank);
				for (int i=0;i<8;i++){
					setPixel(fb->bitmap,i,i,green);
					setPixel(fb->bitmap,i,7-i,green);
					}
				freeFrameBuffer(fb);
			}

			else
			{
			printf("You enetered an invalid color. %s does not exist here. Please try again. \n", colorofx);
			
			pi_framebuffer_t* fb=getFBDevice();
			clearBitmap(fb->bitmap,blank);
			freeFrameBuffer(fb);
			
			}
		}
	}
}

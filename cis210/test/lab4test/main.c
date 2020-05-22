/* Name of the file: main3.c
 * Name: Suryanuj Gupta
 * Date: 04/01/20
 * Description of the file: This file contains the work for Lab 4, Part2. 
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sense/sense.h>
#define MAX_STRING 1024
/*Below is the main function used to do Part 2 of this lab. */

//Declaration of Variables
int x;
pi_framebuffer_t* fb;

//Function that will Draw the Initials
void initials(pi_framebuffer_t* fb){
	setPixel(fb->bitmap,1,0,x);
	setPixel(fb->bitmap,1,1,x);
	setPixel(fb->bitmap,1,2,x);
	setPixel(fb->bitmap,2,2,x);
	setPixel(fb->bitmap,3,2,x);
	setPixel(fb->bitmap,3,1,x);
	setPixel(fb->bitmap,3,0,x);
	setPixel(fb->bitmap,4,0,x);
	setPixel(fb->bitmap,5,0,x);
	setPixel(fb->bitmap,5,1,x);
	setPixel(fb->bitmap,5,2,x);
	/*Below is to make the "G"*/
	setPixel(fb->bitmap,1,4,x);
	setPixel(fb->bitmap,1,5,x);
	setPixel(fb->bitmap,1,6,x);
	setPixel(fb->bitmap,1,7,x);
	setPixel(fb->bitmap,2,7,x);
	setPixel(fb->bitmap,3,7,x);
	setPixel(fb->bitmap,3,6,x);
	setPixel(fb->bitmap,2,4,x);
	setPixel(fb->bitmap,3,4,x);
	setPixel(fb->bitmap,4,4,x);
	setPixel(fb->bitmap,5,4,x);
	setPixel(fb->bitmap,5,5,x);
	setPixel(fb->bitmap,5,6,x);
	setPixel(fb->bitmap,5,7,x);
}

int main(){
	/*Below are the definitions of the different variables in the function, 
	four integers that represent colors and 1 character string that represents the color the user inputs*/
	int red=getColor(255,0,0);
	int green=getColor(0,255,0);
	int blue=getColor(0,0,255);
	int blank=getColor(0,0,0);
	char colorofx[MAX_STRING];
	pi_framebuffer_t* fb=getFBDevice();
	/*Below asks the user what color they want to be shown on the raspberry pi*/
	printf("What color do you want to make the initials (Red, Green, or Blue)? \n");
	scanf("%s", colorofx);
	/*Below is code that, depending on what the user inputted, will change the color of the X on the pi. If they 
	inputted red, then the initials (the letter S and the letter G) on the pi will be red. If they inputted green, then the initials (the letter S 
	and the letter G) on the pi will be green. If they inputted blue, then the initials (the letter S and the letter G) will be blue. If the user 
	inputted a color that is not one of those three colors, then the initials (the letter S and the letter G) will be blank and it asks the user to try again.*/
	if (strcmp(colorofx,"red") == 0 || strcmp(colorofx, "Red")==0)
	{
		clearBitmap(fb->bitmap,blank);
		x=red;
		initials(fb);
		freeFrameBuffer(fb);
	}

	else
	{	if (strcmp(colorofx,"blue")==0 || strcmp(colorofx, "Blue")==0)
		{
			clearBitmap(fb->bitmap,blank);
			x=blue;
			initials(fb);
			freeFrameBuffer(fb);
		}

		else {
			if (strcmp(colorofx, "green")==0 || strcmp(colorofx, "Green")==0)
			{
				clearBitmap(fb->bitmap,blank);
				x=green;
				initials(fb);				
				freeFrameBuffer(fb);
			}

			else
			{
			printf("You entered an invalid color. %s does not exist here. Please try again. \n", colorofx);
		
			pi_framebuffer_t* fb=getFBDevice();
			clearBitmap(fb->bitmap,blank);
			freeFrameBuffer(fb);
			}
		}
	}
}

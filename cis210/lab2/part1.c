/* Name of the file: Part1.c
 * Name: Suryanuj Gupta
 * Date: 03/02/20
 * Description of the file: This file contains the work for Lab 2, part 1.
 * */
#include <stdio.h>
int main(void)
{
	int value;
	 printf("Enter a integer: \n");
         scanf("%d",&value);
	 if (value % 2 ==0)
		printf("%d is an even number.",value);
	 else
		 printf("%d is an odd number.", value);
	return 0;					
}

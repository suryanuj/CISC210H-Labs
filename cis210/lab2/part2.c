/* Name of the file: Part2.c
 * Name: Suryanuj Gupta
 * Date: 03/02/20
 * Description of the file: This file contains the work for Lab 2, part 2.
 * */ 
#include <stdio.h>
int main(void)
{
        int value, i, flag = 0;
        printf("Enter a positive integer: \n");
        scanf("%d", &value);

	if (value % 2 == 0)
	{
		printf("%d is not prime number, since it is even.", value);
		return 0;
	}
	else 
	{	
        	for (i = 2; i <= value/2; ++i)
		{
			if (value % i == 0)
			{
				flag = 1;
			}
		}
		
		if (value == 1)
		{
			printf("%d is not a prime number.", value);
		}
		else
		{
			if (flag == 0)
			{
				printf("%d is a prime number.", value);
				return 0;
			}
			
			else
			{
				printf("%d is not a prime number.", value);
				return 0;
			}
				
		}	
		
	
        return 0;
	}
}

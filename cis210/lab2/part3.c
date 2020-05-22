/* Name of the file: Part3.c
 * Name: Suryanuj Gupta
 * Date: 03/02/20
 * Description of the file: This file contains the work for Lab 2, part 3. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING 1024
int main(void)
{
	char fname[MAX_STRING];
        char lname[MAX_STRING];
	char fullname[MAX_STRING];
	
	printf("What is your first name? \n");
        scanf("%s",fname);

	if (strcmp(fname, "quit") == 0 || strcmp(fname, "Quit") == 0 || strcmp(fname, "QUIT") == 0) 
	{	
	       	printf("Goodbye! \n");
		return 0;	
	}
	
	else
	{
		printf("What is your last name? \n");
		scanf("%s",lname);
	}
		if (strcmp(lname, "quit") == 0 || strcmp(lname, "Quit") == 0 || strcmp(lname, "QUIT") == 0)
		{
			printf("Goodbye! \n");
			return 0;
		}
		
		else
		{
			strcpy(fullname,fname);
			strcat(fullname, " ");
			strcat(fullname,lname);
			strcat(fullname, "!");

			printf("Hello, %s\n", fullname);

			return 0;
		}
}

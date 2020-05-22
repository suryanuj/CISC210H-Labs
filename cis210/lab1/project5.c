# include <stdio.h>
int
	main(void)
	{
		int entries;
		float sum=0, integers, value,average;
		printf("Please enter the number of entries: \n");
		scanf("%d", &entries);
		value=entries;

			while (entries--)
				{
					printf("Enter a integer: \n");
					scanf("%f",&integers);
					sum=sum+integers;
				}
		printf("The sum of these numbers is: %.2f\n", sum);
		average=sum/value;
		printf("Their average is: %.2f ",average);
		return 0;
	}
	
int
	GetOneNumber(int x)
	{	
		int	integer1;
		printf("Enter integer #?");
		scanf("%d",&integer1); 
		return 0;
	}	

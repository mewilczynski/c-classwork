//Marta Wilczynski
//This program uses arrays of 0s and 1s to hold values and calculates the difference between the two
//arrays.

#include <stdio.h>

int main()
{	
	//declare variables and arrays
	int numA = 0;
	int numB = 0;
	int i = 0;
	int a[10] = {0};
	int b[10] = {0};

	//prompt user for input for arrays
	printf("Please enter the number of elements in set A:\n");
	scanf("%d", &numA);

	//use for loop to populate array a
	printf("Enter the numbers in set A:\n");
	for(i = 0; i < numA; i++)
	{
		int temp;
		scanf("%d", &temp);
		a[temp] = 1;
	}

	printf("Please enter the number of elements in set B:\n");
	scanf("%d", &numB);

	//use for loop to populate array b
	printf("Enter the numbers in set B:\n");
	for(i = 0; i < numB; i++)
	{
		int temp;
		scanf("%d", &temp);
		b[temp] = 1;
	}
	
	//use a for loop to determine the difference between arrays a and b (which values array a contains that array b does not)
	for(i = 0; i < 10; i++)
	{
		if (a[i] == 1 && b[i] == 0)
		{
			printf("%d\t", i);
		}
	}

	//print new line for appearance
	printf("\n");	

	//output complement to array a
	for(i = 0; i < 10; i++)
	{
		if(a[i] == 0)
			printf("%d\t", i);
	}

	//print new line for appearance
	printf("\n");

	//output complement to array b
	for(i = 0; i < 10; i++)
	{
		if(b[i] == 0)
			printf("%d\t", i);
	}

	//print new line for appearance
	printf("\n");

	return 0;
}

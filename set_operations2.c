//Marta Wilczynski
//This program uses arrays of 0s and 1s to hold values and calculates the difference between the two
//arrays.

#include <stdio.h>
#define N 10

void set_difference(int *a, int *b, int n, int *difference);

void set_complement(int *a, int n, int *complement);

int main()
{	
	//declare variables and arrays
	int numA = 0;
	int numB = 0;
	int i = 0;
	int a[10] = {0};
	int b[10] = {0};
	int diff[10] = {0};
	int compA[10]= {0};
	int compB[10] = {0};

	//prompt user for input for array a
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
	
	//prompt user for array b
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
	
	//call the difference function
	set_difference(a, b, N, diff);

	//use a for loop to output the difference function
	printf("The difference is: ");
	for(i = 0; i < N; i++)
	{
		if (diff[i] == 1) 	
			printf(" %d", i);
	}

	//print new line for appearance
	printf("\n");	

	//call the complement function
	set_complement(a, N, compA);

	//output results of complement
	printf("The complement of A is: ");
	for( i = 0; i < N; i++)
	{
		if(compA[i] == 1)
			printf(" %d", i);
	}

	//print new line for appearance
	printf("\n");	

	//call the complement function
	set_complement(b, N, compB);

	//output results of complement
	printf("The complement of B is: ");

	for( i = 0; i < N; i++)
	{
		if(compB[i] == 1)
			printf(" %d", i);
	}

	return 0;
}

//define function to calculate the difference between b and a
void set_difference(int *a, int *b, int n, int *difference)
{
	int *p, *q; //declare pointers to pass the values of arrays a and b for calculations and comparisons.
	for(p = a, q = b; p < (a + n); p++, q++)
	{
		if (*p == 1 && *q == 0)
			*difference = 1;
			*difference++;
	}

}

//define function to calculate the complement for both b and a
void set_complement(int *a, int n, int *complement)
{
	int *p;
	for(p = a; p < (a + n); p++)
	{
		if (*p == 0)
			*complement++ = 1;
			*complement++;
	}	
}



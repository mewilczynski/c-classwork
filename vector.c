//Marta Wilczynski
//This program computes vector multiplication between two vectors and compares the two vectors.

#include <stdio.h>

void multi_vec(int *v1, int *v2, int *v3, int n);

int comp_vec(int *v1, int *v2, int n);

int main()
{
	//declare variables and arrays
	int l = 0;
	int i;
	int determinant = 0;

	//prompt user for input
	printf("Please enter the length of the vectors:\n");
	scanf("%d", &l);

	//declare arrays with length
	int vector1[l];
	int vector2[l];
	int multi_vector[l];

	//populate vector 1
	printf("Please enter the first vector:\n");
	for(i = 0; i < l; i++)
	{
		scanf("  %d", &vector1[i]);
	}

	//populate vector 2
	printf("Please enter the second vector:\n");
	for(i = 0; i < l; i++)
	{
		scanf("  %d", &vector2[i]);
	}

	//call function for multi_vec
	multi_vec(vector1, vector2, multi_vector, l);

	//call the function to compare the vectors
	determinant = comp_vec(vector1, vector2, l);

	//print new line for appearance
	printf("\n");

	//Determine what to output based on determinant
	if(determinant == 1)
		printf("The vectors are the same.\n");
	else
		printf("The vectors are not the same.\n");

	return 0;
}

//define function to calculate the multiplication for each number for between the first vector and second vector
void multi_vec(int *v1, int *v2, int *v3, int n)
{
	int *a, *b; //declare pointers to hold values for the two vectors
	int product = 0; //temporary variable to hold the value for the third vector
	for(a = v1, b = v2 ; a < v1 + n; a++, b++)
	{
		product = *a * *b;
		*v3 = product;
		
		//output the product
		printf("  %d", *v3);
		v3++;
	}

}

//define function to compare values between the two vectors
int comp_vec(int *v1, int *v2, int n)
{
	int *a, *b; //declare pointers to hold the values of both vectors
	int determinant = 0; //declare variable to hold the value that tells us whether the vectors are the same (=1) or not (=0)
	for(a = v1, b=v2; a < v1 + n; b++, a++)
	{
		if (*a != *b)
		{
			determinant = 0;
			break;
		}
		else{
			determinant = 1;
		}
	}
	return determinant;
}

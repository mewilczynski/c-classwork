//Marta Wilczynski
// This program uses command line arguments to calculate the median between 10 numbers and the average
// of those numbers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 10.0

void selection_sort(int a[], int n);

int main(int argc, char *argv[])
{
	//check command line arguments
	if (argc != 12)
	{
		printf("Usage: ./a.out -option (a or m) followed by ten numbers.\n");
		return 1; //do not allow program to continue if the arguments are not matched
	}

	//declare variables and arrays
	int i = 0; // used to index the for loop to read the arguments
	int c = 0; // used as an index to begin populating the arrays
	int med_numbers[10]; //declare array for the numbers for the median
	double av_numbers[10]; //declare array as double for the average calculation
	
	//convert command line arguments
	for (i = 2, c = 0; i < 12; i++, c++)
	{
		med_numbers[c] = atoi(argv[i]); //read numbers into both of our arrays
		av_numbers[c] = atof(argv[i]);
	}

	//calculate median
	if (strcmp(argv[1], "-m") == 0)
	{
		selection_sort(med_numbers, N);
		int median;
		median = med_numbers[N/2];
		printf("%d", median);
	}
	//calculate average
	else if (strcmp(argv[1], "-a") == 0)
	{
		double sum = 0;
		for(i = 0; i < 10; i++)
		{	
			sum += av_numbers[i];
		}
		double  average;
		average = sum / M;
		printf("%.1f", average);
	}
	else{ //if argv[1] is not one of the options (-a or -m), output a statement saying such
		printf("invalid option\n");
	}
}

//define selection_sort function, given to us
void selection_sort(int a[], int n)
{
	 int i, largest = 0, temp;

	if (n == 1)
		return;

	for (i = 1; i < n; i++)
	{
		if (a[i] > a[largest])
			largest = i;
	}

	if (largest < n - 1) 
	{
		temp = a[n-1];
		a[n-1] = a[largest];
		a[largest] = temp;
	} 
	selection_sort(a, n - 1);
}

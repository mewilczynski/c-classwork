//Marta Wilczynski
//This program converts the currency from Harry Potter by taking an amount
// of knuts from the user and converting it to sickles and galleons

#include <stdio.h>
#define SICKLES 29
#define GALLEONS 17

//define function that converts the inputted knuts to sickles and galleons
void convert(int total_knuts, int *galleons, int *sickles, int *knuts)
{
	*sickles = total_knuts / SICKLES;
	*knuts = total_knuts % SICKLES;
	*galleons = *sickles / GALLEONS;
	*sickles = *sickles % GALLEONS;	
}

int main()
{
	//define variables
	int numOfKnuts = 0, numOfSickles = 0, numOfGalleons = 0;

	//Prompt user for input
	printf("Enter number of knuts:\n");
	scanf("%d",& numOfKnuts);

	//Check input value and output
	if(numOfKnuts >= 0 && numOfKnuts <= 1000000000)
	{	
		//call function
		convert(numOfKnuts, &numOfGalleons, &numOfSickles, &numOfKnuts);
		printf("Number of Sickles: %d\n", numOfSickles);
		printf("Number of Galleons: %d\n", numOfGalleons);
		printf("Number of Knuts: %d\n", numOfKnuts);
	}
	else {
		printf("Invalid input of %d\n", numOfKnuts);
		printf("Enter a value between 0 and 1000000000, inclusive");
	}
	return 0;	 
}

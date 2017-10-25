//Marta Wilczynski
//This program converts the currency from Harry Potter by taking an amount
// of knuts from the user and converting it to sickles and galleons

#include <stdio.h>

int main()
{
	//define constants and variables
	#define SICKLES 29
	#define GALLEONS 17
	int numOfKnuts = 0, numOfSickles = 0, numOfGalleons = 0;
	int remainderKnuts = 0, remainderSickles = 0;

	//Prompt user for input
	printf("Enter number of knuts:\n");
	scanf("%d",& numOfKnuts);

	//Check input value and calculate output
	if(numOfKnuts >= 0 && numOfKnuts <= 1000000000)
	{
		numOfSickles = numOfKnuts / SICKLES;
		remainderKnuts = numOfKnuts % SICKLES;
		numOfGalleons = numOfSickles / GALLEONS;
		remainderSickles = numOfSickles %  GALLEONS;
		
		printf("Number of Sickles: %d\n", remainderSickles);
		printf("Number of Galleons: %d\n", numOfGalleons);
		printf("Number of Knuts: %d\n", remainderKnuts);
	}
	else {
		printf("Invalid input of %d\n", numOfKnuts);
		printf("Enter a value between 0 and 1000000000, inclusive");
	}
	return 0;	 
}

//Marta Wilczynski
//This program calculates the voltage of a capacitor from 1 to 0 seconds within a circuit and displays the results.

#include <stdio.h>
#include <math.h>

int main()
{
	//define variables and constants
	double time = 0.0;
	double voltage = 0.0;
	double i = 0.0;
	double x = 0.0;
	#define VOLTAGE 10.0
	#define TIME_CONSTANT 0.15

	//begin the labels for the output columns
	printf("time(sec)\t");
	printf("voltage\n");

	//define the for loop
	for(i = 0; i <= 15; i++)
	{
		x = -1.0 * (time/TIME_CONSTANT);
		voltage = (VOLTAGE * (1.0 - exp(x)));
		time = time + (1.0/15.0);
		printf("%.2f \t\t", time);
		printf("%.2f \n", voltage);
	}

	return 0;
}

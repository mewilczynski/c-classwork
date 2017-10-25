//Marta Wilczynski
//This program determines when work assigned by a teacher is due and has it 
//assigned to be turned in NOT on someone's holy day

#include <stdio.h>

int main()
{
	//define variables, where D is the number of days the assignment is due
	#define DAYS_IN_WEEK 7
	int numDate = 0;
	int D = 0;
	int dueDate = 0;
	
	//prompt user input for both D and numDate 
	printf("Please enter the day(0 for Sunday, 1 for Monday, etc.):\n");
	scanf("%d", &numDate);	
	printf("Please enter the number of days students have to work: \n");
	scanf("%d", &D);
	
	//input validation
	
	if(numDate > 6 || numDate < 0)
	{	
		printf("This date is invalid.\n");;
	}

	//calculate the day the assignment is due
	else{
		dueDate = (numDate + D) % DAYS_IN_WEEK;
	
		//switch function to determine the actual due  date
		switch (dueDate) {
			case 1: printf("The assignment will be due Monday, in %d days.\n", D);
				break;
			case 2: printf("The assignment will be due Tuesday, in %d days.\n", D);
				break;
			case 3: printf("The assignment will be due Wednesday, in %d days.\n", D);
				break;
			case 4: printf("The assignment will be due Thursday, in %d days.\n", D);
				break;
			case 5: ++D;
			case 6: ++D;
			case 0:	++D;
				printf("The assignment will be due Monday, in %d days.\n", D);
				break;
	
		}
	}
	return 0;

}

//Marta Wilczynski
//This program allows the user to create and input a  username with specific parameters.


#include <stdio.h>
#include <ctype.h>

int main()
{
	//define variables	
	char ch;
	int length = 0;

	//prompt user for input
	printf("Please enter a username: \n");
	ch = getchar();
	while (ch != '\n')
	{
		//input validation
		if (isalnum(ch) || ch == '_')
		{	ch = getchar();
			length++;
			continue;
		}
		else
		{
			length = 0;
			break;
		}
	}	
	//input validation
	if ( length > 4 && length < 11)
	{
		printf("Valid input\n");
	}
	else
	{
		printf("Invalid username.\n");
	}

	return 0;
}

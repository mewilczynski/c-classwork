//Marta Wilczynski
//This program encodes a message given by the user and outputs the encoded message

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int read_line(char *str, int n);
void convert(char *s1, char *s2);

int main()
{
	//declare variables
	char string1[1001];
	char string2[1001];
	int length;

	//prompt user for input
	printf("input:");
	
	//call read_line function
	length = read_line(string1, 1000);
	
	//convert the message
	convert(string1, string2);

	//output encoded message
	printf("Encoded: ");
	printf("%s\n", string2);

	return 0;
}

//define read_line function, given to us
int read_line(char *str, int n)
{
     int ch, i = 0; 
     while ((ch = getchar()) != '\n')
     {  if (i < n)
        {  *str++= ch;
           i++;
         }
     }
     *str = '\0';   /* terminates string */
     return i;        /* number of characters stored */
}

//define the convert function
void convert(char *s1, char *s2)
{
	//declare variables
	int temp;
	int place; //declare the alphabet to use the array index as our basis for encoding
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'     };

	while(*s1 != '\0') //contine to convert until null character
	{
		if((*s1 >= 'a' && *s1 <= 'z') || (*s1 >= 'A' && *s1 <= 'Z')) //check if we are looking at letters
		{
			for((place = 0); place < strlen(alphabet); place++)
			{
				if(*s1 == alphabet[place]) //find the corrsesponding letter in the alphabet array and use it to 
				{			   // calculate the encoded letter
					*s2 = alphabet[(25 - place)];
					s2++;
					s1++;	
				}

				else{
					temp = tolower(*s1); //hold the lowercased letter in temp
					if(temp == alphabet[place])
					{
						temp = alphabet[25 - place];
						*s2 = toupper(temp); //re-uppercase the held letter
						s2++;
						s1++;		
					}	
				}
			}
		}

		else{ //if not letters, then the symbols and spaces stay the same
			*s2 = *s1;
			s1++;
			s2++;		
		}
	*s2 = '\0';// must end the second string with null
	}	
}


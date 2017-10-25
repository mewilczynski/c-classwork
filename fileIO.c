// Marta Wilczynski
// This program takes words written in a text file, checks if any of the words are anagrams
// of one another, and writes the words that are anagrams into another text file.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//anagram checker function is given to us
int are_anagram(char *word1, char *word2)
{

	int letter_counts[26]={0};
	char *p; char *q;
	int i, count =0;
	char ch;
	for(p = word1; *p!='\0'; p++)
		if(isalpha(*p))
		{
			ch = tolower(*p);
			letter_counts[ch - 'a']++;
		}

	for(q = word2; *q!='\0'; q++)
		if(isalpha(*q))
		{
			ch = tolower(*q);
			letter_counts[ch - 'a']--;
		}

	for(i =0;i<26;i++)
	{
		if(letter_counts[i]==0)
			count++;
	}
		
	if(count == 26)
		return 1;
	else
		return 0;

	return 0;
}

int main()
{
	// Declare arrays and variables
	char words[100][101] = {{0}};
	char file_name[101] = {0};
	int i = 0;
	int j = 0;
	int k = 1;
	int count = 1;
	
	// Prompt user for input
	printf("Please enter the file name:\t");
	scanf("%s", file_name);

	// Open file given by user to read words inside and declare first file pointer
	FILE *fp1 = fopen(file_name, "r");

	//check if the file can be opened. if not, display an error message
	if(fp1 == NULL)
	{
		printf("The file cannot be opened.\n");
		return 1;
	}
	
	//populate our array of strings words with the words from the file given by the user
	while (!feof(fp1) && !ferror(fp1))
	{
		fgets(words[i], 100, fp1);
		i++;
		
		//convert the new line characters to null characters to complete our strings
		for(j= 0; words[i-1][j]; j++ )
		{
			if(words[i-1][j] == '\n')
			{
				words[i-1][j] = '\0';
				break;	
			}
		}
	}

	//close the file
	fclose(fp1);	

	// Change file name to have .ang at the end
	int length;
	length = strlen(file_name);
	file_name[length] = '.';
	file_name[length+1] = 'a';
	file_name[length+2] = 'n';
	file_name[length+3] = 'g';
	file_name[length+4] = '\0';
	
	//Declare second file pointer and use it to write to a new file.
	FILE *fp2 = fopen(file_name, "w");
	
	//print a new line for looks
	fprintf(fp2, "\n");
	
	//start to check for anagrams
	for(j = 0; j < (i-1); j++)
	{
		for(k = (j + 1); k < (i - 1); k++)
		{
			//if we have anagrams, write them to file and count the pair
			if((are_anagram(words[j], words[k]))== 1){
				fprintf(fp2, "%d \t %s \n\t %s \n", count, words[j], words[k]);
				count++;
			}
		}
	}	
	
	//notify user that the file has been written with the anagram pairs
	printf("Anagrams are written to file: %s\n", file_name);	
		
	// Close the new file 
	fclose(fp2);
	
	return 0;
}
                    

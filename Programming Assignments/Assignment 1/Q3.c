/* CS261- Assignment 1 - Q.3*/
/* Name: Andrew Wilson
 * Date: 4/4/2019
 * Solution description: Implemented as per detailed instructions
 */

#include <stdio.h>
#include <stdlib.h>



char toUpperCase(char ch)
{
  /*Convert ch to upper case, assuming it is in lower case currently*/
	return ch - 32;
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/
    return ch + 32;                          

}

int stringLength(char s[]) {
   /*Return the length of the string*/
	int counter = 0;

	while(s[counter] != '\0')
	{
		counter++;
	}
	return counter;
}


void camelCase(char* word){
	/*Convert to camelCase*/
	int i, j;

	for(i = 0; word[i] != '\0'; i++)
	{
		//when you find an underscore,
		if(word[i] == '_')
		{
			//overwrite by shifting entire rest of string over to the left
			for(j = i; word[j] != '\0'; j++)
			{
				word[j] = word[j + 1];
			}
			//and capitalize
			word[i] = toUpperCase(word[i]);
		}
	}
	
}

int main(){
	/*Read the string from the keyboard*/

	char string[256]; //assuming the string will be less than 255 chars
	int hasLetter, hasUnderscore, valid; 
	valid = hasLetter = hasUnderscore = 0; //false
	int i, j;
	i = j = 0;

	do{
		//read in string from user
		printf("Please enter a string: ");
		scanf("%255[^\n]s" , string); 

		//clear the input buffer)
		while ((getchar()) != '\n');
 
		//loop through string char by char until terminator
		for(i = 0; string[i] != '\0'; i++)
		{
			//convert uppercase to lowercase
			if(string[i] >= 'A' && string[i] <= 'Z') 
			{
				string[i] = toLowerCase(string[i]);
			}
			//convert whitespace and other symbols to _
			if(string[i] < 'a' || string[i] > 'z') 
			{
				string[i] = '_';
			}
		}
		
		//delete leading underscores
		while(string[0] == '_')
		{
			for(i = 0; string[i] != '\0'; i++)
			{
				string[i] = string[i + 1];
			}
		}
		//delete duplicate & trailing underscores
		//loop through string char by char,
		for(i = 0; string[i] != '\0'; i++)
		{
			//when you find an underscore,
			if(string[i] == '_')
			{
				//while the next char is an underscore,
				while(string[i + 1] == '_')
				{
					//overwrite by shifting entire rest of string over to the left
					//adapted from https://www.programiz.com/c-programming/examples/remove-characters-string
					for(j = i; string[j] != '\0'; j++)
					{
						string[j] = string[j + 1];
					}
				}
				//if the next char is the null terminator 
				//(i.e. it is a trailing underscore), become terminator
				if(string[i + 1] == '\0')
				{
					string[i] = '\0';
				}
			}
		}

		//check if there's at least one letter and one underscore
		hasLetter = hasUnderscore = 0; //false

		for(i = 0; string[i] != '\0'; i++)
		{
			if(hasLetter == 0 && (string[i] < 'a' || string[i] > 'z'))
			{
				hasLetter = 1; //true
			}
			else if(hasUnderscore == 0 && string[i] == '_')
			{
				hasUnderscore = 1; //true
			}
		}
		if(!hasLetter && !hasUnderscore)
		{
			printf("Invalid input string\n");
		}
		else
		{
			valid = 1; //true
		}
		

	}while(!valid);
	
	printf("\nYour formatted string input is: %s\n", string);
	
	/*Call camelCase*/
	camelCase(string);
	
	/*Print the new string*/
	printf("Your camelCase string input is: %s\n", string);
	
	return 0;
}
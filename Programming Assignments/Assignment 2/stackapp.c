/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	char temp;
	int isEmpty;

	//initialize the stack
	struct DynArr *stack = newDynArr(8);
	initDynArr(stack, 8);
	
	do
	{
		temp = nextChar(s);
		
		//if there is opening bracket, push the expected closing bracket on the stack
		if(temp == '(')
		{
			pushDynArr(stack, ')');
		}
		else if(temp == '{')
		{
			pushDynArr(stack, '}');
		}
		else if(temp == '[')
		{
			pushDynArr(stack, ']');
		}

		//the top of the stack should be the first bracket to be closed
		//if there is a mismatch or the stack is empty, the expression is unbalanced
		if(temp == ')' || temp == '}' || temp == ']')
		{
			if(isEmptyDynArr(stack))
			{
				return 0;
			}
			if(topDynArr(stack) == temp)
			{
				popDynArr(stack);
			}
			else
			{
				return 0;
			}
		}
	}while(temp != '\0'); //I think this does an extra unnecessary loop

	//if the stack is not empty, the expression is unbalanced
	isEmpty = isEmptyDynArr(stack);

	//memory leaks are bad
	freeDynArr(stack);

	return isEmpty;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}


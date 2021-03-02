//Show Pratoomratana
//CS 1337
//03/08/2020
//IDE used: VIM
//Compiler with gcc flag -o
//Written and ran on a raspberry pi 4.0


#include <stdio.h>
#include <stdlib.h>


//Function to do the calculation for leap year.
char ly_calc(int* year)	{ 
	//Is it divisible by 4?
	//If so check if it's divisible by 100. Otherwise not a leap.
	//if so check if it's divisible by 400. If so leap. Otherwise not a leap.
	if (*year % 4 == 0)	{
		if (*year % 100 == 0)	{
			if (*year % 400 == 0)	{
				printf("%d is a leap year!\n", *year); 
				/*Clear the heap and set variable to NULL at the end of program.*/
				free(year);
				year = NULL;
				return 0;
			}
			else	{
				printf("%d is not a leap year.\n", *year); 
				free(year);
				year = NULL;
				return 0;
			}

		}
		else	{
			printf("%d is a leap year!\n", *year);
			free(year);
			year = NULL;
			return 0;
			}
		}

	else	{
		printf("%d is not a leap year.\n", *year);
		free(year);
		year = NULL;
		return 0;
	}
}

//Main function to get inputs from the user
char main(int argc, char **argv)	{

	//If there are two arguments perform the computation with the second argument.
	if (argc == 2)	{
		//Make room on heap for the input.
		int* user_input = malloc(argc*sizeof(int));
		//Changing the char argv[1] to an int for computation and storing it in user_input.
		*user_input = atoi(argv[1]);
		return ly_calc(user_input);
	}

	//If there are no arguments run in manual mode
	else if (argc < 2)	{
		//Create room on the heap for user's input and get it's pointer.
		int* user_input = malloc(argc*sizeof(int));
		printf("Please input a year to find out if it's a leap year.\n");
		//Get the input from user and store into the memory location of the pointer
		scanf("%d", user_input);
		//Call my calculation function to do the calculation with user's input.
		return ly_calc(user_input);
	}

	//If there are too many arguments, tell the user to try again.
	else	{
		printf("Too many arguments passed!\nYou passed %d arguments, try only 2.\n", argc);
		return 1;

		}
	}

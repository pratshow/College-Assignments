//Show Pratoomratana
//CS 1337
//03/08/2020
//IDE used: VIM
//Compiler with gcc flag -o
//Written and ran on a raspberry pi 4.0


#include <stdio.h>
#include <stdlib.h>

//Computing function to create the pattern.
int print_pattern(int* n)	{
	//Main loop to determine how many lines need to be printed
	for (int i = 0; i < *n; i++)	{
		//Setting up this way allows me to change the nested loops parameters based off where I am in my main(line printing) loop.
		//Set up variables inside main loop so the I can access them in my nested loops.
		int current_line = i;	//Just to make more clear what exactly 'i' and 'n' are.
		int user_input = *n;
		//The amount of dashes is (Number from the user - what increment of line we are on.)
		int num_dash = (user_input - current_line);
		//The amount of stars is: Users input - (Users input - (Index + 1)).
		int num_star = user_input - (user_input - (current_line + 1));
			//Nested loops to print the individual characters.
			//Parameters for loop use the pre-defined amount of dashes/stars.
			for (int i = 0; i < num_dash - 1; i++)	{
				printf("-");
			}
			for (int i = 0; i < num_star; i++)	{
				printf("*");
			}
		//New line at the very end.
		*n = user_input;
		printf("\n");
	}
	//Free the memory on the heap after all loops complete.
	free(n);
	n = NULL;
	return 0;
}

//Main func to get input from the user.
char main(int argc, char **argv)	{
	//If there are less than 2 arguments run in manual mode.
	if (argc < 2)	{
		//Make room on heap so I can access the input in another function.
		int* user_input = malloc(argc*sizeof(int));
		printf("How large would you like your pyramid?\n");
		scanf("%d", user_input);
		//Scan the input into the pointer user_input and call the print_pattern function.
		return print_pattern(user_input);
	}

	//If there are 2 arguments use the second argument as the user_input.
	else if	(argc == 2)	{
		//Same idea as the manual function
		int* user_input = malloc(argc*sizeof(int));
		//The user_input is in a different location, argv[1], convert it from char to int and store into user_input pointer.
		*user_input = atoi(argv[1]);
		return print_pattern(user_input);
	}

	//If there are too many function tell the user to try again.
	else	{
		printf("Too many arguments of %d try again with one or no arguments.\n", argc);
		return 1;
	}
}



//Show Pratoomratana
//CS 1337
//03/08/2020
//IDE used: VIM
//Compiler with gcc flag -o
//Written and ran on a raspberry pi 4.0


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Kinda ugly but gets the length of the integer up to 10.
int	length(int n)	{
	if	(n > 999999999)		{return 10;}
	else if (n > 99999999)		{return 9;}
	else if (n > 9999999)		{return 8;}
	else if (n > 999999)		{return 7;}
	else if (n > 99999)		{return 6;}
	else if (n > 9999)		{return 5;}
	else if (n > 999)		{return 4;}
	else if (n > 99)		{return 3;}
	else if (n > 9)			{return 2;}
	else				{return 1;}
}

//Logic to add the numbers together.
int	sum_digits(int user_input)	{
	//Define and initialize result at the beginning as 0.
	int result = 0;
	//Calling length to get the integer length of the input
	int num_leng = length(user_input);
	//For loop to add current number to the running total.
	for (int i = 0; i < num_leng; i++)	{
		//Mod 10 truncates the whole number except for the last digit.
		int current_num = (user_input % 10);
		//Add the current number to the running total.
		result = (result + current_num);
		//Divide the input by 10 to take off the last number before beginning the loop again.
		user_input = (user_input / 10);
		//At the last loop increment print the total and break out of loop.
		if (i == (num_leng - 1))	{
			printf("%d\n", result);
			break;
			}
		}
	return 0;
}

//Main function to get inputs.
char main(int argc, char **argv)	{

	//If there are less than 2 arguments run in manual
	if (argc < 2)	{
		//Creating space in the heap and returning a pointer to int.
		int* user_input = malloc(argc*sizeof(int));
		printf("What numbers would you like to add together?\n");
		//Get input from user and assign that int to the pointer to the heap.
		scanf("%d", user_input);
		//Kinda ghetto way to print the result but it works.
		//Print everything but result now and when sum_digits is called it will print the result\n.
		printf("The numbers %d added together is ", *user_input);
		//Run sum_digits function to with user input.
		int result = sum_digits(*user_input);
		//Once the result is printed, free heap and set variable to NULL.
		free(user_input);
		user_input = NULL;
		return 0;
		}

	//If there are 2 arguments, use argument 2 as the input.
	else if	(argc == 2)	{
		int* user_input = malloc(argc*sizeof(int));
		//Changing the string from the user to an int and storing it to pointer to the heap.
		*user_input = atoi(argv[1]);
		//Same idea as if (argc < 2).
		printf("The numbers %d added together is ", *user_input);
		int result = sum_digits(*user_input);
		free(user_input);
		user_input = NULL;
		return 0;
	}

	//If there are too many arguments, ask user to try again.
	else	{
		printf("Too many arguments of %d try again with one or no arguments.\n", argc);
	}
}

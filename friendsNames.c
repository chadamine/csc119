/*
 * 	Chad Lewis
 * 	CSC 119
 * 	Assignment 9
 * 	Program 8
 *
 * 	Create program allowing user to enter up to five names of friends.
 * 	Use a two dimensional array to store friends’ names.
 * 	After each name is entered, user should have option to enter another name or print report
 * 	showing each name entered thus far.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define A_MAX 20
#define F_NUM 5

void printNames(char friendNames[F_NUM][A_MAX]);	// Printing function prototype

int main()
{
	//REQUIRED FOR ECLIPSE CONSOLE TO FUNCTION
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // variable declarinitialization
	char friendNames[F_NUM][A_MAX] = {{' '}};	// 2D Array
	char moreNames = 'N';						// Response charVar
	char nameChars = ' ';						// Name array loader varChar
	int  c = 0;									// Name (row) counter

	while (c < F_NUM)
	{
		{
			printf("\n************ Menu ************\nn - Insert Friend Names\np - Display Current List of Friends\nx - Print List and Exit\nChoice: ");
			scanf("%c", &moreNames);
			scanf("%*c");	// Grab whitespace character caught by scanf net

			// CAPS moreNames for easy compare
			moreNames = toupper(moreNames);
		}

		if (moreNames == 'X')
		{
			if (c == 0)
				printf("Your list is empty. Goodbye");
			else
				moreNames = 'P';	// Print final list
			break;
		}

		if(moreNames == 'N')
		{
			printf("Insert friend name: ");

			for (int i = 0; i < A_MAX; i++)			// Column counting for loop
			{
				scanf("%c", &nameChars);

				friendNames[c][i] = nameChars;

				if(nameChars == 10)		// break name array loading when '/n' (10) read
					break;
			}

			nameChars = ' ';		// Reset name array loader
			c++;					// Increment name (row) counter
		}

		// Print list of names after five have been entered
		if (c == F_NUM)
			moreNames = 'P';

		if(moreNames == 'P')
		{
			printNames(friendNames);	// Printing function
			moreNames = ' ';			// Reset moreNames, return to menu
		}
	}

	return 0;
}

void printNames(char friendNames[F_NUM][A_MAX])
{
	printf("\n\nYour friends' names are: \n\n");

	for(int x = 0; x < F_NUM; x++)				// Row counting for loop

		for(int i = 0; i < A_MAX; i++)			// Column counting for loop
		{
			printf("%c", friendNames[x][i]);	// 2DArray Printer

			if(friendNames[x][i] == 10)			// Switch to next row when '/n' (10) read
				break;
		}
}

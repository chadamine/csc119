/*
 * 	Chad Lewis
 * 	CSC 119
 * 	Assignment 10
 * 	Program 9
 * 	05.27.13
 *
 * 	Using example program (Example 6.c) in this topic, use friends.dat file and build program
 * 	using fscanf() function for reading each record and printing field information to standard output
 * 	until end-of-file reached. Include error-handling routine notifying user of system errors and exits program.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char firstName[20];
	char lastName[20];

	// FILE stream declaration
	FILE* studentDataStream;

	// fileOpen: fopen("filename", "mode: r, w, a");
	studentDataStream = fopen("friends.dat", "r");

	// Check studentDataStream, print message if error found
	if (!studentDataStream)
	{
		printf("Error opening file");
		exit (100);
	}

	printf("The students' names are:\n\n");

	// fscanf reads from user-defined stream
	fscanf(studentDataStream, "%s%s", firstName, lastName);	// scan needed here for requirements in loop function below

	// end-of-file controlled loop
	while(!feof(studentDataStream))
	{
		// print must precede scan function to ensure last statement of loop is EOF check
		printf("%s %s\n", firstName, lastName);
		fscanf(studentDataStream, "%s%s", firstName, lastName);
	}

	// Close data file
	fclose(studentDataStream);

	return 0;
}

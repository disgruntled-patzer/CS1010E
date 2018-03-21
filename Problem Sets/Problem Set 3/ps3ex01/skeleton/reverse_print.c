// CS1010E Programming Methodology
// Problem Set 3 Exercise #01: reverse_print.c
//
// This program reads a list of numbers
// and print them out reversely.
//
// Lau Yan Han

#include <stdio.h>
#define MAX_SIZE 10

int main(void) {

	// define array according to the max size
	int size, arr[MAX_SIZE];
	int counter;

	printf("Enter the number of integers: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);

	for (counter = 0; counter < size; counter++){
        scanf("%d",&arr[counter]);
	}

	/*
		 You may
		 (1) read and store an integer into array directly, or
		 (2) use a variable to hold the input temporarily,
	    	 and assign it to an array slot thereafter.
		 The first way is more commonly used
	 */

	printf("Reverse printing: ");
	for (counter = size - 1; counter >= 0; counter--){
        printf ("%d ", arr[counter]);
	}
	printf("\n");


	return 0;
}

// CS1010E Programming Methodology
// Problem Set 4 Exercise #04: print_copies.c
//
// This program prints duplicated copies of an
// input string, up to a total of 10 characters.
//
// Lau Yan Han

#include <stdio.h>
#include <string.h>
#define LEN 6

int main(void) {

	char input[LEN];
	int length = 0; //Counts from 1 to 10 to keep the resulting output to 10 characters
	int inputlen; //Length of input string

	printf("Enter a string: ");
	scanf("%s", input); //Note there is no need for & because string is an array which is a pointer
	inputlen = strlen(input);

	while (length <= 10){
        length = length + inputlen; //Increment 'length' variable with the input string length
        if (length > 10){
            break; //If length hits 10 after updating, exit loop without printing another copy of the input
        }
        printf("%s", input); //If input can be safely printed without reaching max length, print it!
	}

	printf("\n");

	return 0;
}

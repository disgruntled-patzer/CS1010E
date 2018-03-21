// CS1010E Programming Methodology
// Problem Set 2 Exercise #09: collatz.c
//
// Calculates the number of iterations required for a number to reach 1 via the Collatz problem
//
//
// Lau Yan Han

#include <stdio.h>

int count_iterations(int num);

int main(void) {

    int num;

	printf("Enter a natural number: ");
	scanf ("%d", &num);
	printf("Number of iterations = %d\n", count_iterations(num));

	return 0;
}

// <Replace this with a short function description>
int count_iterations(int num) {

    int counter = 0;

    while (num != 1){ //When the number is not 1 (break out of loop and return counter = 0 when number is 1)

        if (num%2 == 0){ //If else statement performs Collatz problem, tests for odd/even
            num = num/2;
        }
        else {
            num = 3 * num + 1;
        }

        counter++; //increment 1 to counter at the end of each iteration

    }

	return counter;  // stub
}

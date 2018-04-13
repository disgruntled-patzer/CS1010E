// CS1010E Programming Methodology
// Problem Set 4 Exercise #24: square_sum.c
//
// This program reads a positive integer,
// returns the sum of all its digits in square.
//
// Lau Yan Han

#include <stdio.h>

int square_sum(int num);

int main(void) {

	/** main function is complete **/

	int number;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Square sum of all digits is %d\n",
			square_sum(number));

	return 0;
}

// Recursively calculate the square sum
// of all digits in a given number
int square_sum(int num) {

    if (num / 10 == 0){
        return ((num % 10) * (num % 10)); //Base case: When the leftmost digit of num variable has been reached
    }
    else {
        return ((num % 10) * (num % 10) + square_sum(num / 10));
    } //Return the square of rightmost digit plus the rest of the function (truncated by one digit)

	   return 0;  // stub
}

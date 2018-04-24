// CS1010E Programming Methodology
// Problem Set 4 Exercise #29: odd_digit_sum.c
//
// This program checks whether the sum of
// all digits is odd.
//

#include <stdio.h>

int is_sum_odd(int num);

int main(void) {

	int number;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Sum of digits for %d", number);
	if ( is_sum_odd(number) ) {
		printf(" is odd\n");
	} else {
		printf(" is not odd\n");
	}

	return 0;
}

// Check the sum of all digits,
// return 1 if odd, 0 otherwise.
// Given num is positive initially
int is_sum_odd(int num) {

    if (num / 10 == 0){
        if (num % 2 == 0){
            return 0; //If base case is even, return 0: NOTE THAT 0 IS AN EVEN NUMBER
        }
        else {
            return 1; //Otherwise return 1: Note that 1 IS AN ODD NUMBER
        }
    }
    else { //Test for all the sums of zeros and ones, each odd digit returns 1 (1 is ODD) and even returns 0 (0 is EVEN)
        if ( (num % 10 + is_sum_odd(num / 10)) % 2 == 0){
            return 0; //Thus if combination of zeros and ones are even, sum of the digits are even
        }
        else {
            return 1;
        }
    }
}

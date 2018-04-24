// CS1010E Programming Methodology
// Problem Set 4 Exercise #30: addition.c
//
// This program computes the sum of two
// integers in a recursive way.
//
// Lau Yan Han

#include <stdio.h>

int add(int num1, int num2, int carry);

int main() {

	/** main function is complete **/

	int num1, num2;

	printf("Enter two positive integers: ");

	scanf("%d %d", &num1, &num2);

	printf("Sum = %d\n", add(num1, num2, 0));

	return 0;
}

// Add two integers in a recursive way
// Assume num1 and num2 are of equal length
int add(int num1, int num2, int carry) {

	if (num1 / 10 == 0 || num2 / 10 == 0){ //Since num1 and num2 are assumed to be same length, we can use OR condition
        return num1 + num2 + carry; //Base case is just sum of the single digits + 'carry' from previous function
	}
	else {
        return add(num1/10, num2/10, (num1%10 + num2%10) / 10) * 10 + carry + (num1%10 + num2%10) % 10;
	}
	/* '(num1%10 + num2%10) % 10' is the rightmost digit of the sum of least significant digits
	Add 'carry' (from previous sum) to this, and then add result to the (updated 'add' function * 10)
	In updated add function:
        - Truncate both num1 and num2 by 1 digit (this is taken into account later by multiplying resulting function by 10)
        - new 'carry' is just the carry over from the sum of the least significant digits (num1%10 + num2%10) / 10*/
}

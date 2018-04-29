// CS1010E Programming Methodology
// Problem Set 1 Exercise #09: three_ints.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

// function prototype
int get_hundredth(int num);

// main function is complete
int main(void) {

	int num1, num2, num3;   // inputs
	int digit;  // digit in hundredth position

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	digit = get_hundredth(num1);
	printf("%d ", digit);

	digit = get_hundredth(num2);
	printf("%d ", digit);

	digit = get_hundredth(num3);
	printf("%d\n", digit);

	return 0;
}

// Take a number and return the digit in hundredth position
int get_hundredth(int num) {

    int digit;

    digit = (num % 1000) / 100;

	return digit;  // stub, to be replaced by your code
}

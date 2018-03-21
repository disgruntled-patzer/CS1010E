// CS1010 Programming Methodology
// Problem Set 1 Exercise #11: magic_digit.c
//
// This function reads the 1st, 3rd and 5th digits of a 5 digit number, adds them together, and displays the last digit of the result
//
//
// Lau Yan Han

#include <stdio.h>

// function prototype
int get_magic(int num);

int main(void) {

	/** main function is complete **/

	int num, digit;

	// process first number
	printf("Enter 1st number: ");
	scanf("%d", &num);
	digit = get_magic(num);
	printf("Magic digit = %d\n", digit);

	// process second number
	printf("Enter 2nd number: ");
	scanf("%d", &num);
	digit = get_magic(num);
	printf("Magic digit = %d\n", digit);

	return 0;
}

// Take a number and return the magic digit
int get_magic(int x) {
    int digit_a, digit_b, digit_c, digit_sum;
    digit_a = (x - (x%10000))/10000; //1st digit from the right (Original digit - last 4 digits)/10000
    digit_b = ((x%1000) - (x%100))/100; //2nd digit (Last 3 digits - Last 2 digits)/100
    digit_c = x%10; //Last digit, which is the remainder of the original divided by 10
    digit_sum = digit_a + digit_b + digit_c;
	return digit_sum%10;  //Returns the last digit, which is the remainder of digit_sum divided by 10
}

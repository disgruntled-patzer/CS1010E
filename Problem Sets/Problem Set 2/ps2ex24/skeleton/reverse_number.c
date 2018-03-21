// CS1010E Programming Methodology
// Problem Set 2 Exercise #24: reverse_number.c
//
// This program counts the number of reversible numbers in a given range
//
//
// Lau Yan Han

#include <stdio.h>

int count_reverse(int low, int high);
int is_reverse(int num);
int power (int base, int exp); //Power function for integers

int main(void) {

    int low, high;

	printf("Enter the range: ");
    scanf ("%d %d",&low, &high);

	printf("There are %d reverse numbers.\n",count_reverse(low,high));

	return 0;
}

// Count the number of reversible numbers in a given range
int count_reverse(int low, int high) {

	int a;
	int counter = 0;

	for (a = low; a <= high; a++){

		if (is_reverse(a) == 1){
			counter++;
			}
		}

	return counter;
}

// Tests whether a number is reversible
int is_reverse(int num) {

	int b;
	int reverse_num = 0, num_temp = num;
	//num_temp will be modified and used to extract reverse number (reverse_num) while leaving the original num untouched
	int num_digits = 1;
	int divisor, divisor_rev;

	for (b = 10; num/b != 0; b = b * 10){
		num_digits++; //This loop counts how many digits the number has
		}

    divisor = 10; //Set divisor to 10 for the next loop
    divisor_rev = power (10,num_digits);//10 ^ number of digits: Used to assign digits to reverse number
    //Originally I used (int)pow(10.0,(double)num_digits); but this gives some errors for two digit cases
    //printf ("%d %d %d\n",num_digits, divisor, divisor_rev); //Debugging statement

    for (b = 1; b <= num_digits; b++){
        //printf ("%d %d ",reverse_num,num_temp); //Debugging statement
        reverse_num = reverse_num + (num_temp%divisor) * divisor_rev;
        //Extracts the leftmost digit of num_temp, promotes it to rightmost digit (using divisor_rev) and adds it to reverse_num
        num_temp = num_temp/divisor;
        divisor_rev = divisor_rev/10;
        //Removes the leftmost digit of num_temp and decrease divisor_rev by 1 digit to repeat the earlier process
        //printf ("%d %d\n",reverse_num,num_temp); //Debugging statement
    } //At the end of this loop, the reverse number * 10 is extracted

    reverse_num = reverse_num/10; //Divide by 10 to get the actual reverse number

    if (reverse_num == num){ //This is why we use num_temp instead of num in the earlier loop: Num cannot be modified as it needs to be compared over here
        return 1; //If reverse number = original number, then return TRUE
    }
    else {
        return 0;
    }
}

int power (int base, int exp){

    int c, result = base;

    for (c = 2; c <= exp; c++){
        result = result * base;
    }
    return result;
}

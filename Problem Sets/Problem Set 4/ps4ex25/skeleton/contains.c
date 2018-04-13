// CS1010E Programming Methodology
// Problem Set 4 Exercise #25: contains.c
//
// This program checks if digit k appears
// in integer number.
//
// <Replace this with your name>

#include <stdio.h>

int contains(int num, int k);

int main(void) {

	/** main function is complete **/

	int number, k;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	printf("Enter a single digit integer k: ");
	scanf("%d", &k);

	if ( contains (number, k) ) {
		printf("%d appears in %d\n", k, number);
	} else {
		printf("%d doesn't exist in %d\n", k, number);
	}

	return 0;
}

// Recursive function to check if num contains k
// Return 1 if so or 0 otherwise
// Given num is positive initially
int contains(int num, int k) {

    if (k == num%10){
        return 1; //If k is found, return 1
    }
    else if (num / 10 == 0){
        return 0; //Base Case: If leftmost digit has been reached and k isn't found, return 0
    }
    else {
        return contains(num/10, k); //Test k against the remaining digits
    }

}

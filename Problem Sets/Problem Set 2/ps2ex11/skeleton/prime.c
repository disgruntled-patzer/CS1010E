// CS1010E Programming Methodology
// Problem Set 2 Exercise #11: prime.c
//
// This program determines whether a number input by the user is prime
//
//
// Lau Yan Han

#include <stdio.h>

int is_prime(int num);

int main(void) {

    int num;

	printf("Enter a positive integer: ");
	scanf ("%d",&num);

	if (is_prime(num) == 1){
        printf("%d is a prime\n", num);
	}
	else {
        printf("%d is not a prime\n", num);
	}

	return 0;
}

// Determines whether a number is prime
int is_prime(int num) {

    int counter;

    if (num == 1) {
        return 0; //Because 1 is not a prime
    }
    else { //If number is not 1, enter loop
        for (counter = 2; counter < num; counter++){
            if (num%counter == 0){
                return 0; //If any counter (apart from 1 and num) is a divisor of the number, number is not prime, return FALSE
            }
        }
    }
	return 1;  // If loop is exited, the number is prime and thus return TRUE
}

// CS1010E Programming Methodology
// Problem Set 2 Exercise #11: prime.c
//
// This program determines whether a number input by the user is prime
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

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

    int c;

    if (num == 1){
        return 0; //1 is not a prime number
    }
    if (num % 2 == 0 && num > 2) {
        return 0; //If num is even, it cannot be prime (used to optimize runtime)
    }

    //If num is odd and isn't 1, enter loop
    for (c = 2; c < floor(sqrt(num)); c++){
        //floor(sqrt(num)) is used to optimize runtime; any number greater than sqrt(num) cannot possibly be a divisor of num
        if (num%c == 0){
            return 0; //If any counter (apart from 1 and num) is a divisor of the number, number is not prime, return FALSE
        }
    }

	return 1; //If loop is exited, number is prime
}

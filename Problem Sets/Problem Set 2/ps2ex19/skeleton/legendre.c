// CS1010E Programming Methodology
// Problem Set 2 Exercise #19: legendre.c
//
// This program tests the Legendre Conjecture for all integers
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

int test_conjecture(int n);
int has_prime(int low, int high);
int is_prime(int num);

/*Note: Function currently has three nested loops, and takes a long time for n > 1000
Any way to make the code more efficient? Currently, steps are taken to optimize third loop (is_prime function)*/

int main(void) {

	/** main function is complete **/

	int n;

	printf("Enter n: ");
	scanf("%d", &n);

	if ( test_conjecture(n) ) {
		printf("True\n");
	} else {
		printf("False\n");
	}

	return 0;
}

// Verify if there is at least one prime number in
// each range (1^2 to 2^2), (2^2 to 3^2), (n^2 to (n+1)^2)
int test_conjecture(int n) {

    int a;

    for (a = 1; a <= n; a++){
        if (has_prime(a, a + 1) == 0){
            return 0;
        }
    }

    return 1;
}

// Check whether there is any prime in range [low, high]
// return 1 if so, return 0 otherwise
int has_prime(int low, int high) {

    int b;

    for (b = low*low; b <= high*high; b++){ //Range from n^2 to (n+1)^2
        if (is_prime(b) == 1){
            return 1;
        }
    }

	return 0;
}

// Check num is prime or not
// return 1 if so, return 0 otherwise
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

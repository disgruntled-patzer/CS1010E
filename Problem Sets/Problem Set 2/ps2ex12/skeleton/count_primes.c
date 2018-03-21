// CS1010E Programming Methodology
// Problem Set 2 Exercise #12: count_primes.c
//
// Count how many prime numbers there are in a given range from [1-limit]
//
//
// Lau Yan Han

#include <stdio.h>

int is_prime(int num);
int count_primes(int limit);

int main(void) {

    int limit;

	printf("Enter limit: ");
	scanf("%d", &limit);
	printf("Number of primes (1-%d): %d\n", limit, count_primes(limit));

	return 0;
}

// Return 1 if num is a prime, 0 otherwise
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

// return the number of primes in range [2, limit]
// 1 is not a prime!
int count_primes(int limit) {

    int counter2; //Used in the for loop
    int number_primes = 0; //Counts the number of primes

    for (counter2 = 1; counter2 <= limit; counter2++){
        if (is_prime(counter2) == 1){
            number_primes++; //If number is prime, increment number_primes by one, otherwise do nothing and continue to next number
        }
    }

	return number_primes;
}

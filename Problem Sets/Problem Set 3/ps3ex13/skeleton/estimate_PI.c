// CS1010E Programming Methodology
// Problem Set 3 Exercise #13: estimate_PI.c
//
// This program reads in a list of
// distinct integers and computes
// the estimate value for pi.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define MAX 100

double estimate_PI(int list[], int size);
int gcd(int a, int b);

int main(void) {

    int list[MAX] = {0}, size;
    int i;

	printf("Enter the size of the list: ");
	scanf("%d", &size)
;
	printf("Enter  elements: ");
	for (i = 0; i < size; i++){
        scanf("%d", &list[i]);
	}

	printf("Estimated pi = %.4f\n", estimate_PI(list, size));

	return 0;
}

// Return the estimate value of PI
double estimate_PI(int list[], int size) {

    double pi;
    int i, j;
    int pairs = 0, factor_one = 0;

    for (i = 0; i < size; i++){ //This nested loop finds the total number of pairs, and those that have GCD of 1
        for (j = i + 1; j < size; j++){
            if (gcd(i, j) == 1){ //'No common factor other than one' == GCD is 1
                factor_one++;
            }
            pairs++; // Total number of pairs (even if their GCD > 1)
        }
    }

    pi = sqrt(6.0*pairs/factor_one);

	return pi; // stub
}

// Euclid's Algorithm to return the greatest common divisor of two positive integers a and b
int gcd (int a, int b){

    int rem; //Remainder (When computing a = q*b + rem or b = q*a + rem)

    if (a == b){
        return a;
    }
    else if (a > b){
       while (b > 0){
            rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    else { // b > a
        while (a > 0){
            rem = b % a;
            b = a;
            a = rem;
        }
        return b;
    }
}

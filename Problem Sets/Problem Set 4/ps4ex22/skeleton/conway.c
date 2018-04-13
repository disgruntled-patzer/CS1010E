// CS1010E Programming Methodology
// Problem Set 4 Exercise #22: conway.c
//
// This program prints conway sequence a(n).
//
// Lau Yan Han

#include <stdio.h>

int a(int n);

int main(void) {

	/** main function is complete **/

	int n;

	printf("Enter n (n>0): ");
	scanf("%d", &n);

	printf("a(n) = %d\n", a(n));

	return 0;
}

// Compute a(n) according to
// the recursive formula
int a(int n) {

    if (n == 1 || n == 2){
        return 1;
    }
    else {
        return a(a(n - 1)) + a(n - a(n - 1));
    }

	return 0;  // stub
}

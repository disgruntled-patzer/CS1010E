// CS1010E Programming Methodology
// Problem Set 4 Exercise #21: recursive_sum.c
//
// This program prints f(x) whose value
// is given by the recursive formula.
//
// Lau Yan Han

#include <stdio.h>

int f(int x);

int main(void) {

	/** main function is complete **/

	int x;

	printf("Enter a positive integer: ");
	scanf("%d", &x);

	printf("Sum = %d\n", f(x));

	return 0;
}

// Calculate sum according to recursive formula
int f(int x) {

	if (x == 0 || x == 1 || x == 2){
        return 1;
	}
	else if (x % 2 == 0){
        return f(x - 1) + f(x - 2) + f(x - 3);
	}
	else {
        return f(x - 1) + f(x - 2);
	}

}

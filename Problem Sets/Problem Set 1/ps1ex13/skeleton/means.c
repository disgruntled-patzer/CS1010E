// CS1010E Programming Methodology
// Problem Set 1 Exercise #13: mean.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

// function prototypes
double compute_AM(int a, int b, int c);
double compute_GM(int a, int b, int c);

int main(void) {

    int a, b, c;

	printf("Enter 3 positive integers: ");
    scanf("%d %d %d", &a, &b, &c);

	printf("Arithmetic mean = %.2f\n", compute_AM(a, b, c));
	printf("Geometric mean = %.2f\n", compute_GM(a, b, c));

	return 0;
}

// Compute arithmetic mean
double compute_AM(int a, int b, int c) {

	return ((double)a + b + c) / 3;
}

// Compute geometric mean
double compute_GM(int a, int b, int c) {

	return pow((double)a * b * c, 1.0/3);  // stub, to be replaced by your code
}

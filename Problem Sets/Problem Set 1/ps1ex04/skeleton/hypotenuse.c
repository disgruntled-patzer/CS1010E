// CS1010E Programming Methodology
// Problem Set 1 Exercise #04: hypotenuse.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h> // to use sqrt() function

int main(void) {

    double a, b;

	printf("Enter a and b: ");
	scanf("%lf %lf", &a, &b);

	printf("c = %.2f\n", sqrt(a * a + b * b));

	return 0;
}

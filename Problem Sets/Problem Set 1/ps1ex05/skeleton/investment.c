// CS1010E Programming Methodology
// Problem Set 1 Exercise #05: investment.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

int main(void) {

    int principal, rate, years;
    double result;

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &years);

	result = principal * (1 - pow((1.0 * rate / 100), 1.0 * years + 1) ) / (1 - (1.0 * rate / 100));

	printf("Amount = $%.2f\n", result);

	return 0;
}

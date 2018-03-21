// CS1010 Programming Methodology
// Problem Set 1 Exercise #07: sphere.c
//
// This program reads diameter and
// calculates surface area of a sphere.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h> //To use the power function
#define PI 3.1415

int main(void) {

	double diameter;

	printf("Enter diameter: ");
	scanf ("%lf",&diameter);
	printf("Surface area = %.3f\n",PI*pow(diameter,2.0)); //pow = power function, since the operator ^ doesn't work with doubles
    printf("Volume = %.3f\n",(4.000/3.000)*PI*pow(0.5*diameter,3.0));
    //Note: Use 4.0/3.0 instead of 4/3 to avoid rounding errors when working with integers
	return 0;
}

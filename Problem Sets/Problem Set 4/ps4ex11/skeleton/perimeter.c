// CS1010E Programming Methodology
// Problem Set 4 Exercise #11: perimeter.c
//
// This program reads the lengths of two sides
// of a rectangle, and computes the minimum
// perimeter after folding the rectangle
// once along the x-axis or y-axis.
//
// Lau Yan Han

#include <stdio.h>

typedef struct {
	double side1, side2;
} rectangle_t;

int main(void) {

	// declare a rectangle of type rectangle_t below
	rectangle_t coords;
	double perimeter1, perimeter2;

	printf("Enter lengths of two sides: ");
	scanf("%lf %lf", &coords.side1, &coords.side2);

	perimeter1 = (2*coords.side1) + coords.side2;
	perimeter2 = coords.side1 + (2*coords.side2);

    if (perimeter1 <= perimeter2){
        printf("Min perimeter after fold = %.1f\n", perimeter1);
    }
    else {
        printf("Min perimeter after fold = %.1f\n", perimeter2);
    }

	return 0;
}

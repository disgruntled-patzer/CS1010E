// CS1010 Programming Methodology
// Problem Set 1 Exercise #01: volume.c
//
// This program reads in length, width and
// height of a box, computes its volume.
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

	int length, width, height, volume;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width: ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	// correct the following two statements
	volume = length* width* height;
        printf("Volume = %d\n", volume);

	return 0;
}

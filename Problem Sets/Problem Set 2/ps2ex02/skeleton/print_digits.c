// CS1010E Programming Methodology
// Problem Set 2 Exercise #02: print_digits.c
//
// This program displays the digits of an integer from right to left234
//
//
// Lau Yan Han

#include <stdio.h>

void print_digits(int num); // function prototype

int main(void) {

    int num;

	printf("Enter a positive integer: ");
	scanf("%d",&num);
	print_digits(num);

	return 0;
}

// Print digits right to left
void print_digits(int num) {

    do {
        printf("%d ",num%10);
        num = num/10;
	}
	while (num != 0);

	printf("\n");  // change line
}

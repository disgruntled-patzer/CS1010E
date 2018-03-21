// CS1010E Programming Methodology
// Problem Set 2 Exercise #01: count_digits.c
//
// This program counts the number of digits in an integer that the user enters
//
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

    int num;
    int counter = 0;

	printf("Enter a positive integer: ");
	scanf("%d",&num);

	do {
        counter++;
        num = num/10;
	}
	while (num != 0);

	printf("Number of digits = %d\n",counter);

	return 0;
}

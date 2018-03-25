// CS1010E Programming Methodology
// Problem Set 2 Exercise #17: winners.c
//
// This program calculates the number of winners based on a number of conditions
//
//
// Lau Yan Han

#include <stdio.h>

int test_factor (int factor, int digit);
int test_must_have (int must_have, int digit);

int main(void) {

	int factor, must_have, participants;
	int a;
	int winners = 0;

	printf("Enter factor-digit: ");
	scanf ("%d", &factor);

	printf("Enter must-have-digit: ");
	scanf ("%d", &must_have);

	printf("Enter the number of participants: ");
	scanf ("%d", &participants);

	for (a = 1; a <= participants; a++){
		if (test_factor (factor, a) == 1 && test_must_have (must_have, a) == 1){
			winners++;
		}
	}
	printf("Number of winners: %d\n", winners);

	return 0;
}

int test_factor (int factor, int digit){

	if (digit % factor == 0){
		return 1;
	}
	else {
		return 0;
	}
}

int test_must_have (int must_have, int digit){

	while (digit > 0){
		if (digit % 10 == must_have){
			return 1;
		}
		digit = digit/10;
	}

	return 0;
}

// CS1010E Programming Methodology
// Problem Set 3 Exercise #09: most_appeared.c
//
// This program reports the digit that
// appears most of the time in a given number.
//
// <Replace this with your name>

#include <stdio.h>

int most_appeared(int num);

int main(void) {

    int num;

	printf("Enter a positive integer: ");
	scanf ("%d", &num);

	printf("Most appeared digit in %d: %d\n",num,most_appeared(num));

	return 0;
}

// Return the digit that has max frequency.
// In case more than 1 digit gives the same
// max frequency, return the biggest digit.
int most_appeared(int num) {

	int freq[10] = {0}; // frequency of digits 0-9
	int most_appeared_digit, counter;

	do {
     freq[num%10]++;
     num = num/10;
     printf ("%d\n",num);
	}
    while (num != 0);

    most_appeared_digit = 0; //Assign most-appeared-digit variable to the first array element (0) before comparing it later on

    for (counter = 1; counter < 10; counter++){ //Compare most-appeared digit with the rest of the array elements
        if (freq[counter] > most_appeared_digit){
            most_appeared_digit = counter;
            printf ("%d\n",most_appeared_digit);
        }
    }

	return most_appeared_digit;
}

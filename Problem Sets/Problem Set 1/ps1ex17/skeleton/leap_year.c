// CS1010 Programming Methodology
// Problem Set 1 Exercise #17: leap_year.c
//
// This program calculates whether a given year is a leap year
//
//
// Lau Yan Han

#include <stdio.h>

// function prototype
int is_leap_year(int year);

int main(void) {

	int year;

	printf("Enter year: ");
    scanf ("%d", &year);
    if (is_leap_year(year)==1){
        printf("%d is a leap year.\n", year);
    }
    else {
        printf("%d is not a leap year.\n", year);
    }

	return 0;
}

// Return 1 if year is leap year, or 0 otherwise
int is_leap_year(int year) {

    if ((year%4 == 0 && !(year%100 == 0)) || year%400 == 0) {
        //If year is divisible by 4 AND NOT divisible by 100, OR if year is divisible by 400
        return 1;
    }
    else {
        return 0;
    }
}

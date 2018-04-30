// CS1010E Programming Methodology
// Problem Set 3 Exercise #04: deviation.c
//
// This program calculates the
// standard deviations for n real numbers.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>
#define MAX_LEN 9

double deviation(double val[], int size);
double average(double val[], int size);
double sum_of_difference(double val[], int size);

int main(void) {

    int size, i;
    double val[MAX_LEN];

	printf("How many real numbers? ");
	scanf("%d", &size);

	printf("Enter %d numbers: ", size);
	for (i = 0; i < size; i++){
        scanf("%lf", &val[i]);
	}

	printf("Standard deviation: %.2f\n", deviation(val, size));

	return 0;
}

// Return standard deviation
double deviation(double val[], int size) {

	return sqrt(sum_of_difference(val, size) / size);
}

// Return average of numbers in the array
double average(double val[], int size) {

    double avg = 0;
    int i;
    for (i = 0; i < size; i++){
        avg = avg + val[i];
    }

    avg = avg / size;

	return avg;
}

// Calculate the sum of square differences
// i.e. upper inner part of the formula
double sum_of_difference(double val[], int size) {

    double sum = 0, avg = average(val, size);
    int i;

    for (i = 0; i < size; i++){
        sum = sum + (val[i] - avg) * (val[i] - avg);
    }

	return sum;  // stub
}

// CS1010E Programming Methodology
// Problem Set 2 Exercise #05: count_positive.c
//
// This program counts the number of positive integers input by a user
//
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

    int num [5]; //An array used to read the integers input by the user
    int a; //used for the loop algorithm
    int counter = 0; //counter is used to count number of positive integers

	printf("Enter 5 integers: ");

	for (a = 0; a < 5; a++){ //scans the user input and inserts them from the 0th to 4th slot in the array before testing them for positive/negative
        scanf ("%d",&num[a]);
        if (num[a] > 0){
            counter++;
        }
	}

	printf("Count = %d\n",counter);

	return 0;
}

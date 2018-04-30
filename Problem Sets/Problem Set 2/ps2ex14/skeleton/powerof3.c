// CS1010E Programming Methodology
// Problem Set 2 Exercise #14: power_of_3.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

int count_numbers(int start, int end);

int main(void) {

    int start, end;

	printf("Enter start and end: ");
    scanf("%d %d", &start, &end);

	printf("Answer = %d\n", count_numbers(start, end));

	return 0;
}

// Count the number of integers from start to
// end (both inclusive) which are power of 3
int count_numbers(int start, int end) {

    int result = 0, i;

    for (i = 3; i <= end; i = i * 3){ //Start from the lowest power of 3 and work up from there
        if (i >= start && i <= end){
            result++;
        }
    }

	return result;
}

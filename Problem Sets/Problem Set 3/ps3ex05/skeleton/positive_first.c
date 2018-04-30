// CS1010E Programming Methodology
// Problem Set 3 Exercise #05: positive_first.c
//
// This program tests if all the positive
// number (if any) appear before all the
// non-positive numbers (if any) in an array.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>
#define MAX_LEN 10

int is_positive_first(int numbers[], int size);

int main(void) {

    int size, numbers[MAX_LEN], i;
    int result;

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++){
        scanf("%d", &numbers[i]);
	}

	result = is_positive_first(numbers, size);

    if (result == 1){
        printf("All positive numbers appear before non-positive numbers\n");
    }
    else {
        printf("Some positive numbers appear after non-positive numbers\n");
    }

	return 0;
}

// Return 1 if all positive numbers appear before
// any non-positive numbers, or 0 otherwise
int is_positive_first(int numbers[], int size) {

    int i;

    for (i = 1; i < size; i++){
        if (numbers[i - 1] <= 0 && numbers[i] > 0){ //If a entry is found where it is positive, and its lefthand entry is negative
            return 0; //Then not all positive numbers appear before negative
        }
    }
	return 1;  // stub
}

// CS1010E Programming Methodology
// Problem Set 3 Exercise #07: find_twice.c
//
// This program checks if any integer
// is repeated in an array and if so,
// reports the first duplicated integer.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>
#define MAX_LEN 10

int find_twice(int arr[], int size);

int main(void) {

    int size, arr[MAX_LEN], i;
    int index; //Index where the first repeated integer appears for the first time

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++){
        scanf("%d", &arr[i]);
	}

	index = find_twice(arr, size);

    if (index == -1){
        printf("Array doesn't contain repeated data\n");
    }
    else {
        printf("%d is the first repeated integer\n", arr[index]);
    }

	return 0;
}

// Find the first repeated element.
// Return index of its first appearance
// if found, or -1 otherwise
int find_twice(int arr[], int size) {

    int index = -1; //Index which the first repeated integer appears for the first time
    int i, j; //Loop counters

    for (i = 0; i < size - 1; i++){
        for (j = i + 1; j < size; j++){
            if (arr[i] == arr[j]){ //If a repeated integer is found
                index = i; //Mark its index and return it
                return index;
            }
        }
    }

	return index;
}

// CS1010E Programming Methodology
// Problem Set 3 Exercise #12: containment.c
//
// This program checks if set A is
// contained in set B.
//
// Lau Yan Han

#include <stdio.h>
#define MAX 9

void scan_array(int arr[], int size);
int is_subset(int arrA[], int sizeA, int arrB[], int sizeB);

int main(void) {

	int arrA[MAX], sizeA, arrB[MAX], sizeB;

	printf("Size of 1st array? ");
	scanf("%d", &sizeA);
	scan_array(arrA, sizeA);

	printf("Size of 2nd array? ");
	scanf("%d", &sizeB);
	scan_array(arrB, sizeB);

	if ( is_subset(arrA, sizeA, arrB, sizeB) ) {
		printf("1st array is a subset of 2nd array\n");
	} else {
		printf("1st array is not a subset of 2nd array\n");
	}

	return 0;
}

// Read values into array
void scan_array(int arr[], int size) {

    int row;

	printf("\tEnter %d values: ", size);

	for (row = 0; row < size; row++){
        scanf("%d", &arr[row]);
	}

}

// Check whether arrA is a subset of arrB, return 1 if true, 0 if false
// Assumption: All numbers are distinct (aka no repeat of numbers in either array)
int is_subset(int arrA[], int sizeA, int arrB[], int sizeB) {

    int a, b; // Loop counters for arrA and arrB respectively
    int found = 0; // Indicates whether an entry in arrA has been found in arrB

    for (a = 0; a < sizeA; a++){
        for (b = 0; b < sizeB; b++){ // For each entry in arrA, compare it with the elements in arrB
            if (arrA[a] == arrB[b]){
                found = 1; // If the entry in arrA can be found in arrB, mark it as 'found' and break from inner loop
                break;
            }
        }
        if (found == 0){
            return 0; // If the entry in arrA was not found in arrB, then arrA is not a subset of arrB so return 0
        }
        else {
            found = 0; // Otherwise, go to next entry in arrA and reset "found" marker to zero
        }
    }

	return 1; //If loop exits with every entry of arrA found in arrB, then arrA is a subset of arrB
}

// CS1010E Programming Methodology
// Problem Set 3 Exercise #03: sorted.c
//
// This program checks whether all the values
// in an array are sorted in non-decreasing order.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int is_sorted(int arr[], int size);

int main(void) {

    int arr[MAX], size; //define array and array size
    int a; //Counter used in loop
    int test_sorted; //Checks whether an array is sorted

	printf("Enter the number of elements: ");
    scanf ("%d", &size);

	printf("Enter %d elements: ", size);
    for (a = 0; a < size; a++){ //Scans user inputs into array
        scanf("%d", &arr[a]);
    }

    test_sorted = is_sorted (arr, size);

    if (test_sorted == 1){
       printf("Given array is sorted.\n");
    }
	else {
        printf("Given array is not sorted.\n");
	}

	return 0;
}

// Check if array is sorted in non-decreasing order.
// Return 1 if true, 0 otherwise.
int is_sorted(int arr[], int size) {

    int a;

    for (a = 1; a < size; a++){
        if (arr[a-1] > arr[a]){ //If an index is greater than the next index, it is descending, thus array isn't sorted
            return 0;
        }
    }

	return 1;  // If loop exits without returning 0, array is in ascending order
}

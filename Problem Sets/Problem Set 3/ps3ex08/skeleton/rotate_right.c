// CS1010E Programming Methodology
// Problem Set 3 Exercise #08: rotate_right.c
//
// This program rotates the given array
// k positions to the right, where k is
// a positive integer.
//
// Lau Yan Han

#include <stdio.h>
#define MAX_LEN 100

void rotate_right_k(int arr[], int size, int k);
void rotate_right_1(int arr[], int size);
void print_array(int arr[], int size);

int main(void) {

    int arr[MAX_LEN], size, k;
    int i; //Loop counter

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++){
        scanf("%d", &arr[i]);
	}

	printf("Enter k: ");
	scanf("%d", &k);

	rotate_right_k(arr, size, k);

	print_array(arr, size);

	return 0;
}

// Rotate the array elements
// to the right by k positions
void rotate_right_k(int arr[], int size, int k) {

	int i; //Loop counter

	for (i = 1; i <= k; i++){
        rotate_right_1(arr, size);
	}

}

// Rotate the array elements
// to the right by 1 position
void rotate_right_1(int arr[], int size) {

	int i, temp; //i = loop counter, temp = temporary holding variables for array entries

    temp = arr[size - 1]; //Extract the rightmost entry into the temp variable before shifting
	for (i = size - 1; i > 0; i--){ //This loop shifts all the other entries to the right
        arr[i] = arr[i - 1];
	} //At the end of this loop, the array has been shifted but the temp variable is still holding the original rightmost entry

	arr[0] = temp; //Assign the original rightmost entry in the temp variable to the first entry in arr

}

// Print an array in sequence
// complete and given
void print_array(int arr[], int length) {

	int i;

	printf("[");
	for (i = 0; i < length-1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d]\n", arr[length-1]);
}

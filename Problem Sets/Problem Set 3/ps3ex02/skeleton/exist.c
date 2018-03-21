// CS1010E Programming Methodology
// Problem Set 3 Exercise #02: exist.c
//
// This program reads an array of integers
// and another integer k, checks if k exists
// in the array.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_SIZE 10

int contains(int arr[], int size, int k);

int main(void) {

	// define array according to the max size
	int size, arr[MAX_SIZE];
	int k;
	int a; //Used for the loop
	int test_exist; //Determine whether k exists in arr[]

	printf("Enter the number of elements: ");
	scanf("%d", &size); // read size of array

	printf("Enter %d elements: ", size);
	for (a = 0; a < size; a++){
        scanf("%d",&arr[a]);
	}

	printf("Enter k: ");
	scanf("%d",&k);

	test_exist = contains(arr, size, k);

	if (test_exist == 1){
        printf("%d is in the given array\n", k);
	}
	else {
        printf("%d is not in the given array\n", k);
	}

	return 0;
}

// Take an array 'arr' of 'size' elements,
// check if k exists in the array.
// Return 1 if so, 0 otherwise
int contains(int arr[], int size, int k) {

    int a;

    for (a = 0; a < size; a++){
        if (k == arr[a]){
            return 1;
        }
    }

	return 0;  // stub
}

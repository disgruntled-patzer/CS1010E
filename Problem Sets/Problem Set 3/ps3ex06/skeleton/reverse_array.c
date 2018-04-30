// CS1010E Programming Methodology
// Problem Set 3 Exercise #06: reverse_array.c
//
// This program accepts an array of integers
// and reverse all data in the array
//
// Lau Yan Han

#include <stdio.h>
#define MAX_LEN 20

int read_array(int arr[]);
void reverse_array(int arr[], int size);
void print_array(int arr[], int size);

int main(void) {

	int num, arr[MAX_LEN];

	num = read_array(arr);

	reverse_array(arr, num);

	print_array(arr, num);

	return 0;
}

// Read in an array, return its size
int read_array(int arr[]) {

    int num, i;

	printf("How many values in array? ");
	scanf("%d", &num);

	printf("Enter %d values: ", num);
	for (i = 0; i < num; i++){
        scanf("%d", &arr[i]);
	}
	return num;
}

// Reverse all elements in an array
void reverse_array(int arr[], int size) {

    int i = 0, j = size - 1; //Loop counters that will start at opposite ends of array and move towards each other
    int temp; //Temporary holding variable for array entries when a swap takes place

    while (i < j){ //While i and j haven't collided
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; //Swap entries i and j
        i++;
        j--; //Move i and j one step closer to each other
    }

}

// Print an array in sequence
// complete and given
void print_array(int arr[], int size) {

	int i;

	printf("Reversed: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

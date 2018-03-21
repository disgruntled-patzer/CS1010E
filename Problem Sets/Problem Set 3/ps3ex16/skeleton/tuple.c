// CS1010E AY2013/4 Semester 2
// Problem Set 3 Exercise #16: tuple.c
//
// This program checks if there is at least a pair
// of integers in a sorted array whose sum equals key.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int check_tuple(int arr[], int size, int key);

// main is complete and given
int main(void) {

	int i, size, arr[MAX], key;

	printf("Enter the number of distinct elements in sorted array: ");
	scanf("%d", &size);

	printf("Enter %d elements: ", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter key: ");
	scanf("%d", &key);

	if ( check_tuple(arr, size, key) ) {
		printf("Exist\n");
	} else {
		printf("Not exist\n");
	}

	return 0;
}

// Check if there exist at least a pair
// of integers whose sum equals key.
// Return 1 if so, 0 otherwise
// 'arr' is sorted
int check_tuple(int arr[], int size, int key) {

	int i = 0, j = size - 1;
	//We start at both ends of the array; i is used for the front and j is used at the back

	while (i != j){ //Loop will exit when both i and j collide with each other (i.e. meet the same index)

		if (arr[i] + arr[j] == key){
			return 1; //If a combination is found, return true
		}
		if (arr[i] + arr[j] > key){ //If the sum ends up higher than the key
			j--; //Shift j to the left to test a smaller digit
			i = 0; //Then reset i to 0 to run a new loop with the new value of j
			continue; //Skip to the next loop to avoid incrementing i without any testing with j
		}
		i++; //If j is not modified, increment i by 1 and run the loop again
	}

	return 0;  // If loop exits without returning 1, tuple doesn't exist
}

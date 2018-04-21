/*
 * CS1010E AY2017/18 Semester 2
 * PE2 Ex1: arrangeElements.c
 *
 * Name: Lau Yan Han
 * Student Number: A0164750E
 * PLab Userid: plab0538
 * Tutorial Group Number: E23
 * Short and Meaningful Program Description: This function reads a user input array and arranges it according to:
 *   1. All negative elements on the front of the array (if any)
 *   2. All positive elements on the back of the array (if any)
 *   3. Relative order between negative and positive elements are preserved
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int initArr(int []);
void arrangeArr(int [], int);
void prtArr(int [], int);

int main(void) {
	/********************************************************
	 * Main function is complete and you MUST NOT change it *
	 *******************************************************/

	int intList[ARRAY_SIZE], size;

	size = initArr(intList);
	printf("Initial array: ");
	prtArr(intList, size);

	arrangeArr(intList, size);
	printf("\nAfter re-arranging, the array is: \n");
	prtArr(intList, size);

	return 0;
}

/*
   This function arranges the user-input array according to the requirements stated in the program description
 */
void arrangeArr(int array[], int size) {

	int a; //Counters for loops
	int neg = 0; //Number of negative numbers
	int swapped = 1, temp, limit = size; //Used for Bubble Sorting Algorithms

	//First loop: Find out the number of positive and negative integers
	//Assumption: Take zero to be a positive integer
	for (a = 0; a < size; a++){
		if (array[a] < 0){
			neg++;
		}
	}

	//2nd loop: "Bubble sort" the array such that all negative elements go to the front
	//(But they are not sorted in ascending order yet)
	do {
		swapped = 0;
		for (a = 1; a < limit; a++){
			if (array[a - 1] >= 0 && array[a] < 0){ //If entry on the left is positive and entry on right is negative, swap
				temp = array[a - 1];
				array[a - 1] = array[a];
				array[a] = temp;
				swapped = 1;
			}
		}
		limit--; //"Largest" entry has been sorted to the right, thus reduce limit by 1 for next loop
	} while (swapped == 1); //After this sort, negative and positive elements are divided but not individually sorted yet

}

/*
   Initializing the array and the array size
 */
int initArr(int arr[]) {
	/********************************************************
	 * This function is complete and you MUST NOT change it *
	 *******************************************************/

	int i, size;

	printf("Enter the array size: ");
	scanf("%d", &size);

	printf("Enter %d integers into the array: ", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	return size;
}

/*
   Display the array content.
 */
void prtArr(int arr[], int size) {
	/********************************************************
	 * This function is complete and you MUST NOT change it *
	 *******************************************************/

	int i;
	printf("[ ");
	for (i = 0; i < size-1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d ].\n", arr[size-1]);
}

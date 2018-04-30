// CS1010E Programming Methodology
// Problem Set 3 Exercise #17: sort_three_digits.c
//
// This program sorts a list of integers
// in ascending order of their first 3 digits.
//
// Lau Yan Han

#include <stdio.h>
#define SIZE 100

void sort_array(int arr[], int size);
//int is_less_than(int num1, int num2);

// main is complete and given
int main(void) {

	int i, num, val[SIZE];

	printf("Enter the number of elements: ");
	scanf("%d", &num);

	printf("Enter %d elements: ", num);
	for (i = 0; i < num; i++) {
		scanf("%d", &val[i]);
	}

	sort_array(val, num);

	printf("Sorted array: [");
	for (i = 0; i < num-1; i++) {
		printf("%d, ", val[i]);
	}
	printf("%d]\n", val[num-1]);

	return 0;
}

// Original selection sort, need to be modified
// to sort integers according to the first 3 digits
void sort_array(int arr[], int size) {

	int i, start_idx, min_idx, temp;
	int arr3[size]; //This arr3 will store the first 3 digits of each index in arr to be compared
	//This is to avoid using 3 nested loops in the main selection sort function

	for (i = 0; i < size; i++){
        arr3[i] = arr[i];
        while (arr3[i] / 1000 != 0){ //While each entry in arr3 still has more than 3 digits
            arr3[i] = arr3[i] / 10; //Keep truncating the last digit in the entry
        }
	}

	for (start_idx = 0; start_idx < size-1; start_idx++) { //Selection sort loop (modified to use arr3 instead of arr)
		min_idx = start_idx;
		for (i = start_idx+1; i < size; i++) {
			if (arr3[i] < arr3[min_idx]) { //Instead of arr, compare arr3 (the first 3 digits of each entry in arr)
				min_idx = i;
			}
		}
		temp = arr[start_idx];
		arr[start_idx] = arr[min_idx];
		arr[min_idx] = temp;
		temp = arr3[start_idx]; //Perform the swap in both arr and arr3 entries
		arr3[start_idx] = arr3[min_idx];
		arr3[min_idx] = temp;
	}
}

// Compare integers according to first 3 digits,
// return 1 if first argument is smaller, 0 otherwise
/*int is_less_than(int num1, int num2) {

	return 0;  // stub
}*/

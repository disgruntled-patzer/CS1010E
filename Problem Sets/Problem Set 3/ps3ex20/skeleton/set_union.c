// CS1010E Programming Methodology
// Problem Set 3 Exercise #20: union.c
//
// This program reads two sets of distinct integers
// and prints out the union of two sets.
//
//
// Lau Yan Han

#include <stdio.h>
#define MAX 10

int read_array(int set[], char *index);
int get_union(int setA[], int sizeA, int setB[], int sizeB);
int exist(int arr[], int size, int val);
void sort_array(int set[], int size);
void print_array(int set[], int size);  // given

int main(void) {

	int setA[2*MAX], setB[MAX];  // two sets
	int sizeA, sizeB;

	sizeA = read_array(setA, "1st");
	sizeB = read_array(setB, "2nd");

	// update setA to be union of setA and setB
	// return updated size of setA
	sizeA = get_union(setA, sizeA, setB, sizeB);

	// sort setA in ascending order
	sort_array(setA, sizeA);

	print_array(setA, sizeA);

	return 0;
}

// Read elements of a set one by one
int read_array(int set[], char *index) {

    int i, size;

	printf("Size of %s set? ", index);
	scanf("%d",&size);

	printf("\tEnter %d values: ", size);
	for (i = 0; i < size; i++){
        scanf("%d",&set[i]);
	}

	return size;
}

// Update setA to be the union of setA and setB
int get_union(int setA[], int sizeA, int setB[], int sizeB) {

    int b; //b = index that will run through setB during the loop

    for (b = 0; b < sizeB; b++){
        if (exist(setA, sizeA, setB[b]) == 0){
            setA[sizeA] = setB[b]; //If the value in setB doesn't exist in setA, assign it to the end of setA
            sizeA++; //Update the value of SizeA for next loop
        }
    }
    //printf("%d\n",sizeA); //Debugging statement
	return sizeA;
}

// Return 1 if val exists in arr, or 0 otherwise
int exist(int arr[], int size, int val) {

	int i;

	for (i = 0; i < size; i++){
        if (val == arr[i]){ //If the tested value in SetB finds a matching value in SetA (arr), return 1
            return 1;
        }
	}

	return 0; // If loop exits without finding an existing value, return 0
}

// Sort array in ascending order of elements
void sort_array(int set[], int size) {

    int i;
    int swapped, temp;

    do { //Bubble sort algorithm
        swapped = 0;
        for (i = 1; i < size; i++){
            if (set[i-1] > set[i]){
                temp = set[i-1];
                set [i-1] = set[i];
                set[i] = temp;
                swapped = 1;
            }
        }
    }    while (swapped == 1);

}

// Print elements of array
void print_array(int set[], int size) {

	int i;

	printf("Union of two sets is (in ascending order):");
	for (i = 0; i < size; i++) {
		printf(" %d", set[i]);
	}
	printf("\n");
}

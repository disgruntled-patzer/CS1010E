// CS1010E Programming Methodology
// Problem Set 3 Exercise #19: merge_lists.c
//
// This program merges two sorted lists
// into one sorted list
//
// Lau Yan Han

#include <stdio.h>
#define MAX_SIZE 50

void read_list(int list[], int size);
void merge_lists(int list1[], int size1, int list2[], int size2, int list3[]);
void print_list(int list[], int size);

// complete and given
int main(void) {

	// three lists
	int list1[MAX_SIZE], size1,
			list2[MAX_SIZE], size2,
			list3[MAX_SIZE*2];

	printf("Number of elements in list1: ");
	scanf("%d", &size1);
	read_list(list1, size1);

	printf("Number of elements in list2: ");
	scanf("%d", &size2);
	read_list(list2, size2);

	merge_lists(list1, size1, list2, size2, list3);

	print_list(list3, size1+size2);

	return 0;
}

// Read values from file into arr
void read_list(int list[], int size) {

    int a;

	printf("Enter %d elements: ",size);

	for (a = 0; a < size; a++){
        scanf("%d",&list[a]);
	}
}

// Merge arrays list1 and list2 into list3
// in ascending order
void merge_lists(int list1[], int size1,
		int list2[], int size2, int list3[]) {

    int b; //Variables used within the loops
    int swapped, sort_temp; //Used for the sorting algorithm.
    //'swapped' checks whether a swap of digits has taken place. sort_temp is a temporary digit holder used when swapping digits

    for (b = 0; b < size1; b++){
        list3[b] = list1[b]; //Copy list1 into list3
    }
    //print_list(list3,size1); //Debugging statement

    for (b = size1; b < size1 + size2; b++){
        list3[b] = list2[b - size1]; //Copy list2 into list3, place list2 numbers after list1
        //Note: it's list [b - size1] not list[b], since writing list[b] will run off the end of the array!
    }
    //print_list(list3,size1+size2); //Debugging statement

    do { //Bubble sort algorithm
        swapped = 0; //Reset swapped to 0; at the start of each iteration, no digits have been swapped
        for (b = 1; b < size1 + size2; b++){
            if (list3[b-1] > list3[b]){
                sort_temp = list3[b-1];
                list3[b-1] = list3[b];
                list3[b] = sort_temp;
                swapped = 1;
                //If b-1 entry is more than b entry, swap the digits and indicate that a swap has taken place
            }
        }
    }
    while (swapped == 1); //If no swap has taken place, the list is sorted and the loop exits
}

// Print values of a list
void print_list(int list[], int size) {

    int c;

	printf("Merged list: [");

	for (c = 0; c < size; c++){
        printf ("%d", list[c]);
        if (c == size - 1){
            printf ("]\n"); //For the last element, don't print the comma and print a ] instead
            break;
        }
        printf (", ");
	}
}

/*Queries:
1. For the bubble-sort algorithm, right now the 2 lists are arranged back-to-back and in ascending order each
This makes the algorithm go through quite a lot of 'useless' steps (checking two numbers but not swapping them)
in each iteration, but still requires a lot of iterations overall. (TLDR It will take a long time)

Is it possible to shorten this process? I considered something like assigning list1 digits to odd numbered slots in list3,
and list2 digits to even-numbered slots in list3 (basically the digits in both lists alternate along each other along list 3)
But this may have problems if the number of digits in list1 and list2 are not the same, thus I did not try it.

2. The problem set requirements suggest that there is a way to do this without nested loops.
However, most of the sorting algorithms that I have seen, require at least 2 nested loops;
Those that don't need (e.g. Quick Sort: Divide and Conquer) have quite complicated implementations
Thus I stuck to Bubble Sort to keep things simple.
Is is possible to create a simple algorithm that requires no nested loops?
But then again, I did this exercise before Lecture 8 so there might be something in the lecture that helps
*/

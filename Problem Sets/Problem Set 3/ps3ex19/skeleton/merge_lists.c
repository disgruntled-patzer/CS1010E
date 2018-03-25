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

    int b1 = 0, b2 = 0, b3 = 0;
    //In subsequent loop, b1 = index for list1, b2 = index for list2, b3 = index for list3

    while (b1 < size1 && b2 < size2){ //While counters for list1 and list2 have not reached their limits
        if (list1[b1] <= list2[b2]){
            list3[b3] = list1[b1];
            b1++; //If list1 index is smaller/equal to list2 index, assign that index to list3 and move on to the next index in list1
        }
        else {
            list3[b3] = list2[b2];
            b2++; //If list2 index is bigger, assign it to list3 and move on to the next index in list2
        }
        b3++; //Regardless of whether list1 or list2 index is assigned, list3 moves on to its next index
    }

    /*In the event that sizes of list1 and list2 are different, there will be extra digits left over in the larger list
    after the loop has terminated (since it terminates when the max size of the smaller list has been reached
    Thus, the next two loops are required in order to reassign any remaining elements into list3*/

    while (b1 < size1){ //Assigns any remaining elements from list1 into list3
        list3[b3] = list1[b1];
        b1++;
        b3++;
    }

    while (b2 < size2){ //Assigns any remaining elements from list2 into list3
        list3[b3] = list2[b2];
        b2++;
        b3++;
    }

}

// Print values of a list
void print_list(int list[], int size) {

    int c;

	printf("Merged list: [");

	for (c = 0; c < size; c++){
        printf ("%d", list[c]);
        if (c == size - 1){
            printf ("]\n"); //For the last index, don't print the comma and print a ] instead
            break;
        }
        printf (", ");
	}
}

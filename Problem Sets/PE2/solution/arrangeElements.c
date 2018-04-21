/*
 * CS1010E AY2017/8 Semester 2
 * PE2 Ex1: arrangeElements.c
 * 
 * This program re-arrangement the elements in a 1-dim 
 * integer array such that negative integers are placed 
 * on the left side of the array, and non-negative integers
 * are placed on the right side. The relative ordering of 
 * the elements for each category (negative or non-negative)
 * in the resulting array remains the same as the original 
 * array
 * 
 * Author: Khoo Siau Cheng 
 */

#include <stdio.h>

#define ARRAY_SIZE 10

int initArr(int []) ;
void arrangeArr(int [], int) ;
void prtArr(int [], int) ;

int main(void) {
	int intList[ARRAY_SIZE], size ;

	size = initArr(intList) ;
	printf("Initial array: ") ;
	prtArr(intList, size) ;
	
	arrangeArr(intList, size) ;
	printf("\nAfter re-arranging, the array is: \n") ;
	prtArr(intList, size) ;

	return 0 ;
}

/* 
   Initializing the array and the array size
*/
int initArr(int arr[]) {
	int i, size ;

	printf("Enter the array size: ") ;
	scanf("%d", &size) ;

	printf("Enter %d integers into the array: ", size) ;
	for (i = 0 ; i < size ; i++) {
		scanf("%d", &arr[i]) ;
	}
	return size ;
}

/*
   Re-arrange the elements in the array. Negative elements
   are placed on the left, and non-negative on the right of 
   the array. This function does not make use of additional 
   array or function to perform the job of re-arrangement. 
*/
void arrangeArr(int array[], int size) {
	int unSatHead ;
	int index, i, elt ;
	
	unSatHead = 0 ; // beginning of the non-negative part

	for (index = 0; index < size ; index++) {
		if (array[index] < 0) { 
			/* 
			found one negative integer
		   	move it to before the non-negative segment
			and place the newly found negative integer
			to just before the non-negative segment.
			*/
			elt = array[index] ;
			for (i = index ; i > unSatHead ; i--) {
				array[i] = array[i-1] ;
			}
			array[i] = elt ; 
			/*
			update the beginning of the non-negative
			segment
			*/
			unSatHead++ ; 
		} 
	}
}

/*
   Display the content of the array
*/
void prtArr(int arr[], int size) {
	int i ;
	printf("[ ") ;
	for (i = 0 ; i < size-1 ; i++) {
		printf("%d, ", arr[i]) ;
	}
	printf("%d ].\n", arr[size-1]) ;
}

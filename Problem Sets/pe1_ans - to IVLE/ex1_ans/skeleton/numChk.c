/*
   CS1010E AY2017/18 Semester 2
   PE1 Ex1: numChk.c

	Name:
	Matriculation Number:
	PLab Account ID:
	Tutorial Group Number:
	Description: 
 */

#include <stdio.h>

void numChk(int, int, int) ;
int  maxDist(int, int) ;
int  sumDigits(int) ;

/*
   <Enter description here.>
 */
int main(void) {
	/* do not modify the code in this function */
	int low, count, max ;
	printf("Enter the starting number: ") ;
	scanf("%d", &low) ;
	printf("Enter the range: ") ;
	scanf("%d", &count) ;
	printf("Enter the maximum distance "
			"allowed between two digits: ") ;
	scanf("%d", &max) ;

	numChk(low, count, max) ;

	return 0 ;
}

/* 
   numChk(num,range,maxD) Function 
   <Enter the description here>

*/

void numChk(int num, int range, int maxD) {
	/* Enter your code here */	

	printf("Number of numbers only with max distance of %d is: %d.\n",) ; 
}

/*
   maxDist(num,dist) function
   <Enter your description here>
*/
int maxDist(int num, int dist) {
	/* Enter your code here */
}

/*
   sumDigits(num) function
   <Enter your description here>
*/
int sumDigits(int num) {
	/* Enter your code here */
}


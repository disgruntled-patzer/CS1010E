/*
   CS1010E AY2017/18 Semester 2
   PE1 Ex2: altSum.c

   Name:
   Matriculation Number:
   PLab Account ID:
   Tutorial Group Number:
   Description: 
*/
include <stdio.h>

int altSum (int, int, int) ;
int altFold (int, int, int, int) ;

int main(void) {
	/* Do not modify the code in this function body */
	int start, dist, numItems ;
	int sum ;

	printf("Please enter the value of the first item of the AP: ") ;
	scanf("%d", &start) ;
	printf("What are the difference between two adjacent items? ") ;
	scanf("%d", &dist) ;
	printf("How many items are there? ") ;
	scanf("%d", &numItems) ;

	sum = altSum(start, dist, numItems) ;
	printf("The final alternating sum of the computation is %d.\n", sum) ;

	return 0 ;
}

/*
	altSum(start, diff, numItems) 
	<Enter your description here>	
*/
int altSum(int start, int dist, int numItems) {
	/* Enter your code here */
}

/*
	altFold(i, start, diff, numTimes) 
	<Enter your description here>	
*/
int altFold(int i, int start, int diff, int numItems) {

}


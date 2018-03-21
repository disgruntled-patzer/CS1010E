/*
   CS1010E AY2017/18 Semester 2
   PE1 Ex2: altSum.c

Name: Lau Yan Han
Matriculation Number: A0164750E
PLab Userid: plab0137
Tutorial Group Number: E23
Program Description: This program calculates sum of an alternating series
derived from the arithmetic progression

 */
#include <stdio.h>

int altSum(int, int, int) ;
int altFold(int, int, int, int) ;
int minus_one_calculate (int a, int b);

int main(void) {
	/* Do NOT modify the code in this function body */
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
   Calculates the sum of the alternating series
 */
int altSum(int start, int dist, int numItems) {

	int i, result = 0;

	for (i = 1; i <= numItems; i++){
		result = result + minus_one_calculate(i,1) * altFold (i, start, dist, numItems);
	}
	return result;
}

/*
   altFold(i, start, diff, numTimes)
   Calculates altFold for the altSum function
 */
int altFold(int i, int start, int diff, int numItems) {

	int j, result = 0;
	int a, b; //a = a(j), b = a (n - j + i)

	for (j = i; j <= numItems; j++){ //prod(i,j)
		if (j <= numItems - j + i){ //Checking conditions for prod (i,j)
			a = start + diff * (j-1); // a(j) = a1 + (j-1)*d
			b = start + diff * (numItems - j + i - 1); //a(n - j + i)
			result = result + minus_one_calculate(j,i)*(a * b);
			//printf ("%d ",result); //Debugging statement
		}
	}
	//printf ("%d\n",result); //Debugging statement
	return result;
}

int minus_one_calculate(int a, int b){

    if ( (a - b) % 2 == 0){
        return 1; //If exponential (given by a-b) is even, result is 1, otherwise result is -1
    }
    else {
        return -1;
    }
}

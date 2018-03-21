/*
   CS1010E AY2017/18 Semester 2
   PE1 Ex1: numChk.c

Name: Lau Yan Han
Matriculation Number: A0164750E
PLab Userid: plab0137
Tutorial Group Number: E23
Program Description: This program checks the validity of max-distance
and sum-digit conditions for a given range of numbers

 */

#include <stdio.h>
#include <stdlib.h>

void numChk(int num, int range, int maxD) ;
int  maxDist(int num, int dist) ;
int  sumDigits(int num) ;

int main(void) {
	/* do NOT modify the code in this function */
	int low, count, max ;
	printf("Enter the starting number: ") ;
	scanf("%d", &low) ;
	printf("Enter the range: ") ;
	scanf("%d", &count) ;
	printf("Enter the maximum distance allowed between two digits: ") ;
	scanf("%d", &max) ;

	numChk(low, count, max) ;

	return 0 ;
}

/*
   numChk(num,range,maxD) function
   This function performs the checks of sumDigit and maxDistance conditions
   for each digit within the range
 */
void numChk(int num, int range, int maxD) {

	int maxD_only = 0, sumD_only = 0, both = 0;
	//maxD_only is number of integers which only satisfy maxD condition
	//sumD_only is number of integers which only satisfy sumD condition
	//both is number of integers which satisfy both conditions
	int sumD_check, maxD_check;
	//sumD_check checks whether the sum of digits is divisible by 3 (sumD condition)
	//maxD_check checks the validity of the maxD condition
	int counter; //Used in the loop

	for (counter = num; counter < num + range; counter++){

		sumD_check = sumDigits (counter);
		maxD_check = maxDist (counter,maxD);
		//printf ("%d %d\n",sumD_check, maxD_check); //Debugging statement

		if ((sumD_check % 3 != 0) && (maxD_check == 1)){
			maxD_only++;
		}
		if (sumD_check % 3 == 0 && maxD_check != 1){
			sumD_only++;
		}
		if (sumD_check % 3 == 0 && maxD_check == 1){
			both++;
		}
	}

	printf("Number of numbers only with max distance of %d is: %d.\n",maxD,maxD_only) ;
	printf("Number of numbers only satifying sum-divide requirement is: %d.\n",sumD_only) ;
	printf("Number of numbers meeting both requirements is: %d.\n",both) ;
}

/*
   maxDist(num,dist) function
   This function tests whether any number satisfied the maxDist condition
 */
int maxDist(int num, int dist) {

    int max = num%10, min = num%10;
    //max will store largest digit in num, min will store smallest digit in num. Both are initialized as last digits of num for now

    int i = num%10;
    //i = counter that will run through the digits of num, test them and assign them to max/min. It is initialized as the last digit of num

    do {
        if (i > max){ //If i is larger than max, then the digit max is holding is not largest, thus update accordingly
            max = i;
        }
        if (i < min){ //If i is smaller than min, then the digit min is holding is not smallest, thus update accordingly
            min = i;
        }
        num = num/10;
        i = num%10; //Update num and shift i to the next digit in num
    }
    while (num > 0);

    if ((max - min) > dist){ //Once max and min are finalized, find the distance between them and test the MaxDist condition
        return 0;
    }
    else {
        return 1;
    }

}

/*
   sumDigits(num) function
   This program sums the number of digits in the number
 */
int sumDigits(int num) {

	int sum = 0;

	while (num > 0){
		sum = sum + num%10;
		num = num/10;
	}
	return sum;
}

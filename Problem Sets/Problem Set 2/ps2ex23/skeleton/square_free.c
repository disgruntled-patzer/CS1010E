// CS1010E Programming Methodology
// Problem Set 2 Exercise #23: square_free.c
//
// This program calculates the number of square-free integers within two given ranges, and determines which range has more square-free integers
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

int num_square_free(int lower, int upper);
int is_square_free(int num);
int test_square (int num);

int main(void) {

    int lower1, upper1, lower2, upper2; //The lower and upper bounds of 1 and 2
    int range1, range2; //The number of square-free integers for 1 and 2 respectively

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	range1 = num_square_free(lower1,upper1);
	range2 = num_square_free(lower2,upper2);

	if (range1 > range2){
        printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, range1);
	}

	else if (range1 == range2){
        printf("Both ranges have the same number of square-free numbers: %d\n",range1);
	}

	else{
	    printf("Range [%d, %d] has more square-free numbers: %d\n",lower2, upper2, range2);
	}

	return 0;
}

// num_square_free counts the number of square free integers
int num_square_free(int lower, int upper) {

    int a;
    int counter = 0;

    for (a = lower; a <= upper; a++){

        if (is_square_free(a) == 1){ //If any number in the range is square free, add 1 to counter
            counter++;
        }

    }

	return counter; //Return the final count
}

// is_square_free tests whether a number is square free
int is_square_free(int num) {

    int b;
    for (b = 1; b <= num; b++){

        if (b != 1 && num%b == 0 && test_square(b) == 1){
            return 0; //Return FALSE; num is not square free
        }

    }

	return 1; //If loop is completed without returning 0, number is square free so return TRUE
}

int test_square(num){

    int c;

    c = sqrt(num); //sqrt() is a function for float/double values.
    //If a square integer undergoes sqrt, it returns a double that remains the same even when converted to int
    //If a non-square integer undergoes sqrt, converting it back to int will change the value!

    if (c*c == num){ //Hence, for non-square integers, c is an inaccurate value and squaring it will NOT give num
        return 1; //Number is perfect square if squaring c gives num (aka temp is accurate)
    }
    else {
        return 0;//If c is inaccurate, number is not square
    }
}

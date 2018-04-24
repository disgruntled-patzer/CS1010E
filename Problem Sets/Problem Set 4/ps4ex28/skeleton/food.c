// CS1010E Programming Methodology
// Problem Set 4 Exercise #28: food.c
//
// This program computes the number of ways to
// have fast-food meals and health-food meals
// out of n meals.
//
// Lau Yan Han

#include <stdio.h>

int enumerate(int n);

int main(void) {

	/** main function is complete **/

	int n;

	printf("Enter total number of meals: ");
	scanf("%d", &n);

	printf("Number of combinations = %d\n", enumerate(n));

	return 0;
}

// Compute the number of ways to take the n meals
// provided NO two consecutive fast-food meals.
int enumerate(int n) {

    /*If we trace out the number of possible combinations for low values of n, we see a pattern:
    Number of possible combinations is just the Fibonacci sequence, with 2 and 3 as starting digits
    i.e. instead of 1,1,2,3,5,8,13... instead it is 2,3,5,8,13...*/

	if (n == 1){
        return 2; //Base case 1
	}
	else if (n == 2){
        return 3; //Base case 2
	}
	else {
        return enumerate (n - 1) + enumerate (n - 2);
	}
}

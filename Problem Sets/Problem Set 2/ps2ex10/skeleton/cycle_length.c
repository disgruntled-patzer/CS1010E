// CS1010E Programming Methodology
// Problem Set 2 Exercise #10: cycle_length.c
//
// Find the number of Collatz iterations needed for every integer in a given range and return the max
//
//
// Lau Yan Han

#include <stdio.h>

int count_iterations(int num);
int get_max_cycle_length(int low, int high);

int main(void) {

    int low, high;

	printf("Enter range: ");
	scanf("%d %d", &low, &high);
	printf("Maximum cycle length = %d\n",get_max_cycle_length(low,high));

	return 0;
}

// Counts the number of iterations required for a number to reach 1 via the Collatz problem
int count_iterations(int num) {

    int counter = 0;

    while (num != 1){ //When the number is not 1 (break out of loop and return counter = 0 when number is 1)

        if (num%2 == 0){ //If else statement performs Collatz problem, tests for odd/even
            num = num/2;
        }
        else {
            num = 3 * num + 1;
        }

        counter++; //increment 1 to counter at the end of each iteration

    }

	return counter;
}

// Find the max cycle length (number of Collatz iterations) among a range of numbers
int get_max_cycle_length(int low, int high) {

    int a, max_cycle;

    for (a = low; a <= high; a++){
        if (a == low){
            max_cycle = count_iterations(a); //Starting point: Set max_cycle to number of iterations in first integer
        }
        else if (count_iterations(a) > max_cycle){ //If a has more iterations than a - 1, use the new number a
            max_cycle = count_iterations(a);
        }
    }

	return max_cycle;
}

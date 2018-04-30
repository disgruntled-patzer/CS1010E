// CS1010E Programming Methodology
// Problem Set 3 Exercise #11: sieve.c
//
// This program implements Sieve of Eratosthenes,
// which is used to check if a given number is
// prime or not.
// It use preprocessing to figure out all prime
// numbers and answer queries by looking up
// the array constructed.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>
#define SIZE 10000

void initialize(int arr[]);
void preprocess(int arr[]);

int main(void) {

	int num, arr[SIZE+1];

	initialize(arr);

	preprocess(arr);

	printf("Pre-processing ready, "
			"enter values (0 to stop):\n");

	scanf("%d", &num);
	while (num > 0) {
		if (arr[num] == 1) {
			printf("prime\n");
		} else {
			printf("not prime\n");
		}
		scanf("%d", &num);
	}

	return 0;
}

// Initialize all slots to 1
void initialize(int arr[]){

	int m;

	for (m = 0; m <= SIZE; m++){
        arr[m] = 1;
	}

}

// Pre-process and determine all prime numbers
void preprocess(int arr[]) {

	int m, n; //Loop counters

	for (m = 2; m <= ceil(sqrt(SIZE)); m++){ //Start from 2 instead of 1, since all prime numbers are divisible by 1 anyway
        //ceil(sqrt(SIZE)) is to optimize runtime: Any number above that, when multiplied by 2, will already be above 10000 so no point checking those
        n = m;
        if (arr[n] == 1){ // Assign m to the next prime number in the array
            while (n <= SIZE){
                n = n + m; // Scan through all multiples of m (2 * m, 3 * m all the way to k * m where k * m < 10000)
                if (n > SIZE){
                    break; // if n exceeds the array size, break to avoid array overflow
                }
                arr[n] = 0; // Assign all multiples of m to be zero
            }
        }
        //Note: Do update of n before comparison and assigning, so that m itself (which is prime) doesn't get assigned to "not prime" by mistake
	}

}

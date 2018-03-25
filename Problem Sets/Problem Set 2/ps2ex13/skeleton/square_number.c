// CS1010E Programming Methodology
// Problem Set 2 Exercise #13: square_number.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

int is_integer (int n);

int main(void) {

	int n, result;

	printf("Enter an integer: ");
	scanf ("%d",&n);

	result = is_integer (n);

	if (result == 1){
		printf("%d is a square number\n",n);
	}
	else {
		printf("%d is not a square number\n",n);
	}

	return 0;
}

int is_integer (int n){

	int counter = 2;

	if (n == 1){
		return 1;
	}

	while (counter < n){
		if (n % counter == 0 && (n/counter) == counter){
			return 1;
		}
		counter++;
	}
	return 0;
}

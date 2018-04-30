// CS1010E Programming Methodology
// Problem Set 2 Exercise #04: perfect_number.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

    int num, divisors = 0, i;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	for (i = 1; i < num; i++){
        if (num == 1){
            break;
        }
        if (num % i == 0){
            divisors = divisors + i;
        }
	}

    if (num != 1 && num == divisors){
        printf("%d is a perfect number.\n", num);
    }
    else {
        printf("%d is not a perfect number, its sum of proper divisors is %d.\n", num, divisors);
    }

	return 0;
}

// CS1010E Programming Methodology
// Problem Set 2 Exercise #25: prime_product.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

void factorize_prime (int num);

#include <stdio.h>

int main(void) {

    int num;

	printf("Enter integer: ");
	scanf("%d",&num);

	factorize_prime(num); //To print the result for us
	printf ("\n");

	return 0;
}

void factorize_prime (int num){

    int factor = 2;

    if (num > 0){ //This if-else statement takes into account whether the number is positive or negative
        printf ("%d = 1",num);
    }
    else {
        num = num/(-1);
        printf ("-%d = -1",num);
    }

    while (factor <= num){

        if (num%factor == 0){
            num = num/factor;
            printf (" * %d",factor);
        }
        //When the number has a factor, divide the number by the factor and then
        //Test whether the result is still divisible by the factor
        else {
            factor++; //If at any point the number is no longer divisible by the factor, increase factor by 1 and test again
        }

    }

}

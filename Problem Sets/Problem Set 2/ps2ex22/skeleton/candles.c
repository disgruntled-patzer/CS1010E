// CS1010E Programming Methodology
// Problem Set 2 Exercise #22: candles.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int number_of_candles (int n, int k);

int main(void) {

	int n, k;

	printf("Enter n, number of candles: ");
	scanf ("%d",&n);

	printf("Enter k, number of residuals to make a new candle: ");
	scanf ("%d",&k);

	printf("Peter will burn this number of candles: %d\n",number_of_candles(n,k));

	return 0;
}

int number_of_candles (int n, int k){

	int result = n;

	while (n >= k){
		result = result + (n / k); //n / k = number of new candles formed
		n = (n / k) + (n % k); //Update n to be used for the next loop; n&k = leftover candles after new candles are made
		//When n < k, no more candles can be made
	}
	//When n is no longer greater than k , exit loop

	return result;
}

// CS1010E Programming Methodology
// Problem Set 1 Exercise #06: coins.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

    int coins[6] = {1, 5, 10, 20, 50, 100};
    int i = 5; //Loop counter, start at the end of the coins array
    int amount, amount2 = 0, numcoins = 0;
    //amount = user input amount, amount2 calculates number of coins with reference to 'amount', numcoins = min number of coins

	printf("Enter amount in cents: ");
	scanf("%d", &amount);

	while (amount2 < amount){
        amount2 = amount2 + coins[i]; //Keep adding coins of denomination coins[i] to amount2 until it hits amount1
        numcoins++;
        if (amount2 == amount){ //If a combination of coins can be found that matches the amount, break from loop
            break;
        }
        if (amount2 > amount){
            amount2 = amount2 - coins[i];
            numcoins--; //If the amount2 exceeds the user input amount, remove the coin value previously added
            i--; //And decrease the denomination by 1 to add a smaller coin value in subsequent iterations
        }
	}

	printf("Minimum number of coins needed: %d\n", numcoins);

	return 0;
}

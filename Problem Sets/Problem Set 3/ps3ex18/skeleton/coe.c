// CS1010E Programming Methodology
// Problem Set 3 Exercise #18: coe.c
//
// This program calculates COE final price for a month.
//
// Lau Yan Han

#include <stdio.h>
#define MAX 5000

void print_bids(int bids[], int size);
void sort(int bids[], int size);
int compute_coe(int bids[], int size, int num);

// main is complete and given
int main(void) {

	int i, num_coe, bids[MAX], num_bids, coe_val;

	printf("Enter the number of available COEs: ");
	scanf("%d", &num_coe);

	printf("Enter the number of bids: ");
	scanf("%d", &num_bids);

	printf("Enter %d bids: ", num_bids);
	for (i = 0; i < num_bids; i++) {
		scanf("%d", &bids[i]);
	}

	sort(bids, num_bids);

	// for debugging
	//print_bids(bids, num_bids);

	coe_val = compute_coe(bids, num_bids, num_coe);

	printf("COE final price this month is $%d\n", coe_val);

	return 0;
}

// Print out the bids
// Complete and given
void print_bids(int bids[], int size) {

	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", bids[i]);
	}
	printf("\n");
}

// Sort bids in descending order
void sort(int bids[], int size) {

    int i, swapped, temp; //Variables used in Bubble Sort Algorithm
    int limit = size; //Initial limit = size, it will decrease by 1 for each iteration

    do { //Enhanced Bubble sort algorithm
        swapped = 0;
        for (i = 1; i < limit; i++){
            if (bids [i-1] < bids [i]){ //NOTE: Sort in DESCENDING order, not ascending
                temp = bids [i-1];
                bids [i-1] = bids [i];
                bids [i] = temp;
                swapped = 1;
            }
        }
        limit--; //Since the smallest entry has been sorted to the rightmost side, reduce the limit by 1 for the next iteration
    } while (swapped == 1);

}

// Return the final COE value
//Precondition: bids [] is already sorted in DESCENDING order
int compute_coe(int bids[], int num_bids, int num_coe) {

    int candidate_price, final_price = 0;
    int a;

    if (num_coe == num_bids){ //If the number of bids = number of coe, everyone gets the coe (yay!)
        final_price = bids [num_coe - 1];
        return final_price;
        //There is no need to compare candidate price since number of bids exceeding final price cannot be more than number of coe
    }

    //If number of bids lesser than number of coe, go through the rest of the function to calculate candidate/final price
    candidate_price = bids [num_coe - 1]; //Candidate price is the price of the nth highest bid (n = number of coe)

    if (bids [num_coe] == candidate_price){
        //If the next entry in bids[] is equal to candidate price, this means that number of bids that >= candidate price is more than number of coe
        for (a = num_coe - 1; a >= 0; a--){ //Sort through the previous entries (which hold the larger bid values)
            if (bids[a] > candidate_price){ //The moment a larger bid value is found, assign it to final price and break
                final_price = bids[a];
                break;
            }
        }
    }
    else { //If number of bids >= candidate price is not more than number of coe, then final price is just candidate price
        final_price = candidate_price;
    }

	return final_price; // stub
}

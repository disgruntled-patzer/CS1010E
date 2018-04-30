// CS1010E Programming Methodology
// Problem Set 3 Exercise #10: soft_toys.c
//
// This program checks on which day Kitty
// is able to collect all 5 types of soft
// toys or she is unable to do it.
//
// Lau Yan Han

#include <stdio.h>
#define SIZE 100

int which_day(int types[], int size);

int main(void) {

    int days, i, types[SIZE]; //days = number of days campaign lasts, i = loop counter, types = array containing types of toys on each day
    int whichday; // Which day will Kitty be able to collect all her toys, return -1 if impossible

	printf("How long will the campaign last: ");
	scanf("%d", &days);

	printf("Enter type of toys in each day: ");
	for (i = 0; i < days; i++){
        scanf("%d", &types[i]);
	}

	whichday = which_day(types, days);

    if (whichday == -1){
        printf("Kitty is unable to collect all types of toys\n");
    }
    else {
        printf("Kitty is able to collect all types of toys on day %d\n", whichday);
    }

	return 0;
}

// Return the day on which Kitty is able to
// collect all 5 types of soft toys, or -1 if
// she is unable to do so before the campaign ends
int which_day(int types[], int size) {

    int day = 0, toys[5] = {0}; //day returns number of days required to collect all 5 toys, 'toys' array tracks which toy Kitty has collected
    int count = 0; //This counts the number of toys collected so far. It must reach 5 for Kitty to get all toys
    int i; //Loop counter

    while (day < size){
        if (toys[types[day] - 1] == 0){ //If kitty hasn't collected the toy available on a certain day (note day - 1 because arrays run from 0 to n - 1)
            toys[types[day] - 1]++; //Then mark the toy as 'collected'
            count++; //Also track the number of toys that have been collected so far
        }
        if (count == 5){
            break; //Once Kitty is able to get all 5 toys, exit from the loop
        }
        day = day + 2; //Kitty will come back every OTHER day, thus increment day by 2 instead of 1 for the next iteration
    }

    if (count < 5){
        day = -1; //If Kitty hasn't collected all 5 toys after campaign ends, return -1
    }

	return day;  // stub
}

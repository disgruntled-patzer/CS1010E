// CS1010E Programming Methodology
// Problem Set 3 Exercise #14: rabbit_jump.c
//
// A bunny can jump at most 50 centimetres.
// It needs to cross a river, with rocks
// positioned in a straight line in the river.
// This program computes the minimum number
// of jumps for the rabbit to cross to the
// other side of the river.
//
// Lau Yan Han

#include <stdio.h>
#define N 50

int count_jumps(int rocks[], int num_rocks);

int main(void) {

    int rocks[N] = {0}, num_rocks; //num_rocks = number of rocks, rocks[] stores the rock positions
    int a; //Used in the loop
    int num_jumps; //Number of jumps needed

	printf("Enter the number of rocks: ");
	scanf("%d", &num_rocks);

	printf("Enter locations of  rocks: ");
	for (a = 1; a < num_rocks + 1; a++){ //The entry rocks[0] holds zero, which is the starting point of the rabbit
        scanf("%d", &rocks[a]);
	}

	num_jumps = count_jumps(rocks, num_rocks);

	if (num_jumps == -1){
        printf("Impossible\n");
	}
	else {
        printf("%d jumps\n", num_jumps);
	}

	return 0;
}

// Count the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
int count_jumps(int rocks[], int num_rocks) {

    int i, j; //Loop counters, i is the starting rock for each jump and j calculate the ending rock
    int num_jumps = 0; //Number of jumps, intialize to 0

    i = 0; //Intialize i to zero for the first jump (at starting position 0)

    while (i <= num_rocks){ //Note: Not (i < num_rocks) because there are num_rocks + 1 (the starting position) entry

        if (i == num_rocks){ //If rabbit has already reached the other side of the river
            return num_jumps;
        }

        j = i + 1; //Assign j as the next rock (after the starting rock i)

        if ((rocks[j] - rocks[i]) > 50){
            return -1; //At any point if the distance betweeen adjacent rocks > 50, rabbit cannot jummp
        }

        //If jump is possible, enter the next loop which seeks to minimize the number of jumps
        while (j <= num_rocks && (rocks[j] - rocks[i]) <= 50){
            j++; //While the distance between the rocks is less than 50 and j doesn't exceed the number of rocks, move j to the next rock
        } //Once the distance becomes more than 50, exit the loop (because distance is too far)

        j--; //Reset j to the previous rock when it was still less than 50
        i = j; //Update the starting rock (i) to the newly calculated ending rock for the next iteration
        num_jumps++; //Update num_jumps before proceeding to the next iteration of i
    }

	return num_jumps; // stub
}

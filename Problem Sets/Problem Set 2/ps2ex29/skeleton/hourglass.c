// CS1010E Programming Methodology
// Problem Set 2 Exercise #29: hourglass.c
//
// No
//
//
// Lau Yan Han

#include <stdio.h>

int count_flips(int hg1, int hg2, int time, int *flip1_p, int *flip2_p);

int main(void) {

	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int flips1, flips2;  // number of flips needed for hourglasses
	int possible; //Check whether it is possible or not to achieve the desired time (1 if possible, 0 if not)

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg1, &hg2, &time);

    possible = count_flips(hg1, hg2, time, &flips1, &flips2);

    if (possible == 0){
        printf("Impossible!\n");
    }
	else {
        printf("%d flip(s) for %d-minute hourglass and %d flip(s) "
               "for %d-minute hourglass.\n", flips1, hg1, flips2, hg2);
	}

	return 0;
}

// Counts the number of flips required to reach the desired time, and whether it is possible to do so
int count_flips(int hg1, int hg2, int time, int *flip1_p, int *flip2_p) {

    int time_temp = time; //The total price which will be used to run the loop
    int possible = 0; //Checks whether it is possible to achieve the desired time (returns 1 if possible, 0 if not)

    /*This data set is used to temporarily store values returned from the loop.
    At the end of the loop, it will return the minimum number of slips*/
    int total_flips_temp = -1; //Total number of slips required. This is initialized to -1 to provide a starting condition for the loop
    int flip1_temp = 0, flip2_temp = 0; //flip1_temp = flips required for hourglass 1, flip2_temp = hourglass 2

    /*This data set is similar to the temp one but is used to run the loops, before being used to compare with the temp set*/
    int total_flips_loop;
    int flip1_loop = 0, flip2_loop; //Initialize number of flips in hourglass 1 to be zero as a starting point
    int time1_loop = flip1_loop * hg1; //time1_temp = total time taken for hourglass 1 (based on number of flips)

    while (time1_loop <= time){
        if ((time - time1_loop) % hg2 != 0){
            //Calculate number of flips required by hourglass 2 based on a given number of flips by hourglass 1
            //If this number of flips generates a remainder, there is no solution for the current number of hourglass 1 flips
            flip1_loop++;
            time1_loop = flip1_loop * hg1;
            continue; //Thus, update number of hourglass 1 flips by 1, and skip to the next iteration
        }
        else {
            flip2_loop = (time - time1_loop) / hg2; //If there is no remainder, assign hourglass 2 flips accordingly
            total_flips_loop = flip1_loop + flip2_loop;
            possible = 1; //Since there is no remainder, a solution exists for the total time, thus it is possible
        }

        /*The next set of if-else statements compare the 'loop' data set with 'temp' data set
        to check whether there is a minimum number of flips available.
        There are 2 cases where 'temp' data set needs to be updated:
        1. If nothing has been assigned to 'temp' yet (and total_flips_temp is still -1)
        2. If the number of flips in 'loop' data set is smaller than the 'temp' set*/
        if (total_flips_temp == -1 || total_flips_loop < total_flips_temp){
            total_flips_temp = total_flips_loop;
            flip1_temp = flip1_loop;
            flip2_temp = flip2_loop;
        }

        flip1_loop++;
        time1_loop = flip1_loop * hg1; //Increment flip1_loop by 1 and update time1_loop for the next iteration
    }
     //After exiting loop, flip1_temp and flip2_temp contain the optimal number of flips for hourglass 1 and 2, thus return them via pointers
    *flip1_p = flip1_temp;
    *flip2_p = flip2_temp;
    /*In the event that possible = 0, flip1_temp and flip2_temp will be holding zero values which they were initialized with
    This is to prevent the pointers from pointing to any uninitialized variables which might be a problem*/

	return possible;  // Return whether it is possible to find a solution
}

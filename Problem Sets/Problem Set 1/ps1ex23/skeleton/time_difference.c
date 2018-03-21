// CS1010E Programming Methodology
// Problem Set 1 Exercise #23: time_difference.c
//
// This program calculates the time difference between two different time inputs
//
//
// Lau Yan Han

#include <stdio.h>

struct time {
    int hr;
    int min;
    int sec;
};

int calculate_min_or_sec (int time1, int time2, int *timeptr);

int main(void) {

    struct time time1;
    struct time time2;
    struct time time_diff;

    scanf("%d %d %d",&time1.hr,&time1.min,&time1.sec);
    scanf("%d %d %d",&time2.hr,&time2.min,&time2.sec);

    time_diff.hr = time2.hr - time1.hr;
    time_diff.min = calculate_min_or_sec(time1.min,time2.min,&time_diff.hr);
    time_diff.sec = calculate_min_or_sec(time1.sec,time2.sec,&time_diff.min);

	// Hint: use %02d to print out an integer in two positions
	// e.g., 8 will be print out as 08
	printf("Time difference: %02d:%02d:%02d\n",time_diff.hr,time_diff.min,time_diff.sec);

	return 0;
}

//Higher order function used to calculate min/sec difference
int calculate_min_or_sec (int time1, int time2, int *timeptr){
    //Use hrs and mins as an example: time1.min value in time1, time2.min value in time2, time_diff.h pointed to by *timeptr

    int time_diff; //Calculate difference in minutes depending on two possible cases

    if (time2 < time1){ //If min of time 2 is less than time1, modify the hour difference to decrease by 1 (using *timeptr)
        *timeptr = *timeptr - 1;
        time_diff = (60 - time1) + time2; //Then the minute difference is calculated using this formula
    }
    else{
        time_diff = time2 - time1; //If min of time 2 is more than time1, do normal subtraction, no need to modify hour difference
    }

    return time_diff;
}

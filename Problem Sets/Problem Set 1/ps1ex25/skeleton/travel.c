// CS1010 Programming Methodology
// Problem Set 1 Exercise #25: travel.c
//
// (CS1101J AY2014/15 Sem1 PE1 Ex#2)
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

double compute_original_fare(int id, int num_stations);
double compute_final_fare(double fare, int day, int dest,
		int hour, int min);

int main(void) {

    int id; int num_stations; //For calculating original fare (take into account only ID and no. of stations)
    int day, dest, hour, min; //For calculating final fares (taking into account day, time and exiting station)
    double fare, final_fare; //Original and final fares

	printf("Enter your identity (0 for adult, 1 for student): ");
    scanf ("%d",&id);

	printf("Which day did you travel? "); // 1 - 5 for weekday, 6 or 7 for weekend
    scanf ("%d",&day);

	printf("How many stations did you travel? "); // an integer between 1 - 15
    scanf("%d",&num_stations);

	printf("Where did you alight the train? NE "); // destination station to alight
	scanf("%d",&dest);

	printf("What time did you alight (hour min)? "); // time to alight
	scanf("%d %d",&hour, &min);

	fare = compute_original_fare(id,num_stations);
	final_fare = compute_final_fare(fare,day,dest,hour,min);

	printf("Original fare = $ %.3lf\n",fare);

	printf("Final fare = $ %.3lf\n",final_fare);

	return 0;
}

// Compute the original fare for certain number of stations
// 'id' means adult or student;
// 'num_stations' is the number of stations travelled
double compute_original_fare(int id, int num_stations) {

    double default_fare;

    switch (num_stations){ //This switch-case stateent calculates the fare based on the number of stations travelled
        case 1:
            default_fare = 0.87; //If no. of stations travelled is 1, fare is 0.87, and so on
            break;
        case 2: case 3:
            default_fare = 0.92;
            break;
        case 4: case 5:
            default_fare = 1.23;
            break;
        case 6: case 7:
            default_fare = 1.48;
            break;
        case 8: case 9: case 10:
            default_fare = 1.62;
            break;
        case 11: case 12: case 13: case 14: case 15:
            default_fare = 1.86;
            break;
        default: //If user inputs something out of range, use 15 stations by default (otherwise it will return error)
            //printf("Invalid entry. Assume 15 stations by default.\n");
            default_fare = 1.86;
            break;
    }

    if (id == 1) { //If user is a student, return the discounted fare
        return default_fare * 0.6;
    }
    else { //Otherwise, return the normal fare
        return default_fare;
    }

}

// Compute the final fare under the "Free MRT Rides" scheme
// 'fare' is the original fare; 'day' means weekday or weekend;
// 'dest' is the station to alight;
// 'hour' and 'min' are the alighting time
double compute_final_fare(double fare, int day, int dest, int hour, int min) {

    switch (day){
        case 1: case 2: case 3: case 4: case 5: //If user inputs weekday, go to the next test (exiting station)
            switch (dest){ //Test for destination is another nested switch case statement!
                case 4: case 5: case 6: //If user exits at NE4, NE5, NE6, discounts come into play
                    if ((hour < 7) || ((hour == 7) && (min < 45))){ //If user exits before 7.45am, fare is ZERO!
                        return 0; //The Boolean statement reads: if (1) Hour is less than 7, OR (2) Hour is 7 AND min is less than 45
                    }
                    else if (((hour < 8) && (min >=45) && (min <= 59)) || ((hour == 8) && (min == 0))){//If user exits before 8am but after 7.45, 50cent discount
                        //The Boolean statement reads: if (1) Hour is less than 8 (aka hour = 7), and min is greater than 45 and less than 59, OR (2) Hour is 8 and min is 00
                        //Note that don't need to include hour > 7 since that is taken care of in the first if statement
                        return fare - 0.5;
                    }
                    else { //For any other time, there is no discount
                        return fare;
                    } //End of the nested if-else statement that tests for exit time
                default: //If user exits at any other station, return the original fare
                    return fare;
            } //End of switch-case statement for exiting statement
            break; //Here, the switch-case statement for weekday-weekend continues
        case 6: case 7: //If user inputs weekend, then no discounts, return original value
            return fare;
            break;
        default: //To prevent errors, assume a weekend if user input is out of range
            //printf("Invalid entry, assume weekend by default\n");
            return fare;
    }
}

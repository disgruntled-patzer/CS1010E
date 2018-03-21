// CS1010E Programming Methodology
// Problem Set 2 Exercise #28: car.c
//
// This program returns the final odometer value, average trip distance and max difference in distance
//
//
// Lau Yan Han

#include <stdio.h>
#include <stdlib.h>

void compute_statistics(double *odometer_p, int trips,
		double *avg_dist_p, double *max_diff_p);

int main(void) {

    double odometer;
    int trips;
    double average_dist, max_diff;

	printf("Initial odometer value: ");
	scanf("%lf", &odometer);

	printf("Number of trips today: ");
	scanf("%d", &trips);

	compute_statistics (&odometer, trips, &average_dist, &max_diff);

	// print result here
	printf("Final odometer value: %.1f\n", odometer);
	printf("Total number of trips: %d\n", trips);
	printf("Average distance per trip: %.1f\n", average_dist);
	printf("Maximum difference between two consecutive trips: %.1f\n", max_diff);

	return 0;
}

// <Replace this with a short function description>
void compute_statistics(double *odometer_p, int trips,
		double *avg_dist_p, double *max_diff_p) {

	int a; //Counter used to run the loop
	double trip_temp = 0.0; //Scans the distance for each trip into a temporary variable
	double trip_previous; //Distance of trip previous to trip_temp
	double consecutive_distance_temp; //Temporary holding variable for consecutive trip distance
	double max_consecutive_distance = 0.0; //Max consecutive trip distance
	double trip_total = 0.0; //Trip_total = total trip distance

	for (a = 1; a <= trips; a++){
        if (a > 1){
            trip_previous = trip_temp; //For second trip onwards, assign trip_previous before trip_temp gets updated
        }
        printf("Distance for trip %d: ", a);
        scanf ("%lf", &trip_temp);
        if (a == 1){
            trip_previous = trip_temp; //For first trip, trip_previous is the same as trip_temp
        }

        if (trip_temp > trip_previous){ //This if-else loop calculates the absolute distance between trip_temp and trip_previous
            consecutive_distance_temp = trip_temp - trip_previous;
        }
        else {
            consecutive_distance_temp = trip_previous - trip_temp;
        }

        if (max_consecutive_distance < consecutive_distance_temp){
            max_consecutive_distance = consecutive_distance_temp;
        } //Compare distance between consecutive trips with max_consecutive distance and update if neeeded

        trip_total = trip_total + trip_temp; //Update the total distance travalled
	}

    *max_diff_p = max_consecutive_distance; //Maxiimum distance between trips

    if (trips == 0){//Average distance between trips
        *avg_dist_p = 0.0;
    }
    else{
       *avg_dist_p = trip_total / trips;
    }

    *odometer_p = *odometer_p + trip_total; //Absolute distance travelled + initial odometer value (before reset)

    while (*odometer_p > 999.9){ //If the odometer reading is greater than 999.9
        *odometer_p = *odometer_p - 999.9 - 0.1; //Keep resetting the reading until it is less than 999.9
        /*Note the + 0.1 because when odometer reaches 999.9 and resets to 000.0, it "loses" 0.1
        e.g. For 1000.0, the final odometer reading is 000.0 after it resets
        Which can only be reached if we add 0.1 after subtracting 999.9*/
    }

}

// CS1010 Programming Methodology
// Problem Set 1 Exercise #08: speed.c
//
// Calculating the Speed of Sound for a given temperature
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

// function prototype
double speed_of_sound(double temperature);

// main function is complete
int main(void) {

	double ans, temperature;

	printf("Temperature in degree Fahrenheit: ");
	scanf("%lf", &temperature);

	ans = speed_of_sound(temperature);
	printf("Speed = %.2f ft/sec\n", ans);

	return 0;
}

// Return speed of sound given temperature
double speed_of_sound(double temperature) {

	return 1086*sqrt((5*temperature+297)/247); // Calculates speed of sound
}

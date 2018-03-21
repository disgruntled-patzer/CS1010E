// CS1010E Programming Methodology
// Problem Set 1 Exercise #12: travel.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

struct coords{
    double x;
    double y;
    };

// function prototype
double distance(double x1, double y1, double x2, double y2);

int main(void) {

    struct coords home;
    struct coords office;
    struct coords ntuc;
    double total_distance;

	printf("Enter X Y coordinates for Home: ");
	scanf ("%lf %lf",&home.x, &home.y);

	printf("Enter X Y coordinates for Office: ");
	scanf ("%lf %lf",&office.x, &office.y);

	printf("Enter X Y coordinates for NTUC: ");
	scanf ("%lf %lf",&ntuc.x, &ntuc.y);

	total_distance = distance (home.x,home.y,office.x,office.y) + distance (office.x,office.y,ntuc.x,ntuc.y)
    + distance (ntuc.x,ntuc.y,home.x,home.y);

	printf("Distance of travel is %.2f\n", total_distance);

	return 0;
}

// Calculate distance between two points (x1, y1), (x2, y2)
double distance(double x1, double y1, double x2, double y2) {

	return sqrt(pow(x2 - x1 , 2) + pow (y2 - y1, 2));

}

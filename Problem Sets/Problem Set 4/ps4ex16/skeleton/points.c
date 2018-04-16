// CS1010E Programming Methodology
// Problem Set 4 Exercise #16: points.c
//
// This program reads a series of points
// and calculates the area of the minimum
// surrounding circle.
//
// <Replace this with your name>

#include <stdio.h>

#define PI 3.14159
#define MAX_NUM 10  // max number of points

typedef struct {
	int x, y;
} point_t;

int read_points(point_t pts[]);
double compute_circle_area(point_t pts[], int numPts);

int main(void) {

	int numPts;  // actual number of points read in
	double area;

	point_t pts[MAX_NUM];

	numPts = read_points(pts);

	area = compute_circle_area(pts, numPts);

	printf("Area of smallest circle = %.2f\n", area);

	return 0;
}

// Read points one by one and store into array.
// Return the number of points read
int read_points(point_t pts[]) {

    int numPts, a;

	printf("Enter the number of points: ");
	scanf("%d", &numPts);

	printf("Enter x- and y-coordinates for %d points:\n", numPts);
    for (a = 0; a < numPts; a++){
        scanf("%d %d", &pts[a].x, &pts[a].y);
    }

	return numPts; // stub
}

// Calculate the area of surrounding circle
double compute_circle_area(point_t pts[], int numPts) {

    int a; //Loop counter
    double area; //Area of smallest circle that contains all points (aka circle of largest point radius)
    int radius;//"Distance" of each point from the origin (0,0)
    int radius_max = (pts[0].x * pts[0].x) + (pts[0].y * pts[0].y); //Holding variable for maximum "distance", initialized to point 0
    /* Note that this variable isn't the true distance (in fact it is square of the distance)
    because there's no square root. But we can afford to do this because we are only comparing
    magnitudes between distances. Thus we can avoid additional computation of square root*/

    for (a = 1; a < numPts; a++){
        radius = (pts[a].x * pts[a].x) + (pts[a].y * pts[a].y);
        if (radius > radius_max){
            radius_max = radius; //if a larger radius is found, update accordingly
        }
    }

    area = PI * (double)radius_max; //Note: Here it's PI * radius not PI * radius^2 because the "radius_max" variable is actually radius squared!

	return area;
}

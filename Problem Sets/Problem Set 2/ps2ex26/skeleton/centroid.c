// CS1010E Programming Methodology
// Problem Set 2 Exercise #26: centroid.c
//
// This program returns the coordinates of a triangle centroid given the coordinates of its vertexes
//
//
// Lau Yan Han

#include <stdio.h>

void centroid(double x1, double y1, double x2, double y2,
		double x3, double y3, double *xG_p, double *yG_p);

int main(void) {

	double x1, y1,    // coordinates of 1st vertex
		   x2, y2,    // coordinates of 2nd vertex
		   x3, y3,    // coordinates of 3rd vertex
		   xG, yG;    // coordinates of centroid

	printf("Coordinates of 1st vertex: ");
	scanf ("%lf %lf",&x1,&y1);

	printf("Coordinates of 2nd vertex: ");
	scanf ("%lf %lf",&x2,&y2);

	printf("Coordinates of 3rd vertex: ");
	scanf ("%lf %lf",&x3,&y3);

	centroid(x1,y1,x2,y2,x3,y3,&xG,&yG); //The two pointers "point" to xG and yG

	printf("Coordinates of centroid = (%.2f, %.2f)\n", xG, yG);

	return  0;
}

// This function returns the x-y coordinates of the triangle centroid
void centroid(double x1, double y1, double x2, double y2,
		double x3, double y3, double *xG_p, double *yG_p) {

    double x_centroid, y_centroid;

    x_centroid = (x1 + x2 + x3)/3;
    y_centroid = (y1 + y2 + y3)/3;

    *xG_p = x_centroid; //Place the value of x_centroid into the address that *xG_p points to, which is xG in main function
    *yG_p = y_centroid;

}

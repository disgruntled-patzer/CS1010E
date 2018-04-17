// CS1010E Programming Methodology
// Problem Set 4 Exercise #18: lines.c
//
// This program reads a list of points, sorts them
// by x-coordinates and y-coordinates, and computes
// the total length of horizontal and vertical lines
// if we trace the points in the sorted list.
//
// Lau Yan Han

#include <stdio.h>
#include <stdlib.h>
#define MAX_POINTS 20

typedef struct {
	int x, y;
} point_t;

void scan_points(point_t pts[], int *size_ptr);
void sort_points(point_t pts[], int size);
int less_than(point_t p, point_t q);
int trace_lines(point_t pts[], int size);
void print_points(point_t pts[], int size);

int main(void) {

	/** main function is complete **/

	point_t pts[MAX_POINTS];  // array of points
	int num_points; // actual number of points

	scan_points(pts, &num_points);
	// printf("Before sort:\n");
	// print_points(pts, num_points); // for checking

	sort_points(pts, num_points);

	printf("After sort:\n");
	print_points(pts, num_points);

	printf("Sum of lengths of vertical and horizontal lines = %d\n",
			trace_lines(pts, num_points));

	return 0;
}

// Read points and assign to arrays x and y
// Return the number of points read through pointer
void scan_points(point_t pts[], int *size_ptr) {

    int a; //Loop counter

	printf("Enter the number of points: ");
	scanf("%d", size_ptr);

	printf("Enter x- and y-coordinates of %d points:\n", *size_ptr);
	for (a = 0; a < *size_ptr; a++){
        scanf("%d %d", &pts[a].x, &pts[a].y);
	}

}

// Sort the points in ascending order of x-coordinates and
// then y-coordinates.
void sort_points(point_t pts[], int size) {

    int limit = size, swapped = 1, a; //Variables for Enhanced Bubble Sort
    point_t temp; //Temporary holding structure for coordinates when a swap takes place

    do {
        swapped = 0;
        for (a = 1; a < limit; a++){
            if (less_than(pts[a], pts[a - 1]) == 1){ //If an entry is "less than" previous entry, swap
                temp.x = pts[a].x;
                temp.y = pts[a].y;
                pts[a].x = pts[a - 1].x;
                pts[a].y = pts[a - 1].y;
                pts[a - 1].x = temp.x;
                pts[a - 1].y = temp.y;
                swapped = 1;
            }
        }
        limit--; //After one iteration, "largest" point is sorted to the right, thus decrease limit by 1
    } while (swapped == 1);

}

// Return 1 if point at index p is "less than" point at index q;
// otherwise returns 0.
// Point at index p is "less than" point at index q if the former
// has a smaller x-coordinate, or if their x-coordinates are the
// same, then the former has a smaller y-coordinate.
int less_than(point_t p, point_t q) {

	if (p.x < q.x){ //If x coord of p is smaller, return 1
        return 1;
	}
	else if (p.x == q.x){ //If both have same x coords, compare y
        if (p.y < q.y){
            return 1;
        }
        else {
            return 0;
        }
	}
	else{ //If x coord of p is larger, return 0
        return 0;
	}

}

// Trace lines on points in sorted array and compute the
// sum of lengths of horizontal and vertical lines
int trace_lines(point_t pts[], int size) {

    int sum = 0;
    int a; //Loop counter

    for (a = 1; a < size; a++){
        if (pts[a].y == pts[a - 1].y){ //If points are horizontal
            sum = sum + abs(pts[a].x - pts[a - 1].x); //Add the horizontal points together
        } //Note that if points are equal, the sum will not increase
        else if (pts[a].x == pts[a - 1].x){ //If points are not horizontal, check if they're vertical
            sum = sum + abs(pts[a].y - pts[a - 1].y); //If yes, then add the vertical points together
        }
        else {} //If points are neither vertical nor horizontal, do nothing and continue to next loop
    }

	return sum;  // stub
}

// Print points
// Complete and given
void print_points(point_t pts[], int size) {

	int i;

	for (i = 0; i < size; i++) {
		printf("Point #%2d: (%d,%d)\n", i, pts[i].x, pts[i].y);
	}
}

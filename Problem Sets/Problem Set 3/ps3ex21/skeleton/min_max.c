// CS1010E Programming Methodology
// Problem Set 3 Exercise #21: min_max.c
//
// This program reports the minimum and
// maximum elements in a given matrix.
//
// Lau Yan Han

#include <stdio.h>
#define NROWS 10
#define NCOLS 10

void get_min_max(int mtx[NROWS][NCOLS], int num_rows,
		int num_cols, int *min_p, int *max_p);
void scan_matrix (int mtx[NROWS][NCOLS], int num_rows, int num_cols);

int main(void) {

    int mtx[NROWS][NCOLS];
    int num_rows, num_cols;
    int min, max;

	printf("Enter the size of the matrix: ");
    scanf ("%d %d",&num_rows, &num_cols);

	printf("Enter elements row by row:\n");
	scan_matrix(mtx, num_rows, num_cols);

	get_min_max(mtx, num_rows, num_cols, &min, &max);

	printf("Min = %d\n", min);
	printf("Max = %d\n", max);

	return 0;
}

// Return maximum and minimum elements through two pointers
void get_min_max(int mtx[NROWS][NCOLS], int num_rows,
		int num_cols, int *min_p, int *max_p) {

	int row, col;
	*min_p = mtx[0][0];
	*max_p = mtx[0][0];

	for (row = 0; row < num_rows; row++){
        for (col = 0; col < num_cols; col++){
            if (mtx[row][col] > *max_p){ //If there is an entry that is larger than *max_p, reassign *max_p to that entry
                *max_p = mtx[row][col];
            }
            if (mtx[row][col] < *min_p){ //Do the same for *min_p
                *min_p = mtx[row][col];
            }
        }
	}

}

void scan_matrix(int mtx[NROWS][NCOLS], int num_rows, int num_cols){

    int row, col;

	for (row = 0; row < num_rows; row++){
        for (col = 0; col < num_cols; col++){
            scanf ("%d",&mtx[row][col]);
        }
	}
}

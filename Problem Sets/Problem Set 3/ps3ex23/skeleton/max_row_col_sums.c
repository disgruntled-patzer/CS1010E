// CS1010E Programming Methodology
// Problem Set 3 Exercise #23: max_row_col_sums.c
//
// This program prints out the maximum row sum
// and column sum in a given matrix.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>
#define NROWS 10
#define NCOLS 10

void read_matrix(int mtx[NROWS][NCOLS], int *rows_p, int*cols_p);
int get_max_row_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols);
int get_max_col_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols);
void print_matrix (int mtx[NROWS][NCOLS], int num_rows, int num_cols);

// complete and given
int main(void) {

	int mtx[NROWS][NCOLS], num_rows, num_cols;
	int max_row_sum, max_col_sum;

	read_matrix(mtx, &num_rows, &num_cols);
    //print_matrix(mtx, num_rows, num_cols); //Debugging statement

	max_row_sum = get_max_row_sum(mtx, num_rows, num_cols);

	max_col_sum = get_max_col_sum(mtx, num_rows, num_cols);

	printf("Max row sum = %d\n", max_row_sum);
	printf("Max col sum = %d\n", max_col_sum);

	return 0;
}

// Read values into the matrix
// Return the number of rows and columns through pointers
void read_matrix(int mtx[][NCOLS], int *rows_p, int *cols_p) {

    int row,col;

	printf("Enter the size of the matrix: ");
	scanf ("%d %d",&*rows_p,&*cols_p);

	printf("Enter elements row by row:\n");
	for (row = 0; row < *rows_p; row++){
        for (col = 0; col < *cols_p; col++){
            scanf ("%d",&mtx[row][col]);
        }
	}

}

// Return maximum row sum
int get_max_row_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols) {

    int row, col;
    int row_sum_loop = 0, row_sum_temp = 0;
    //row_sum_temp is the temporary maximum row sum and will be modified if necessary
    //row_sum_loop is computed for each iteration in the 2nd loop and compared with row_sum_temp

    row = 0;
    for (col = 0; col < num_cols; col++){ //Assign row_sum_temp to the sum of 1st row to be compared later
        row_sum_temp = row_sum_temp + mtx [row][col];
    }
    //printf ("%d\n",row_sum_temp); //Debugging statement

    for (row = 1; row < num_rows; row++){ //Now, calculate row sums for the 2nd and subsequent rows before comparing them
        for (col = 0; col < num_cols; col++){
            row_sum_loop = row_sum_loop + mtx[row][col];
        }
        if (row_sum_loop > row_sum_temp){
            row_sum_temp = row_sum_loop;
        } //If calculated row sum is more than temporarily stored max row sum, replace temporarily stored sum with new value
        row_sum_loop = 0; //Reset row_sum_loop to zero to be used again in next iteration
    }

	return row_sum_temp; //The "temporarily" stored max sum now stores the final max sum after exiting loop
}

// Return maximum column sum
int get_max_col_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols) {

    int row, col;
    int col_sum_loop = 0, col_sum_temp = 0;
    //col_sum_temp is the temporary maximum column sum and will be modified if necessary
    //col_sum_loop is computed for each iteration in the 2nd loop and compared with col_sum_temp

    col = 0;
    for (row = 0; row < num_rows; row++){ //Assign col_sum_temp to the sum of 1st column to be compared later
        col_sum_temp = col_sum_temp + mtx[row][col];
    }
    //printf ("%d\n",col_sum_temp); //Debugging statement

    for (col = 1; col < num_cols; col++){ //Now, calculate column sums for the 2nd and subsequent columns before comparing them
        for (row = 0; row < num_rows; row++){
            col_sum_loop = col_sum_loop + mtx[row][col];
        }
        if (col_sum_loop > col_sum_temp){
            col_sum_temp = col_sum_loop;
        } //If calculated column sum is more than temporarily stored max column sum, replace temporarily stored sum with new value
        col_sum_loop = 0; //Reset col_sum_loop to zero to be used again in next iteration
    }

	return col_sum_temp; //The "temporarily" stored max sum now stores the final max sum after exiting loop

	return 0; // stub
}

//Debugging function
void print_matrix(int mtx [NROWS][NCOLS], int num_rows, int num_cols){

    int row, col;

	for (row = 0; row < num_rows; row++){
        for (col = 0; col < num_cols; col++){
            printf ("%d ", mtx[row][col]);
        }
        printf ("\n");
	}
}

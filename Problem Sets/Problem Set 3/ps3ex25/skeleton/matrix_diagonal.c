// CS1010E Programming Methodology
// Problem Set 3 Exercise #25: matrix_diagonal.c
//
// This program reads a matrix
// and checks for descending diagonal
// matrix and anti-diagonal matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int read_matrix(int matrix[MAX][MAX]);
int is_desc_diagonal(int matrix[MAX][MAX], int size);
int is_anti_diagonal(int matrix[MAX][MAX], int size);

int main(void) {

	int size, matrix[MAX][MAX];

	size = read_matrix(matrix);

	if ( is_desc_diagonal(matrix, size) ) {
		printf("Given matrix is a descending diagonal matrix.\n");
	} else {
		printf("Given matrix is not a descending diagonal matrix.\n");
	}

	if ( is_anti_diagonal(matrix, size) ) {
		printf("Given matrix is an anti-diagonal matrix.\n");
	} else {
		printf("Given matrix is not an anti-diagonal matrix.\n");
	}

	return 0;
}

// Read data into matrix, return size
int read_matrix(int matrix[MAX][MAX]) {

    int size;
    int row, col;

	printf("Enter the size of square matrix: ");
	scanf ("%d", &size);

	printf("Enter values:\n");
	for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            scanf ("%d",&matrix[row][col]);
        }
	}

	return size; // stub
}

// Check if diagonal values are in decreasing
// consecutive numbers and all the non-diagonal
// values are 0. Return 1 if so, 0 otherwise
int is_desc_diagonal(int matrix[MAX][MAX], int size) {

    int row, col;
    int diagonal, previous; //Variables used to compare a diagonal entry with the previous diagonal entry

    //Two steps: (1) Check whether matrix is diagonal, (2) Check whether diagonal entries are descending

    for (row = 0; row < size; row++){ //This loop checks whether the matrix is diagonal
        for (col = 0; col < size; col++){
            if (row != col && matrix [row][col] != 0){
                return 0; //If any of the nondiagonal entries are nonzero, matrix is not diagonal
            }
        }
    }

    for (row = 0; row < size; row++){ //This loop checks whether matrix diagonal entries are descending consecutive
        col = row;
        if (row == 0){ //For the first entry (row/col = 0), intialize the "previous" entry
            previous = matrix [row][col];
        }
        else { //For subsequent entries, check the diagonal entry in the row with the "previous" entry
            diagonal = matrix [row][col];
            if (diagonal != previous - 1){
                return 0; //If at any point the diagonal entry not one less than previous diagonal, matrix is not descending diagonal
            }
            previous = matrix [row][col]; //Update the "previous" entry to be compared in the next iteration
        }
    }

	return 1;  // If both loops don't return 0, the array is a descending diagonal
}

// Check if all the values are zeroes except those
// on the anti-diagonal. Return 1 if so, 0 otherwise
int is_anti_diagonal(int matrix[MAX][MAX], int size) {

    int row, col;

    for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            if (col != (size - row - 1) && matrix[row][col] != 0){
                //For antidiagonal entries, the entries have column number = size - row - 1
                //If entries not on the antidiagonal are nonzero, matrix is not antidiagonal
                return 0;
            }
        }
    }

	return 1;
}

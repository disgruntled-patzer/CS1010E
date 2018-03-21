// CS1010E Programming Methodology
// Problem Set 3 Exercise #24: square_matrix.c
//
// This program checks if a square matrix is
// a diagonal matrix or an upper-triangular matrix.
//
// Lau Yan Han

#include <stdio.h>
#define N 10

int scan_matrix(int matrix[N][N]);
int is_diagonal(int matrix[N][N], int size);
int is_upper_triangular(int matrix[N][N], int size);
void print_matrix(int matrix[N][N], int size);

// main is complete and given
int main(void) {

	int matrix[N][N];
	int size;

	size = scan_matrix(matrix);
	//print_matrix(matrix,size); //Debugging statement

	if ( is_diagonal(matrix, size) ) {
		printf("Given matrix is a diagonal matrix.\n");
	} else {
		printf("Given matrix is not a diagonal matrix.\n");
	}

	if ( is_upper_triangular(matrix, size) ) {
		printf("Given matrix is an upper triangular matrix.\n");
	} else {
		printf("Given matrix is not an upper triangular matrix.\n");
	}

	return 0;
}

// Read values into mtx
// Return the size of square matrix
int scan_matrix(int mtx[N][N]) {

    int size, row, col;

	printf("Enter the size of the square matrix: ");
	scanf ("%d",&size);

	printf("Enter elements row by row:\n");
	for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            scanf ("%d",&mtx[row][col]);
        }
	}

	return size; // Return size of matrix
}

// Return 1 if mtx is diagonal matrix,
// otherwise return 0.
int is_diagonal(int mtx[N][N], int size) {

    int row, col;

    for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            if (col != row && mtx[row][col] != 0){
                return 0; //If any entry not on the diagonal is evaluated to nonzero, matrix is nondiagonal
            }
        }
    }

	return 1; // If loop exits without returning 0, the matrix is diagonal
}

// Return 1 if mtx is upper-triangular matrix,
// otherwise return 0.
int is_upper_triangular(int mtx[N][N], int size) {

    int row, col;

    for (row = 0; row < size; row++){
        for (col = 0; col < row; col++){ //Check only for cells to the left of the diagonal (i.e. column counter less than row counter)
            if (mtx[row][col] != 0){ //Note: No need to check col != row condition since those cells are not checked
                return 0; //If any entry left of the diagonal is evaluated to nonzero, matrix is nondiagonal
            }
        }
    }

	return 1; // If loop exits without returning 0, the matrix is upper-triangular
}

// Print values of mtx
// not required in output - use it for debugging purpose
void print_matrix(int mtx[N][N], int size) {

	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			printf("%d\t", mtx[row][col]);
		}
		printf("\n");
	}
}

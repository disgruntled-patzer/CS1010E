// CS1010E Programming Methodology
// Problem Set 3 Exercise #26: max_pair.c
//
// This program finds the pair of the same value
// that appears most frequently in a given matrix
// and reports its frequency.
//
// Lau Yan Han

#include <stdio.h>
#define NROWS 4
#define NCOLS 4
#define NDIGITS 10 //Number of digits from 0 to 9 (total of 10)

void scan_matrix(int mtx[NROWS][NCOLS]);
int get_max_pairs(int mtx[NROWS][NCOLS]);
int find_max(int number[NDIGITS]);
void print_matrix(int mtx[NROWS][NCOLS]);

int main(void) {

    int mtx[NROWS][NCOLS];
    int max_pairs;

	printf("Enter values:\n");
	scan_matrix(mtx);

	max_pairs = get_max_pairs(mtx);

	printf("Max number of pairs: %d\n", max_pairs);

	return 0;
}
// Scans user input values into the matrix
void scan_matrix(int mtx[NROWS][NCOLS]) {

    int row, col;

	for (row = 0; row < NROWS; row++){
        for (col = 0; col < NCOLS; col++){
            scanf ("%d",&mtx[row][col]);
        }
	}
}

// Return the maximum number of pairs of the
// same value within the same row or column
int get_max_pairs(int mtx[NROWS][NCOLS]) {

    int row, col; //Used to loop through mtx to scan for pairs
    int number[NDIGITS] = {0}; //Number of pairs for each digit from 0 to 9, initialized to 0
    int digit; //If a pair is found, this variable copies the number in the pair to be stored in the "number" array
    int max_pairs; //Maximum number of pairs in the matrix

    //This loop checks for pairs in the rows of the matrix
    for (row = 0; row < NROWS; row++){
        for (col = 1; col < NCOLS; col++){ //Initialize col at 1 because we are checking the entry with entry in previous column
            if (mtx [row][col] == mtx [row][col - 1]){
                digit = mtx[row][col]; //If a pair is found, copy it to "digit" to be updated in the number array
                number[digit]++;
            }
        }
    }

    //This loop checks for pairs in the columns of the matrix
    for (col = 0; col < NCOLS; col++){
        for (row = 1; row < NROWS; row++){ //Initialize row at 1 because we are checking the entry with the entry in previous row
            if (mtx [row][col] == mtx [row - 1][col]){
                digit = mtx[row][col]; //If a pair is found, copy it to "digit" to be updated in the number array
                number[digit]++;
            }
        }
    }

    //Use find_max function to scan through the "number" array and find the digit with highest pair value
    max_pairs = find_max(number);

	return max_pairs;
}

int find_max(int number[NDIGITS]){

    int a; //This will run a loop through the "number" array to find the digit with the highest pair value
    int max_pairs = 0;

    for (a = 0; a < NDIGITS; a++){
        if (number[a] > max_pairs){
            max_pairs = number[a];
        }
    }
    return max_pairs;
}

// For debugging
void print_matrix(int mtx[NROWS][NCOLS]) {

	int row, col;

	for (row = 0; row < NROWS; row++) {
		for (col = 0; col < NCOLS; col++) {
			printf("%d\t", mtx[row][col]);
		}
		printf("\n");
	}
}

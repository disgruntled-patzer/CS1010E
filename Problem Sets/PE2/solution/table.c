/*
 * CS1010E AY2017/8 Semester 2
 * PE2 Ex2: table.c
 * 
 * This program fills a 2-dim integer table with values 
 * and sum the values in the rectangular portion of
 * of table whose corners are entered by the user.
 * 
 * Author: Zhou Lifeng
 */

#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 8 

void fill_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols);
int read_two_elements(int num_rows, int num_cols, int *ele1_r_p,
		int *ele1_c_p, int *ele2_r_p, int *ele2_c_p);
int compute_square_sum(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols,
		int ele1_r, int ele1_c, int ele2_r, int ele2_c);
void print_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols);


int main(void) {

	int num_rows, num_cols;
	int table[MAX_ROW][MAX_COL];
	int ele1_r, ele1_c, ele2_r, ele2_c, sum;

	printf("Enter the number of rows and columns of the table: ");
	scanf("%d %d", &num_rows, &num_cols);

	fill_table(table, num_rows, num_cols);
	printf("The table is shown below:\n");
	print_table(table, num_rows, num_cols);

	if ( read_two_elements(num_rows, num_cols, &ele1_r, &ele1_c, &ele2_r, &ele2_c) ) {
		sum = compute_square_sum(table, num_rows, num_cols, ele1_r, ele1_c, ele2_r, ele2_c);
		printf("Sum = %d\n", sum);
	} else {
		printf("Wrong inputs!\n");
	}

	return 0;
}


// Fill in the tables with the following values:
// First row and columns are all 1s
// Every other ele is the sum of the ele on top of it and to the left
void fill_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols) {

	int row, col;
	for (row = 0; row < num_rows; row++) {
		table[row][0] = 1;
	}

	for (col = 0; col < num_cols; col++) {
		table[0][col] = 1;
	}

	for (row = 1; row < num_rows; row++) {
		for (col = 1; col < num_cols; col++) {
			table[row][col] = table[row-1][col] + table[row][col-1];
		}
	}
}


// Read row and column numbers of 2 eles
// The user inputs must not exceed the array boundary 
// Maximum three attempts are allowed
int read_two_elements(int num_rows, int num_cols, int *ele1_r_p,
		int *ele1_c_p, int *ele2_r_p, int *ele2_c_p) {

	int attempt = 0;

	do {
		printf("Enter row and column numbers of the first element: ");
		scanf("%d %d", ele1_r_p, ele1_c_p);

		printf("Enter row and column numbers of the second element: ");
		scanf("%d %d", ele2_r_p, ele2_c_p);

		if ( (*ele1_r_p!=*ele2_r_p || *ele1_c_p!=*ele2_c_p) && // two different elements
				// within boundary
				*ele1_r_p>=0 && *ele1_r_p<num_rows && *ele1_c_p>=0 && *ele1_c_p<num_cols &&
				*ele2_r_p>=0 && *ele2_r_p<num_rows && *ele2_c_p>=0 && *ele2_c_p<num_cols) {
			return 1; // successful
		}
		attempt++;
	} while (attempt < 3);

	return 0; // unsuccessful
}


// Compute the sum of the rectangular portion cornered by two given elements
int compute_square_sum(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols,
		int ele1_r, int ele1_c, int ele2_r, int ele2_c) {

	int row, col, sum = 0;

	// find the left-top corner and right-bottom corner
	// cor1 represents the left-top corner; cor2 is the right-bottom corner
	int cor1_r, cor1_c, cor2_r, cor2_c;

	cor1_r = ele1_r < ele2_r ? ele1_r : ele2_r;
	cor2_r = ele1_r + ele2_r - cor1_r;
	cor1_c = ele1_c < ele2_c ? ele1_c : ele2_c;
	cor2_c = ele1_c + ele2_c - cor1_c;

	// for testing
	//printf("corner1 = [%d, %d], corner2 = [%d, %d]\n", cor1_r, cor1_c, cor2_r, cor2_c);

	for (row = cor1_r; row <= cor2_r; row++) {
		for (col = cor1_c; col <= cor2_c; col++) {
			sum += table[row][col];
		}
	}

	return sum;
}


// Print out the table row by row
void print_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols) {

	int row, col;

	for (row = 0; row < num_rows; row++) {
		for (col = 0; col < num_cols; col++) {
			printf("%d\t", table[row][col]);
		}
		printf("\n");
	}
}

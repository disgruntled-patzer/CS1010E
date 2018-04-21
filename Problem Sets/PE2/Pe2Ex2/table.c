/*
 * CS1010E AY2017/18 Semester 2
 * PE2 Ex2: table.c
 *
 * Name: Lau Yan Han
 * Student Number: A0164750E
 * PLab Userid: plab0538
 * Tutorial Group Number: E23
 * Short and Meaningful Program Description: This function generates a "Pascal's Triangle" table
 * based on user input size. It then prompts the user to input two coordinates
 * before returning the sum of values in the rectangle cornered by these coordinates
 * However, if the user inputs up to 3 invalid coordinates, the program terminates
 */

#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 8 

void fill_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols);
int read_two_elements(int num_rows, int num_cols, int *ele1_r_p,
		int *ele1_c_p, int *ele2_r_p, int *ele2_c_p);
int compute_square_sum(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols,
		int ele1_r, int ele1_c, int ele2_r, int ele2_c);
int lower_diagonal_sum(int table[MAX_ROW][MAX_COL], int left_r, int left_c, int right_r, int right_c);
int upper_diagonal_sum(int table[MAX_ROW][MAX_COL], int left_r, int left_c, int right_r, int right_c);
void print_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols);


int main(void) {

	/*******************************************************
	 * Main function is complete and you MUST NOT change it *
	 *******************************************************/

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


// Based on a user input size, generate the table which sums the rows and columns
// This sum is based on a "Pascal's Triangle" sum method: Each entry is the sum of
// the entry above and to the left of it
void fill_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols) {

	int row, col;

	//Loop 1 and 2: Fill in the first row and column with ones
	for (row = 0; row < num_rows; row++){
		table[row][0] = 1; //Fill in the first column with ones
	}
	for (col = 0; col < num_cols; col++){
		table[0][col] = 1; //Fill in the first row with ones
	}

	//Loop 3: Fill up the rest of the table based on the sum requirements
	for (row = 1; row < num_rows; row++){
		for (col = 1; col < num_cols; col++){
			table[row][col] = table[row - 1][col] + table[row][col - 1];
		}
	}

}


// This function reads in 2 user input coordinates (distinct and within table boundaries)
// and returns them via 4 pointers. If the coordinates input are invalid, it will
// prompt the user to enter again. After 3 invalid attempts, the function returns 0
int read_two_elements(int num_rows, int num_cols, int *ele1_r_p,
		int *ele1_c_p, int *ele2_r_p, int *ele2_c_p) {

	int attempts = 0; //Number of invalid attempts by the user

	while (attempts < 3){

		printf("Enter row and column numbers of the first element: ");
		scanf("%d", ele1_r_p);
		scanf("%d", ele1_c_p);

		printf("Enter row and column numbers of the second element: ");
		scanf("%d", ele2_r_p);
		scanf("%d", ele2_c_p);

		// If the coordinates are similar, input is invalid, try again
		if (*ele1_r_p == *ele2_r_p && *ele1_c_p == *ele2_c_p){
			attempts++;
			continue;
		}
		// If first element coordinates is out of boundary, also invalid
		else if ((*ele1_r_p < 0 || *ele1_r_p >= num_rows) || (*ele1_c_p < 0 || *ele1_c_p >= num_cols)){
			attempts++;
			continue;
		}
		// If second element coordinates are out of boundary, also invalid
		else if ((*ele2_r_p < 0 || *ele2_r_p >= num_rows) || (*ele2_c_p < 0 || *ele2_c_p >= num_cols)){
			attempts++;
			continue;
		}
		// If inputs are valid, break from the loop
		else{
			break;
		}
	}
	// If after exiting loop, attempts is 3 or more, return 0 (wrong inputs)
	if (attempts >= 3){
		return 0;
	}
	else {
		return 1;
	}
}


// Computes the sum of all entries in the rectangle portion cornered by the two coordinates
// which the user had entered previously (assuming they are valid)
int compute_square_sum(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols,
		int ele1_r, int ele1_c, int ele2_r, int ele2_c) {

	int sum = 0;

	//There are 4 possible cases for the location of the two input coordinates
	//which will need either a sum along the upper or lower diagonals. The 4 cases are taken into account
	//In the following set of if-else statements

	//Case 1: If coords form an lower diagonal with coordinate 1 on the left
	//This also takes into account the special case when the coordinates form a vertical line
	//where coordinate 1 is above coordinate 2
	if (ele1_r < ele2_r && ele1_c <= ele2_c){
		sum = lower_diagonal_sum(table, ele1_r, ele1_c, ele2_r, ele2_c);
	}
	//Case 2: If coords form an lower diagonal with coordinate 2 on the left
	//This also takes into account the special case when the coordinates form a vertical line
	//where coordinate 2 is above coordinate 1
	else if (ele1_r > ele2_r && ele1_c >= ele2_c){
		sum = lower_diagonal_sum(table, ele2_r, ele2_c, ele1_r, ele1_c);
	}
	//Case 3: If coords form a lower diagonal with coordinate 1 on the left
	//This also takes into account the special case when the coordinates form a horizontal line
	//where coordinate 1 is left of coordinate 2
	else if (ele1_r >= ele2_r && ele1_c < ele2_c){
		sum = upper_diagonal_sum(table, ele1_r, ele1_c, ele2_r, ele2_c);
	}
	//Case 4: If coords form a lower diagonal with coordinate 2 on the left
	//This also takes into account the special case when the coordinates form a horizontal line
	//where coordinate 2 is left of coordinate 1
	else{
		sum = upper_diagonal_sum(table, ele2_r, ele2_c, ele1_r, ele1_c);
	}

	return sum;
}

//Calculates sum of a matrix where the two input coordinates are along the lower diagonal
//left_r = row number of left coordinate, left_c = column number of left coordinate, and so on
int lower_diagonal_sum(int table[MAX_ROW][MAX_COL], int left_r, int left_c, int right_r, int right_c){

	int row, col;
	int sum = 0; //Sum of elements in the array

	for (row = left_r; row <= right_r; row++){
		for (col = left_c; col <= right_c; col++){
			sum = sum + table[row][col];
		}
	}
	return sum;
}

//Calculates sum of a matrix where the two input coordinates are along the upper diagonal
//left_r = row number of left coordinate, left_c = column number of left coordinate, and so on
int upper_diagonal_sum(int table[MAX_ROW][MAX_COL], int left_r, int left_c, int right_r, int right_c){

	int row, col;
	int sum = 0; //Sum of elements in the array

	for (row = left_r; row >= right_r; row--){
		for (col = left_c; col <= right_c; col++){
			sum = sum + table[row][col];
		}
	}

	return sum;
}

// Print out the table row by row
void print_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols) {

	/***************************************************************
	 * print_table function is complete and you MUST NOT change it *
	 ***************************************************************/

	int row, col;

	for (row = 0; row < num_rows; row++) {
		for (col = 0; col < num_cols; col++) {
			printf("%d\t", table[row][col]);
		}
		printf("\n");
	}
}

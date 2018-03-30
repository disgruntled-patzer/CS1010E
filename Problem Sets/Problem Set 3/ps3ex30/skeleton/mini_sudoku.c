// This function solves a mini 4 x 4 Sudoku Problem
// Lau Yan Han

#include <stdio.h>
#define N 4

void scan_mtx(int mtx[N][N]);
void solve_row(int mtx[N][N], int *modified);
void solve_col(int mtx[N][N], int *modified);
void solve_cell(int mtx[N][N], int *modified);
void find_zero_cell (int mtx[N][N], int digits[N + 1], int row, int col, int *row_zero, int *col_zero);
void find_zeros (int mtx[N][N], int digits [N + 1], int row, int col, int **row_zero, int **col_zero);
void fill_entry (int mtx[N][N], int digits[N + 1], int row_zero, int col_zero, int **modified);
void print_mtx(int mtx[N][N]);

int main (void){

    int mtx[N][N];
    int modified = 0; //Check whether the matrix needs to be modified or not

    printf("Enter board (0 for blank cell):\n");
    scan_mtx(mtx);

    do {  //Solve the puzzle using these three functions as long as modifications were made in the previous iteration
        modified = 0; //Reset modified to zero before functions are run (thus there are no modifications yet)
        solve_row(mtx, &modified);
        solve_col(mtx, &modified);
        solve_cell(mtx, &modified);
    } while (modified == 1);

    printf("The Sudoku puzzle solved:\n");
    print_mtx(mtx);

    return 0;
}

void scan_mtx(int mtx[N][N]){

    int row, col;

    for (row = 0; row < N; row++){
        for (col = 0; col < N; col++){
            scanf("%d",&mtx[row][col]);
        }
    }
}

// Finds the rows containing only one zero and replace them with the obvious number
void solve_row (int mtx[N][N], int *modified){

    int row, col;
    int row_zero, col_zero; //Mark down the location of any zeros in the row
    int digits[N + 1] = {0}; //Number of digits 0 - 4 in the row, initialized to zero

    for (row = 0; row < N; row++){ //Outer loop: Go through each row in the matrix
        for (col = 0; col < N; col++){ //Inner loop: Go through each entry in the row and mark the digits that are present
            digits[mtx[row][col]]++;
            if (mtx[row][col] == 0){
                row_zero = row; //If a zero is found, mark its location
                col_zero = col;
            }
        }

        fill_entry(mtx, digits, row_zero, col_zero, &modified); //Call a function to fill up the rows that have single zeros

    } //End of the outer loop

}

// Finds the columns containing only one zero and replace them with the obvious number
void solve_col(int mtx[N][N], int *modified){

    int row, col;
    int row_zero, col_zero; //Mark down the location of any zeros in the row
    int digits[N + 1] = {0}; //Number of digits 0 - 4 in the row, initialized to zero

    for (col = 0; col < N; col++){ //Outer loop: Go through each col in the matrix
        for (row = 0; row < N; row++){ // Inner loop: Go through each entry in the col and mark the digits that are present
            digits[mtx[row][col]]++;
            if (mtx[row][col] == 0){
                row_zero = row; //If a zero is found, mark its location
                col_zero = col;
            }
        }

        fill_entry(mtx, digits, row_zero, col_zero, &modified); //Call a function to fill up the columns that have single zeros

    } //End of the outer loop
}

// Find the 2 x 2 cells containing only one zero and fill them with the obvious number
void solve_cell(int mtx[N][N], int *modified){

    int row, col;
    int row_zero, col_zero; //Mark down the location of any zeros in the row
    int digits[N + 1] = {0}; //Number of digits 0 - 4 in the row, initialized to zero

    row = 0; //Start with the top-left cell
    col = 0;
    find_zero_cell(mtx, digits, row, col, &row_zero, &col_zero);
    fill_entry(mtx, digits, row_zero, col_zero, &modified);

    col = 2; //Continue to the top-right cell
    find_zero_cell(mtx, digits, row, col, &row_zero, &col_zero);
    fill_entry(mtx, digits, row_zero, col_zero, &modified);

    row = 2; //Continue to the bottom-right cell
    find_zero_cell(mtx, digits, row, col, &row_zero, &col_zero);
    fill_entry(mtx, digits, row_zero, col_zero, &modified);

    col = 0; //Continue to the bottom-left cell
    find_zero_cell(mtx, digits, row, col, &row_zero, &col_zero);
    fill_entry(mtx, digits, row_zero, col_zero, &modified);

}

// Higher order function: Find the zeros in each 2 x 2 cell of the matrix
void find_zero_cell(int mtx[N][N], int digits[N + 1], int row, int col,
               int *row_zero, int *col_zero){

    //Start at the top-right of the cell
    find_zeros(mtx, digits, row, col, &row_zero, &col_zero); //Check whether the entry contains a zero

    row++; //Move to the top-right and repeat
    find_zeros(mtx, digits, row, col, &row_zero, &col_zero);

    col++; //Move to the bottom-right and repeat
    find_zeros(mtx, digits, row, col, &row_zero, &col_zero);

    row--; //Move to the bottom-left and repeat
    find_zeros(mtx, digits, row, col, &row_zero, &col_zero);

}

// Higher order function that finds entries containing zero in the find_cells function
void find_zeros (int mtx[N][N], int digits [N + 1], int row, int col, int **row_zero, int **col_zero){

    //Note the ** represents a pointer to a pointer, since we are changing variables that are two functions upstream
    digits[mtx[row][col]]++; //Look at the digit inside the desired entry, update the digits array (+1) accordingly
    if (mtx[row][col] == 0){ //If that digit is zero, mark its location
        **row_zero = row;
        **col_zero = col;
    }
}

// Higher order function: Fills up the zero entries for the solve_row, solve_col and solve_cell functions
void fill_entry(int mtx[N][N], int digits[N + 1], int row_zero, int col_zero, int **modified){

    //Note the ** represents a pointer to a pointer, since we are changing variables that are two functions upstream
    int a;

    if (digits[0] == 1){ //If the row/col/cell is found to have a one zero
        for (a = 1; a <= N; a++){
            if (digits[a] == 0){ //Scan through the digits matrix to find the digit that doesn't exist in the row/col/cell
                mtx[row_zero][col_zero] = a; //And assign that digit to the zero entry in the matrix
            }
        }
        **modified = 1; //For this iteration, a modification has been performed thus update "modified" to 1 (otherwise it is zero)
    }
    for (a = 0; a <= N; a++){ //Reset the digits array to zero for the next iteration in the solve_row/col/cell function
        digits[a] = 0;
    }

}

// Prints out the entries of the matrix
void print_mtx(int mtx[N][N]){

    int row, col;

    for (row = 0; row < N; row++){
        for (col = 0; col < N; col++){
            printf("%d ", mtx[row][col]);
        }
        printf("\n");
    }
}

//Lau Yan Han
//A0164750E
//This program tests a user input chessboard with queens to solve the attacking queen problem

#include <stdio.h>
#include <stdlib.h>
#define N 10

void scan_mtx(int mtx[N][N], int size);
int attacking(int mtx[N][N], int size);
int solve_row(int mtx[N][N], int size);
int solve_col(int mtx[N][N], int size);
int solve_upper_diagonal (int mtx[N][N], int size);
int solve_lower_diagonal (int mtx[N][N], int size);

int main()
{
    int mtx[N][N], size;

    printf("Enter n:");
    scanf("%d", &size);

    scan_mtx(mtx, size);

    if (attacking(mtx, size) == 1){
        printf("Attacking\n");
    }
    else {
        printf("Not attacking\n");
    }

    return 0;
}

// Scans user input into the matrix (chessboard)
void scan_mtx(int mtx[N][N], int size){

    int row, col;

    for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            scanf("%d", &mtx[row][col]);
        }
    }
}

// Checks whether any of the queens along the board are attacking each other (return 1 if attacking, 0 if not)
int attacking(int mtx[10][10], int size){

    if (solve_row(mtx, size) == 1){
        return 1;
    }
    else if (solve_col(mtx, size) == 1){
        return 1;
    }
    else if (solve_upper_diagonal(mtx, size) == 1){
        return 1;
    }
    else if (solve_lower_diagonal(mtx, size) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

// Tests whether any row contains 2 or more queens (return 1 if yes, 0 if not)
int solve_row(int mtx[N][N], int size){

    int row, col, queens = 0; //queens = number of queens in the particular row

    for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            if (mtx[row][col] > 0){
                queens++;
            } //For each row, count the number of queens in that row
        }
        if (queens > 1){ //If more than one queen in a particular row, return 1 (they are attacking)
            return 1;
        }
        queens = 0; //Reset the number of queens to be counted in the next row
    }

    return 0; //If no row is found with more than one queen, no attacking along the row (return 0)
}

// Tests whether any column contains 2 or more queens (return 1 if yes, 0 if not)
int solve_col(int mtx[N][N], int size){

    int row, col, queens = 0; //queens = number of queens in the particular row

    for (col = 0; col < size; col++){
        for (row = 0; row < size; row++){
            if (mtx[row][col] > 0){
                queens++;
            } //For each column, count the number of queens in that row
        }
        if (queens > 1){ //If more than one queen in a particular column, return 1 (they are attacking)
            return 1;
        }
        queens = 0; //Reset the number of queens to be counted in the next column
    }

    return 0; //If no column is found with more than one queen, no attacking along the row (return 0)

}

// Tests whether any upper diagonal contains 2 or more queens (return 1 if yes, 0 if not)
int solve_upper_diagonal(int mtx[N][N], int size){

    int row, queens = 0;
    int row2, col2; //These variables scan along the diagonals looking for queens

    for (row = 0; row < size; row++){
        row2 = row; //Intialize row2 to scan along the diagonal
        col2 = 0; //Start on the first column for every diagonal
        while (row2 >= 0) { //Inner loop scans along the diagonal looking for queens up till the uppermost row
            if (mtx[row2][col2] > 0){
                queens++;
            }
            row2--;
            col2++; //Update the rows and columns in the inner loop to find queens on the next entry along the diagonal
        }

        if (queens > 1){ //If more than one queen in a particular upper diagonal, return 1 (they are attacking)
            return 1;
        }
        queens = 0; //Reset the number of queens to be counted in the next upper diagonal
    }
    return 0; //If no upper diagonal is found with more than one queen, no attacking along the row (return 0)
}

int solve_lower_diagonal(int mtx[10][10], int size){

    int row, queens = 0;
    int row2, col2; //These variables scan along the diagonals looking for queens

    for (row = 0; row < size; row++){
        row2 = row; //Intialize row2 to scan along the diagonal
        col2 = 0; //Start on the first column for every diagonal
        while (row2 < size) { //Inner loop scans along the diagonal looking for queens up till the bottommost row
            if (mtx[row2][col2] > 0){
                queens++;
            }
            row2++;
            col2++; //Update the rows and columns in the inner loop to find queens on the next entry along the diagonal
        }

        if (queens > 1){ //If more than one queen in a particular lower diagonal, return 1 (they are attacking)
            return 1;
        }
        queens = 0; //Reset the number of queens to be counted in the next lower diagonal
    }
    return 0; //If no lower diagonal is found with more than one queen, no attacking along the row (return 0)
}

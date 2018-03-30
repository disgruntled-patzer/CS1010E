// CS1010E Programming Methodology
// Problem Set 3 Exercise #28: contour.c
//
// This program reads in a map, counts the number of peaks
// and valleys, and produces the hiking map.
//
// Lau Yan Han

#include <stdio.h>
#include <stdlib.h>
#define MAX 12

void getPeaksValleys(int [][MAX], int [][MAX], int, int, int *, int *);
int is_peak(int [][MAX], int, int);
int is_valley(int [][MAX], int, int);
void getHikeTrail(int [][MAX], int [][MAX], int, int);
void checkFirstRowCol (int [][MAX], int [][MAX], int, int);
void scanArray(int [][MAX], int, int);
void printArray(int [][MAX], int, int);

int main(void) {

	int map[MAX][MAX];
	int hike[MAX][MAX] = {{0}};
	int peaksandvalleys[MAX][MAX] = {{0}};
	int nopeaks = 0, novalleys = 0;
	int row, col;

	printf("Enter the number of rows and cols: ");
	scanf("%d %d", &row, &col);
	printf("Enter the data:\n");
	scanArray(map, row, col);

    getPeaksValleys(map, peaksandvalleys, row, col, &nopeaks, &novalleys);
	printf("Number of peaks = %d\n", nopeaks);
	printf("Number of valleys = %d\n", novalleys);
	printf("Peaks and Valleys map\n");
	printArray(peaksandvalleys, row, col);

    getHikeTrail(map, hike, row, col);
	printf("Hiking map\n");
	printArray(hike, row, col);

	return 0;
}

// Count the number of peaks and valleys in 'map', and also produces the peaks and valleys map
void getPeaksValleys(int map[][MAX], int peaksandvalleys[][MAX], int row, int col, int *nopeaks, int *novalleys) {

    int i, j; // i = loop counter for row, j = loop counter for column

    for (i = 1; i < row - 1; i++){ //Run from 1 to row - 1 because don't need to investigate entries at the edges
        for (j = 1; j < col - 1; j++){
            if (is_peak(map, i, j) == 1){
                *nopeaks = *nopeaks + 1;
                peaksandvalleys[i][j] = 1;
            }
            if (is_valley(map, i, j) == 1){
                *novalleys = *novalleys + 1;
                peaksandvalleys[i][j] = 2;
            }
        }
    }
}

// Scans the 8 entries around a selected entry (map[i][j]) to check whether the selected entry is a peak
int is_peak(int map[][MAX], int i, int j){

    int a, b; //New loop counters for row and column respectively

    //Scan the 8 entries surrounding map[i][j], if any of them is same or greater than map[i][j], then map[i][j] is not a peak
    for (a = i - 1; a <= i + 1; a++){
        for (b = j - 1; b <= j + 1; b++){
            if (map[a][b] != map[i][j] && map[a][b] >= map[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

// Scans the 8 entries around a selected entry (map[i][j]) to check whether the selected entry is a valley
int is_valley(int map[][MAX], int i, int j){

    int a, b; //New loop counters for row and column respectively

    //Scan the 8 entries surrounding map[i][j], if any of them is same or lesser than map[i][j], then map[i][j] is not a valley
    for (a = i - 1; a <= i + 1; a++){
        for (b = j - 1; b <= j + 1; b++){
            if (map[a][b] != map[i][j] && map[a][b] <= map[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

// Produce the hiking map
void getHikeTrail(int map[][MAX], int hike[][MAX], int row, int col) {

    int i, j; //Loop counters for row and column respectively
    int modified = 1; //Checks whether "hike" array has been modified in the previous iteration (1 if yes, 0 if no)

    hike[0][0] = 1; //Assign the starting point as 1

    checkFirstRowCol(map, hike, row, col); // Call a function to check the first row and column for reachable points

    if (hike[0][1] == 0 && hike [1][0] == 0){ //If the points adjacent to the starting point are unreachable
        return; //Then exit early; there is no point going through rest of the function
    }

    // If no early return, then go through the rest of the matrix to plot the hiking route
    do{
       modified = 0; //Reset modification parameter to zero: No modification has taken place yet for this iteration

       for (i = 1; i < row; i++){ //Scan through the matrix rows and columns
            for (j = 1; j < col; j++){

                if (hike[i][j] == 1){ //Check whether the test entry was already marked as reachable
                    continue; //If so, continue to next iteration (no point testing again)
                }

                //The next set of if-else statements check whether any adjacent cells have already been marked as reachable points
                //If yes, then check whether selected entry (map[i][j])
                if (hike[i - 1][j] == 1){ //Case 1: Test with top adjacent cell
                    if (abs(map[i][j] - map[i - 1][j]) <= 2){
                        hike[i][j] = 1;
                        modified = 1; //Update "modified" to 1 to indicate a modification has taken place
                        continue; //If entry has already been marked as reachable, skip to next iteration
                    }
                }
                if (hike[i][j - 1] == 1){ //Case 2: Test with left adjacent cell
                    if (abs(map[i][j] - map[i][j - 1]) <= 2){
                        hike[i][j] = 1;
                        modified = 1;
                        continue;
                    }
                }
                if (i != row - 1 && hike[i + 1][j] == 1){ //Case 3: Test with bottom adjacent cell
                    //Note the i != row - 1 checks that map[i][j] is not at the bottom of the matrix (to prevent segmentation fault)
                    if (abs(map[i][j] - map[i + 1][j]) <= 2){
                        hike[i][j] = 1;
                        modified = 1;
                        continue;
                    }
                }
                if (j != col - 1 && hike[i][j + 1] == 1){ //Case 4: Test with right adjacent cell
                    //Note the j != col - 1 checks that map[i][j] is not at the rightmost of the matrix (to prevent segmentation fault)
                    if (abs(map[i][j] - map[i][j + 1]) <= 2){
                        hike[i][j] = 1;
                        modified = 1;
                        continue;
                    }
                }
            }
       } //End of matrix scanning loops
    } while (modified == 1); //End of outer do-while loop. Loop will terminate when no more modification has taken place

}

// Helps the getHikeTrail function check for reachable points along the first row and column (make it look  less messy)
void checkFirstRowCol(int map[][MAX], int hike[][MAX], int row, int col){

    int i, j; //Loop counters for row and column respectively

    for (j = 1; j < col; j++){ //Search along the first row
        if (abs(map[0][j] - map[0][j - 1]) <= 2){
            hike[0][j] = 1;
        }
        else {
            break; //If no reachable point is found, the rest of the row is unreachable (for now)
        }
    }
    for (i = 1; i < row; i++){ //Search along the first column
        if (abs(map[i][0] - map[i - 1][0]) <= 2){
            hike[i][0] = 1;
        }
        else {
            break; //If no reachable point is found, the rest of the column is unreachable (for now)
        }
    }
}

// Read in the data for the contour map
void scanArray(int array[][MAX], int row, int col) {
	int r, c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			scanf("%d", &array[r][c]);
		}
	}
}

// Print the 2D map
void printArray(int array[][MAX], int row, int col) {
	int r, c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			printf("%d ", array[r][c]);
		}
		printf("\n");
	}
}

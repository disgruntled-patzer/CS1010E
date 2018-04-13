// CS1010E Programming Methodology
// Problem Set 4 Exercise #14: tiles.c
//
// This program computes the difference
// in cost between the cheapest tile
// and the most expensive tile.
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

#define MAX_NUM 20  // max number of tiles

typedef struct {
	int length;
	int width;
	double price;

} tile_t;

int scan_tiles(tile_t tiles[]);
double difference(tile_t tiles[], int numTiles);

int main(void) {

	int numTiles;  // actual number of tiles read in

	tile_t tiles[MAX_NUM];

	numTiles = scan_tiles(tiles);

	printf("Largest difference = $%.2f\n", difference(tiles, numTiles));

	return 0;
}


// Read tiles' data into array tiles
// returns the number of tiles read
int scan_tiles(tile_t tiles[]) {

    int numTiles;
    int a; //Loop counter

	printf("Enter the number of tiles: ");
    scanf("%d", &numTiles);

	printf("Enter data for %d tiles:\n", numTiles);
    for (a = 0; a < numTiles; a++){
        scanf ("%d %d %lf", &tiles[a].length, &tiles[a].width, &tiles[a].price);
    }

	return numTiles;
}


// Return the difference in cost between cheapest
// tile and most expensive tile in the array tiles
double difference(tile_t tiles[], int numTiles) {

    double max = tiles[0].price * (tiles[0].length * tiles[0].width);
    double min = tiles[0].price * (tiles[0].length * tiles[0].width);
    //Max and min tile price in the array. They are both assigned to the first tile (0th entry)
    int a; //Loop counter
    double temp; //A temporary variable to store the price of the tiles

    for (a = 1; a < numTiles; a++){
        temp = tiles[a].price * (tiles[a].length * tiles[a].width);
        if (temp > max){ //If the price of the checked tile is greater than the current max price, update max
            max = temp;
        }
        if (temp < min){ //Same for min
            min = temp;
        }
    }

	return max - min;
}

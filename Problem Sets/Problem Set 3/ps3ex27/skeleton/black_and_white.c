// CS1010E Programming Methodology
// Problem Set 3 Exercise #27: black_and_white.c
//
// This program flips or rotates a square matrix.
//
// Lau Yan Han

#include <stdio.h>
#define N 10

int read_img(int img[N][N]);
void flip(int img[N][N], int size);
void rotate(int img[N][N], int size);
void print_img(int img[N][N], int size);
void transfer_img(int img[N][N], int img_temp[N][N], int size); //Used in flip and rotate functions

int main(void) {

    int choice; //User-input choice of flip or rotate
    int img[N][N], size; //matrix called img and its corresponding size

    size = read_img (img);

	printf("Enter choice:\n(1) flip\n(2) rotate\n");
	scanf("%d", &choice);

	printf("Original image:\n");
	print_img(img, size);

	switch (choice){
	    case 1:
            flip(img, size);
	        printf("Flipped image:\n");
	        print_img(img, size);
	        break;
        case 2:
            rotate(img, size);
            printf("Rotated image:\n");
            print_img(img, size);
            break;
        default:
            break;
	}

	return 0;
}

// Read in a black-and-white image, return its size
int read_img(int img[N][N]) {

    int size, row, col;

	printf("Enter the size of image: ");
	scanf("%d", &size);

	printf("Enter image:\n");
	for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            scanf("%d", &img[row][col]);
        }
	}

	return size;
}

// Flip the img upside down
void flip(int img[N][N], int size) {

	int row, col;
	int img_temp[N][N]; //Temporary img array to hold entries before the original img is flipped

	transfer_img(img, img_temp, size);

	for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            img[size - row - 1][col] = img_temp[row][col];
            //Transfer the entries from img_temp to its corresponding flipped entry in the original img
        }
	}
}

// Rotate the img 90 degree clockwise
void rotate(int img[N][N], int size) {

	int row, col;
	int img_temp[N][N]; //Temporary img array to hold entries before the original img is rotated
	//int axis = size/2; //Central entry which acts as the axis/pivot upon which image is rotated

	transfer_img(img, img_temp, size);

	for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            img[row][col] = img_temp[size - col - 1][row];
            //Transfer the entries to original img from its corresponding flipped entry in the img_temp
        }
	}

}

// Transfer the entries from img to a temporary img array before the flip/rorate process
void transfer_img(int img[N][N], int img_temp[N][N], int size){

    int row, col;

    for (row = 0; row < size; row++){
        for (col = 0; col < size; col++){
            img_temp[row][col] = img[row][col];
        }
    }

}


// Print out a binary img
// Complete and given
void print_img(int img[N][N], int size) {

	int row, col;
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			printf("%d ", img[row][col]);
		}
		putchar('\n');
	}
}

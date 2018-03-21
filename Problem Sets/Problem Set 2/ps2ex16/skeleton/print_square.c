// CS1010E Programming Methodology
// Problem Set 2 Exercise #16: print_square.c
//
// Reads a number input by user and prints a square with dimensions equal to the number
//
//
// Lau Yan Han

#include <stdio.h>

void square_limits (int k); //For 1st and last line
void square_middle (int k); //For second to second-last line (if k > 2)

int main(void) {

    int k;
    int counter; //Used in the "for" loop for second to second last line

	printf("Enter k: ");
	scanf("%d",&k);

	square_limits(k);// print first line
	printf("\n");


	if (k > 2){ //For a square of 2, only the first and last line is necessary

        for (counter = 2; counter <= k - 1; counter++){ // print second to second last line
            square_middle(k);
            printf ("\n");
        }

	}

	square_limits(k);// print last line
	printf ("\n"); //I KEEP FORGETTING THIS AND GET FAILED BY CODECRUNCH OMG ):

	return 0;
}

void square_limits (int k) {

    int a;
    for (a = 1; a <= k; a++){
        printf ("*");
    }

}

void square_middle (int k){

    int b;

    printf ("*");
    for (b = 2; b <= k - 1; b++){
        printf (" ");
    }
    printf ("*");

}

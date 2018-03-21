// CS1010E Programming Methodology
// Problem Set 1 Exercise #16: magnitude.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

    float magnitude;

	printf("Magnitude: ");
	scanf ("%f",&magnitude);

	if (magnitude < 4.0){
        printf("Classification: Minor\n");
	}
    else if (magnitude >= 4.0 && magnitude < 6.0){
        printf("Classification: Moderate\n");
    }
    else if (magnitude >= 6.0 && magnitude < 6.9){
        printf("Classification: Strong\n");
    }
    else {
        printf("Classification: Major\n");
    }
	return 0;
}

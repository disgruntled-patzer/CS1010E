// CS1010E Programming Methodology
// Problem Set 2 Exercise #15: pattern.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

	int count;   // number of #
	int i, j;

	printf("Enter count: ");
	scanf ("%d", &count);

	for (i = 1; i <= count; i++){
        printf("#");
        for (j = 1; j <= i; j++){
            printf("-");
        }
	}
	printf("\n");

	return 0;
}

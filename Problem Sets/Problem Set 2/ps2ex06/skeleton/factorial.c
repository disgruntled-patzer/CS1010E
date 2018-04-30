// CS1010E Programming Methodology
// Problem Set 2 Exercise #06: factorial.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

    int n, i, result;

	printf("Enter n: ");
	scanf("%d", &n);
	result = n;

    for (i = n - 1; i > 0; i--){
        result = result * i;
    }
    printf("%d\n", result);

	return 0;
}

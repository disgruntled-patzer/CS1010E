// CS1010E Programming Methodology
// Problem Set 2 Exercise #07: multiple_3_5.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

    int n, i, result = 0;

	printf("Enter n: ");
    scanf("%d", &n);

    for (i = 3; i < n; i++){ //start from 3 since 1 or 2 cannot be multiples of 3 or 5. Also, note that n is not included
        if (i % 3 == 0 || i % 5 == 0){
            result++;
        }
    }
    printf("%d\n", result);

	return 0;
}

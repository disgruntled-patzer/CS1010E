// CS1010E Programming Methodology
// Problem Set 2 Exercise #03: age.c
//
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

    int age, attempts = 0;

    do {
       printf("Enter age: ");
       scanf("%d", &age);
       attempts++;
    } while (age < 1 || age > 100);

	printf("Your age is %d\n", age);
	printf("Number of attempts = %d\n", attempts);

	return 0;
}

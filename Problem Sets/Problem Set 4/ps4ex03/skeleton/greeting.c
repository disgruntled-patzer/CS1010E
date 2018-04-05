// CS1010E Programming Methodology
// Problem Set 4 Exercise #03: greeting.c
//
// This program reads age and gender of a person,
// print out corresponding information.
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

    int age;
    char gender;

	printf("Your age? ");
	scanf("%d", &age);
	scanf("%c", &gender); //Scan in the "enter" (\n) key to prevent it from messing with the gender character

	printf("Your gender? ");
	scanf("%c", &gender);

    if (age < 18){
        if (gender == 'M'){
            printf("Hello boy\n");
        }
        else {
            printf("Hey girl\n");
        }
    }
    else {
        if (gender == 'M'){
            printf("Hello Mr.\n");
        }
        else {
            printf("Hey Ms.\n");
        }
    }

	return 0;
}

// CS1010E Programming Methodology
// Problem Set 4 Exercise #09: palindromes.c
//
// This program reads a list of input strings,
// reports how many of them are palindrome.
//
// Lau Yan Han

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 81

int count_palindrome(char str[]);
void read_string(char str[]);
int is_palindrome(char str[]);

int main(void) {

	int count; // number of palindrome strings

	char str[MAX_LEN];

	count = count_palindrome(str);

	printf("Number of palindromes = %d\n", count);

	return 0;
}


// Count the number of palindromes
// in the input strings
int count_palindrome(char str[]) {

    int num; //Number of strings
    int a, b; //Used for loops
    int count = 0; //Number of palindromes
    int len;

	printf("How many strings? ");
	scanf("%d", &num);

	printf("Enter %d strings, each on a line:\n", num);
	read_string(str);
	/*Apparently the extra read_string() line above is needed, because without it, in the first input
	where the user scans into num and hits "enter", the \n key will be read into the string somehow
	and enter the loop straightaway, incrementing "a" by 1 and messing around with the result. Thus
	this extra read_string line "absorbs" the additional \n input so that it will not affect the loop*/

    // This loop reads user-input strings one by one and checks whether each string is palindromic
	for (a = 1; a <= num; a++){
        read_string(str); //Scan in the string
        if (is_palindrome(str) == 1){
            count++; //If string is a palindrome, increment number of palindromes by 1
        }
        // printf("%d\n", count); Debugging
	}

	return count;
}


// Read one string using fgets and store into str
void read_string(char str[]) {

    int len;

    fgets(str, MAX_LEN, stdin);
    len = strlen(str); //Find the length of the string
    if (str[len - 1] == '\n'){
        str[len - 1] = '\0'; //If the last part of the string has the enter key, replace it with null
    }

}


// Check if str is a palindrome or not
// Return 1 if so, 0 otherwise
int is_palindrome(char str[]) {

    int a = 0, b = strlen(str) - 1; //Used in the loop
    // a starts at the beginning of the string, b starts at the end of the string, they scan towards each other

    while (a <= b){ //While a and b haven't collided
        if (isalpha(str[a]) == 0){
            a++; //If entry that a 'points' to is not a letter, skip to the next entry
        }
        else if (isalpha(str[b]) == 0){
            b--; //Same for b
        }
        else { //If both a and b are pointing to letters
            if (tolower(str[a]) != tolower(str[b])){ //See whether the letters correspond ("tolower" helps to ignore upper/lower case)
                return 0; //Early return if they don't
            }
            else {
                a++;
                b--; //If they are the same, move a and b closer to each other for the next iteration
            }
        }
    }

	return 1; //If loop exits without returning 0, string is palindromic
}

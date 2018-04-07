// CS1010E Programming Methodology
// Problem Set 4 Exercise #07: my_str_functions.c
//
// This program writes our own string functions:
// my_strlen(), my_strcpy(), my_strcat() and my_strcmp().
//
// Lau Yan Han

#include <stdio.h>
#include <string.h>
#define MAX 100

void read_string(char str[]);
int my_strlen(char s[]);
void my_strcpy(char s1[], char s2[]);
void my_strcat(char s1[], char s2[]);
int my_strcmp(char s1[], char s2[]);

int main(void) {

	/** main function is complete **/

	char s1[MAX], s2[MAX];

	printf("Enter s1: ");
	read_string(s1);

	printf("Enter s2: ");
	read_string(s2);

	printf("my_strlen(s1) returns %d\n", my_strlen(s1));

	printf("my_strlen(s2) returns %d\n", my_strlen(s2));

	printf("my_strcmp(s1, s2) returns %d\n", my_strcmp(s1, s2));

	my_strcat(s1, s2);
	printf("my_strcat(s1, s2) returns %s\n", s1);

	my_strcpy(s1, s2);
	printf("my_strcpy(s1, s2) returns %s\n", s1);

	return 0;
}

// Read a string from user input
void read_string(char str[]) {

	/** read_string function is complete **/

	int len;

	fgets(str, MAX, stdin);
	len = strlen(str);
	if (str[len-1] == '\n') {
		str[len-1] = '\0';
	}
}

// Return the number of characters in string
// before termination null character
int my_strlen(char s[]) {

    int len = 0;

    while (s[len] != '\0'){
        len++;
    }

	return len;
}

// Copy string s2 to s1, including the
// terminating null character
void my_strcpy(char s1[], char s2[]) {

    int a = 0; //Loop counters

    while (s2[a] != '\0'){
        s1[a] = s2[a]; //While null character in s2 hasn't been reached, assign everything in s2 to s1
        a++;
    }
    s1[a] = '\0'; //Once out of the loop, terminate the end of the newly updated s1 with the null character
}

// Append a copy of string s2, including
// '\0', to the end of string s1
void my_strcat(char s1[], char s2[]) {

	int a = 0; //Loop counter. NOTE: PLEASE ALWAYS INTIALIZE THIS TO ZERO TO AVOID SEGMENTATION FAULT
	int len1 = my_strlen(s1); //Length of string 1

	while (s2[a] != '\0'){
        s1[len1 + a] = s2[a]; //While null character in s2 hasn't been reached, assign everything in s2 to tail of s1
        //Note: The len1 - 1 is to get rid of the \0 character at the end of s1
        a++;
	}
	s1[len1 + a] = '\0'; //Once out of the loop, terminate the end of the newly updated s1 with the null character

}

// Compare s1 and s2 character by character
// Return 15 if s1 > s2, -15 if s1 < s2, or 0 if s1 = s2.
// Return value 15 is just an example.
int my_strcmp(char s1[], char s2[]) {

    int a = 0; //Loop counter

    while (s1[a] == s2[a]){
        if (s1[a] == 0){
            return 0; // Edge case: If s1 and s2 are identical, they will terminate (\0) at the same time, return 0 when it happens
        }
        a++;
    } //Break out of loop once s1 and s2 hits different characters
    //Then proceed to compare the ASCII of these different characters
    if (s1[a] > s2[a]){
        return 15;
    }
    else {
        return -15; //Note: No need to take into account s1 == s2 since that is already done in the loop
    }

    //stub

}

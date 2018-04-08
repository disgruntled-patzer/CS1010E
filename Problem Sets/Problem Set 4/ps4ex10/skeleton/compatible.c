// CS1010E Programming Methodology
// Problem Set 4 Exercise #10: compatible.c
//
// This program removes common characters
// in two names, ignoring cases. Then check
// whether the remains two strings both have
// odd or even characters.
//
// Lau Yan Han

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Name has at most 35 characters
#define MAXLEN 36

void read_name(char name[]);
void match(char name1[], char name2[], int *count1_p, int *count2_p);

int main(void) {

	char name1[MAXLEN], name2[MAXLEN];
	int remain1, // number of remaining letters in name1
			remain2; // and name2 after matching

	printf("Enter 2 names below:\n");
	read_name(name1); // do not remove/change this line
	read_name(name2); // do not remove/change this line

	// Call the match() function here
    match(name1, name2, &remain1, &remain2);

	printf("Number of letters remaining in 1st name = %d\n",
			remain1);
	printf("Number of letters remaining in 2nd name = %d\n",
			remain2);

    if ((remain1%2 == 0 && remain2%2 == 0) || (remain1%2 != 0 && remain2%2 != 0)){
        printf("The names are compatible.\n");
    }
	else {
        printf("The names are not compatible.\n");
	}

	return 0;
}

// Read a name (may contain spaces) using fgets
void read_name(char name[]) {

	int len; //Length of name

	fgets(name, MAXLEN, stdin);
	len = strlen(name);
	if (name[len - 1] == '\n'){
        name[len - 1] = '\0';
	}

}

// We cross out common characters from both names,
// and return the number of remaining letters in both names.
void match(char name1[], char name2[], int *count1_p,
		int *count2_p) {

	int a1, a2; //Loop counters running through name 1 and name 2 respectively
	*count1_p = 0;
	*count2_p = 0; //Intialize both pointers to zero

    // To 'cancel' a letter, use the number 0 as an indicator
	for (a1 = 0; name1[a1] != '\0'; a1++){
        if (isalpha(name1[a1]) < 1){
            continue; //If the character in name1 is already 'cancelled' or is a space, skip to next character
        }
        for (a2 = 0; name2[a2] != '\0'; a2++){ //For each character in name1, compare it with the characters in name2
            if (isalpha(name2[a2]) < 1){ //If the character in name2 is already 'cancelled' or is a space, skip to next character
                continue;
            }
            if (tolower(name1[a1]) == tolower(name2[a2])){ //If a similar character (ignoring case) is sound in name1 and name2
                name1[a1] = '0';
                name2[a2] = '0'; //Cancel out the characteres
                break; //Then stop scanning through name2, and continue to next character in name1
            }
        }
	}
    //The next two loops count the number of characters remaining in name1 and name2
	for (a1 = 0; name1[a1] != '\0'; a1++){
        if (isalpha(name1[a1]) >= 1){
            *count1_p = *count1_p + 1;
        }
	}
	for (a2 = 0; name2[a2] != '\0'; a2++){
        if (isalpha(name2[a2]) >= 1){
            *count2_p = *count2_p + 1;
        }
	}

}

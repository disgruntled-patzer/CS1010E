// CS1010E Programming Methodology
// Problem Set 4 Exercise #05: date_convertion.c
//
// This program reads a string in the UK date format
// and outputs the equivalent American format.
//
// Lau Yan Han

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 20 // Max possible length for user input UK date
// Note that longest possible month string (September) will give a total string length of 18, add two for \n and \0

int read_date (char UK[N]);
void convert (char UK[N], int len);

int main(void) {

    char UK [N]; // User input for UK format

    int len; //Length of input string

	printf("Enter date in UK format: ");
	len = read_date(UK);

	printf("Date in American format: ");
	convert (UK, len);

	return 0;
}

int read_date(char UK[N]){

    int len; //Length of input string

    fgets(UK, N, stdin);
    len = strlen(UK);
    if (UK[len - 1] == '\n'){
        UK[len - 1] = '\0';
    }

    return len;
}

void convert(char UK[N], int len){

    int a = 0; //Loop counter for input UK string
    char date[3], month[N], year[5]; //Strings to hold date, month, year (note that date and year are 1 more than required (to hold \0)
    int d = 0, m = 0, y = 0; //Loop counters for date, month and year
    int filled = 0; //Condition variable which is used to read entries into date and year

    //Loop 1: Scans through the user input UK string
    for (a = 0; a < len; a++){
        //Since only the month is comprised of letters, assign the letters to the month array
        if (isalpha(UK[a]) >= 1){
            month[m] = UK[a];
            //printf("%d %c\n", isalpha(UK[a]), UK[a]);
            m++; //At the end of this loop, m will contain the length of month array
        }
        //Once the first non-letter is detected, break from the loop
        else {
            //printf("%d %c\n", isalpha(UK[a]), UK[a]);
            month[m] = '\0'; //Assign null after the last letter in the month array (to prevent messy outputs)
            break;
        }
    }

    //Loop 2: Scans the date and year digits in the input UK string and copies them into the date and year array
    for (a = m + 1; a < len; a++){
        //Note that m + 1 is the position in the UK string array where the date starts (assumption!)

        if (isdigit(UK[a]) == 0){ //If 'a' hits an entry which isn't a digit, this indicates that 'a' has already passed the date and is moving to the year
            filled = 1; //Thus set 'filled' to 1 to indicate that date array is completed
        }

        if (filled == 0){ //If date array hasn't been completed, assign the digits to the date array
            date[d] = UK[a];
            d++;
        }
        else { //For entries in the UK string array that come after the date
            if (isdigit(UK[a]) == 0){ // Any nondigit entry will not be part of the year
                continue; //So if 'a' hits a nondigit entry, skip to the next iteration (to check the next entry)
            }
            else { //Any subsequent digits that 'a' hits will be assigned to the year array
                 year[y] = UK[a];
                 y++;
            }
        }

    }
    date[d] = '\0';
    year[y] = '\0'; //Assign null after the last digits in the date and year array (to prevent messy outputs)

    printf("%s %s %s\n", date, month, year);

}

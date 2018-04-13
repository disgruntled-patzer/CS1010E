// CS1010E Programming Methodology
// Problem Set 4 Exercise #15: birthday.c
//
// This program reads in a list of birthdays
// and checks if there exists two birthdays
// of the same day and month.
//
// Lau Yan Han

#include <stdio.h>
#define MAX 25

typedef struct {
	int day, month;
} date_t;

int read_birthdays(date_t bday[]);
int share_birthday(date_t bday[], int num);

int main(void) {

    date_t bday[MAX];

    int size = read_birthdays(bday); //Number of people in group

	printf("Group of %d having same birthday: ", size);

	if (share_birthday(bday, size) == 1){
        printf("Yes\n");
	}
	else {
        printf("No\n");
	}

	return 0;
}

// Read in all birthdays
// Return the number of birthdays read
int read_birthdays(date_t bday[]) {

    int size; //Number of people in group
    int a; //Loop counter

	printf("How many birthdays to input? ");
    scanf("%d", &size);

	printf("Enter %d birthdays, day followed by month each:\n", size);

	for (a = 0; a < size; a++){
        scanf("%d %d", &bday[a].day, &bday[a].month);
	}

	return size;
}

// Check if any two birthdays in the array are the same
// Return 1 if so, or 0 otherwise
int share_birthday(date_t bday[], int num) {

    int a, b; //Loop counter

    for (a = 0; a < num; a++){ //For each entry in the array
        for (b = a + 1; b < num; b++){ //Scan through the subsequent entries
            if (bday[a].month == bday[b].month && bday[a].day == bday[b].day){
                return 1; //If a match is found, return 1
            }
        }
    }

	return 0;  // If no match is found, return 0
}

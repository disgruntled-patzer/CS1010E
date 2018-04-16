// CS1010E Programming Methodology
// Problem Set 4 Exercise #17: roster.c
//
// This program reads student number and major,
// and prints out the student roster in
// ascending order of student number.
//
// Lau Yan Han

#include <stdio.h>
#include <string.h>
#define NUM_STUD 1000  // max 1000 students in class

typedef struct {
	char number[10];    // student number
	char major[15];
} student_t;

int read_roster(student_t roster[]);
void sort_roster(student_t roster[], int size);
void print_roster(student_t roster[], int size);

int main(void) {

	int size;  // actual number of students
	student_t roster[NUM_STUD]; // class roster

	// read student info.
	size = read_roster(roster);

	// sort roster accoding to ascending order of student
	sort_roster(roster, size);

	// print roster
	print_roster(roster, size);

	return 0;
}

// Read student and major of students into array 'roster',
// return the number of students read.
int read_roster(student_t roster[]) {

    int size, a;

	printf("Enter the number of students in class: ");
	scanf("%d", &size);
	getchar(); //"Absorbs" the \n key input during scanf of size, so that it will not mess around with the next string input

	printf("Enter student number and major of each student:\n");
	for (a = 0; a < size; a++){
        scanf("%s %s", roster[a].number, roster[a].major);
	}

	return size;  // stub
}

// Sort roster according to ascending order of student number
void sort_roster(student_t roster[], int size) {

	int swapped = 1, a, limit = size; //Variables used for Enhanced Bubble Sort Algorithm
	student_t temp; //Temporary holding structure for student data when a swap takes place

	do {
        swapped = 0;
        for (a = 1; a < limit; a++){
            if (strcmp(roster[a - 1].number, roster[a].number) > 0){
                //strcmp: Returns positive value if first string is greater than second string
                //Thus, if previous entry is greater than next entry, perform the swap
                strcpy(temp.number, roster[a - 1].number); //Use stringcopy function instead of normal assign function when dealing with strings
                strcpy(temp.major, roster[a - 1].major);
                strcpy(roster[a - 1].number, roster[a].number);
                strcpy(roster[a - 1].major, roster[a].major);
                strcpy(roster[a].number, temp.number);
                strcpy(roster[a].major, temp.major);
                swapped = 1; //Indicate that swap has taken place
            }
        }
        limit--; //At end of inner loop, "largest" number has been moved to the rightmost entry, thus decrease limit by 1
	}
     while (swapped == 1); //If no more swaps occur, list is already sorted

}

// Print the roster
// Complete and given
void print_roster(student_t roster[], int size) {

	int i;

	printf("Sorted list:\n");
	for (i = 0; i < size; i++) {
		printf("%-10s%-12s\n", roster[i].number, roster[i].major);
	}
}

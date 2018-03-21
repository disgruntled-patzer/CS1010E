// CS1010 Programming Methodology
// Problem Set 1 Exercise #20: younger.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int test_value (int value1, int value2); //Tests whether Value 1 or Value 2 (which can be date, month or year) is smaller

int test_value (int value1, int value2){
    if (value1<value2){return 1;} //If value 1 is smaller, return 1
    else if (value1>value2) {return 2;} //If Value 2 is smaller, return 2
    else {return 0;} //If both values are equal, return 0
}

int main(void) {

	int date1; int month1; int year1; //Birthday of Tamil
	int date2; int month2; int year2; //Birthday of Alice

	printf("Enter birthday for Tamil (day month year): ");
	scanf ("%d %d %d", date1, month1, year1);

	printf("Enter birthday for Alice (day month year): ");
    scanf ("%d %d %d", date2, month2, year2);

    if (test_value(year1,year2)=0 && test_value(month1,month2)=0 && test_value(date1,date2)=0)
        {
        printf("Tamil and Alice are of the same age\n");
        }
    else if (test_value (year1,year2)=1 || (test_value (year1,year2)=0 && test_value (month1,month2)=1) || ((test_value (year1,year2)=0 && test_value (month1,month2)=0 &&test_value (date1,date2)=1)))
        {
        printf("Tamil is younger\n");
        }
    else
        {
        printf("Alice is younger\n");
        }

	return 0;
}

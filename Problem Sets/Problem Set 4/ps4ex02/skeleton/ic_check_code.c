// CS1010E Programming Methodology
// Problem Set 4 Exercise #02: ic_check_code.c
//
// This program reads an NRIC number
// and produces its check code.
//
// Lau Yan Han

#include <stdio.h>

char generate_code(int num);

int main(void) {

	/** main function is complete **/

	int num;
	char code;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &num);

	code = generate_code(num);

	printf("Check code is %c\n", code);

	return 0;
}

// Generate check code according
// to the given algorithm
char generate_code(int num) {

    int result = 0;
    int x = 1; //Counter used in the loop to measure weight of each digit
    char code;

    while (num > 0){
        x++; //Increment s to the position of the next digit (which has weight of 'digit position' + 1, except the 7th digit)
        if (x == 8){ //For the 7th digit (which is supposed to have weight 7 + 1 = 8)
            x = 2; //Weight of the 7th digit is actually 2 and not 8 (I don't know why)
        }
        result = result + (num%10)*x;
        num = num/10;
    }

    result = result%11;
    result = 11 - result;

    switch (result){
        case 1:
            code = 'A';
            break;
        case 2:
            code = 'B';
            break;
        case 3:
            code = 'C';
            break;
        case 4:
            code = 'D';
            break;
        case 5:
            code = 'E';
            break;
        case 6:
            code = 'F';
            break;
        case 7:
            code = 'G';
            break;
        case 8:
            code = 'H';
            break;
        case 9:
            code = 'I';
            break;
        case 10:
            code = 'Z';
            break;
        case 11:
            code = 'J';
            break;
    }

	return code;
}

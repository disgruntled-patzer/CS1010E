// CS1010E Programming Methodology
// Problem Set 4 Exercise #01: calculator.c
//
// This program implements a simple calculator
// that can perform addition, subtraction,
// multiplication and division on integers.
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

    int a, b; //a, b = two digits to be input in the calculator
    char opr; //Operator
    int i; //Used in the loop
    int num; //Number of operations

	printf("Enter the number of operations: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++){
        scanf("%d %c %d", &a, &opr, &b);
        if (opr == '+'){
            printf("%d%c%d = %d\n", a, opr, b, a + b);
        }
        else if (opr == '-'){
            printf("%d%c%d = %d\n", a, opr, b, a - b);
        }
        else if (opr == '*'){
            printf("%d%c%d = %d\n", a, opr, b, a * b);
        }
        else { //Divide (/)
            printf("%d%c%d = %.2f\n", a, opr, b, 1.0*a/b);
        }
	}

	return 0;
}

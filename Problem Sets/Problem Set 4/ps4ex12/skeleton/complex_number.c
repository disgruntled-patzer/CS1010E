// CS1010E Programming Methodology
// Problem Set 4 Exercise #12: complex_number.c
//
// This program performs arithmetic calculation
// on complex numbers.
//
// Lau Yan Han

#include <stdio.h>

typedef struct {
	int a, b;   // a + bi
} complex_t;

void add (complex_t *num1, complex_t num2);
void subtract (complex_t *num1, complex_t num2);
void multiply (complex_t *num1, complex_t num2);
void divide (complex_t *num1, complex_t num2);

int main(void) {

	char operator;
	complex_t op1, op2;

    scanf("%d %d", &op1.a, &op1.b);
	printf("Complex number (%d + %di) created\n", op1.a, op1.b);

	do {
        scanf(" %c", &operator); // without space in front of %c, operator will read in the \n from the previous entry
        if (operator == 'q'){
            break; //If user types q, break from the loop
        }

        scanf("%d %d", &op2.a, &op2.b);

        switch (operator){
            case '+':
                add(&op1, op2);
                printf("After addition: (%d + %di)\n", op1.a, op1.b);
                break;
            case '-':
               subtract(&op1, op2);
                printf("After subtraction: (%d + %di)\n", op1.a, op1.b);
                break;
            case '*':
                multiply(&op1, op2);
                printf("After multiplication: (%d + %di)\n", op1.a, op1.b);
                break;
            case '/':
                divide(&op1, op2);
                printf("After division: (%d + %di)\n", op1.a, op1.b);
                break;
            default:
                continue; //Any invalid input sends the user back to the start of the loop to enter again
        }
     } while (operator != 'p');

	return 0;
}

// Adds num2 to num1, updates num1 via a structure pointer
void add (complex_t *num1, complex_t num2){
    num1->a = num1->a + num2.a;
    num1->b = num1->b + num2.b;
}

// Subtracts num2 from num1, updates num1 via a structure pointer
void subtract (complex_t *num1, complex_t num2){
    num1->a = num1->a - num2.a;
    num1->b = num1->b - num2.b;
}

// Multiplies num2 and num1, updates num1 via a structure pointer
void multiply (complex_t *num1, complex_t num2){

    complex_t temp = *num1; //Temporarily stores the value for num1 (since num1 will be modified later)

    num1->a = (temp.a * num2.a) - (temp.b * num2.b);
    num1->b = (temp.b * num2.a) + (temp.a * num2.b);
}

// Divides num1 by num2, updates num1 via a structure pointer
void divide (complex_t *num1, complex_t num2){

    complex_t temp = *num1; //Temporarily stores the value for num1 (since num1 will be modified later)

    num1->a = ( (temp.a * num2.a) + (temp.b * num2.b) ) / (num2.a * num2.a + num2.b * num2.b);
    num1->b = ( (temp.b * num2.a) - (temp.a * num2.b) ) / (num2.a * num2.a + num2.b * num2.b);
}

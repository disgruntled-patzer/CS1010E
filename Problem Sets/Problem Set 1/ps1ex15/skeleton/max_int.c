// CS1010 Programming Methodology
// Problem Set 1 Exercise #15: max_int.c
//
// Finding the maximum integer
//
//
// Lau Yan Han

#include <stdio.h>

// function prototype
int get_max_outer(int num1, int num2, int num3);

int main(void) {

	int num1, num2, num3;

	printf("Enter three integers: ");
    scanf ("%d %d %d",&num1,&num2,&num3);
	printf("Maximum input integer is %d\n",get_max(num1,num2,num3)); //Calls the function get_max to return the max integer

	return 0;
}

// Return the max value among the three inputs
int get_max(int num1, int num2, int num3) {

//If statements: Test between Number 1 and 2, before testing Number 3 against the result
    if (num1>num2){ //Case 1: If Number 1 is bigger than 2
        if (num3>num1){return num3;} //Then check whether Number 3 is bigger than 1
        else {return num1;}
    }
    else{
        if (num3>num2){return num3;} //Case 2: If Number 2 is bigger than 1
        else {return num2;} //Then check whether Number 3 is bigger than 2
    }
}

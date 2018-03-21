// CS1010E Programming Methodology
// Problem Set 2 Exercise #08: fibonacci.c
//
// This program reads a number n by the user and returns the nth number of the Fibonacci sequence
//
//
// Lau Yan Han

#include <stdio.h>

int fib(int n);

int main(void) {

    int n;

	printf("Enter n: ");
	scanf ("%d",&n);

	printf ("%d\n",fib(n));

	return 0;
}

// Return nth term of fibonacci
int fib(int n) {

    int a;
    int b1, b2, b_final;

    for (a = 1; a <= n; a++){
        if (a <= 2){
            b1 = 1;
            b2 = 1;
            b_final = 1;
        }
        else {
            b_final = b1 + b2;
            b1 = b2;
            b2 = b_final;
        }
    }

	return b_final;  // stub
	/* We have seen the word 'stub' many times. What is a 'stub'?
	 *
	 * A stub is a function which is incomplete, but has enough code to
	 * be compiled and work with other functions. When programmers are writing
	 * code together, they frequently use stubs as placeholders until
	 * the programmer responsible has finished the work.
	 * Even if you are working alone, you may use stubs for certain parts
	 * of your code while you are focusing on other parts first. This is the
	 * idea of incremental development.
	 *
	 * In a stub, the body of the function usually contains only a comment
	 * like 'this is a stub'. If the function needs to return a value in order
	 * to compile successfully, the programmer will add a line to return
	 * a dummy value, such as zero.
	 */
}

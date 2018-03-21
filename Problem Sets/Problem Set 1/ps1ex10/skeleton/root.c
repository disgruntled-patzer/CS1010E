// CS1010 Programming Methodology
// Problem Set 1 Exercise #10: root.c
//
// Getting the bigger root of a function
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

// function prototype
double get_root(double a, double b, double c);

int main(void) {

	double a, b, c, root;

	printf("Enter coefficients (a b c): ");
    scanf("%lf %lf %lf",&a,&b,&c);

	root = get_root(a, b, c);

	printf("Bigger root is %.2f\n", root);

	return 0;
}

// Take three coefficients and return the bigger root
double get_root(double a, double b, double c) {

    double root1; double root2;
    root1 = (-b+sqrt((b*b)-4*a*c))/(2*a);
    root2 = (-b-sqrt((b*b)-4*a*c))/(2*a);

    if (root1>root2){
        return root1;
    }
    else {
        return root2;
    }
}

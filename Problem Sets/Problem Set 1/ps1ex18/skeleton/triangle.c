// CS1010E Programming Methodology
// Problem Set 1 Exercise #18: triangle.c
//
// This program tests the type of triangle which 3 different triangles form
//
//
// Lau Yan Han

#include <stdio.h>

int is_triangle (int a, int b, int c);
int is_equilateral (int a, int b, int c);
int is_isoceles (int a, int b, int c);

int main(void) {

    int a, b, c;
    scanf ("%d %d %d", &a, &b, &c);

    if (is_triangle(a, b, c) == 0){
        printf("Not a triangle\n");
    }
    else if (is_equilateral(a, b, c) == 1){
        printf("Equilateral\n");
    }
    else if (is_isoceles(a, b, c) == 1){
        printf("Isosceles\n");
    }
	else {
        printf("Scalene\n");
	}
	return 0;
}

int is_triangle(int a, int b, int c){
    if (a >= b + c || b >= a + c || c >= a + b){
        return 0;
    }
    else {
        return 1;
    }
}

int is_equilateral(int a, int b, int c){
    if (a == b && b == c){
        return 1;
    }
    else {
        return 0;
    }
}

int is_isoceles (int a, int b, int c){
    if (a == b || b == c || a == c){
        return 1;
    }
    else {
        return 0;
    }
}

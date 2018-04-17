// CS1010E Programming Methodology
// Problem Set 4 Exercise #19: fraction.c
//
// This program reads in two fractions,
// checks if they equal and computes their sum.
//
// Lau Yan Han

#include <stdio.h>

typedef struct {
	int numer;  // numerator
	int denom;  // denominator
} fraction_t;

int euclid_gcd(int a, int b);
fraction_t simplify(fraction_t frac);
int equals(fraction_t frac1, fraction_t frac2);
fraction_t add(fraction_t frac1, fraction_t frac2);

int main(void) {

	fraction_t frac1, frac2, frac3;

	printf("Enter 1st fraction: ");
	scanf("%d %d", &frac1.numer, &frac1.denom);
	printf("Enter 2nd fraction: ");
	scanf("%d %d", &frac2.numer, &frac2.denom);

	printf("1st fraction is %d/%d\n", frac1.numer, frac1.denom);
	printf("2nd fraction is %d/%d\n", frac2.numer, frac2.denom);

    if (equals(frac1, frac2) == 1){
        printf("Two fractions are the same.\n");
    }
    else{
        printf("Two fractions are not the same.\n");
    }

    frac3 = add (frac1, frac2);

	printf("%d/%d + %d/%d = %d/%d\n", frac1.numer, frac1.denom, frac2.numer, frac2.denom,
        frac3.numer, frac3.denom);

	return 0;
}

// Check whether two fractions equal
// Return 1 if so, 0 otherwise
int equals(fraction_t frac1, fraction_t frac2) {

    fraction_t temp1 = simplify(frac1);
    fraction_t temp2 = simplify(frac2); //Need to simplify first before comparing

    if (temp1.denom == temp2.denom && temp1.numer == temp2.numer){
        return 1;
    }
    else {
        return 0;
    }
}

// Add frac1 to frac2, return the result
// in the simplified form
fraction_t add(fraction_t frac1, fraction_t frac2) {

    fraction_t sum; //sum of frac1 and frac2

    sum.numer = frac1.numer * frac2.denom + frac2.numer * frac1.denom;
    sum.denom = frac1.denom * frac2.denom; //Calculate numerator and denominator respectively

    sum = simplify(sum); //Simplify the result

    return sum;
}

fraction_t simplify(fraction_t frac){

    int gcd = euclid_gcd(frac.numer, frac.denom); //Greatest common divisor of numerator and denominator
    fraction_t result; //The final simplified form

    result.numer = frac.numer/gcd;
    result.denom = frac.denom/gcd;

    return result;

}

// Return greatest common divisor of a and b
int euclid_gcd(int a, int b) {

    int rem; //Remainder (When computing a = q*b + rem or b = q*a + rem)

    if (a == b){
        return a;
    }
    else if (a > b){
       while (b > 0){
            rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    else { // b > a
        while (a > 0){
            rem = b % a;
            b = a;
            a = rem;
        }
        return b;
    }
}

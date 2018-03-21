// CS1010E Programming Methodology
// Problem Set 1 Exercise #21: sat.c
//
// This program calculates the percentile and IQ based on SAT score
//
//
// Lau Yan Han

#include <stdio.h>

// function prototypes
int compute_percentile(int verbal, int maths, int writing);
double compute_iqscore(int verbal, int maths);

int main(void) {

	int verbal, maths, writing;
	int percentage; // percentile of the SAT score
	double iq;      // IQ score

	printf("Enter scores: ");
	scanf ("%d %d %d",&verbal,&maths,&writing);

	percentage = compute_percentile (verbal,maths,writing);

	printf("The SAT score is in the %d percentile.\n", percentage);

    iq = compute_iqscore (verbal,maths);
	printf("The IQ score is %.2f\n", iq);

	if (iq >= 120 || (verbal > 600 && maths > 600 && writing > 600)){
        printf("Wow, this is amazing!\n");
	}

	return 0;
}

// compute_percentile determines the percentile based on individual scores
int compute_percentile(int verbal, int maths, int writing) {

    int overall,percentage;

    overall = verbal + maths + writing;

    if (overall < 1500){
        percentage = 10;
    }
    else if (overall >= 1500 && overall < 2000){
        percentage = 50;
    }
    else if (overall >= 2000 && overall < 2200){
        percentage = 95;
    }
    else {
        percentage = 99;
    }

	return percentage;
}

// compute_iqscore computes the iq based on a given formula
double compute_iqscore(int verbal, int maths) {

    double iq;
    iq = (0.095 * (double)maths) + (0.003 * (double)verbal) + 50.241;

	return iq;
}

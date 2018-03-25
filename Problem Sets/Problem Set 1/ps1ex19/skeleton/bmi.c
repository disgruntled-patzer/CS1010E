// CS1010E Programming Methodology
// Problem Set 1 Exercise #19: bmi.c
//
// This program calculates the BMI given a person's height and weight
//
//
// Lau Yan Han

#include <stdio.h>
#define FEMALE 0
#define MALE 1
#define UNDERWEIGHT -1
#define ACCEPTABLE 0
#define OVERWEIGHT 1

// function prototype
int body_type(int gender, double weight, double height);

int main(void) {

	int gender;
	double weight,height;
	int type;

	printf("Enter your gender (0 for female, 1 for male): ");
	scanf("%d",&gender);
	printf("Enter your weight (kg) and height (m): ");
	scanf("%lf %lf", &weight, &height);

	type = body_type (gender,weight,height);

	if (type == UNDERWEIGHT){
		printf("Stuff yourself with more food!\n");
	}
	else if (type == ACCEPTABLE){
		printf("Great! Maintain it!\n");
	}
	else{
		printf("Time to join the gym!\n");
	}

	return 0;
}

// Takes gender, weight, height and returns body type
int body_type(int gender, double weight, double height) {

	double BMI = weight/(height*height);
	int type;

	switch (gender){
		case FEMALE:
			if (BMI <= 19){
				type = UNDERWEIGHT;
			}
			else if (BMI > 24){
				type = OVERWEIGHT;
			}
			else {
				type = ACCEPTABLE;
			}
			break;
		case MALE:
			if (BMI <= 20){
				type = UNDERWEIGHT;
			}
			else if (BMI > 25){
				type = OVERWEIGHT;
			}
			else {
				type = ACCEPTABLE;
			}
			break;
	}
	return type;
}

// CS1010 Programming Methodology
// Problem Set 1 Exercise #03: bill.c
//
// This program calculates the bill with service and GST charges
//
//
// Lau Yan Han

#include <stdio.h>

int main(void) {

	double menu_price, service_charge, GST;

	printf("Enter menu price: $");
	scanf ("%lf",&menu_price);
	service_charge = 0.1 * menu_price;
	GST = 0.07 * (service_charge + menu_price);

	printf("10%% Service Charge: $%.2f\n",service_charge);

	printf("7%% GST: $%.2f\n",GST);

	printf("Your total bill: $%.2f\n", menu_price + service_charge + GST);

	return 0;
}

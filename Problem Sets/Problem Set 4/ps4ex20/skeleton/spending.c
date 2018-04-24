// CS1010E Programming Methodology
// Problem Set 4 Exercise #20: spending.c
//
// This program prints the spending of
// a particular customer in descending order.
//
// Lau Yan Han

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
#define MAX_CUSTOMER 20
#define MAX_RECORD 100

typedef struct {
	int id;
	char name[MAX_LENGTH+1];
} customer_t;

typedef struct {
	int cusID;
	char category[MAX_LENGTH+1];
	int spending;
} record_t;

int find_records(customer_t customers[MAX_CUSTOMER], int num_customers,
		record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH],
		record_t result[MAX_RECORD]);
void sort_records(record_t result[MAX_RECORD], int size);

int main(void) {

	char name[MAX_LENGTH];
	customer_t customers[MAX_CUSTOMER];
	record_t records[MAX_RECORD], result[MAX_RECORD];
	int num_cus, num_rec, size; //num_cus = Number of customers, num_rec = Number of records, size = size of result record
	int a; //Loop counter

	printf("Enter the number of customers: ");
	scanf("%d", &num_cus);

	printf("Enter customers:\n");
	for (a = 0; a < num_cus; a++){
        scanf("%d %s", &customers[a].id, &customers[a].name);
	}

	printf("Enter the number of records: ");
	scanf("%d", &num_rec);

	printf("Enter records:\n");

	for (a = 0; a < num_rec; a++){
        scanf("%d %s %d", &records[a].cusID, &records[a].category, &records[a].spending);
	}

	getchar(); //So that the \n entered by user previously doesn't mess with the string input in the next scanf

	printf("Enter name: ");
	scanf("%s", &name);

	size = find_records(customers, num_cus, records, num_rec, name, result);

	if (size == 0){ //If no records are found, length of result array will be zero
        printf("No record can be found for %s\n", name);
	}
	else { //If there are records, sort them before printing
        sort_records(result, size);
        printf("The records for %s are as follows: \n", name);
        for (a = 0; a < size; a++){
            printf("%s %d\n", result[a].category, result[a].spending);
        }
	}

	return 0;
}

// Find all spending records for customer with given 'name'
// and store them into the result array.
// Return the number of elements in result array.
int find_records(customer_t customers[MAX_CUSTOMER], int num_customers,
		record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH],
		record_t result[MAX_RECORD]) {

    int size = 0, i; //size will return size of 'results' array, i is a loop counters
    int key = -1; //Contains the id of the 'name' variable input by the user, initialized to -1 (assume -1 to be invalid id)

    for (i = 0; i < num_customers; i++){
        if (strcmp(customers[i].name, name) == 0){ //Note: Strcmp returns zero if two strings are identical
            key = customers[i].id;
            break; //If the name is found in 'customer' array, assign its corresponding id to the 'key' variable
        }
    }
    if (key == -1){
        return size; //If the name cannot be found, then there are no records so return 0
    }

    for (i = 0; i < num_records; i++){
        if (records[i].cusID == key){ //If the id corresponding to the name is found in the records
            strcpy(result[size].category, records[i].category); //Copy the spending details into 'results' array
            result[size].spending = records[i].spending;
            size++; //And move on to next entry of 'result' array
        }
    }

	return size;
}

// Sort 'result' array in descending order of spendings
void sort_records(record_t result[MAX_RECORD], int size) {

    int i, swapped; //Variables used in Bubble Sort Algorithm
    record_t temp; //Temporary holding structure when swapping entries in result array
    int limit = size; //Initial limit = size, it will decrease by 1 for each iteration

    do { //Enhanced Bubble sort algorithm
        swapped = 0;
        for (i = 1; i < limit; i++){
            if (result[i-1].spending < result[i].spending){ //NOTE: Sort in DESCENDING order, not ascending
                strcpy(temp.category, result[i-1].category);
                strcpy(result[i-1].category, result[i].category);
                strcpy(result[i].category, temp.category);
                temp.spending = result[i-1].spending;
                result[i-1].spending = result[i].spending;
                result[i].spending = temp.spending;
                swapped = 1;
            }
        }
        limit--; //Since the smallest entry has been sorted to the rightmost side, reduce the limit by 1 for the next iteration
    } while (swapped == 1);

}

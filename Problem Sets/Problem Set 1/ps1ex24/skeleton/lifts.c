// CS1010E Programming Methodology
// Problem Set 1 Exercise #24: lifts.c
//
// This algorithm takes two lift command inputs and calculates the time taken and the final storey
//
//
// Lau Yan Han

#include <stdio.h>
#include <stdlib.h>

struct command { //The three digits entered as the lift commands
    int a; //a = first digit, b = second digit and so on
    int b;
    int c;
};

struct liftdata { //The data for the lift which will be modified and displayed (time taken and final storey)
    int time;
    int initial_storey; //initial storey will be used to calculate the differences in storeys between both commands
    int final_storey;
};

int lift_command (struct command liftcommand, int *initialptr, int *finalptr); //Use pointers to modify lift data

int main(void) {

    struct command command1; //First command input
    struct command command2; //Second command input
    struct liftdata lift1;
    struct liftdata lift2;

    lift1.time = 0;
    lift1.initial_storey = 1;
    lift1.final_storey = lift1.initial_storey;
    lift2.time = 0;
    lift2.initial_storey = 1;
    lift2.final_storey = lift2.initial_storey; //Initialize all the liftdata to prevent errors later on

	// first instruction
	printf("Enter 1st instruction: ");
	scanf ("%d %d %d",&command1.a,&command1.b,&command1.c);

	if (command1.a == 1){ //If lift 1 is called
        lift1.time = lift1.time + lift_command(command1,&lift1.initial_storey,&lift1.final_storey);
	} //*initialptr points to initial storey of lift 1 to modify it later on, *finalptr points to final storey of lift 1
	else { //If lift 2 is called
        lift2.time = lift2.time + lift_command(command1,&lift2.initial_storey,&lift2.final_storey);
	}

	// second instruction
	printf("Enter 2nd instruction: ");
	scanf ("%d %d %d",&command2.a,&command2.b,&command2.c);


	if (command2.a == 1){
        lift1.time = lift1.time + lift_command(command2,&lift1.initial_storey,&lift1.final_storey);
	}
	else {
        lift2.time = lift2.time + lift_command(command2,&lift2.initial_storey,&lift2.final_storey);
	}

	printf("Lift 1 took %d sec. and ended at level %d\n",lift1.time,lift1.final_storey);
	printf("Lift 2 took %d sec. and ended at level %d\n",lift2.time,lift2.final_storey);

	return 0;
}

int lift_command(struct command liftcommand, int *initialptr, int *finalptr){

    int lift_time;
    lift_time = 2 * abs(liftcommand.b - *initialptr) + 2 * abs(liftcommand.c - liftcommand.b);
    //Absolute function to make sure the difference is always positive
    //liftcommand.b - *initialptr: The difference between the second number and the initial storey which the lift is on
    //liftcommand.c - liftcommand.b: Difference between third and second numbers

    *finalptr = liftcommand.c; //Assign the value of the third number to the final storey (pointed to by *finalptr)
    *initialptr = liftcommand.c; //Do the same for initial storey: Lift's initial storey is now the destination storey which it reached
    //This is in case the same lift is called again to perform a second command, in which the initial storey is already updated

    return lift_time; //Returns the time in the standard manner, and returns final storey via pointers
}

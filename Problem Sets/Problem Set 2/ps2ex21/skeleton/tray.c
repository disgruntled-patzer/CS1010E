// CS1010E Programming Methodology
// Problem Set 2 Exercise #21: tray.c
//
// This program calculates the minimum perimeter after folding a tray 3 times
//
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>

double calculate_min_perimeter (double length, double breadth);

int main(void) {

    double length,breadth;

	printf("Enter size of tray: ");
	scanf ("%lf %lf",&length,&breadth);

	printf("Minimum perimeter after folding = %.2f\n",calculate_min_perimeter(length,breadth));

	return 0;
}

double calculate_min_perimeter(double length, double breadth){

    int fold_num = 3; //Number of times paper is folded
    int max = 4; //The maximum possible number of perimeter combinations; for folding 3 times, the max number is 4
    double perimeter[max]; //Contains all the possible perimeters in an array
    double length_temp, breadth_temp; //To be used in the loops for calculating perimeters
    int counter;
    double min_perimeter; //Returns the smallest value in perimeter[max]

    /*Each time the tray is folded, either length or breadth decreases by half
    By the end of 3 folds, the "total number of times either length or breadth decreases by half" is 3
    It doesn't matter what the order is, as long as the number of times adds up to 3!
    In total, there are 4 possible combinations: Length folded 3 times; length folded 2 times and breadth folded once;
    length folded once and breadth folded 2 times; breadth folded 3 times
    Thus the following loop goes through all 4 combinations and calculates the perimeter accordingly*/

    for (counter = 0; counter < max; counter++){
        breadth_temp = breadth * pow(0.5 , counter); //breadth_temp = breadth / (2^counter) -> breadth divided by half for the specified number of times
        length_temp = length * pow(0.5 , fold_num - counter);
        perimeter[counter] = 2 * breadth_temp + 2 * length_temp;
        //printf ("%.2f\n",perimeter[counter]); debugging statement
    }

    //The next loop calculates which is the min perimeter out of all the possible perimeters in the array
    min_perimeter = perimeter[0]; //Assign the min_parameter to the first element before starting the loop
    counter = 0;

    for (counter = 0; counter < max; counter++){
        if (perimeter[counter] < perimeter[counter - 1]){
            min_perimeter = perimeter[counter];
        }
        //printf ("%.2f\n",min_perimeter); debugging statement
    }
    return min_perimeter;

}


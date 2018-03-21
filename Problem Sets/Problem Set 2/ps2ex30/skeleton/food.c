// CS1010E Programming Methodology
// Problem Set 2 Exercise #30: food.c
//
// This program calculates a meal combination that maximizes the given budget and number of health-food meals
//
//
// Lau Yan Han

#include <stdio.h>

void best_combination(int budget, int ff_cost, int hf_cost,
		int *final_ff_num, int *final_hf_num);

int main(void) {

    int budget, ff_cost, hf_cost, final_ff_num = 0, final_hf_num = 0;

	printf("Enter budget: $");
    scanf("%d",&budget);

	printf("Enter fast-food cost per meal: $");
	scanf("%d",&ff_cost);

	printf("Enter health-food cost per meal: $");
    scanf("%d",&hf_cost);

    best_combination(budget, ff_cost, hf_cost, &final_ff_num,&final_hf_num);

	printf("Number of fast-food meals = %d\n",final_ff_num);
	printf("Number of health-food meals = %d\n",final_hf_num);

	return 0;
}

// This function returns the number of health-food and fast-food meals (via two pointers) for the best possible combination
void best_combination(int budget, int ff_cost, int hf_cost,
		int *final_ff_num, int *final_hf_num) {

        /*The following set of variables temporarily stores a set of data that will be returned later on
        These data will be replaced if the loop finds a set of more "efficient" data*/
        int ff_temp = 0, hf_temp = 0; //Number of fast-food/health-food meals
        int total_price_temp = 0; //The total price calculated and temporarily stored

        /*This is the data set that will run through the loop and save any desired data to the "temp" set above*/
        int ff_loop = 0, hf_loop; //ff_loop has been initialized to 0 as a starting point for the loop
        int ff_loop_price = ff_loop * ff_cost; //Price of fast-food meals combined. This is needed to avoid some repeated computations in the loop
        int total_price_loop;

        while (ff_loop_price <= budget){ //We select fast food as a indicator (using health food is possible too)
            hf_loop = (budget - ff_loop_price)/hf_cost; //Calculates number of health food meals, given the number of fast food
            total_price_loop = ff_loop_price + hf_loop * hf_cost;

            //The next two sets of if statements are used to determine whether the tested data is "better" than the temporarily stored data
            if (total_price_loop > total_price_temp){
                /*If the calculated total price in the loop is greater than the total price stored (maximizing budget use),
                replace all the temporarily stored data with the new one. Note that we don't need to check
                whether the total price exceeds budget since that is already taken care of in the earlier parts of the loop*/
                ff_temp = ff_loop;
                hf_temp = hf_loop;
                total_price_temp = total_price_loop;
            }
            if (total_price_loop == total_price_temp){
                if (hf_loop > hf_temp){
                    /*If calculated total price in loop = total price stored temporarily, move on to compare
                    number of health food meals. If calculated health food meals is more than the one stored temporarily,
                    replace in similar way to earlier if statement.*/
                    ff_temp = ff_loop;
                    hf_temp = hf_loop;
                    //However, note that total_price_temp does not need to be replaced since it is equal to total_price_loop
                }
            }

            ff_loop++;
            ff_loop_price = ff_loop * ff_cost; //Update fast-food meal number and price to be tested again
        }

        *final_ff_num = ff_temp;
        *final_hf_num = hf_temp;
}

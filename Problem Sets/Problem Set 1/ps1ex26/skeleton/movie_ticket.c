// CS1010E Programming Methodology
// Problem Set 1 Exercise #26: movie_ticket.c
//
// (CS1101J AY2016/17 Sem1 PE1 Ex#2)
// <Replace this with a short program description>
//
//
// Lau Yan Han

#include <stdio.h>

int day_of_the_week(int day, int month);
void print_date(int day, int month);
double ticket_price(int day, int month, int movie_type, int identity, int is_member);

int main(void) {

	/** Main function is complete and you MUST NOT change it **/

	int day, month, movie_type, identity, is_member;
	double price;

	printf("Enter day and month to watch movie: ");
	scanf("%d %d", &day, &month);

	print_date(day, month);

	printf("Enter type of movie (0 for 2D, 1 for 3D): ");
	scanf("%d", &movie_type);

	printf("Enter your identity (0 for student, 1 for senior citizen, 2 for others): ");
	scanf("%d", &identity);

	printf("Are you a movie club member (0 for No, 1 for Yes)? ");
	scanf("%d", &is_member);

	price = ticket_price(day, month, movie_type, identity, is_member);
	printf("Ticket Price: $%.1f\n", price);

	return 0;
}

// day_of_the_month reads the input date and month, and returns which day of the week it is
int day_of_the_week(int day, int month) { // Note: 1st and 15th September 2016 is a Thursday, 1st October 2016 is a Saturday

    int test_day; //This variable is used to test the date/month and map them to a certain day

    if (month == 9 && day >= 15){ //For the month of September

        test_day = (day%7) + 3; //This is to modify such that when 15 is the input, the test_case will return 4, which is a Saturday

    }
    else if (month == 10){ //For the month of October

        test_day = (day%7) + 5; //When 1st October is the input, the test_day will return 6, which is a Saturday

    }

    else {

        test_day = 14; //Dates are out of range so the test_day will return a value that produces an error

    }

    switch (test_day){
        case 0: case 7: //For 0, return Sunday (0).
            //Case 7 is included to take into account the addition effects of test_case in the if_else statements earlier on
            return 0;
            break;
        case 1: case 8: //For 1, return Monday (1) and so on.
            return 1;
            break;
        case 2: case 9:
            return 2;
            break;
        case 3: case 10:
            return 3;
            break;
        case 4: case 11:
            return 4;
            break;
        case 5: case 12:
            return 5;
            break;
        case 6: case 13:
            return 6;
            break;
        default: //If test_case is out of range, don't return anything and the program gives an error
            printf("ERROR\n");
            return 0;
    }

}

// print_date prints out the day depending on the input date and month
// Note: year is always 2016
void print_date(int day, int month) {

    switch (day_of_the_week(day,month)){ //Asks day_of_the_week function to calculate which day of the week it is
        case 0:
            printf("%d/%d/2016 is a Sunday\n",day,month);
            break;
        case 1:
            printf("%d/%d/2016 is a Monday\n",day,month);
            break;
        case 2:
            printf("%d/%d/2016 is a Tuesday\n",day,month);
            break;
        case 3:
            printf("%d/%d/2016 is a Wednesday\n",day,month);
            break;
        case 4:
            printf("%d/%d/2016 is a Thursday\n",day,month);
            break;
        case 5:
            printf("%d/%d/2016 is a Friday\n",day,month);
            break;
        case 6:
            printf("%d/%d/2016 is a Saturday\n",day,month);
            break;

    }


}

// ticket_price calculates the price based on the movie type, day, identity and membership
double ticket_price(int day, int month, int movie_type, int identity, int is_member) {

    double D3_Normal = 11.0, D3_Senior = 4.5, D3_Student = 7.0, D3_Weekend = 14.0;
    double D2_Normal = 8.5, D2_Senior = 4.5, D2_Student = 7.0, D2_Weekend = 12.5;
    double member_price = 6.5; //Declare all the variables here instead of hardcoding them into the function below
    //This is to make it easy to modify these variables if they ever need to be changed

    if (movie_type == 0){ //If this is a 2D movie

        if (day_of_the_week(day,month) >= 5 || day_of_the_week(day,month) == 0){ //If it is Friday, Saturday OR Sunday, return $12.5
            return D2_Weekend;
        }
        else { //If it is Monday-Thursday, need to test other cases

            if (is_member == 1 && day_of_the_week(day,month)==2 && identity != 1){
                //If user is a member AND it is Tuesday AND user is NOT senior member (since senior price is cheaper than member price)
                return member_price;
            }
            else { //Otherwise, move on to last test: Finding out whether identity is student (0), senior (1) or others (default)
                switch (identity){
                    case 0:
                        return D2_Student;
                        break;
                    case 1:
                        return D2_Senior;
                        break;
                    default:
                        return D2_Normal;
                } //Ends the switch-case for identity
            }
        } //Ends the test for whether person is member
    }
    else { //If the movie is 3D, perform all the same tests as in the 2D movie except that some prices are different

        if (day_of_the_week(day,month) >= 5 || day_of_the_week(day,month) == 0){
            return D3_Weekend;
        }
        else {

            if (is_member == 1 && day_of_the_week(day,month) == 2 && identity != 1){
                return member_price;
            }
            else {
                switch (identity){
                    case 0:
                        return D3_Student;
                        break;
                    case 1:
                        return D3_Senior;
                        break;
                    default:
                        return D3_Normal;
                }
            }
        }
    }
    //End of test for whether movie is 2D or 3D
}

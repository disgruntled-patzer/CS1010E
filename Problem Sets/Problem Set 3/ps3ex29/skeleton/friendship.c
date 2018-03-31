// CS1010E Programming Methodology
// Problem Set 3 Exercise #29: friendship.c
//
// This program reads 2D array capturing
// direct friendship and computes:
// (a) The most isolated users (iSolitude)
// (b) The friend-of-friend relationship (uFriend)
//
// Lau Yan Han

#include <stdio.h>
#include <math.h>
#define N 10

void scan_Array (int friendArr[N][N], int users, int num);
void iSolitude(int friendArr[N][N], int users);
void uFriend(int friendArr[N][N], int users);
void sort_mutual (int mutual[2][N*(N+1)/2], int num_mutual);
void print_array(int friendArr[N][N], int users);

int main(void) {

    int friendArr[N][N] = {0}, users; //users = number of users in friendArr
    int num; //Number of pairs of friendships

	printf("Read in the number of users: ");
	scanf("%d", &users);
	printf("There are %d users, indexed from 0 to %d.\n", users, users - 1);

	printf("Enter the number of pairs of direct friends: ");
	scanf("%d", &num);

	printf("Enter %d pairs of direct friends:\n", num);
    scan_Array(friendArr, users, num);

	print_array(friendArr, users);
	iSolitude(friendArr, users);
	uFriend(friendArr, users);

	return 0;
}

void scan_Array(int friendArr[N][N], int users, int num){

    int input1, input2; //The friendship pair variable that is dependent on user input
    int a; //Used in the loop

    for (a = 0; a < num; a++){
        scanf("%d", &input1);
        scanf("%d", &input2); //From a = 0 to a = num, scan the friendship pairs input by the user
        friendArr[input1][input2] = 1;
        friendArr[input2][input1] = 1; //Then assign them to their respective entries in the friendArr
    }

    for (a = 0; a < users; a++){
        friendArr[a][a] = 1; //Assign each user to himself as a direct friend
    }

}

// Print out a list of users who have
// the least number of direct friends.
// Assume that every user has
// himself/herself as a direct friend.
void iSolitude(int friendArr[N][N], int users) {

    int min = users; //Minimum number of friends, initialized to max possible value (note number of friends cannot be more than number of users)
    int counter = 0; //Counts how many friends each user has
    int row, col;

    // The first loop finds what is the least number of friends among all the users
    for (row = 0; row < users; row++){
        for (col = 0; col < users; col++){
            if (friendArr[row][col] == 1){
                counter++; //For each user (represented by the row), go through the row counting number of friends
            }
        }
        if (counter < min){
            min = counter; //If user is found to have fewer friends than the "minimum" variable, update "minimum" variable
        }
        counter = 0; //Reset counter to zero for the next iteration
    }
	printf("The least number of friends found is %d\n", min);

	// The second loop finds the users with the least amount of friends
	for (row = 0; row < users; row++){
        for (col = 0; col < users; col++){
            if (friendArr[row][col] == 1){
                counter++; //Do the same as first loop to count number of friends for each user
            }
        }
        if (counter == min){ //If user's number of friends match the minimum value
            printf("User %d has least number of friends\n", row);
        }
        counter = 0; //Reset counter to zero for the next iteration
	}

}

// Print pairs of users who are
// related by "friend-of-friend" relation.
// users i and j are related by
// "friend-of-friend" if:
//     i. they are not direct
//        friends of each other
//    ii. there exists another user k
//        such that (i,k) and (k,j)
//        are direct friend related
void uFriend(int friendArr[N][N], int users) {

    int userArr[N]; //Stores the index of friends which each user has
    int mutual[2][N*(N+1)/2]; //Stores all the mutual friendship pairs to be sorted later (max possible pairs = 10 + 9 + 8 + ...)
    int num_mutual = 0; //Number of mutual friendship pairs
    int a = 0, b = 0; //counters which run through the userArr array, initialized to zero for the first loop
    int numfriends = 0; //Number of friends which each user has, also initialized to zero
    int row, col; //counters that run through the main friendArr rows and columns

    for (row = 0; row < users; row++){ //Outer Loop: Perform the inner loops for each user (represented by the row)

        for (col = 0; col < users; col++){ //1st Inner loop: Scan through the columns to find the users's friends
            if (row != col && friendArr[row][col] == 1){ //If a friend is found (which isn't the selected person himself/herself)
                userArr[a] = col; //Add that friend to the userArr
                a++; //Update a to add the next friend into the next entry of userArr
                numfriends++; //Increase the number of friends for selected user by one
            }
        }

        for (a = 0; a < numfriends; a++){ //2nd Inner Loop: Scan through the userArr to compare all the friends of the selected user
            for (b = a + 1; b < numfriends; b++){ //Note that if user has only one friend, this inner loop will not be entered
                if (friendArr [userArr[a]] [userArr[b]] == 0){ //If friends in entries a and b are not friends with each other, they share a mutual friend
                    mutual[0][num_mutual] = userArr[a];
                    mutual[1][num_mutual] = userArr[b]; //Store this pair into the mutual array
                    num_mutual++; //Increment number of mutual pairs by one
                    //printf("Users (%d, %d) have a friend-of-friend relation.\n", userArr[a], userArr[b]);
                }
            }
        }
        //Reset a and numfriends to zero for the next outer loop
        //Note: no need to reset b because it will auto-reset in the 2nd Inner Loop, as well as mutual because it will keep adding all the mutual pairs
        a = 0;
        numfriends = 0;

    } //End of outer loop

    sort_mutual(mutual, num_mutual); //Sort all the mutual friendship pairs in ascending order and get rid of repeated pairs

}

// Sorts the mutual friendship pairs in ascending order and removes any repeated pairs
void sort_mutual(int mutual[2][N*(N + 1)/2], int num_mutual){

    int sorted[2][N*(N + 1)/2]; //Contains the sorted mutual friendship pairs from mutual friendship array
    int i, j; //This will run through the mutual friendship array looking for repeated pairs
    int num_sorted = 0; //Number of distinct friendship pairs (after repeated pairs have been removed)
    int swapped = 0, limit, temp0, temp1; //For the bubble sort algorithm

    for (i = 0; i < num_mutual; i++){ //Loop 1: Scans through the mutual array and "removes" repeated pairs
        if (mutual[0][i] == -1){
            continue; //-1 is used as an indicator for a repeated pair that has been removed. Don't waste time comparing this "removed" pair with others
        }
        for (j = i + 1; j < num_mutual; j++){
            if (mutual[0][j] == -1){
                continue; //Similarly, skip to the next iteration when finding a repeated pair that has already been 'removed'
            }
            if (mutual[0][j] == mutual[0][i] && mutual[1][j] == mutual[1][i]){ //If a repeated pair is found
                mutual[0][j] = -1;
                mutual[1][j] = -1; //Set the repeated pair to -1 to "remove" it
            }
        }
    }

    for (i = 0; i < num_mutual; i++){ //Loop 2: Assign the remaining pairs into the sorted array (to be sorted later on)
        if (mutual[0][i] != -1){ //Finds all the pairs which haven't been "removed"
            sorted[0][num_sorted] = mutual[0][i]; //And assign these pairs to the sorted array
            sorted[1][num_sorted] = mutual[1][i];
            num_sorted++;
        }
    }

    limit = num_sorted; //Set the limit to the size of the sorted array in preparation for the bubble sorting
    do { //Loop 3; Enhanced Bubble sort algorithm to sort the distinct pairs in ascending order
        swapped = 0;
        for (i = 1; i < limit; i++){
            if (sorted [0][i-1] > sorted [0][i] || (sorted[0][i-1] == sorted[0][i] && sorted[1][i-1] > sorted[1][i])){
                //Compare the lefthand side of the pair first, if lefthand is equal, then compare righthand side
                temp0 = sorted [0][i-1];
                sorted [0][i-1] = sorted [0][i];
                sorted [0][i] = temp0;
                temp1 = sorted [1][i-1]; //NOTE: Swap BOTH entries in the pairs [0] (lefthand) and [1] (righthand)
                sorted [1][i-1] = sorted [1][i];
                sorted [1][i] = temp1;
                swapped = 1;
            }
        }
        limit--; //Since the largest entry has been sorted to the rightmost side, reduce the limit by 1 for the next iteration
    } while (swapped == 1);

    for (i = 0; i < num_sorted; i++){ //Final loop: Scan through the now-sorted array to print out the mutual pairs
        printf("Users (%d, %d) have a friend-of-friend relation.\n", sorted[0][i], sorted[1][i]);
    }

}

// Print out array
// Complete and given
void print_array(int friendArr[N][N], int users) {

	int row, col;

	printf("The friendship matrix is:\n");
	for (row = 0; row < users; row++) {
		for (col = 0; col < users; col++) {
			printf(" %d", friendArr[row][col]);
		}
		printf("\n");
	}
}

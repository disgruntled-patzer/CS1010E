// CS1010E AY2013/4 Semester 2
// Problem Set 4 Exercise #06: word_game.c
//
// This program reads in a word and computes
// the total points of all the letters in the word.
//
// Lau Yan Han

#include <stdio.h>
#define MAX 21

int compute_score(char word[]);

int main(void) {

	char word[MAX];

	printf("Enter a word: ");
	scanf("%s", word);  // read a sigle word

	printf("Total score = %d\n", compute_score(word));

	return 0;
}

// Compute total score of letters in a word
int compute_score(char word[]) {

    int score = 0;
    int a = 0; // Loop counter

    while (word[a] != '\0'){ //While a is still running through the valid part of the string
        switch (word[a]){
            case 'D': case 'G':
                score = score + 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                score = score + 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                score = score + 4;
                break;
            case 'K':
                score = score + 5;
                break;
            case 'J': case 'X':
                score = score + 8;
                break;
            case 'Q': case 'Z':
                score = score + 10;
                break;
            default: // For A, E, I, L, N, O, R, S, T, U (Assumption: User does not input invalid characters)
                score = score + 1;
                break;
        }
        a++; //Update a to read the next character
    }

	return score;  // stub
}

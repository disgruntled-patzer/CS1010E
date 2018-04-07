// CS1010E Programming Methodology
// Problem Set 4 Exercise #08: count_words.c
//
// This program reads in a sentence, counts
// the number of English word inside.
//
// Lau Yan Han

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int count_words(char sentence[]);

int main(void) {

	int len;
	char text[MAX];

	printf("Enter a sentence: ");
	fgets(text, MAX, stdin);
	len = strlen(text);
	if (text[len-1] == '\n') {
		text[len-1] = '\0';
	}

	printf("Word count = %d\n", count_words(text));

	return 0;
}

// count the number of English word inside a sentence
int count_words(char sentence[]) {

    int a = 0; //Loop counter
    int word = 0; //Number of words

    while (sentence[a] != '\0'){
        if (isalpha(sentence[a]) >= 1 && isalpha(sentence[a + 1]) < 1){
            word++; //End of a word occurs when a letter is detected and the entry after it is white space
        }
        a++;
    }
    /*//At the end of the loop, if the last entry contains a word, it will not have white space after it (it will have \0 instead)
    //Thus the next if-else statement is necessary to ensure any word at the end of the sentence is counted.
    if (isalpha(sentence[a - 1]) >= 1){
        word++;
    }*/

	return word; // stub
}

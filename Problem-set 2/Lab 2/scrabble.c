// directories----

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// com_score is a integer and it has the word variable which is a string
int com_score(string word);

int main(void)
{
    // getting user input----
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // assigning the score variables to com_score with word variables
    int score1 = com_score(word1);
    int score2 = com_score(word2);

    // which player will win
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
         printf("Player 2 wins!\n");
    }
    // they both pick the same letter
    else {
        printf("Tie!\n");
    }

}

// again?
int com_score(string word)
{
    // sum_points variable assignning ----
    int sum_point = 0;

    // foooOOR LooOooPp~~~
    for (int i = 0; i < strlen(word); i++) // 'strlen' means string length
    {
        if (isalpha(word[i])) // 'isalpha' means to check if a certain value is an alphabet letter
        {
            int letter_offset = toupper(word[i]) - 'A';
            sum_point += POINTS[letter_offset];
        }
    }
    return sum_point;
}

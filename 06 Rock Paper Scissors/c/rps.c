#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    char choice;

    do {
        printf("Rock, paper, or scissors? (r/p/s): ");
        scanf(" %c", &choice);
    } while (choice != 'r' && choice != 'p' && choice != 's');

    srand(time(NULL));
    int random = rand() % 3;

    const char choices[] = { 'r', 'p', 's' };
    const char *words[] = { "rock", "paper", "scissors" };
    char ai_choice = choices[random];

    printf("The AI chooses %s. ", words[random]);
    if (ai_choice == choice) {
        printf("It is a tie.\n");
    } else if ((ai_choice == 'r' && choice == 's') || (ai_choice == 'p' && choice == 'r') || (ai_choice == 's' && choice == 'p')) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }
    
    return EXIT_SUCCESS;
}

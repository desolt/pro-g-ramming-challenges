#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

int main()
{
    puts("Heads or tails? (h/t): ");

    int ch = 0;
    do {
        ch = getchar();
    } while (tolower(ch) != 'h' && tolower(ch) != 't');

    srand(time(NULL));
    int result = rand() % 2; /* 1 = heads, 0 = tails */

    const char *coin = result == 1 ? "heads" : "tails";
    if ((result == 1 && ch == 'h') || (result == 0 && ch == 't')) {
        printf("It was %s! You won!\n", coin);
    } else {
        printf("It was %s! You lose!\n", coin);
    }

    return EXIT_SUCCESS;
}

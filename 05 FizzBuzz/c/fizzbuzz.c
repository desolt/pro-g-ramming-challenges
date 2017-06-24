#include <stdlib.h>
#include <stdio.h>

int main()
{
    int turns;
    do {
        printf("How many turns? ");
        scanf(" %d", &turns);
    } while (turns <= 0);

    for (int i = 0; i < turns; i++) {
        if (i % 3 == 0)
            printf("Fizz");
        if (i % 5 == 0)
            printf("Buzz");
        if (i % 3 != 0 && i % 5 != 0)
            printf("%d", i);
        printf("\n");
    }
}

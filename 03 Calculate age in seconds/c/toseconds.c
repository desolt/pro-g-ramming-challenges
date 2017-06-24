#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    float age = 0;

    do {
        printf("What is your age (in years)?: ");
        scanf("%f", &age);
    } while (age <= 0);

    float years = 346.620075883 * age;
    float minutes = years * 24 * 60;
    long seconds = minutes * 60;

    printf("You are %lu seconds old.\n", seconds);


    return EXIT_SUCCESS;
}
